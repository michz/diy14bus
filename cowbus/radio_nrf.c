/**
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h"      // cowbus-one
#include "cpu.h"        // stmf0 ?
#include "thread.h"
#include "nrf24l01p.h"
#include "nrf24l01p_settings.h"
#include "hwtimer.h"

#include "radio_nrf.h"

/// @brief instance of RIOTs nrf24l01p driver
static nrf24l01p_t nrf24l01p_0;

/// @brief Callback function pointer for incoming packets
static void (*recv_callback)(cowpacket);

/// @brief Current sequence number
static unsigned char c_seq_no = 1;

/// @brief Current backoff time
static unsigned int c_backoff = 0;

/// @brief stack for rx_handler-thread // TODO: stacksize anders wählen (?)
char rx_handler_stack[KERNEL_CONF_STACKSIZE_DEFAULT];

/// @brief Address of this node
unsigned short cowbus_address = COWBUS_DEFAULT_ADDR;

/// @brief Increments and returns the sequence number counter
static inline unsigned char radio_get_next_seq_no(void) {
    if (c_seq_no >= 31) c_seq_no = 0;
    return ++c_seq_no;
}

// based on a test from RIOT
void *nrf24l01p_rx_handler(void *arg) {
    msg_t msg_q[1];
    msg_init_queue(msg_q, 1);
    unsigned int pid = thread_getpid();
    char rx_buf[NRF24L01P_MAX_DATA_LENGTH];

    nrf24l01p_register(&nrf24l01p_0, &pid);

    msg_t m;

    while (msg_receive(&m)) {
        printf("nrf24l01p_rx_handler got a message: ");

        switch (m.type) {
            case RCV_PKT_NRF24L01P:
                puts("Received packet.");

                // CE low
                nrf24l01p_stop((nrf24l01p_t *)m.content.ptr);

                // read payload
                nrf24l01p_read_payload((nrf24l01p_t *)m.content.ptr, rx_buf, NRF24L01P_MAX_DATA_LENGTH);

                // flush rx fifo
                nrf24l01p_flush_rx_fifo((nrf24l01p_t *)m.content.ptr);

                // CE high
                nrf24l01p_start((nrf24l01p_t *)m.content.ptr);

                // TODO check if correct cowpacket (especially version!)
                if (recv_callback != NULL) {
                    cowpacket p;
                    memcpy(&p, rx_buf, NRF24L01P_MAX_DATA_LENGTH);
                    recv_callback(p);
                    //TODO better do NOT process packet directly in ISR/thread,
                    //     better enqueue into some kind of processing queue
                }

                break;

            default:
                break;
        }
    }

    return NULL;
}

void radio_nrf_init(void) {
    // initialize radio module
    //                                            ce=B11, cs=B12, irq=A1
    int ret = nrf24l01p_init(&nrf24l01p_0, SPI_0, GPIO_6, GPIO_7, GPIO_12);
    //TODO auf cowbus-board anpassen
    
    nrf24l01p_disable_all_auto_ack(&nrf24l01p_0); // disable all auto ack

    if (ret < 0) {
        printf("Transceiver initialization failed: %i\n", ret);
        // TODO: Fehlerzustand irgendwie anzeigen, LEDs?
        return;
    }

    thread_create(
        rx_handler_stack, sizeof(rx_handler_stack), PRIORITY_MAIN - 1, 0,
        nrf24l01p_rx_handler, 0, "nrf24l01p_rx_handler");

    nrf24l01p_set_rxmode(&nrf24l01p_0);

    recv_callback = NULL;

    // initialize RNG for CSMA/CA backoff
    srand(hwtimer_now());
}

void radio_nrf_register_rx_callback(void (*callback)(cowpacket)) {
    recv_callback = callback;
}

void radio_nrf_send_data(char* payload, unsigned short payload_length) {
    // TODO: CSMA/CA
    // check if medium is busy
    //   if yes: radio_nrf_backoff();
    // check again
    
    
    // power on the device
    int r = nrf24l01p_on(&nrf24l01p_0);
    
    // setup device as transmitter
    r = nrf24l01p_set_txmode(&nrf24l01p_0);
    
    // load data to transmit into device
    r = nrf24l01p_preload(&nrf24l01p_0, payload, payload_length);
    
    // trigger transmitting
    nrf24l01p_transmit(&nrf24l01p_0);

    // wait while data is pysically transmitted 
    hwtimer_wait(DELAY_DATA_ON_AIR);

    r = nrf24l01p_get_status(&nrf24l01p_0);
    if (r & TX_DS) {
        printf("Sent Packet\n");
    }
    else {
        //TODO error handling
    }

    // setup device as receiver
    nrf24l01p_set_rxmode(&nrf24l01p_0);

}

void radio_nrf_send_packet(unsigned short address, cowpacket_type type, 
                            char* payload, unsigned char payload_length) {
    //TODO assure that payload is not longer than PAYLOAD_MAX_LENGTH bytes
    cowpacket pkt;
    pkt.version     = COWBUS_VERSION;
    pkt.seq_no      = radio_get_next_seq_no();
    pkt.ttl         = COWBUS_DEFAULT_TTL;
    pkt.addr        = address;
    pkt.type        = type;
    pkt.is_fragment = 0;
    memcpy(pkt.payload, payload, payload_length);

    //TODO: Checksumme berechnen

    radio_nrf_send_data((char*)&pkt, sizeof(cowpacket));


}

void radio_nrf_backoff(void) {
    if (c_backoff == 0) {
        c_backoff = 165 + rand() % 660; // from 1 to 5 packets
        // TODO test if this calculation is correct
    }
    hwtimer_wait(HWTIMER_TICKS(c_backoff));
    c_backoff = 0;
}

/*
 * Some notes:
 * According to nrf24l01+ datasheet, a packet is not larger than 329 bit.
 * So the transmission of one packet at 2Mbps should not take longer than 
 *  164.5µs (or 0.1645ms).
 */

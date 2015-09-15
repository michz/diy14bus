/**
 * @file
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-15
 *
 * Copyright (C) 2015 Michael Zapf <michael.zapf@fau.de>
 */

#include "cowmac.h"


char cowmac_receiver_stack[THREAD_STACKSIZE_MAIN];
uint16_t cowmac_address = COWBUS_DEFAULT_ADDR;
void (*cb_pkt_recv)(cowpacket) = NULL;

/// @brief Current sequence number
static uint8_t c_seq_no = 1;

/// @brief Current backoff time
static unsigned int c_backoff = 0;


extern nrf24l01p_t nrf24l01p_0;


/// @brief Increments and returns the sequence number counter
static inline uint8_t cowmac_next_seqno(void) {
    if (c_seq_no >= 254) c_seq_no = 0;
    return ++c_seq_no;
}

void cowmac_send_packet(cowpacket *pkt) {
    // TODO: CSMA/CA
    // check if medium is busy
    //   if yes: radio_nrf_backoff();
    // check again

    radio_nrf_send_data((char*)pkt, sizeof(cowpacket));
}

void cowmac_register_packet_handler(void (*fnc)(cowpacket)){
    cb_pkt_recv = fnc;
}

int cowmac_init_packet(cowpacket *pkt, uint16_t address,
        cowpacket_type type, char* payload, unsigned char payload_length) {

    memset(pkt, 0, sizeof(cowpacket));
    pkt->version    = COWBUS_VERSION;
    pkt->seq_no     = cowmac_next_seqno();
    pkt->ttl        = COWBUS_DEFAULT_TTL;
    cowpacket_set_address(pkt, address);
    cowpacket_set_type(pkt, type);
    cowpacket_set_is_fragment(pkt, 0);

    if (payload_length > PAYLOAD_MAX_LENGTH) return 0;
    memcpy(pkt->payload, payload, payload_length);
    return 1;
}

void *cowmac_receiver(void *arg) {
    // initialize RNG for CSMA/CA backoff
    srand(xtimer_now());

    msg_t msg_q[1];
    msg_init_queue(msg_q, 1);
    unsigned int pid = thread_getpid();
    char rx_buf[NRF24L01P_MAX_DATA_LENGTH];

    nrf24l01p_register(&nrf24l01p_0, &pid);

    msg_t m;

    printf("nrf24l01p_rx_handler started.\n");
    while (msg_receive(&m)) {
        printf("nrf24l01p_rx_handler got a message: \n");

        switch (m.type) {
            case RCV_PKT_NRF24L01P:
                printf("Received packet. %d\n", inISR());

                // CE low
                nrf24l01p_stop((nrf24l01p_t *)m.content.ptr);

                // read payload
                nrf24l01p_read_payload((nrf24l01p_t *)m.content.ptr, rx_buf, NRF24L01P_MAX_DATA_LENGTH);

                // flush rx fifo
                nrf24l01p_flush_rx_fifo((nrf24l01p_t *)m.content.ptr);

                // CE high
                nrf24l01p_start((nrf24l01p_t *)m.content.ptr);

                // TODO check if correct cowpacket (especially version!)
                cowpacket p;
                memcpy(&p, rx_buf, NRF24L01P_MAX_DATA_LENGTH);
                if (cb_pkt_recv != NULL) {
                    cb_pkt_recv(p);
                }

                break;
            default:
                break;
        }
    }

    return NULL;
}

void cowmac_backoff(void) {
    if (c_backoff == 0) {
        c_backoff = 165 + rand() % 660; // from 1 to 5 packets
        // TODO test if this calculation is correct
    }
    xtimer_usleep(c_backoff);
    c_backoff = 0;
}

/*
 * Some notes:
 * According to nrf24l01+ datasheet, a packet is not larger than 329 bit.
 * So the transmission of one packet at 2Mbps should not take longer than 
 *  164.5µs (or 0.1645ms).
 */

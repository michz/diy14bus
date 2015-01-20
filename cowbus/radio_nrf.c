/**
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */
#include "board.h"      // cowbus-one
#include "cpu.h"        // stmf0 ?
#include "thread.h"
#include "nrf24l01p.h"
#include "nrf24l01p_settings.h"

#include "radio_nrf.h"

/// @brief instance of RIOTs nrf24l01p driver
static nrf24l01p_t nrf24l01p_0;

/// stack for rx_handler-thread // TODO: stacksize anders wählen (?)
char rx_handler_stack[KERNEL_CONF_STACKSIZE_MAIN];


// TODO implement RX handler that waits for a message from the ISR
// Now: example implementation from RIOT/tests/
void *nrf24l01p_rx_handler(void *arg)
{
    msg_t msg_q[1];
    msg_init_queue(msg_q, 1);
    unsigned int pid = thread_getpid();
    char rx_buf[NRF24L01P_MAX_DATA_LENGTH];

    puts("Registering nrf24l01p_rx_handler thread...");
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

                // TODO: for first tests simply switch LED on/off or send response
                // print rx buffer
                for (int i = 0; i < NRF24L01P_MAX_DATA_LENGTH; i++) {
                    printf("%i ", rx_buf[i]);
                }
                printf("\n");

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
    int ret = nrf24l01p_init(&nrf24l01p_0, SPI_1, GPIO_6, GPIO_7, GPIO_12);
    //TODO auf cowbus-board anpassen

    if (ret < 0) {
        printf("Transceiver initialization failed: %i\n", ret);
        // TODO: Fehlerzustand irgendwie anzeigen, LEDs?
        return;
    }

    thread_create(
        rx_handler_stack, sizeof(rx_handler_stack), PRIORITY_MAIN - 1, 0,
        nrf24l01p_rx_handler, 0, "nrf24l01p_rx_handler");

    nrf24l01p_set_rxmode(&nrf24l01p_0);
}

void radio_nrf_register_rx_callback(void) {
}

void radio_nrf_send_packet(char* payload, uint8_t payload_length) {

}



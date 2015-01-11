#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h"      // cowbus-one
#include "cpu.h"        // stmf0 ?
#include "hwtimer.h"

#include "thread.h"

#include "nrf24l01p.h"
#include "nrf24l01p_settings.h"
#include "periph/spi.h"
#include "periph/gpio.h"

#include "board_uart0.h"

#include "cowpacket.h"
#include "grazed_list.h"
#include "actor.h"
#include "sensor.h"
#include "packet_queue.h"

//#define SND_BUFFER_SIZE     (100)
//#define RCV_BUFFER_SIZE     (64)
//#define RADIO_STACK_SIZE    (KERNEL_CONF_STACKSIZE_DEFAULT)


/// instance of nrf24l01+ transceiver
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

                /* CE low */
                nrf24l01p_stop((nrf24l01p_t *)m.content.ptr);

                /* read payload */
                nrf24l01p_read_payload((nrf24l01p_t *)m.content.ptr, rx_buf, NRF24L01P_MAX_DATA_LENGTH);

                /* flush rx fifo */
                nrf24l01p_flush_rx_fifo((nrf24l01p_t *)m.content.ptr);

                /* CE high */
                nrf24l01p_start((nrf24l01p_t *)m.content.ptr);

                /* print rx buffer */
                for (int i = 0; i < NRF24L01P_MAX_DATA_LENGTH; i++) {
                    printf("%i ", rx_buf[i]);
                }

                puts("");

                break;

            default:
                puts("stray message.");
                break;
        }
    }

    puts("nrf24l01p_rx_handler: this should not have happened!");

    return NULL;
}


int main(void)
{

    // initialize ringbuffer for received packets
    packet_queue_init();

    // TODO get node address from eeprom
    //      if not available, go through algorithm to determine new address:
    //          1. generate randomly address of length 11 bit
    //          2. send PING with generated address
    //          3. wait X seconds for answer (ping_answer)
    //          4. if no answer received, accept address and save it
    //          5. if an answer is received, start over with 1.
    //              (or determine another address on another way)
    //

    // initialize radio module
    //                                            ce=B11, cs=B12, irq=A1
    int ret = nrf24l01p_init(&nrf24l01p_0, SPI_1, GPIO_6, GPIO_7, GPIO_12);

    if (ret < 0) {
        printf("Transceiver initialization failed: %i\n", ret);
    }

    thread_create(
        rx_handler_stack, sizeof(rx_handler_stack), PRIORITY_MAIN - 1, 0,
        nrf24l01p_rx_handler, 0, "nrf24l01p_rx_handler");

    nrf24l01p_set_rxmode(&nrf24l01p_0);

    // TODO initialize buttons (with interrupts)
    // TODO initialize LEDs

	while(1) {
        // TODO
        // if everything works with interrupts, we could go to sleep here
    }

    return 0;
}

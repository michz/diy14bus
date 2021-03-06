#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h" // stm32f3discovery-diy
#include "cpu.h"
#include "hwtimer.h"

#include "thread.h"


#include "nrf24l01p.h"
#include "nrf24l01p_settings.h"
#include "periph/spi.h"
#include "periph/uart.h"

#include "periph/gpio.h"

#include "board_uart0.h"

#include "../cowbus/include/cowpacket.h"

#define SND_BUFFER_SIZE     (100)
#define RCV_BUFFER_SIZE     (64)
#define RADIO_STACK_SIZE    (THREAD_STACKSIZE_MAIN)

char radio_stack_buffer[RADIO_STACK_SIZE];
msg_t msg_q[RCV_BUFFER_SIZE];

#define DBG_MSG_BUTTON      (1)
#define DBG_PING_ANSWER     (2)
#define DBG_GET_NAME        (3)

uint8_t sendMsg;
kernel_pid_t radio_pid;

static nrf24l01p_t nrf24l01p_0;

int seq_no = 0xB;

char dbg_name[PAYLOAD_MAX_LENGTH+1];

char rx_handler_stack[RADIO_STACK_SIZE];

/* RX handler that waits for a message from the ISR */
void *nrf24l01p_rx_handler(void *arg)
{
    msg_t msg_q[1];
    msg_init_queue(msg_q, 1);
    unsigned int pid = thread_getpid();
    char rx_buf[NRF24L01P_MAX_DATA_LENGTH];
    memset(rx_buf, 0, NRF24L01P_MAX_DATA_LENGTH);

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

                // -v-v-v- DEBUG do some basic stuff -v-v-v-
                cowpacket* p = (cowpacket*)rx_buf;

                // check checksum
                if (cowpacket_check_checksum(p)) {
                    LD9_ON;
                    hwtimer_wait(HWTIMER_TICKS(100 * 1000));

                    if (p->type == ping)  {
                        // PING request
                        sendMsg = DBG_PING_ANSWER;
                    }
                    else if (p->type == get_name)  {
                        sendMsg = DBG_GET_NAME;
                    }
                    else if (p->type == set_name)  {
                        // SET_NAME request
                        memset(dbg_name, 0, PAYLOAD_MAX_LENGTH+1);
                        strncpy(dbg_name, (char*)p->payload, strlen((char*)p->payload));

                        // set ping response (type = 7)
                        sendMsg = DBG_GET_NAME;

                        LD7_ON;
                        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
                        LD7_OFF;
                    }

                    LD9_OFF;
                }
                else { // checksum failure
                    for (int i = 0; i < 3; ++i) {
                        LD10_ON;
                        hwtimer_wait(HWTIMER_TICKS(75 * 1000));
                        LD10_OFF;
                        hwtimer_wait(HWTIMER_TICKS(125 * 1000));
                    }
                }

                break;

            default:
                puts("stray message.");
                break;
        }
    }

    puts("nrf24l01p_rx_handler: this should not have happened!");

    return NULL;
}


void button_pressed(void) {
    sendMsg = 1;
}

int main(void)
{
	sendMsg = 1;

    // DEBUG
    char* tmp_name = "TESTNODE1";
    strncpy(dbg_name, tmp_name, strlen(tmp_name));

    LD3_OFF;
    LD4_OFF;
    LD5_OFF;
    LD6_OFF;
    LD7_OFF;
    LD8_OFF;
    LD9_OFF;
    LD10_OFF;
    hwtimer_wait(HWTIMER_TICKS(500 * 1000));

    LD3_ON;
    LD4_ON;
    LD5_ON;
    LD6_ON;
    LD7_ON;
    LD8_ON;
    LD9_ON;
    LD10_ON;

    board_uart0_init();
    printf("test_uart.\n");

    hwtimer_wait(HWTIMER_TICKS(500 * 1000));
    LD3_OFF;
    LD4_OFF;
    LD5_OFF;
    LD6_OFF;
    LD7_OFF;
    LD8_OFF;
    LD9_OFF;
    LD10_OFF;

    hwtimer_wait(HWTIMER_TICKS(1000 * 1000));

    int ret = nrf24l01p_init(&nrf24l01p_0, SPI_1,
            GPIO(PORT_B, 11),       // B11  (CE)
            GPIO(PORT_B, 12),       // B12  (CS)
            GPIO(PORT_A, 1)         // A1   (IRQ)
            );

    if (ret < 0) {
        printf("Transceiver initialization failed: %i\n", ret);
    }

    thread_create(
        rx_handler_stack, sizeof(rx_handler_stack), THREAD_PRIORITY_MAIN - 1, 0,
        nrf24l01p_rx_handler, 0, "nrf24l01p_rx_handler");

    nrf24l01p_disable_all_auto_ack(&nrf24l01p_0); // disable all auto ack
    nrf24l01p_set_rxmode(&nrf24l01p_0);


    // initialize button USER
    gpio_init_int(GPIO(PORT_A, 0), GPIO_NOPULL, GPIO_RISING, (void *)button_pressed, 0);
    gpio_irq_enable(GPIO(PORT_A, 0));

    int i = 0;
	while (1) {
		if (sendMsg > 0) {

            int r = 0;

            int status = 0;
            char tx_buf[NRF24L01P_MAX_DATA_LENGTH];

            /* fill TX buffer with sample data */
            cowpacket* cp = (cowpacket*)tx_buf;
            cp->version = 0;
            cp->seq_no  = seq_no;
            cp->ttl     = 5;
            cp->addr    = 2040;
            cp->type    = event;
            cp->is_fragment = 0;


            if (sendMsg == DBG_MSG_BUTTON) {
                for (int i = 0; i < sizeof(cp->payload); ++i) {
                    cp->payload[i] = 48+i;
                }
            }
            else if (sendMsg == DBG_PING_ANSWER) {
                cp->type = ping_answer;

                // send name back for example
                memset(cp->payload, 0, sizeof(cp->payload));
                strncpy((char*)cp->payload, dbg_name, strlen((char*)dbg_name));
            }
            else if (sendMsg == DBG_GET_NAME) {
                cp->type = get_name;
                memset(cp->payload, 0, sizeof(cp->payload));
                strncpy((char*)cp->payload, dbg_name, strlen((char*)dbg_name));
            }


            cowpacket_generate_checksum(cp);
//            cp->checksum[0] = 0xAA;
//            cp->checksum[1] = 0xAA;

            if (seq_no > 30) { seq_no = 0; }
            else { seq_no++; }

            /* power on the device */
            r = nrf24l01p_on(&nrf24l01p_0);
            printf("on: %i\n", r);
            /* setup device as transmitter */
            r = nrf24l01p_set_txmode(&nrf24l01p_0);
            printf("txmode: %i\n", r);
            /* load data to transmit into device */
            r = nrf24l01p_preload(&nrf24l01p_0, tx_buf, NRF24L01P_MAX_DATA_LENGTH);
            printf("preload: %i\n", r);
            /* trigger transmitting */
            nrf24l01p_transmit(&nrf24l01p_0);

            /* wait while data is pysically transmitted  */
            hwtimer_wait(DELAY_DATA_ON_AIR);

            status = nrf24l01p_get_status(&nrf24l01p_0);
            printf("Status: %i\n", status);
            if (status & TX_DS) {
                printf("Sent Packet\n");
            }
            /* setup device as receiver */
            nrf24l01p_set_rxmode(&nrf24l01p_0);

            // reset
            sendMsg = 0;
		}



        if (i < 5000) {
            LD5_ON;
            LD4_OFF;
        }
        else if (i < 10000) {
            LD5_OFF;
            LD4_ON;
        }
        else {
            i = 0;
        }
        i++;
        hwtimer_wait(HWTIMER_TICKS(100)); // 100 us
    }



    return 0;

}

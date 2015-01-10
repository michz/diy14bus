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

#include "transceiver.h"

#include "periph/gpio.h"

#include "board_uart0.h"


#define SND_BUFFER_SIZE     (100)
#define RCV_BUFFER_SIZE     (64)
#define RADIO_STACK_SIZE    (KERNEL_CONF_STACKSIZE_DEFAULT)

char radio_stack_buffer[RADIO_STACK_SIZE];
msg_t msg_q[RCV_BUFFER_SIZE];

uint8_t sendMsg;
kernel_pid_t radio_pid;

static nrf24l01p_t nrf24l01p_0;


void *radio(void *arg)
{

	uint8_t temp = 0;

    (void) arg;

    msg_t m;

    msg_init_queue(msg_q, RCV_BUFFER_SIZE);

    while (1) {

		//cc110x_txrx('a'); //just for debug

		sendMsg = 1;

		if(msg_try_receive(&m) == 1){

		    if (m.type == RCV_PKT_CC1100) {

				if(temp == 0){
					LD3_ON;
					temp = 1;
				}
				else{
					LD3_OFF;
					temp = 0;
				}

		    }
		    else if (m.type == ENOBUFFER) {
		        puts("Transceiver buffer full");
		    }
		    else {
		        puts("Unknown packet received");

		    }
		}


		hwtimer_wait(HWTIMER_TICKS(500 * 1000));

    }
}




/*
void init_transceiver(void)
{
    radio_pid = thread_create(
                        radio_stack_buffer,
                        sizeof(radio_stack_buffer),
                        PRIORITY_MAIN - 2,
                        CREATE_STACKTEST,
                        radio, //name der Funktion, in der der Thread losackert.
                        NULL,
                        "radio");

    uint16_t transceivers = TRANSCEIVER_DEFAULT;

    transceiver_init(transceivers);
    (void) transceiver_start();
    if(transceiver_register(transceivers, radio_pid) != 1){
		//no success
		//20141205 not reached
		LD4_ON;
	}
}
*/



char rx_handler_stack[KERNEL_CONF_STACKSIZE_MAIN];

/* RX handler that waits for a message from the ISR */
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
                LD9_ON;
                hwtimer_wait(HWTIMER_TICKS(100 * 1000));
                LD9_OFF;

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

    //                                  ce=B11, cs=B12, irq=A1
    int ret = nrf24l01p_init(&nrf24l01p_0, SPI_1, GPIO_6, GPIO_7, GPIO_12);

    if (ret < 0) {
        printf("Transceiver initialization failed: %i\n", ret);
    }

    thread_create(
        rx_handler_stack, sizeof(rx_handler_stack), PRIORITY_MAIN - 1, 0,
        nrf24l01p_rx_handler, 0, "nrf24l01p_rx_handler");

    nrf24l01p_set_rxmode(&nrf24l01p_0);


    //	init_transceiver();

    // initialize button USER
    gpio_init_int(GPIO_11, GPIO_NOPULL, GPIO_RISING, (void *)button_pressed, 0);
    gpio_irq_enable(GPIO_11);


    char* text_msg = "Bla";
	while(1) {
		if(gpio_read(GPIO_0) > 0 && sendMsg == 1){ //hier dann auf sendMsg pruefen, das durch externen Taster in dessen ISR auf 1 gesetzt wird.
			sendMsg = 0;

            int r = 0;



            int status = 0;
            char tx_buf[NRF24L01P_MAX_DATA_LENGTH];

            /* fill TX buffer with numbers 32..1 */
            for (int i = 0; i < sizeof(tx_buf); i++) {
                tx_buf[i] = NRF24L01P_MAX_DATA_LENGTH - i;
            }
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


            /*
            radio_packet_t p;

            transceiver_command_t tcmd;
            tcmd.transceivers = TRANSCEIVER_CC1100;
            tcmd.data = &p;

            p.data = (uint8_t *) text_msg;
            p.length = strlen(text_msg) + 1;
            p.dst = (uint16_t)0;

			//neue msg anlegen.
			msg_t msg;
            msg.type = SND_PKT;
            msg.content.ptr = (char *)&tcmd;
            msg_send_receive(&msg, &msg, transceiver_pid);
            */

            /*
			if(msg_send(newMsg, radio_pid) == -1){
				//no success
				//20141205: is reached :(
				LD4_ON;
			}
            */

			//free(newMsg);

		}




        LD5_ON;
        hwtimer_wait(HWTIMER_TICKS(500* 1000));
        LD5_OFF;
        LD4_ON;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD4_OFF;
    }



    return 0;

}

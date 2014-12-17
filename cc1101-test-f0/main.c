//#define MODULE_CC110X_LEGACY //wo wird das sonst definiert? ^^

#include <stdlib.h>
#include <string.h>

#include "board.h" // stm32f0discovery-diy
#include "cpu.h"
//#include "periph/spi.h"
#include "hwtimer.h"

#include "thread.h"

#include "cc110x_legacy.h"
#include "transceiver.h"

#include "periph/gpio.h"


#define SND_BUFFER_SIZE     (100)
#define RCV_BUFFER_SIZE     (64)
#define RADIO_STACK_SIZE    (KERNEL_CONF_STACKSIZE_DEFAULT)

char radio_stack_buffer[RADIO_STACK_SIZE];
msg_t msg_q[RCV_BUFFER_SIZE];

uint8_t sendMsg;
kernel_pid_t radio_pid;

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


int main(void)
{
	sendMsg = 1;

	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	//RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOFEN;

//    gpio_init_out(GPIO_6, GPIO_NOPULL);
//    gpio_clear(GPIO_6);

	init_transceiver();

    /*
    cc110x_spi_init();


#ifdef MODULE_CC110x_SPI
    cc110x_spi_unselect();
    cc110x_spi_cs();
    cc110x_spi_unselect();
#endif
    hwtimer_wait(RESET_WAIT_TIME);
    cc110x_wakeup_from_rx();
#ifdef MODULE_CC110x_SPI
    cc110x_spi_select();
#endif
    cc110x_strobe(0x30);
//    gpio_set(GPIO_6);


    hwtimer_wait(RTIMER_TICKS(100));
    radio_state = RADIO_IDLE;
*/

//    cc110x_print_config();

        gpio_init_in(GPIO_0, GPIO_NOPULL);

    char* text_msg = "Bla";
	while(1) {
		if(gpio_read(GPIO_0) > 0 && sendMsg == 1){ //hier dann auf sendMsg pruefen, das durch externen Taster in dessen ISR auf 1 gesetzt wird.
			sendMsg = 0;

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


            /*
			if(msg_send(newMsg, radio_pid) == -1){
				//no success
				//20141205: is reached :(
				LD4_ON;
			}
            */

			//free(newMsg);

		}
    }


        //LD3_ON;
        //hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
        //LD3_OFF;
        //LD4_ON;
        //hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        //LD4_OFF;

    return 0;

}

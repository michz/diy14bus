//#define MODULE_CC110X_LEGACY //wo wird das sonst definiert? ^^

#include <stdlib.h>

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

    (void) arg;

    msg_t m;

    msg_init_queue(msg_q, RCV_BUFFER_SIZE);

    while (1) {

		sendMsg = 1;

		if(msg_try_receive(&m) == 1){

			

		    if (m.type == PKT_PENDING) {

		    }
		    else if (m.type == ENOBUFFER) {
		        puts("Transceiver buffer full");
		    }
		    else {
		        puts("Unknown packet received");
				
		    }
		}

		else if(sendMsg == 1){ //hier dann auf sendMsg pruefen, das durch externen Taster in dessen ISR auf 1 gesetzt wird.
			
			//neue msg anlegen.
			msg_t *newMsg = (msg_t *) malloc(sizeof(msg_t));
			newMsg->type = PKT_PENDING;

			if(msg_send(newMsg, radio_pid) == -1){ 
				//no success 
				//20141205: wird ausgeführt
				//LD4_ON;
			}

			free(newMsg);
	
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

		//LD4_ON; 
	}
}



int main(void)
{
	sendMsg = 1;

	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOFEN;

	init_transceiver();

	while(1){}


        //LD3_ON;
        //hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
        //LD3_OFF;
        //LD4_ON;
        //hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        //LD4_OFF;

    return 0;

}

#define MODULE_CC110X_LEGACY

#include <stdlib.h>

#include "board.h" // stm32f3discovery
#include "cpu.h"
#include "periph/spi.h"
#include "hwtimer.h"

#include "thread.h"

#include "cc110x_legacy.h"
#include "transceiver.h"


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

    radio_packet_t *p;
    radio_packet_length_t i;

    msg_init_queue(msg_q, RCV_BUFFER_SIZE);

    while (1) {

		if(msg_try_receive(&m) == 1){

			LD4_ON;

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
			msg_send(newMsg, radio_pid); //hier noch Fehlerabfragen einfuegen!
			sendMsg = 0;
	
	
		}
	


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
    transceiver_register(transceivers, radio_pid);
}






int main(void)
{

	init_transceiver();

	sendMsg = 1;



        //LD3_ON;
        //hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
        //LD3_OFF;
        //LD4_ON;
        //hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        //LD4_OFF;

    return 0;

}

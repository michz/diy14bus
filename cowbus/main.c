#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "board.h"      // cowbus-one
#include "cpu.h"        // stmf0 ?
#include "xtimer.h"

#include "thread.h"

#include "nrf24l01p.h"
#include "nrf24l01p_settings.h"
#include "periph/spi.h"
#include "periph/gpio.h"
#include "periph/uart.h"

#include "led.h"
#include "switch.h"
#include "cowpacket.h"
#include "cowconfig.h"
#include "grazed_list.h"
#include "actor.h"
#include "sensor.h"
#include "packet_queue.h"
#include "radio_nrf.h"
#include "eeprom.h"
#include "temp.h"
#include "buzzer.h"

#include "cowmac.h"


/// @brief local in-memory representation of configuration rules of this node
int seq_no = 0xB;
uint16_t radio_addr = 1021;

int sendMsg = 0;


//#define MODULE_UART0

void packet_received(cowpacket pkt) {
    led_blink_s(green, 100, 1);
    // TODO packet handling (switch led on/off, ping response, ...)
    // only interpret this if address is my node's address
    if (cowpacket_get_address(&pkt) == config_get_address()) {
        // TODO interpret message payload (led1 on, led2 color, ...)
    }
    else {
        // TODO go through programmed event handlers
    }
}


void switch1(void)
{
	printf("switch 1 pressed.\n");
    sendMsg = 1;
}

void switch2(void)
{
	printf("switch 2 pressed.\n");
    sendMsg = -1;
}

void switch3(void)
{
	printf("switch 3 pressed.\n");
}

void switch4(void)
{
	printf("switch 4 pressed.\n");
    if (switch3_get_state()) {
        printf("Pressed #3 and #4, reset!\n");
        xtimer_spin(1000);
        NVIC_SystemReset();                     // perform reset
    }
}

int main(void)
{
	(RCC->AHBENR |= RCC_AHBENR_GPIOAEN);
	(RCC->AHBENR |= RCC_AHBENR_GPIOBEN);

    switch1_set_isr(switch1);
    switch2_set_isr(switch2);
    switch3_set_isr(switch3);
    switch4_set_isr(switch4);
    
    radio_nrf_init();
    cowmac_register_packet_handler(packet_received);


    int i = 0;
	while (1) {
		if (sendMsg > 0) {
            cowpacket pkt;

            cowmac_init_packet(&pkt, ping, "123456", 7);

            cowmac_send_packet(&pkt);

            // reset
		}
        else if (sendMsg < 0) {
            //uint16_t addr = eeprom_get_addr();
            //printf("addr from eeprom: %d\n", addr);
            printf("Temp: %s\n", temp_to_readable(temp_get()));
            buzzer(note_c2, 250);
            buzzer(note_d2, 250);
            buzzer(note_e2, 250);
            buzzer(note_f2, 250);
            buzzer(note_g2, 250);
            buzzer(note_a2, 250);
            buzzer(note_b2, 250);
            buzzer(note_c3, 250);
        }
        sendMsg = 0;



        if (i > 5000) {
            led_blink_s(magenta, 100, 1);
            i = 0;
        }
        i++;
        xtimer_usleep(100); // 100 us
    }






    // initialize ringbuffer for received packets
    packet_queue_init();




    //<just for debug>

//    GPIO_9		SW1
//    GPIO_10		SW2
//    GPIO_11		SW4
//    GPIO_12		nRF-IRQ
//

    //gpio_init_int(GPIO_9, GPIO_PULLDOWN, GPIO_FALLING, (void *)test, 0); //wird extern auf high gezogen
    //gpio_irq_enable(GPIO_9);


    // initialize radio driver


    //eeprom_init();




    // TODO get node address from eeprom
    //      if not available, go through algorithm to determine new address:
    //          1. generate randomly address of length 11 bit
    //          2. send PING with generated address
    //          3. wait X seconds for answer (ping_answer)
    //          4. if no answer received, accept address and save it
    //          5. if an answer is received, start over with 1.
    //              (or determine another address on another way)
    //

    // TODO read name from eeprom
    //eeprom_get_name();

    // TODO read configuration from eeprom
    cowconfig_init();
    eeprom_read_configuration((char*)cowconfig_data);

	while (1) {
        // we can go to sleep here
        // THIS DOES NOT WAKE UP!
        // (if needed, thread has to be woken up externally)
        thread_sleep();
    }

    return 0;
}





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

#include "led.h"
#include "switch.h"
#include "cowpacket.h"
#include "grazed_list.h"
#include "actor.h"
#include "sensor.h"
#include "packet_queue.h"
#include "radio_nrf.h"



void packet_received(cowpacket pkt) {
	led1_on();
    // TODO packet handling (switch led on/off, ping response, ...)
    switch (pkt.type) {
        case event:
            // only interpret this if address is my node's address
            if (pkt.addr == cowbus_address) {
                // TODO interpret message payload (led1 on, led2 color, ...)
            }
            else {
                // TODO go through programmed event handlers
            }
            break;

        case get_name:
            if (pkt.addr == cowbus_address) {
                // TODO send packet with our name
            }
            break;

        case ping:
            if (pkt.addr == cowbus_address) {
                radio_nrf_send_packet(cowbus_address, ping_answer, "", 0);
            }
            break;

        case set_name:
            if (pkt.addr == cowbus_address) {
                // TODO save name into eeprom and RAM
            }
            break;
    }
}


//<just for debug>
void test(void)
{
	led1_off();
}
//</just for debug>

int main(void)
{

	(RCC->AHBENR |= RCC_AHBENR_GPIOAEN);
	(RCC->AHBENR |= RCC_AHBENR_GPIOBEN);

    // initialize ringbuffer for received packets
    packet_queue_init();

    switch_init();
    led_init();


    //<just for debug>

//    GPIO_9		SW1
//    GPIO_10		SW2
//    GPIO_11		SW4
//    GPIO_12		nRF-IRQ

    gpio_init_int(GPIO_10, GPIO_PULLDOWN, GPIO_FALLING, (void *)test, 0); //wird extern auf high gezogen
    gpio_irq_enable(GPIO_10);

    led1_on();


    // </ust for debug>


    // initialize radio driver
    radio_nrf_init();
    radio_nrf_register_rx_callback(packet_received);


    // TODO get node address from eeprom
    //      if not available, go through algorithm to determine new address:
    //          1. generate randomly address of length 11 bit
    //          2. send PING with generated address
    //          3. wait X seconds for answer (ping_answer)
    //          4. if no answer received, accept address and save it
    //          5. if an answer is received, start over with 1.
    //              (or determine another address on another way)
    //




	while (1) {
        // we can go to sleep here
        // THIS DOES NOT WAKE UP!
        // (if needed, thread has to be woken up externally)
        thread_sleep();
    }

    return 0;
}





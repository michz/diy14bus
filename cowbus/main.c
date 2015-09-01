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
#include "periph/uart.h"

#include "board_uart0.h"

#include "led.h"
#include "switch.h"
#include "cowpacket.h"
#include "grazed_list.h"
#include "actor.h"
#include "sensor.h"
#include "packet_queue.h"
#include "radio_nrf.h"
#include "eeprom.h"

//#define MODULE_UART0


void packet_received(cowpacket pkt) {
	led1_off();
//    // TODO packet handling (switch led on/off, ping response, ...)
//    switch (pkt.type) {
//        case event:
//            // only interpret this if address is my node's address
//            if (pkt.addr == cowbus_address) {
//                // TODO interpret message payload (led1 on, led2 color, ...)
//            }
//            else {
//                // TODO go through programmed event handlers
//            }
//            break;
//
//        case get_name:
//            if (pkt.addr == cowbus_address) {
//                // TODO send packet with our name
//            }
//            break;
//
//        case ping:
//            if (pkt.addr == cowbus_address) {
//                radio_nrf_send_packet(cowbus_address, ping_answer, "", 0);
//            }
//            break;
//
//        case set_name:
//            if (pkt.addr == cowbus_address) {
//                // TODO save name into eeprom and RAM
//            }
//            break;
//    }
}


//<just for debug>
void test(void)
{

	led1_off();
	printf("test_uart.\n");

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


    board_uart0_init(); //uart_init wird von syscalls schon vorher aufgerufen - hoffentlich zumindest

    //<just for debug>

//    GPIO_9		SW1
//    GPIO_10		SW2
//    GPIO_11		SW4
//    GPIO_12		nRF-IRQ
//
//  Button 1 : GPIO(PORT_A, 15)
//  Button 2 : GPIO(PORT_B, 8)
//  Button 3 : GPIO(PORT_B, 9)
//  Button 4 : GPIO(PORT_B, 14)
//
//  nrf24l01p:
//  IRQ : GPIO(PORT_B, 0)
//  CSN : GPIO(PORT_B, 1)
//  CE  : GPIO(PORT_B, 2)
//  SCK : GPIO(PORT_A, 5)
//  MISO: GPIO(PORT_A, 6)
//  MOSI: GPIO(PORT_A, 7)

    gpio_init_int(GPIO_9, GPIO_PULLDOWN, GPIO_FALLING, (void *)test, 0); //wird extern auf high gezogen
    gpio_irq_enable(GPIO_9);

    led1_on();




    // initialize radio driver
    radio_nrf_init();


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



	while (1) {
        // we can go to sleep here
        // THIS DOES NOT WAKE UP!
        // (if needed, thread has to be woken up externally)
        thread_sleep();
    }

    return 0;
}





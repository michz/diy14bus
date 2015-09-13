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


/// @brief local in-memory representation of configuration rules of this node
cowconfig_rule cowconfig_data[COWCONFIG_COUNT];
int seq_no = 0xB;
uint16_t radio_addr = 1021;


//#define MODULE_UART0


void packet_received(cowpacket pkt) {
    led_blink_s(green, 100, 1);
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
	printf("test_uart.\n");

}
//</just for debug>

int main(void)
{
	(RCC->AHBENR |= RCC_AHBENR_GPIOAEN);
	(RCC->AHBENR |= RCC_AHBENR_GPIOBEN);

    led_init();
    while (true) {
        test();
        //led_blink_s(red, 100, 1);
        led_set_color(red);
        hwtimer_wait(HWTIMER_TICKS(1000 * 1000));
        led_set_color(green);
        hwtimer_wait(HWTIMER_TICKS(1000 * 1000));
        led_set_color(blue);
        hwtimer_wait(HWTIMER_TICKS(1000 * 1000));
        led_set_color(black);
        hwtimer_wait(HWTIMER_TICKS(1000 * 1000));
    }
    //uart_init();
    //board_uart0_init(); //uart_init wird von syscalls schon vorher aufgerufen - hoffentlich zumindest


    // initialize ringbuffer for received packets
    packet_queue_init();

    switch_init();



    //<just for debug>

//    GPIO_9		SW1
//    GPIO_10		SW2
//    GPIO_11		SW4
//    GPIO_12		nRF-IRQ
//

    gpio_init_int(GPIO_9, GPIO_PULLDOWN, GPIO_FALLING, (void *)test, 0); //wird extern auf high gezogen
    gpio_irq_enable(GPIO_9);


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





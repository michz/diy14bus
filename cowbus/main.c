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
#include "volatile_config.h"


/// @brief local in-memory representation of configuration rules of this node
int seq_no = 0xB;
uint16_t radio_addr = 1021;

int sendMsg = 0;


//#define MODULE_UART0

void packet_received(cowpacket pkt) {
    //led_blink_s(green, 100, 1);
    
    // TODO packet handling (switch led on/off, ping response, ...)
    // only interpret this if address is my node's address
    if (cowpacket_get_address(&pkt) == config_get_address()) {
        //led_blink_s(blue, 100, 1);
        // TODO interpret message payload (led1 on, led2 color, ...)
    }
    else {
        printf("value: %d\n", pkt.payload[0]);
        for (int i = 0; i < COWCONFIG_COUNT; ++i) {
            if (cowconfig_data[i].operation > 0 &&
                cowconfig_data[i].address == cowpacket_get_address(&pkt)) {

                if (
                    (cowconfig_data[i].operation == OP_ANY) ||
                    (cowconfig_data[i].operation == OP_LT && pkt.payload[0] < cowconfig_data[i].threshold_a) ||
                    (cowconfig_data[i].operation == OP_GT && pkt.payload[0] > cowconfig_data[i].threshold_a) ||
                    (cowconfig_data[i].operation == OP_LTE && pkt.payload[0] <= cowconfig_data[i].threshold_a) ||
                    (cowconfig_data[i].operation == OP_GTE && pkt.payload[0] >= cowconfig_data[i].threshold_a) ||
                    (cowconfig_data[i].operation == OP_EQ && pkt.payload[0] == cowconfig_data[i].threshold_a) ||
                    (cowconfig_data[i].operation == OP_NEQ && pkt.payload[0] != cowconfig_data[i].threshold_a) ||
                    (cowconfig_data[i].operation == OP_RANGE_GT_LT && 
                     (pkt.payload[0] > cowconfig_data[i].threshold_a &&
                      pkt.payload[0] < cowconfig_data[i].threshold_b)) ||
                    (cowconfig_data[i].operation == OP_RANGE_GTE_LTE && 
                     (pkt.payload[0] >= cowconfig_data[i].threshold_a &&
                      pkt.payload[0] <= cowconfig_data[i].threshold_b)) ||
                    (cowconfig_data[i].operation == OP_RANGE_GTE_LT && 
                     (pkt.payload[0] >= cowconfig_data[i].threshold_a &&
                      pkt.payload[0] < cowconfig_data[i].threshold_b)) ||
                    (cowconfig_data[i].operation == OP_RANGE_GT_LTE && 
                     (pkt.payload[0] > cowconfig_data[i].threshold_a &&
                      pkt.payload[0] <= cowconfig_data[i].threshold_b)) ||
                    (cowconfig_data[i].operation == OP_NOT_RANGE_GT_LT && 
                     !(pkt.payload[0] > cowconfig_data[i].threshold_a &&
                      pkt.payload[0] < cowconfig_data[i].threshold_b)) ||
                    (cowconfig_data[i].operation == OP_NOT_RANGE_GTE_LTE && 
                     !(pkt.payload[0] >= cowconfig_data[i].threshold_a &&
                      pkt.payload[0] <= cowconfig_data[i].threshold_b)) ||
                    (cowconfig_data[i].operation == OP_NOT_RANGE_GTE_LT && 
                     !(pkt.payload[0] >= cowconfig_data[i].threshold_a &&
                      pkt.payload[0] < cowconfig_data[i].threshold_b)) ||
                    (cowconfig_data[i].operation == OP_NOT_RANGE_GT_LTE && 
                     !(pkt.payload[0] > cowconfig_data[i].threshold_a &&
                      pkt.payload[0] <= cowconfig_data[i].threshold_b))
                        ) {
                            // MATCH! yeah!
                            
                            // do action
                            
                            switch (cowconfig_data[i].action) {
                                case 1:
                                    led_set_color(red);
                                    break;
                                case 2:
                                    led_set_color(green);
                                    break;
                                case 3:
                                    led_set_color(blue);
                                    break;
                                case 4:
                                    led_set_color(black);
                                    break;
                                case 5:
                                    sendMsg = -3;
                                    break;
                                default:
                                    //do nothing
                                    break;
                            }

                }
            }
        }
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
    sendMsg = 2;
}

void switch3(void)
{
	printf("switch 3 pressed.\n");
    sendMsg = 3;
}

void switch4(void)
{
	printf("switch 4 pressed.\n");
    sendMsg = 4;


    // emergency reboot
    if (switch3_get_state()) {
        printf("Pressed #3 and #4, reset!\n");
        xtimer_spin(1000);
        NVIC_SystemReset();                     // perform reset
    }
}

void watchdog_start(void) {
    IWDG->KR = 0xCCCC;
}

void watchdog_config(void) {
    IWDG->KR = 0x5555;

    IWDG->PR = 0x3;                     // prescaler /32
    while (!(IWDG->SR & IWDG_SR_PVU)) ; // wait for reload value update

    IWDG->RLR = 0xFFF;                  // max: 0xFFF
    while (!(IWDG->SR & IWDG_SR_RVU)) ; // wait for reload value update

    // these settings should result in a watchdog timeout of 4,0 seconds
    // (assuming the low speed clock has 32,768kHz)
}

void watchdog_reset(void) {
    IWDG->KR = 0xAAAA;
}

int main(void)
{
	//(RCC->AHBENR |= RCC_AHBENR_GPIOAEN);
	//(RCC->AHBENR |= RCC_AHBENR_GPIOBEN);

    printf("Booting up on CPUID 0x%lx\n", config_get_cpuid());


    switch1_set_isr(switch1);
    switch2_set_isr(switch2);
    switch3_set_isr(switch3);
    switch4_set_isr(switch4);

    cowconfig_init();

    eeprom_read_name(config_name);
    config_set_address(eeprom_get_addr());
    eeprom_read_configuration(cowconfig_data);

    printf("Node name: %s\n", config_name);
    printf("Node addr: %d\n", config_get_address());
    printf("Hello!\n");
    
    radio_nrf_init();
    cowmac_register_packet_handler(packet_received);

    // say we are up and running
    led_blink_s(magenta, 150, 1);
    led_blink_s(cyan, 150, 1);
    led_blink_s(orange, 150, 1);

    // now initalize watchdog
    watchdog_config();
    watchdog_start();
    watchdog_reset();

    //__IO uint32_t KR;   /*!< IWDG Key register,       Address offset: 0x00 */
    //__IO uint32_t PR;   /*!< IWDG Prescaler register, Address offset: 0x04 */
    //__IO uint32_t RLR;  /*!< IWDG Reload register,    Address offset: 0x08 */
    //__IO uint32_t SR;   /*!< IWDG Status register,    Address offset: 0x0C */
    //__IO uint32_t WINR; /*!< IWDG Window register,    Address offset: 0x10 */

    int i = 0;
	while (1) {
		if (sendMsg > 0) {
            cowpacket pkt;

            cowmac_init_packet_empty(&pkt, event);
            pkt.payload[0] = sendMsg;

            cowmac_send_packet(&pkt);

            // reset
		}
        else if (sendMsg == -2) {
            //uint16_t addr = eeprom_get_addr();
            //printf("addr from eeprom: %d\n", addr);
            printf("Temp: %s\n", temp_to_readable(temp_get()));
        }
        else if (sendMsg == -3) {
            buzzer(note_c2, 100);
            buzzer(note_e2, 100);
            buzzer(note_g2, 100);
            buzzer(note_d2, 100);
            buzzer(note_f2, 100);
            buzzer(note_b2, 100);
        }
        sendMsg = 0;



        if (i > 10000) {
            led_blink_s(white, 50, 1);
            i = 0;
        }
        i++;
        watchdog_reset();
        xtimer_usleep(100); // 100 us
    }






    // initialize ringbuffer for received packets
    packet_queue_init();


    // TODO get node address from eeprom
    //      if not available, go through algorithm to determine new address:
    //          1. generate random address (cpuid?)
    //          2. send PING with generated address
    //          3. wait X seconds for answer (ping_answer)
    //          4. if no answer received, accept address and save it
    //          5. if an answer is received, start over with 1.
    //              (or determine another address on another way)
    //

	//while (1) {
    //    // we can go to sleep here
    //    // THIS DOES NOT WAKE UP!
    //    // (if needed, thread has to be woken up externally)
    //    thread_sleep();
    //}

    return 0;
}





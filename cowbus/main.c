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


/// @brief local in-memory representation of configuration rules of this node
cowconfig_rule cowconfig_data[COWCONFIG_COUNT];
int seq_no = 0xB;
uint16_t radio_addr = 1021;

int sendMsg = 0;


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


void switch1(void)
{
	printf("switch 1 pressed.\n");
    sendMsg = 1;
}

void switch2(void)
{
	printf("switch 2 pressed.\n");
}

void switch3(void)
{
	printf("switch 3 pressed.\n");
}

void switch4(void)
{
	printf("switch 4 pressed.\n");
}

extern  nrf24l01p_t nrf24l01p_0;
int main(void)
{
	(RCC->AHBENR |= RCC_AHBENR_GPIOAEN);
	(RCC->AHBENR |= RCC_AHBENR_GPIOBEN);

    xtimer_init();
    led_init();
    switch_init();
    switch1_set_isr(switch1);
    switch2_set_isr(switch2);
    switch3_set_isr(switch3);
    switch4_set_isr(switch4);
    
    radio_nrf_init();
    radio_nrf_register_rx_callback(packet_received);



    int i = 0;
	while (1) {
		if (sendMsg > 0) {

            int r = 0;

            char tx_buf[NRF24L01P_MAX_DATA_LENGTH];
            memset(tx_buf, 0, sizeof(cowpacket)); // clear out data buffer

            /* fill TX buffer with sample data */
            cowpacket* cp = (cowpacket*)tx_buf;
            cp->version = 0;
            cp->seq_no  = seq_no;
            cp->ttl     = 5;
            //cowpacket_set_address(cp, radio_addr);
            cowpacket_set_address(cp, 0);
            //cowpacket_set_type(cp, event);
            cowpacket_set_type(cp, ping);
            cowpacket_set_is_fragment(cp, 0);

            for (int i = 0; i < sizeof(cp->payload); ++i) {
                cp->payload[i] = 48+i;
            }

            //cowpacket_generate_checksum(cp);

            if (seq_no > 30) { seq_no = 0; }
            else { seq_no++; }

            /* power on the device */
            r = nrf24l01p_on(&nrf24l01p_0);
            xtimer_usleep(DELAY_DATA_ON_AIR); // DEBUG: does not work without
            //printf("on: %i\n", r);
            /* setup device as transmitter */
            r = nrf24l01p_set_txmode(&nrf24l01p_0);
            //printf("txmode: %i\n", r);
            /* load data to transmit into device */
            r = nrf24l01p_preload(&nrf24l01p_0, tx_buf, NRF24L01P_MAX_DATA_LENGTH);
            //printf("preload: %i\n", r);
            /* trigger transmitting */
            nrf24l01p_transmit(&nrf24l01p_0);

            /* wait while data is pysically transmitted  */
            xtimer_usleep(2*DELAY_DATA_ON_AIR);

            r = nrf24l01p_get_status(&nrf24l01p_0);
            //printf("Status: %i\n", r);
            if (r & TX_DS) {
                printf("Sent Packet: %d\n", r);
            }
            /* setup device as receiver */
            nrf24l01p_set_rxmode(&nrf24l01p_0);

            // reset
            sendMsg = 0;
		}



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





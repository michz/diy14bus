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
    // TODO packet handling (switch led on/off, ping response, ...)
}

int main(void)
{
    // initialize ringbuffer for received packets
    packet_queue_init();

    switch_init();
    led_init();

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




	while(1) {
        // TODO
        // if everything works with interrupts, we could go to sleep here
    }

    return 0;
}

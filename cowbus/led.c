/**
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */

#include "board.h"
#include "cpu.h"

#include "led.h"

void led_init(void) {
    //TODO configure GPIOs
}

void led1_switch_state(bool on) {
    //TODO GPIO switch on / off
}

inline void led1_on(void) {
    led1_switch_state(false);
}

inline void led1_off(void) {
    led1_switch_state(false);
}

void led2_set_color(led_color color) {
    //TODO GPIO switch on / off
}


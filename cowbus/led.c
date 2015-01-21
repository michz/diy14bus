/**
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */

#include "board.h"
#include "cpu.h"
#include "periph/gpio.h"

#include "led.h"

void led_init(void) {

    //led1
    //GPIO_3    LED
    gpio_init_out(GPIO_3, GPIO_NOPULL); //set as output
    gpio_clear(GPIO_3); //set to low -> led off
    
    //led2: rgb //TODO
    //GPIO_0    RGB-LED
    //GPIO_1    RGB-LED
    //GPIO_2    RGB-LED
    
}

void led1_switch_state(bool on) {
    gpio_write(GPIO_3, (int)on); //should work, or is "if then else" differenciation for input value on necessary?
}

inline void led1_on(void) {
    led1_switch_state(true);
}

inline void led1_off(void) {
    led1_switch_state(false);
}

void led2_set_color(led_color color) {
    //TODO GPIO switch on / off
    

    
}


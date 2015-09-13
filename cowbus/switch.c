/**
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */

#include "board.h"
#include "cpu.h"
#include "periph/gpio.h"

#include "switch.h"

//three pull-up push buttons, internal pull-down resistor required!
//switch1: GPIO_0
//switch2: GPIO_6
//switch3: GPIO_7


// TODO ISR

void switch1_pressed(void) {
	printf("Switch 1 pressed.\n");
}
void switch2_pressed(void) {
	printf("Switch 2 pressed.\n");
}
void switch3_pressed(void) {
	printf("Switch 3 pressed.\n");
}
void switch4_pressed(void) {
	printf("Switch 4 pressed.\n");
}


void switch_init(void) {
    
    gpio_init_int(GPIO_SWITCH_1, GPIO_PULLDOWN, GPIO_RISING,
            (void *)switch1_pressed, 0);

    gpio_init_int(GPIO_SWITCH_2, GPIO_PULLDOWN, GPIO_RISING,
            (void *)switch2_pressed, 0);

    gpio_init_int(GPIO_SWITCH_3, GPIO_PULLDOWN, GPIO_RISING,
            (void *)switch3_pressed, 0);

    gpio_init_int(GPIO_SWITCH_4, GPIO_PULLDOWN, GPIO_RISING,
            (void *)switch4_pressed, 0);
    
    // TODO: still required?
    gpio_irq_enable(GPIO_SWITCH_1);
    gpio_irq_enable(GPIO_SWITCH_2);
    gpio_irq_enable(GPIO_SWITCH_3);
    gpio_irq_enable(GPIO_SWITCH_4);
}

bool switch1_get_state(void) {
    if(gpio_read(GPIO_SWITCH_1) > 0){
        return true;
    }
    else{
        return false;
    }
}

bool switch2_get_state(void) {
    if(gpio_read(GPIO_SWITCH_2) > 0){
        return true;
    }
    else{
        return false;
    }
}

bool switch3_get_state(void) {
    if(gpio_read(GPIO_SWITCH_3) > 0){
        return true;
    }
    else{
        return false;
    }
}

bool switch4_get_state(void) {
    if(gpio_read(GPIO_SWITCH_4) > 0){
        return true;
    }
    else{
        return false;
    }
}


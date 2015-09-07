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

void switch1_pressed(void);
void switch2_pressed(void);
void switch3_pressed(void);
void switch4_pressed(void);


void switch_init(void) {
    
    gpio_init_int(GPIO(PORT_A, 15), GPIO_PULLDOWN, GPIO_RISING,
            (void *)switch1_pressed, 0);

    gpio_init_int(GPIO(PORT_B, 8), GPIO_PULLDOWN, GPIO_RISING,
            (void *)switch2_pressed, 0);

    gpio_init_int(GPIO(PORT_B, 9), GPIO_PULLDOWN, GPIO_RISING,
            (void *)switch3_pressed, 0);

    gpio_init_int(GPIO(PORT_B, 14), GPIO_PULLDOWN, GPIO_RISING,
            (void *)switch4_pressed, 0);
    
    // TODO: still required?
    gpio_irq_enable(GPIO(PORT_A, 15));
    gpio_irq_enable(GPIO(PORT_B,  8));
    gpio_irq_enable(GPIO(PORT_B,  9));
    gpio_irq_enable(GPIO(PORT_B, 14));

}

bool switch1_get_state(void) {
    if(gpio_read(GPIO_0) > 0){
        return true;
    }
    else{
        return false;
    }
}

bool switch2_get_state(void) {
    if(gpio_read(GPIO_6) > 0){
        return true;
    }
    else{
        return false;
    }
}

bool switch3_get_state(void) {
    if(gpio_read(GPIO_7) > 0){
        return true;
    }
    else{
        return false;
    }
}

//TODO ISR

void switch1_pressed(void){}
void switch2_pressed(void){}
void switch3_pressed(void){}
void switch4_pressed(void){}

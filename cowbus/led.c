/**
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */

#include "board.h"
#include "cpu.h"
#include "periph/gpio.h"
#include "xtimer.h"

#include "led.h"



void led_init(void) {
    gpio_init(GPIO_LED_R, GPIO_DIR_OUT, GPIO_NOPULL);
    gpio_init(GPIO_LED_G, GPIO_DIR_OUT, GPIO_NOPULL);
    gpio_init(GPIO_LED_B, GPIO_DIR_OUT, GPIO_NOPULL);

    led_set_color(black);
}

void led_set_color(led_color color) {
    switch(color) {
        case black:
            GPIO_LED_OFF(GPIO_LED_R);
            GPIO_LED_OFF(GPIO_LED_G);
            GPIO_LED_OFF(GPIO_LED_B);
            break;
        case red:
            GPIO_LED_ON(GPIO_LED_R);
            GPIO_LED_OFF(GPIO_LED_G);
            GPIO_LED_OFF(GPIO_LED_B);
            break;
        case green:
            GPIO_LED_OFF(GPIO_LED_R);
            GPIO_LED_ON(GPIO_LED_G);
            GPIO_LED_OFF(GPIO_LED_B);
            break;
        case blue:
            GPIO_LED_OFF(GPIO_LED_R);
            GPIO_LED_OFF(GPIO_LED_G);
            GPIO_LED_ON(GPIO_LED_B);
            break;
        case orange:
            GPIO_LED_ON(GPIO_LED_R);
            GPIO_LED_ON(GPIO_LED_G);
            GPIO_LED_OFF(GPIO_LED_B);
            break;
        case cyan:
            GPIO_LED_OFF(GPIO_LED_R);
            GPIO_LED_ON(GPIO_LED_G);
            GPIO_LED_ON(GPIO_LED_B);
            break;
        case magenta:
            GPIO_LED_ON(GPIO_LED_R);
            GPIO_LED_OFF(GPIO_LED_G);
            GPIO_LED_ON(GPIO_LED_B);
            break;
        case white:
            GPIO_LED_ON(GPIO_LED_R);
            GPIO_LED_ON(GPIO_LED_G);
            GPIO_LED_ON(GPIO_LED_B);
            break;
    }
}

void led_blink(led_color color, uint16_t ms_on, uint16_t ms_off, uint8_t times) {
    for (uint8_t i = 0; i < times; ++i) {
        // set on
        led_set_color(color);

        // wait on
        xtimer_usleep(ms_on * 1000);

        // set off
        led_set_color(black);
        if (i < times - 1) { // not last iteration
            // wait after off
            xtimer_usleep(ms_off * 1000);
        }
    }
}

inline void led_blink_s(led_color color, uint16_t ms_on, uint8_t times) {
    led_blink(color, ms_on, ms_on, times);
}


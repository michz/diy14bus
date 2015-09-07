/**
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */

#include "board.h"
#include "cpu.h"
#include "periph/gpio.h"
#include "hwtimer.h"

#include "led.h"

#define LED_R   GPIO(PORT_B, 11)
#define LED_G   GPIO(PORT_B, 12)
#define LED_B   GPIO(PORT_B, 13)

#define LED_ON  gpio_set
#define LED_OFF gpio_clear


void led_init(void) {
    gpio_init(LED_R, GPIO_DIR_OUT, GPIO_NOPULL);
    gpio_init(LED_G, GPIO_DIR_OUT, GPIO_NOPULL);
    gpio_init(LED_B, GPIO_DIR_OUT, GPIO_NOPULL);
}

void led_set_color(led_color color) {
    switch(color) {
        case black:
            LED_OFF(LED_R);
            LED_OFF(LED_G);
            LED_OFF(LED_B);
            break;
        case red:
            LED_ON(LED_R);
            LED_OFF(LED_G);
            LED_OFF(LED_B);
            break;
        case green:
            LED_OFF(LED_R);
            LED_ON(LED_G);
            LED_OFF(LED_B);
            break;
        case blue:
            LED_OFF(LED_R);
            LED_OFF(LED_G);
            LED_ON(LED_B);
            break;
        case orange:
            LED_ON(LED_R);
            LED_ON(LED_G);
            LED_OFF(LED_B);
            break;
        case cyan:
            LED_OFF(LED_R);
            LED_ON(LED_G);
            LED_ON(LED_B);
            break;
        case magenta:
            LED_ON(LED_R);
            LED_OFF(LED_G);
            LED_ON(LED_B);
            break;
        case white:
            LED_ON(LED_R);
            LED_ON(LED_G);
            LED_ON(LED_B);
            break;
    }
}

void led_blink(led_color color, uint16_t ms_on, uint16_t ms_off, uint8_t times) {
    for (uint8_t i = 0; i < times; ++i) {
        // set on
        led_set_color(color);

        // wait on
        hwtimer_wait(HWTIMER_TICKS(ms_on * 1000));

        // set off
        led_set_color(black);
        if (i < times - 1) { // not last iteration
            // wait after off
            hwtimer_wait(HWTIMER_TICKS(ms_off * 1000));
        }
    }
}

inline void led_blink_s(led_color color, uint16_t ms_on, uint8_t times) {
    led_blink(color, ms_on, ms_on, times);
}


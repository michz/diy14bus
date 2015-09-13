/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-01
 * @file
 */


#include <stdint.h>
#include "buzzer.h"

#include "board.h"
#include "cpu.h"
#include "periph/gpio.h"
#include "xtimer.h"

void buzzer_init(void) {
    gpio_init(BUZZER_PIN, GPIO_DIR_OUT, GPIO_NOPULL);
}

void buzzer(uint16_t ms, uint8_t times) {
    for (uint8_t i = 0; i < times; ++i) {
        buzzer_on();
        xtimer_usleep(ms * 1000);
        buzzer_off();
        if (i < times - 1) {
            xtimer_usleep(ms * 1000);
        }
    }
}

static inline void buzzer_on(void) {
    gpio_clear(BUZZER_PIN);
}

static inline void buzzer_off(void) {
    gpio_set(BUZZER_PIN);
}



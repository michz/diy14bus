/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */


#ifndef LED_H
#define LED_H

typedef enum led_color {
    black   = 0x0,
    red     = 0x1,
    green   = 0x2,
    orange  = 0x3,
    blue    = 0x4,
    magenta = 0x5,
    cyan    = 0x6,
    white   = 0x7
} led_color;

/**
 * @brief   Initializes the LEDs
 */
void led_init(void);

/**
 * @brief   Switches the RGB LED on or off and sets color.
 * @param   col Color to be set
 */
void led_set_color(led_color color);

/**
 * @brief   Switches the RGB LED on and off the given number of times.
 * @param   col         Color to be set
 * @param   ms_on       Time in ms the LED should be on each time
 * @param   ms_off      Time in ms the LED should be off each time
 * @param   ms_times    How often the LED should be switched on
 */
void led_blink(led_color color, uint16_t ms_on, uint16_t ms_off, uint8_t times);

/**
 * @brief   Switches the RGB LED on and off the given number of times.
 * @param   col         Color to be set
 * @param   ms_on       Time in ms the LED should be on each time
 * @param   ms_times    How often the LED should be switched on
 */
void led_blink_s(led_color color, uint16_t ms_on, uint8_t times);

#endif // LED_H

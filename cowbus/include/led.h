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
 * @brief   Switches the first LED on or off.
 * @param   on  \b true for on
 */
void led1_switch_state(bool on);

/**
 * @brief   Switches the first LED on.
 */
void led1_on(void);

/**
 * @brief   Switches the first LED off.
 */
void led1_off(void);

/**
 * @brief   Switches the RGB LED on or off and sets color.
 * @param   col Color to be set
 */
void led2_set_color(led_color color);

#endif // LED_H

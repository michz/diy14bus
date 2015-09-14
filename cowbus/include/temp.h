/**
 * @file
 * @brief   Reading the temperature sensor on PERIPH subboard.
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-14
 */

#include "board.h"      // cowbus-one
#include "cpu.h"


#ifndef TEMP_H
#define TEMP_H


void temp_init(void);


/**
 * @brief   Returns the current measured temperature.
 *
 * @return  The temperature. First byte: Integer part of temperature, second: 0.5
 */
char* temp_get(void);

/**
 * @brief           Converts the given raw temperature to readable ASCII.
 * @para    raw     The raw temperature as read from sensor.
 *
 * This function converts the temperature to degree celsius in human
 * readable ASCII characters.
 *
 * @return          Null terminated string.
 */
char* temp_to_readable(char* raw);


#endif // TEMP_H


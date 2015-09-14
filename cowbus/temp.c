/**
 * @file
 * @brief   TODO
 *
 * TODO
 *
 * @author  Michael Zapf <%MAIL>
 * @date    2015-09-14
 *
 * Copyright (C) 2015 Michael Zapf <michael.zapf@fau.de>
 */

#include "temp.h"

#include <string.h>

#include "board.h"      // cowbus-one
#include "cpu.h"
#include "thread.h"
#include "xtimer.h"

#include "cowconfig.h"

#include "periph/i2c.h"
#include "periph/gpio.h"

// TODO implement shutdown and configuration functionality

#define TEMP_INT(x)     ((signed char)(x[0]))
#define TEMP_FRACT(x)   ((x[1] >> 7) & 0x1)

char temp_buffer_raw[2];
char temp_buffer_readable[7];

void temp_init(void) {
    i2c_init_master(I2C_0, I2C_SPEED_NORMAL);
    // no problem if already done by eeprom driver
}

char* temp_get(void) {
    // TEMP_I2C_ADDRESS
    memset(temp_buffer_raw, 0, sizeof(temp_buffer_raw));

    i2c_read_bytes(I2C_0, TEMP_I2C_ADDRESS, temp_buffer_raw, 2);
    
    return temp_buffer_raw;
}

char* temp_to_readable(char* raw) {
    memset(temp_buffer_readable, 0, sizeof(temp_buffer_readable));
    signed char int_part = TEMP_INT(raw);
    int n = 0;

    
    // TODO     I'm not sure about the following hack.
    // But without, the datasheet seems to be wrong.
    // 1111 1111 1 would give "-1,5", not "-0,5" as mentioned in the datasheet.

    // if negative, we must add one (see LM75 datasheet p. 7)
    // (1111 1111 means -0,5, not -1,5!)
    if (int_part >> 7) {
        int_part += 1;

        // but if it was "-0", then we have to add the '-' manually
        if (int_part == 0xff) {
            temp_buffer_readable[0] = '-';
            n++;
        }
    }

    n += sprintf(temp_buffer_readable+n, "%d", int_part);

    if (TEMP_FRACT(raw)) {
        temp_buffer_readable[n++] = ',';
        temp_buffer_readable[n++] = '5';
    }
    else {
        temp_buffer_readable[n++] = ',';
        temp_buffer_readable[n++] = '0';
    }
    return temp_buffer_readable;
}

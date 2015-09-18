/**
 * @file
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-14
 */

#include <string.h>

#include "eeprom.h"

#include "board.h"      // cowbus-one
#include "cpu.h"
#include "thread.h"
#include "xtimer.h"

#include "cowconfig.h"
#include "volatile_config.h"

#include "periph/i2c.h"
#include "periph/gpio.h"


#define EEPROM_GET_PAGE(x)  ((x >> 8) & 0x1)
#define EEPROM_GET_ADDR(x)  (x & 0xFF)

#define EEPROM_POS_NAME     (0)
#define EEPROM_LENGTH_NAME  (NAME_MAX_LENGTH)       // 20 ?

#define EEPROM_POS_ADDRESS      (24)
#define EEPROM_LENGTH_ADDRESS   (2)

#define EEPROM_POS_CONFIG       (32)
#define EEPROM_LENGTH_CONFIG    (COWCONFIG_COUNT * sizeof(cowconfig_rule))  // 64 ?


void eeprom_init(void) {
    i2c_init_master(I2C_0, I2C_SPEED_NORMAL);
}


char* eeprom_read_name(char* to) {
    char* buf = eeprom_read_bytes(to, EEPROM_POS_NAME, EEPROM_LENGTH_NAME);

    if (buf[0] < 32 || buf[0] > 122) {  // not usable character, assume NOT SET
        memcpy(buf, CONFIG_DEFAULT_NAME, EEPROM_LENGTH_NAME);
    }
    else {
        // reset "empty" eeprom bytes (default to 255) back to system default (0)
        for (int i = 0; i < EEPROM_LENGTH_NAME; ++i) {
            if (buf[i] == 255) buf[i] = 0;
            printf("%d ", (int)(buf[i]));
        }
        printf("\n");
    }
    return buf;
}


uint16_t eeprom_get_addr(void) {
    char buf[2];
    eeprom_read_bytes(buf, EEPROM_POS_ADDRESS, EEPROM_LENGTH_ADDRESS);

    uint16_t addr = 0;
    addr += buf[0] & 0xFF;
    addr += (buf[1] << 8);

    if (addr == 0xffff) { // not set in eeprom
        addr = config_get_cpuid() & 0xffff;
    }
    return addr;
}

void eeprom_read_configuration(void* to) {
    eeprom_read_bytes(to, EEPROM_POS_CONFIG, EEPROM_LENGTH_CONFIG);

    // reset "empty" eeprom bytes (default to 255) back to system default (0)
    cowconfig_rule* cowconfig_data = to;
    for (int i = 0; i < COWCONFIG_COUNT; ++i) {
        if (cowconfig_data[i].operation == 255) {
            memset(&(cowconfig_data[i]), 0, sizeof(cowconfig_rule));
        }
    }
}

void eeprom_set_name(char* new_name) {
    char buf[EEPROM_LENGTH_NAME];
    memset(buf, 0, EEPROM_LENGTH_NAME);             // clear stack memory
    memcpy(buf, new_name, strlen(new_name));        // name to buffer
    eeprom_write_bytes(new_name,                    // write buffer to eeprom
            EEPROM_POS_NAME, EEPROM_LENGTH_NAME);
}


void eeprom_set_addr(uint16_t addr) {
    char buf[2];

    buf[0] = addr & 0xFF;           // low byte
    buf[1] = (addr >> 8) & 0xFF;    // high byte

    eeprom_write_bytes(buf, EEPROM_POS_ADDRESS, EEPROM_LENGTH_ADDRESS);
}

void eeprom_write_configuration(void* from) {
    eeprom_write_bytes(from, EEPROM_POS_CONFIG, EEPROM_LENGTH_CONFIG);
}


char* eeprom_read_bytes(char* buf, int address, int n) {
    if (address >= EEPROM_SIZE) return 0;

    // ctrl should be:  0 1 0 1 0 X X (Page 0|1)    with x = don't care
    char ctrl = 0;
    char* ptr = buf;
    for (int i = 0; i < n; ++i) {
        ctrl |= (0xA << 3);
        ctrl |= EEPROM_GET_PAGE((address+i));

        i2c_acquire(I2C_0);
        i2c_read_regs(I2C_0, ctrl, EEPROM_GET_ADDR((address+i)), ptr++, 1);
        i2c_release(I2C_0);
    }

    return buf;
}


void eeprom_write_bytes(char* from, int address, int n) {
    if (address >= EEPROM_SIZE) return;

    // ctrl should be:  0 1 0 1 0 X X (Page 0|1)    with x = don't care
    char ctrl = 0;
    char* ptr = from;

    for (int i = 0; i < n; ++i) {
        ctrl |= (0xA << 3);
        ctrl |= EEPROM_GET_PAGE((address+i));

        i2c_acquire(I2C_0);
        i2c_write_regs(I2C_0, ctrl, EEPROM_GET_ADDR((address+i)), ptr++, 1);
        i2c_release(I2C_0);
        xtimer_usleep(WRITE_DELAY_US);  // wait one write cycle time
    }
}

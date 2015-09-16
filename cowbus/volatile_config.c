/**
 * @file
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-16
 *
 * Copyright (C) 2015 Michael Zapf <michael.zapf@fau.de>
 */

#include "volatile_config.h"
#include "cowmac.h"


uint16_t        cowmac_address = COWBUS_DEFAULT_ADDR;
char*           config_name = "unnamed-node              ";
cowconfig_rule  cowconfig_data[COWCONFIG_COUNT];

void config_set_name(char* name) {
    memset(config_name, 0, sizeof(config_name));
    memcpy(config_name, name, sizeof(config_name));
}

char* config_get_name(void) {
    return config_name;
}

void config_set_address(uint16_t addr) {
    cowmac_address = addr;
}

uint16_t config_get_address(void) {
    return cowmac_address;
}

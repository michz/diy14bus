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
#include "periph/cpuid.h"

uint16_t        cowmac_address = COWBUS_DEFAULT_ADDR;
char            config_name[] = CONFIG_DEFAULT_NAME;
cowconfig_rule  cowconfig_data[COWCONFIG_COUNT];
uint32_t        config_cpuid;

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

uint32_t config_get_cpuid(void) {
    cpuid_get(&config_cpuid);
    return config_cpuid;
}

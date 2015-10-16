/**
 * @file
 *
 * @brief   Holds non-persistent configuration.
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-16
 *
 * Copyright (C) 2015 Michael Zapf <michael.zapf@fau.de>
 */

#ifndef VOLATILE_CONFIG_H
#define VOLATILE_CONFIG_H

#include "cowmac.h"

/// @brief  Default address if not configured / auto detected
#define COWBUS_DEFAULT_ADDR     (0)

/// @brief  Default name for nodes that where not named before.
/// (Remember to make this at least as long as NAME_MAX_LENGTH !)
#define CONFIG_DEFAULT_NAME     "unnamed-node               "


extern char config_name[];


/**
 * @brief   TODO
 */
void config_set_name(char* name);

/**
 * @brief   TODO
 */
char* config_get_name(void);

/**
 * @brief   TODO
 */
uint16_t config_get_address(void);

/**
 * @brief   TODO
 */
void config_set_address(uint16_t addr);

/**
 * @brief   Reads out the unique(?) serial number of processor.
 */
uint32_t config_get_cpuid(void);

#endif /* !VOLATILE_CONFIG_H */

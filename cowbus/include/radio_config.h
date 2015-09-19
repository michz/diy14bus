/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @file
 */


#ifndef RADIO_CONFIG_H
#define RADIO_CONFIG_H

#include <stdint.h>

/// @brief Should be a 5 byte array
#define RADIO_ADDRESS       {0xe7, 0xe7, 0xe7, 0xe7, 0xe7}

/// @brief Should be in the range of [0; 124]
#define RADIO_RF_CHANNEL    (5)

/// @brief Should be one of DR_250KBS, DR_1MBS, DR_2MBS
#define DR_250KBS           (250)
#define DR_1MBS             (1000)
#define DR_2MBS             (2000)
//#define RADIO_DATARATE      (DR_250KBS)
#define RADIO_DATARATE      (DR_1MBS)
// TODO set various speeds in implementations
// TODO recalculate on-air-time in RIOT

#endif // RADIOCONFIG_H



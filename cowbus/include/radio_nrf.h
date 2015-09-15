/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  TODO
 * @file
 */


#ifndef RADIO_NRF_H
#define RADIO_NRF_H

#include "cowpacket.h"


/**
 * @brief   TODO
 */
void radio_nrf_init(void);


/**
 * @brief   TODO
 */
void radio_nrf_send_data(char* payload, unsigned short payload_length);


#endif // RADIO_NRF_H


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

extern unsigned short cowbus_address;

/**
 * @brief   TODO
 */
void radio_nrf_init(void);

/**
 * @brief   TODO
 */
void radio_nrf_register_rx_callback(void (recv_callback)(cowpacket)); //TODO

/**
 * @brief   TODO
 */
void radio_nrf_send_data(char* payload, unsigned short payload_length);

/**
 * @brief   TODO
 */
void radio_nrf_send_packet(unsigned short address, cowpacket_type type,         
                            char* payload, unsigned char payload_length);

/**
 * @brief   TODO
 */
void radio_nrf_backoff(void);

#endif // RADIO_NRF_H


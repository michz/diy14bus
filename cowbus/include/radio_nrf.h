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

#define RADIO_NRF_SPI           SPI_1
#define RADIO_NRF_PIN_CE        GPIO_6
#define RADIO_NRF_PIN_CS        GPIO_7
#define RADIO_NRF_PIN_IRQ       GPIO_12
#define RADIO_NRF_ADDR          {0xe7, 0xe7, 0xe7, 0xe7, 0xe7}
#define RADIO_NRF_CHANNEL       (5)

#define COWBUS_VERSION          (1)
#define COWBUS_DEFAULT_TTL      (5)
#define COWBUS_DEFAULT_ADDR     (99)

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


#endif // RADIO_NRF_H


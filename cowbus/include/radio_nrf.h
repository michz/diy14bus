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
#define RADIO_NRF_CHANNEL       5


/**
 * @brief   TODO
 */
void radio_nrf_init(void);

/**
 * @brief   TODO
 */
void radio_nrf_register_rx_callback(void); //TODO

/**
 * @brief   TODO
 */
void radio_nrf_send_packet(char* payload, uint8_t payload_length);


#endif // RADIO_NRF_H


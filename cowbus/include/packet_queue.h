/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  TODO
 * @file
 */


#ifndef PACKET_QUEUE_H
#define PACKET_QUEUE_H

#include "nrf24l01p_settings.h"

#include "cowpacket.h"

#define MAX_BUFFERED_IN_PACKETS         (8)
#define INCOMING_PACKETS_BUFFER_SIZE    (MAX_BUFFERED_IN_PACKETS * NRF24L01P_MAX_DATA_LENGTH)


/**
 * @brief   Initializes the packet queue.
 */
void packet_queue_init(void);

/**
 * @brief       Puts one packet into the queue.
 * @param   pkt cowpacket, that's content is copied into queue
 * @return      0 on error (queue full), positive number if successful
 */
int packet_queue_insert(cowpacket *pkt);

/**
 * @brief       Retrieves one packet from the queue.
 * @param   buf Memory the content of the buffer is copied into.
 * @return      0 on error (no packet in queue), 1 if copied successfully
 */
int packet_queue_get(cowpacket *buf);


#endif // PACKET_QUEUE_H

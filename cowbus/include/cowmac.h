/**
 * @file
 *
 * @brief   MAC layer for cowbus radio
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-15
 *
 * Copyright (C) 2015 Michael Zapf <michael.zapf@fau.de>
 */

#ifndef COWMAC_H
#define COWMAC_H


// cowbus includes
#include "cowpacket.h"
#include "cowconfig.h"
#include "radio_config.h"
#include "radio_nrf.h"
#include "volatile_config.h"

// RIOT includes
#include "kernel.h"
#include "board.h"
#include "cpu.h"
#include "thread.h"
#include "nrf24l01p.h"
#include "nrf24l01p_settings.h"
#include "xtimer.h"


// stdlib includes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/// @brief  Version of this cowbus packets
#define COWBUS_VERSION          (1)

/// @brief  Default time to live for packets
#define COWBUS_DEFAULT_TTL      (5)


/// @brief stack for working-thread  // TODO: stacksize anders wählen (?)
extern char cowmac_receiver_stack[THREAD_STACKSIZE_MAIN];

/// @brief Address of this node
extern uint16_t cowmac_address;



/**
 * @brief    Working thread waiting for incoming packets over the air.
 */
void *cowmac_receiver(void *arg);

/**
 * @brief       Returns a pseudo randomly generated number between min and max.
 * @param   min (Inclusive) lower border.
 * @param   max (Exclusive) upper border.
 *
 * @warning Only works reliable if cowmac_receiver thread was started before.
 */
uint32_t cowmac_get_random(uint32_t min, uint32_t max);


/**
 * @brief    TODO
 */
void cowmac_send_packet(cowpacket *pkt);


/**
 * @brief    Sends back an error message regarding a received packet.
 * @param   addr    Address field of received packet.
 * @param   seqno   Sequence number field of received packet.
 */
void cowmac_send_error(uint16_t addr, uint8_t seqno);


/**
 * @brief    Sends back an success+ack message regarding a received packet.
 * @param   addr    Address field of received packet.
 * @param   seqno   Sequence number field of received packet.
 */
void cowmac_send_ack(uint16_t addr, uint8_t seqno);


/**
 * @brief    TODO
 */
void cowmac_register_packet_handler(void (*fnc)(cowpacket));


/**
 * @brief   TODO
 */
int cowmac_init_packet_empty(cowpacket *pkt, cowpacket_type type);


/**
 * @brief    TODO
 */
int cowmac_init_packet(cowpacket *pkt,
        cowpacket_type type, char* payload, unsigned char payload_length);

/**
 * @brief    TODO
 */
void cowmac_backoff(void);


/**
 * @brief    TODO
 */
void cowmac_send_ping_answer(void);

/**
 * @brief    TODO
 */
void cowmac_send_name(void);

/**
 * @brief    TODO
 */
void cowmac_send_config(void);

/**
 * @brief    Returns \b true if the parameter equals the own cowbus address.
 */
bool cowmac_is_own_addr(uint16_t);


#endif /* !COWMAC_H */

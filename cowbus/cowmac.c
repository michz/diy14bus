/**
 * @file
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-15
 *
 * Copyright (C) 2015 Michael Zapf <michael.zapf@fau.de>
 */

#include "cowmac.h"
#include "eeprom.h"
#include "led.h"
#include "grazed_list.h"


char cowmac_receiver_stack[THREAD_STACKSIZE_MAIN];
void (*cb_pkt_recv)(cowpacket) = NULL;

/// @brief Current sequence number
static uint8_t c_seq_no = 1;

/// @brief Current backoff time
//static unsigned int c_backoff = 0;


extern nrf24l01p_t nrf24l01p_0;


/// @brief Increments and returns the sequence number counter
static inline uint8_t cowmac_next_seqno(void) {
    if (c_seq_no >= 254) c_seq_no = 0;
    return ++c_seq_no;
}

inline uint32_t cowmac_get_random(uint32_t min, uint32_t max) {
    return min + rand() % (max-min);
}

void cowmac_send_error(uint16_t addr, uint8_t seqno) {
    cowpacket pkt;
    cowmac_init_packet_empty(&pkt, error);
    cowpacket_set_address(&pkt, addr);
    pkt.seq_no = seqno;
    cowmac_send_packet(&pkt);
}

void cowmac_send_ack(uint16_t addr, uint8_t seqno) {
    cowpacket pkt;
    cowmac_init_packet_empty(&pkt, ack);
    cowpacket_set_address(&pkt, addr);
    pkt.seq_no = seqno;
    cowmac_send_packet(&pkt);
}

void cowmac_send_packet(cowpacket *pkt) {
    int8_t rssi = radio_get_rssi();
    while (rssi != 0) {
        cowmac_backoff();
        rssi = radio_get_rssi();
    }

    // TODO: CSMA/CA

    radio_nrf_send_data((char*)pkt, sizeof(cowpacket));
}

void cowmac_register_packet_handler(void (*fnc)(cowpacket)){
    cb_pkt_recv = fnc;
}

int cowmac_init_packet_empty(cowpacket *pkt, cowpacket_type type) {

    memset(pkt, 0, sizeof(cowpacket));
    pkt->version    = COWBUS_VERSION;
    pkt->seq_no     = cowmac_next_seqno();
    pkt->ttl        = COWBUS_DEFAULT_TTL;
    cowpacket_set_address(pkt, cowmac_address);
    cowpacket_set_type(pkt, type);
    cowpacket_set_is_fragment(pkt, 0);

    return 1;
}

int cowmac_init_packet(cowpacket *pkt,
        cowpacket_type type, char* payload, unsigned char payload_length) {

    cowmac_init_packet_empty(pkt, type);

    if (payload_length > PAYLOAD_MAX_LENGTH) return 0;
    memcpy(pkt->payload, payload, payload_length);
    return 1;
}

void cowmac_packet_handler(void) {
}

void *cowmac_receiver(void *arg) {
    // initialize RNG for CSMA/CA backoff
    srand(xtimer_now() * config_get_cpuid());

    msg_t msg_q[1];
    msg_init_queue(msg_q, 1);
    unsigned int pid = thread_getpid();
    char rx_buf[NRF24L01P_MAX_DATA_LENGTH];

    nrf24l01p_register(&nrf24l01p_0, &pid);

    msg_t m;

    printf("nrf24l01p_rx_handler started.\n");
    while (msg_receive(&m)) {
        printf("nrf24l01p_rx_handler got a message: \n");

        switch (m.type) {
            case RCV_PKT_NRF24L01P:
                printf("Received packet. %d\n", inISR());

                // CE low
                nrf24l01p_stop((nrf24l01p_t *)m.content.ptr);

                // read payload
                nrf24l01p_read_payload((nrf24l01p_t *)m.content.ptr, rx_buf, NRF24L01P_MAX_DATA_LENGTH);

                // flush rx fifo
                nrf24l01p_flush_rx_fifo((nrf24l01p_t *)m.content.ptr);

                // CE high
                nrf24l01p_start((nrf24l01p_t *)m.content.ptr);

                // TODO check if correct cowpacket (especially version!)
                cowpacket p;
                memcpy(&p, rx_buf, NRF24L01P_MAX_DATA_LENGTH);

                uint16_t addr = cowpacket_get_address(&p);
                uint8_t type = cowpacket_get_type(&p);
                printf("Received addr: %d; type: %d\n", addr, type);

                // check grazed list
                int grazed = grazed_add(p.seq_no, addr);
                if (grazed > 0) break;

                // check if own address or broadcast ping
                if (type == event)  {
                    if (cb_pkt_recv != NULL) {
                        cb_pkt_recv(p);
                    }
                }
                else if (addr == cowmac_address || (addr == 0 && type == ping)) {
                    if (type == ping) {        // PING request
                        // send ping answer
                        cowmac_send_ping_answer();
                    }
                    else if (type == get_name) {
                        // send name answer
                        cowmac_send_name();
                    }
                    else if (type == set_name) {
                        // SET_NAME request
                        config_set_name((char*)(p.payload));

                        // send name answer
                        cowmac_send_name();

                        // write to eeprom
                        eeprom_set_name(config_get_name());
                    }
                    else if (type == configure) {
                        cowconfig_packet* ccp = (cowconfig_packet*)p.payload;

                        switch(ccp->method) {
                            case CCPM_LIST:
                                cowmac_send_config();
                                cowconfig_dump();
                                break;
                            case CCPM_ADD: {
                                int i = cowconfig_add(&(ccp->rule));
                                if (i < 0) { // error, perhaps too much rules?
                                    cowmac_send_error(addr, p.seq_no);
                                }
                                else {
                                    printf("Added rule #%d.\n", i);
                                    cowmac_send_ack(addr, p.seq_no);
                                    eeprom_write_configuration(cowconfig_data);
                                }
                                cowconfig_dump();
                                break;
                            }
                            case CCPM_DELETE_ALL:
                                cowconfig_delete_all();
                                printf("Deleted all rules.\n");
                                cowmac_send_ack(addr, p.seq_no);
                                eeprom_write_configuration(cowconfig_data);
                                cowconfig_dump();
                                break;
                            case CCPM_DELETE_ONE:
                                cowconfig_delete_one(ccp->id);
                                cowmac_send_ack(addr, p.seq_no);
                                eeprom_write_configuration(cowconfig_data);
                                cowconfig_dump();
                                break;
                            case CCPM_DELETE_ADDR:
                                cowconfig_delete_addr((ccp->raw[0] << 8) + ccp->raw[1]);
                                cowmac_send_ack(addr, p.seq_no);
                                eeprom_write_configuration(cowconfig_data);
                                cowconfig_dump();
                                break;
                        }
                    }
                }

                // now broadcast again if needed
                if (!cowmac_is_own_addr(addr)) {
                    if (p.ttl < 1) break; // abort if TTL is zero

                    p.ttl -= 1;
                    cowmac_send_packet(&p);
                }

                break;
            default:
                break;
        }
    }

    return NULL;
}

void cowmac_send_ping_answer(void) {
    cowpacket pkt;
    cowmac_init_packet_empty(&pkt, ping_answer);
    PACKET_COPY(config_get_name(), pkt.payload);
    cowmac_send_packet(&pkt);
}

void cowmac_send_name(void) {
    cowpacket pkt;
    cowmac_init_packet_empty(&pkt, get_name);
    PACKET_COPY(config_get_name(), pkt.payload);
    cowmac_send_packet(&pkt);
}


void cowmac_backoff(void) {
    // TODO real implementation
    xtimer_usleep(2 * cowmac_get_random(1, 50) * DELAY_DATA_ON_AIR);
    
    
    //if (c_backoff == 0) {
    //    c_backoff = 165 + rand() % 660; // from 1 to 5 packets
    //    // TODO test if this calculation is correct
    //}
    //xtimer_usleep(c_backoff);
    //c_backoff = 0;
}

void cowmac_send_config(void) {
    for (int i = 0; i < COWCONFIG_COUNT; ++i) {
        if (cowconfig_data[i].operation > 0) {
            cowpacket cp;
            cowmac_init_packet_empty(&cp, configure);

            cowconfig_packet* ccp = (cowconfig_packet*)(cp.payload);
            ccp->id = i;
            ccp->method = CCPM_ANSWER_LIST;
            memcpy(ccp->raw, &(cowconfig_data[i]), sizeof(cowconfig_rule));

            //printf("Send configure packet: \n");
            //printf("v: %d\n", cp->version);
            //printf("s: %d\n", cp->seq_no);
            //printf("tt:%d\n", cp->ttl);
            //printf("a: %d\n", cp->addr);
            //for (int i = 0; i < sizeof(cowpacket); i++) {
            //    printf("%d\n", ((char*)cp)[i]);
            //}
            //printf("\n");

            cowmac_send_packet(&cp);

            printf("sending configuration ... %d ...\n", i);
        }
    }
}


bool cowmac_is_own_addr(uint16_t addr) {
    return (addr == cowmac_address);
}


/*
* Some notes:
* According to nrf24l01+ datasheet, a packet is not larger than 329 bit.
* So the transmission of one packet at 2Mbps should not take longer than
*  164.5µs (or 0.1645ms).
 */

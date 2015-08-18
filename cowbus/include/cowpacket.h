/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @file
 */


#ifndef COWPACKET_H
#define COWPACKET_H

#include <stdint.h>
#define PAYLOAD_MAX_LENGTH      (26)
#define PACKET_COPY(from,to)    (memcpy(to, from, PAYLOAD_MAX_LENGTH))

typedef enum cowpacket_type {
    undefined   = 0,    ///< reserved!
    event       = 1,    ///< normal bus event
    program     = 2,    ///< map action of actor to given sensor event (addr+event)
    get_name    = 3,    ///< get name of device with given addr
    get_state   = 4,    ///< get current state of sensor (data) or actor (if stateful)
    get_config  = 5,    ///< get config of actor (event mapping)
    ping        = 6,    ///< ask if there is somebody out there with the given address
    ping_answer = 7,    ///< ping answer saying "I am ADDR"
    set_name    = 8,    ///< set the name of the current node
    configure   = 9     ///< configuration mode
} cowpacket_type;

typedef struct cowpacket {
    unsigned int version            : 3;
    unsigned int seq_no             : 5;
    unsigned int ttl                : 8;
    unsigned int addr               : 11;
    cowpacket_type type             : 4;
    unsigned int is_fragment        : 1;
    unsigned char payload[PAYLOAD_MAX_LENGTH];
    unsigned char checksum[2];
} cowpacket;

static inline void cowpacket_generate_checksum(cowpacket* p) {
    uint16_t r = 0;
    p->checksum[0] = 0;
    p->checksum[1] = 0;

    char* buf = (char*)p;
    for (unsigned int i = 0; i < sizeof(cowpacket); ++i) {
        r += buf[i];
    }

    p->checksum[1] = r >> 8;    // high byte
    p->checksum[0] = r;         // low byte
}

static inline int cowpacket_check_checksum(cowpacket* p) {
    uint16_t checksum = p->checksum[0] + (p->checksum[1] << 8);
    uint16_t r = 0;
    p->checksum[1] = 0;
    p->checksum[0] = 0;

    char* buf = (char*)p;
    for (unsigned int i = 0; i < sizeof(cowpacket); ++i) {
        r += buf[i];
    }

    // restore checksum into packet data
    p->checksum[1] = checksum >> 8;    // high byte
    p->checksum[0] = checksum;         // low byte

    if (checksum == r) return 1;
    return 0;
}

#endif // COWPACKET_H

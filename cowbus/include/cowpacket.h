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
#include <stdio.h>
#include <string.h>

/// @brief  Sets the maximum payload size.
#define PAYLOAD_MAX_LENGTH      (26)

/// @brief  Copy PAYLOAD_MAX_LENGTH bytes from one pointer to another.
#define PACKET_COPY(from,to)    (memcpy(to, from, PAYLOAD_MAX_LENGTH))

/// @brief  Possible types of packets sent over the air.
typedef enum cowpacket_type {
    undefined   = 0,    ///< reserved!
    event       = 1,    ///< normal bus event
    get_name    = 2,    ///< get name of device with given addr
    get_state   = 3,    ///< get current state of sensor (data) or actor (if stateful)
    ping        = 4,    ///< ask if there is somebody out there with the given address
    ping_answer = 5,    ///< ping answer saying "I am ADDR"
    set_name    = 6,    ///< set the name of the current node
    configure   = 7     ///< configuration mode
} cowpacket_type;


/// @brief Technically describes a cowpacket.
typedef struct cowpacket {
    /// @brief Protocol version.
    uint8_t version;

    /// @brief Sequence number of packet.
    uint8_t seq_no;

    /// @brief Low byte of address
    uint8_t addr_low;
    
    /// @brief High byte of address
    uint8_t addr_high;

    /// @brief Time to live (in hops).
    uint8_t ttl;

    /**
     * @brief Contains the type of the packet and if this is a fragment.
     *
     * Bits 0..3: type (range: 0..15, see \ref cowpacket_type ) \n
     * Bit 4: 0 for "is not a fragment" and 1 for "is a fragment" \n
     * Bits 5..7: reserved for future use
     */
    uint8_t type_isfragment_res;

    /// @brief Application payload
    uint8_t payload[PAYLOAD_MAX_LENGTH];
} cowpacket;

// old packet structure
//typedef struct cowpacket {
//    unsigned int version            : 3;
//    unsigned int seq_no             : 5;
//    unsigned int ttl                : 8;
//    unsigned int addr               : 11;
//    cowpacket_type type             : 4;
//    unsigned int is_fragment        : 1;
//    unsigned char payload[PAYLOAD_MAX_LENGTH];
//    unsigned char checksum[2];
//} cowpacket;


static inline uint16_t cowpacket_get_address(cowpacket* p) {
    uint16_t addr = 0;
    addr += (p->addr_low & 0xFF);
    addr += ((((uint16_t)p->addr_high) << 8) & 0xFFFF);
    return addr;
}
static inline uint16_t cowpacket_set_address(cowpacket* p, uint16_t addr) {
    p->addr_low     = (addr & 0xFF);
    p->addr_high    = ((addr >> 8) & 0xFF);
    return addr;
}

static inline cowpacket_type cowpacket_get_type(cowpacket* p) {
    return (cowpacket_type)(p->type_isfragment_res & 0xF);
}
static inline cowpacket_type cowpacket_set_type(cowpacket* p, cowpacket_type type) {
    uint8_t t               = (type & 0xF);
    p->type_isfragment_res  = t;
    return (cowpacket_type)t;
}

static inline uint8_t cowpacket_set_is_fragment(cowpacket* p, uint8_t is_fragment) {
    if (is_fragment) {
        p->type_isfragment_res |= (1 >> 4);
    }
    else {
        p->type_isfragment_res &= ~(1 >> 4);
    }
    return is_fragment;
}

static inline uint8_t cowpacket_get_is_fragment(cowpacket* p) {
    return ((p->type_isfragment_res >> 4) & 0x1);
}

static inline void cowpacket_dump(cowpacket *pkt) {
    printf("cowpacket dump:\n");
    for (int i = 0; i < 32; ++i) {
        printf("%d ", ((char*)&pkt)[i]);
    }
    printf("\n\n");
}

//static inline void cowpacket_generate_checksum(cowpacket* p) {
//    uint16_t r = 0;
//    p->checksum[0] = 0;
//    p->checksum[1] = 0;
//
//    char* buf = (char*)p;
//    for (unsigned int i = 0; i < sizeof(cowpacket); ++i) {
//        r += buf[i];
//    }
//
//    p->checksum[1] = r >> 8;    // high byte
//    p->checksum[0] = r;         // low byte
//}
//
//static inline int cowpacket_check_checksum(cowpacket* p) {
//    uint16_t checksum = p->checksum[0] + (p->checksum[1] << 8);
//    uint16_t r = 0;
//    p->checksum[1] = 0;
//    p->checksum[0] = 0;
//
//    char* buf = (char*)p;
//    for (unsigned int i = 0; i < sizeof(cowpacket); ++i) {
//        r += buf[i];
//    }
//
//    // restore checksum into packet data
//    p->checksum[1] = checksum >> 8;    // high byte
//    p->checksum[0] = checksum;         // low byte
//
//    if (checksum == r) return 1;
//    return 0;
//}

#endif // COWPACKET_H

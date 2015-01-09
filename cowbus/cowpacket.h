/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  TODO
 * @file
 */


#ifndef COWPACKET_H
#define COWPACKET_H

typedef enum cowpacket_type {
    undefined   = 0,    ///< reserved!
    event       = 1,    ///< normal bus event
    program     = 2,    ///< map action of actor to given sensor event (addr+event)
    get_name    = 3,    ///< get name of device with given addr
    get_state   = 4,    ///< get current state of sensor (data) or actor (if stateful)
} cowpacket_type;

// TODO definiere Paketstruktur
typedef struct cowpacket {
    unsigned int seq_no             : 5;
    unsigned int ttl                : 8;
    unsigned int addr               : 11;
    cowpacket_type type             : 4;
    unsigned int is_fragment        : 1;
    unsigned int reserved           : 3;
    unsigned char payload[26];
    unsigned char checksum[2];
} cowpacket;

#endif // COWPACKET_H

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

#define PAYLOAD_MAX_LENGTH  (26)


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

#endif // COWPACKET_H

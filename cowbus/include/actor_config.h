/**
 * @brief   TODO
 *
 * TODO
 *
 * Uses eeprom functions to read and write the persistant configuration.
 *
 *
 * @author  TODO
 * @file
 */


#ifdef NODE_IS_ACTOR

#ifndef ACTOR_CONFIG_H
#define ACTOR_CONFIG_H

#include "cowpacket.h"


typedef struct actor_mapping_entry {
    unsigned int addr               : 11;
    unsigned int length             : 5;  ///< max length of data field is <32
    char payload[PAYLOAD_MAX_LENGTH];
    unsigned int length_mapped      : 8;
    char mapped_to[PAYLOAD_MAX_LENGTH];
} actor_mapping_entry;
// current size: PAYLOAD_MAX_LENGTH=32, so: 16+32+32 = 70
// In eeprom, this can be compressed by using only length*8 bit for the payload
// and length_mapped*8 bit for mapped_to.
//
// TODO Has somebody an idea how to compress this even in RAM?


// TODO Which datastructure should be used in RAM to hold a list of mappings?
//      Array with static number of entries? Linked list (on heap?)?



#endif // ACTOR_CONFIG_H
#endif // NODE_IS_ACTOR

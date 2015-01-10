#include "ringbuffer.h"

#include "packet_queue.h"

static ringbuffer_t rb;
static char         queue_buffer[INCOMING_PACKETS_BUFFER_SIZE];


void packet_queue_init(void) {
    ringbuffer_init(&rb, queue_buffer, sizeof(queue_buffer));
}

inline int packet_queue_insert(cowpacket *pkt) {
    // TODO synchronize (mutex?)
    return ringbuffer_add(&rb, (const char*)pkt, NRF24L01P_MAX_DATA_LENGTH); 
}

int packet_queue_get(cowpacket *buf) {
    // TODO synchronize (mutex?)
    return ringbuffer_get(&rb, (char*)buf, NRF24L01P_MAX_DATA_LENGTH);
}


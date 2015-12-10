/**
 * @file
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-10-16
 *
 * Copyright (C) 2015 Michael Zapf <michael.zapf@fau.de>
 */

#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "grazed_list.h"

#define GRAZED_MAX      (32)
char    grazed_raw[GRAZED_MAX * sizeof(grazed_header)];

grazedBuffer grazed_buf;
grazedBuffer *grazed;

void grazed_init(void) {
    grazed_buf.size     = GRAZED_MAX + 1;
    grazed_buf.start    = 0;
    grazed_buf.end      = 0;
    grazed_buf.elems    = (void*)grazed_raw;
    memset(grazed_raw, 0, grazed_buf.size * sizeof(grazed_header));

    grazed = &grazed_buf;
}

int grazed_add(uint8_t seq_nr, uint16_t addr) {
    // check if element inside, otherwise add
    if (grazed_is(seq_nr, addr)) return 1;

    grazed_header g = {seq_nr, addr};
    bufferWrite(grazed, g);
    return 0;
}

// TODO call it somewhere for example once per two seconds or so
void grazed_delete_cyclic(void) {
    grazed_header g;
    if (!isBufferEmpty(grazed)) {
        bufferRead(grazed, g);
        (void)(g); // suppress GCC warning (-Werror=unused-but-set-variable)
        // DBG("%d\t: %d\n", g.seq_no, g.addr);      // DEBUG
    }
}

int grazed_is(uint8_t seq_nr, uint16_t addr) {
    int i = 0;
    int end = (grazed->start < grazed->end) ? grazed->end : grazed->end + GRAZED_MAX + 1;

    for (i = grazed->start; i < end; ++i) {
        DBG("%d %d\n", i, end);
        grazed_header l = grazed->elems[i % grazed->size];
        if (l.seq_no == seq_nr && l.addr == addr) return 1;
    }
    return 0;
}

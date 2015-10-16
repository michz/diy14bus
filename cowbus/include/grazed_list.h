/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  TODO
 * @file
 */


#ifndef GRAZED_LIST_H
#define GRAZED_LIST_H

#include <stdint.h>

// TODO definiere Liste der zuletzt empfangenen Pakete
// - sollte sowas wie FIFO-Liste sein
// - könnte wie Ringpuffer realisiert sein:
//   Ein Schreibzeiger merkt sich, wo als nächstes geschrieben wird.
//   Gelesen werden wenn dann ja eh immer alle im Kreis.
// - Leere Einträge sollten 0 sein.
//
// - grazed_delete_cyclic() wird regelmäßig aufgerufen
//   und löscht zyklisch die Einträge, damit keiner zu alt ist.

typedef struct grazed_header {
    uint8_t seq_no;
    uint16_t addr;
} grazed_header;


/**
 * Checks if packet is already on list.
 * If no, return 0, otherwise return nonzero value.
 * If table full, oldest entry is overwritten.
 * If new entry is the one that would be deleted next by grazed_delete_cyclic()
 * move this pointer one entry ahead.
 *
 * @param   seq_nr  sequence number of current packet
 * @param   addr    sender/receiver/sensor/actor address of packet
 */
int grazed_add(uint8_t seq_nr, uint16_t addr); //TODO

/**
 * Clears the next entry.
 * This is used to assure that no entry is too old.
 */
void grazed_delete_cyclic(void); // TODO


#endif // GRAZED_LIST_H

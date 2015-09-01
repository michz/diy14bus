#include "board.h"      // cowbus-one
#include "cpu.h"        // stmf0 ?
#include "thread.h"
#include "hwtimer.h"
#include "eeprom.h"

#include "periph/i2c.h"
#include "periph/gpio.h"

char eeprom_name_buffer[NAME_MAX_LENGTH];



void eeprom_init(void){
    i2c_init_master(I2C_0, I2C_SPEED_NORMAL);
}


char eeprom_get_status(void){
    return 42;
}


char* eeprom_get_name(void){
    return "42"; //TODO ;)
}


int eeprom_get_addr(void){
    return 42; //TODO ;)
}


void eeprom_set_name(char* new_name){

}


void eeprom_set_addr(int addr){

}


void eeprom_read(uint16_t addr, char* buf, uint16_t n) {
    // TODO read n bytes from addr into buffer
}

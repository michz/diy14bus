#include "eeprom.h"

char eeprom_name_buffer[NAME_MAX_LENGTH];


void eeprom_init(){
	//SPI_0 is already configured by radio_nrf_init(void)
	// -> make sure it is called before.
	
	//TODO: config GPIOS
		// GPIO_4	ROM-CS
		// GPIO_5	ROM-HOLD

}



char* eeprom_get_name(void){



}


int eeprom_get_addr(void){



}



void eeprom_set_name(char* new_name){




}


void eeprom_set_addr(int addr){



}




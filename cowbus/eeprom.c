#include "board.h"      // cowbus-one
#include "cpu.h"        // stmf0 ?
#include "thread.h"
#include "hwtimer.h"
#include "eeprom.h"

#include "periph/spi.h"
#include "periph/gpio.h"

char eeprom_name_buffer[NAME_MAX_LENGTH];


// READ 0000 0011 Read data from memory array beginning at selected address
// WRITE 0000 0010 Write data to memory array beginning at selected address
// WRDI 0000 0100 Reset the write enable latch (disable write operations)
// WREN 0000 0110 Set the write enable latch (enable write operations)
// RDSR 0000 0101 Read STATUS register
// WRSR 0000 0001 Write STATUS register

void eeprom_init(void){
	//SPI_0 is already configured by radio_nrf_init(void)
	// -> make sure it is called before.
	

	// GPIO_4	ROM-CS
	// GPIO_5	ROM-HOLD //not needed because of cs -> set high

	gpio_init_out(GPIO_4, GPIO_NOPULL);
	gpio_set(GPIO_4);

	gpio_init_out(GPIO_5, GPIO_NOPULL);
	gpio_set(GPIO_5);

}


char eeprom_get_status(void){
	char ret = 0;

	//drive CS low
	gpio_clear(GPIO_4);

	//Write 0x05
	spi_transfer_byte(SPI_0, 0x05, &ret);

	//read 8 bit
	spi_transfer_byte(SPI_0, 0x00, &ret);

	//drive CS high
	gpio_set(GPIO_4);

	return ret;
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




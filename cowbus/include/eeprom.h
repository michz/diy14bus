/**
* @brief   TODO
 *
 * TODO
 *
 * This file refers to "cowbit-characters" which by now means characters
 * that are encoded with a length of 5 bit.
 *
 * @author  TODO
 * @file
 */


#ifndef EEPROM_H
#define EEPROM_H

#define EEPROM_SIZE             ((4*1024)/8)
#define NAME_MAX_LENGTH         (20)


extern char eeprom_name_buffer[NAME_MAX_LENGTH];


void eeprom_init(void);


/**
 * Returns the name of this device.
 *
 * @return  A pointer to the eeprom_name_buffer char array.
 */
char* eeprom_get_name(void);

/**
 * Returns the address of this device.
 *
 * @return  The address.
 */
uint16_t eeprom_get_addr(void);

/**
 * Reads the configuration from eeprom.
 */
void eeprom_read_configuration(char* to);



/**
 * Set the name of this device.
 * @param   new_name    The new name array.
 */
void eeprom_set_name(char* new_name);

/**
 * Set the address of this device.
 * @param   addr    The new address.
 */
void eeprom_set_addr(uint16_t addr);

/**
 * Writes the configuration to eeprom.
 */
void eeprom_write_configuration(char* from);

/**
 * @brief           Reads n bytes from eeprom.
 * @param   buf     Buffer (in RAM) where the bytes should be written.
 * @param   address Absolute address in eeprom that should be read.
 * @para,   n       Number of bytes that should be read.
 *
 * This function calculates automatically the page number and offset address.
 */
char* eeprom_read_bytes(char* buf, int address, int n);


/**
 * @brief           Writes n bytes to eeprom.
 * @param   buf     Buffer (in RAM) where the bytes should be read from.
 * @param   address Absolute address in eeprom that should be written.
 * @para,   n       Number of bytes that should be written.
 *
 * This function calculates automatically the page number and offset address.
 */
void eeprom_write_bytes(char* from, int address, int n);


#endif // EEPROM_H

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


#define NAME_MAX_LENGTH         (20)    ///< coded as cowbit
#define NAME_ASCII_MAX_LENGTH   (32)    ///< ((NAME_MAX_LENGTH / 5) * 8)
// This means, that the name can currently have 32 characters,
// that can be represented by 20 bytes if it is coded in cowbit,
// or alternatively by 32 byte encoded as 8-bit-ASCII.


extern char eeprom_name_buffer[NAME_MAX_LENGTH];


/**
 * Returns the name of this device coded as cowbit-characters.
 *
 * @return  A pointer to the eeprom_name_buffer char array.
 */
char* eeprom_get_name(void);


/**
 * Set the ame of this device.
 * @param   new_name    The new name array coded as cowbit-characters.
 */
void eeprom_set_name(char* new_name);


#endif // EEPROM_H

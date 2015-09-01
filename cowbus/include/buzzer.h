/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-09-01
 * @file
 */


#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_PIN  GPIO(PORT_A, 4)

/**
 * @brief   Initializes the Buzzer
 */
void buzzer_init(void);

/**
 * @brief   
 */
void buzzer(uint16_t ms, uint8_t times);

/**
 * @brief   Switch on the buzzer.
 */
static inline void buzzer_on(void);

/**
 * @brief   Switch off the buzzer.
 */
static inline void buzzer_off(void);


#endif // BUZZER_H

/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-01-20
 * @file
 */


#ifndef SWITCH_H
#define SWITCH_H


/**
 * @brief   Initializes the Switches
 */
void switch_init(void);

/**
 * @brief   Get the state of switch #1.
 * @return  \b true for "pressed", \b false otherwise
 */
bool switch1_get_state(void);

/**
 * @brief   Get the state of switch #2.
 * @return  \b true for "pressed", \b false otherwise
 */
bool switch2_get_state(void);

/**
 * @brief   Get the state of switch #3.
 * @return  \b true for "pressed", \b false otherwise
 */
bool switch3_get_state(void);

/**
 * @brief   Get the state of switch #4.
 * @return  \b true for "pressed", \b false otherwise
 */
bool switch4_get_state(void);


#endif // SWITCH_H

/**
 * @file
 *
 * @brief   Simple debug redefinition.
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @date    2015-12-09
 *
 * Copyright (C) 2015 Michael Zapf <michael.zapf@fau.de>
 */

#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG
#define DBG             printf
#else
static inline int do_nothing_really_dummy(char* f, ...) { return 0; }
#define DBG             do_nothing_really_dummy
#endif



#endif /* !DEBUG_H */

#include "board.h" // stm32f3discovery
//#include "stm32f3"
#include "hwtimer.h"

int main(void)
{
    while(1) {
        LD0_OFF;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD0_ON;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD1_ON;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD1_OFF;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD2_ON;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD2_OFF;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD3_ON;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD3_OFF;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
    }
    return 0;
}

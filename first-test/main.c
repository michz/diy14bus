#include "board.h" // stm32f3discovery
//#include "stm32f3"
#include "hwtimer.h"

int main(void)
{
    while(1) {
        LD3_ON;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD3_OFF;
        LD10_ON;
        hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        LD10_OFF;
    }
    return 0;
}

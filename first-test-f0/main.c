#include "board.h" // stm32f3discovery
#include "cpu.h"
#include "periph/spi.h"
#include "hwtimer.h"
#include "cc110x_legacy.h"


int main(void)
{


	//transceiver_pid = thread_create(transceiver_stack, TRANSCEIVER_STACK_SIZE, PRIORITY_MAIN - 3, CREATE_STACKTEST, run, NULL, "Transceiver");

	//cc110x_init(transceiver_pid);



        //LD3_ON;
        //hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
        //LD3_OFF;
        //LD4_ON;
        //hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        //LD4_OFF;

    return 0;

}

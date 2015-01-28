#include "board.h" // stm32f3discovery
//#include "stm32f3"
#include "hwtimer.h"
#include "periph/gpio.h"

#define LEEEEEDS 0

int main(void)
{
  GPIO_0_CLKEN();
  gpio_init_out(GPIO_0, GPIO_NOPULL);
  GPIO_1_CLKEN();
  gpio_init_out(GPIO_1, GPIO_NOPULL);
  GPIO_2_CLKEN();
  gpio_init_out(GPIO_2, GPIO_NOPULL);
  GPIO_3_CLKEN();
  gpio_init_out(GPIO_3, GPIO_NOPULL);

  GPIO_9_CLKEN();
  gpio_init_in(GPIO_9, GPIO_PULLDOWN);
  GPIO_10_CLKEN();
  gpio_init_in(GPIO_10, GPIO_PULLDOWN);
  GPIO_11_CLKEN();
  gpio_init_in(GPIO_11, GPIO_PULLDOWN);

      gpio_set(GPIO_3);

      gpio_clear(GPIO_1);
      hwtimer_wait(HWTIMER_TICKS(500 * 1000));
      gpio_set(GPIO_0);
      gpio_set(GPIO_1);
      gpio_set(GPIO_2);

    while(1) {
      #if LEEEEDS
      gpio_clear(GPIO_1);
      hwtimer_wait(HWTIMER_TICKS(500 * 1000));

      gpio_clear(GPIO_0);
      hwtimer_wait(HWTIMER_TICKS(500 * 1000));
      gpio_clear(GPIO_2);
      hwtimer_wait(HWTIMER_TICKS(500 * 1000));
      gpio_set(GPIO_0);
      gpio_set(GPIO_1);
      gpio_set(GPIO_2);
      #endif

     if (gpio_read(GPIO_9))
      {
        gpio_clear(GPIO_0);
      }
      else
        {
          gpio_set(GPIO_0);
        }

        if (gpio_read(GPIO_10))
          {
            gpio_clear(GPIO_1);
          }
          else
            {
              gpio_set(GPIO_1);
            }
            
            if (gpio_read(GPIO_11))
              {
                gpio_clear(GPIO_2);
              }
              else
                {
                  gpio_set(GPIO_2);
                }
    }
    return 0;
}

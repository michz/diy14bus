#include "board.h" // stm32f3discovery
#include "cpu.h"
#include "periph/spi.h"
#include "hwtimer.h"


#define 	TEST_WAIT	500


int main(void)
{

	if(spi_init_master(SPI_0, SPI_CONF_FIRST_RISING, SPI_SPEED_100KHZ) != 0){
		while(1) LD3_ON; //nix mehr machen

	}
	LD4_ON;

	uint8_t mirwors = 0;

    while(1) {
		for(uint8_t i = 0; i<30; i++){

			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}

			hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));

			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}

			hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
		}

		if(spi_transfer_byte(SPI_0, 0xF0, mirwors) != 0){
			while(1) LD3_ON; //nix mehr machen
		}
		if(spi_transfer_byte(SPI_0, 0xF0, mirwors) != 0){
			while(1) LD3_ON; //nix mehr machen
		}
		if(spi_transfer_byte(SPI_0, 0xF0, mirwors) != 0){
			while(1) LD3_ON; //nix mehr machen
		}


		for(uint8_t i = 0; i<30; i++){

			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}

			hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));

			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x7F, mirwors) != 0){
				while(1) LD3_ON; //nix mehr machen
			}

			hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
		}

		if(spi_transfer_byte(SPI_0, 0xF0, mirwors) != 0){
			while(1) LD3_ON; //nix mehr machen
		}
		if(spi_transfer_byte(SPI_0, 0xF0, mirwors) != 0){
			while(1) LD3_ON; //nix mehr machen
		}
		if(spi_transfer_byte(SPI_0, 0xF0, mirwors) != 0){
			while(1) LD3_ON; //nix mehr machen
		}


        //LD3_ON;
        //hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
        //LD3_OFF;
        //LD4_ON;
        //hwtimer_wait(HWTIMER_TICKS(500 * 1000));
        //LD4_OFF;
    }
    return 0;
}

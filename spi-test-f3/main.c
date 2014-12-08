#include "board.h" // stm32f3discovery
#include "cpu.h"
#include "periph/spi.h"
#include "hwtimer.h"


//dies ist eine kleine Testanwendung für meine LPD8896 LED-Leiste.
// und funktioniert sogar!


#define 	TEST_WAIT	10

int main(void)
{

	//noetig? Nein, LE nicht notwendig fuer SPI-Konfiguration.
    //GPIOA->MODER &= ~(2 << (2 * 4));           /* set pin to output mode */
    //GPIOA->MODER |= (1 << (2 * 4));
    //GPIOA->OTYPER &= ~(1 << 4);                /* set to push-pull configuration */
    //GPIOA->OSPEEDR |= (3 << (2 * 4));          /* set to high speed */
    //GPIOA->PUPDR &= ~(3 << (2 * 4));           /* configure push-pull resistors */
    //GPIOA->PUPDR |= (0b00 << (2 * 4));
    //GPIOA->ODR &= ~(1 << 4);                   /* set pin to low signal */


	if(spi_init_master(SPI_0, SPI_CONF_FIRST_RISING, SPI_SPEED_1MHZ) != 0){
		while(1) LD3_ON; //nix mehr machen

	}

	char blubb = 0;
	char *mirwors = &blubb; //null und NULL wollte er nicht, daher halt umstaendlich

    while(1) {
		for(uint8_t i = 0; i<30; i++){
			
			//blau
			if(spi_transfer_byte(SPI_0, 0x8f, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}

			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}

			hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));

			//gruen
			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x8f, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}

			hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
		}

		for(uint16_t i=((60+31)/32); i>0; i--) {
			if(spi_transfer_byte(SPI_0, 0x00, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
		}


		for(uint8_t i = 0; i<30; i++){

			//dunkel
			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}

			hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));

			//rot
			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x8f, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
			if(spi_transfer_byte(SPI_0, 0x80, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}

			hwtimer_wait(HWTIMER_TICKS(TEST_WAIT * 1000));
		}


		for(uint16_t i=((60+31)/32); i>0; i--) {
			if(spi_transfer_byte(SPI_0, 0x00, mirwors) != 1){
				while(1) LD3_ON; //nix mehr machen
			}
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

cowbus general demonstration firmware
=====================================



# currently used board: cowbus-one


folgendes ist wo anders sicher besser aufgehoben, aber wo?

# pin configuration

## GPIOs

GPIO_0		RGB-LED
GPIO_1		RGB-LED
GPIO_2		RGB-LED
GPIO_3		LED
GPIO_4		ROM-CS
GPIO_5		ROM-HOLD
GPIO_6		nRF-CE
GPIO_7		nRF-CSN
GPIO_8
GPIO_9		SW1
GPIO_10		SW2
GPIO_11		SW4
GPIO_12		nRF-IRQ


Pins auf Board:

PA0		out		RGB-LED
PA1		out		RGB-LED
PA2		out		RGB-LED
PA3		out		LED
PA4
PA5		out		SPI-CLK  -> "SPI_0"
PA6		in		SPI-MISO -> "SPI_0"
PA7		out		SPI-MOSI -> "SPI_0"
PA8
PA9		out		UART_TX
PA10	in		UART_RX
PA11
PA11
PA12
PA13
PA14
PA15

PB0		i?o		nRF-IRQ//TODO
PB1		i?o		nRF-CSN
PB2		in		nRF-CE //TODO
PB3
PB4		in		SW1
PB5		in		SW2
PB6
PB7
PB8		in		SW4//TODO
PB9
PB10	out		ROM-CS
PB11	out		ROM-HOLD
PB12
PB13	out		BUZZER
PB14
PB15

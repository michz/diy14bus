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
GPIO_4
GPIO_5
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
PA5		out		SPI-CLK
PA6		in		SPI-MISO
PA7		out		SPI-MOSI
PA8
PA9		out		UART_TX
PA10	in		UART_RX
PA11
PA11
PA12
PA13
PA14
PA15

PB0		i?o		nRF-CE
PB1		i?o		nRF-CSN
PB2		in		nRF-IRQ
PB3
PB4		in		SW1
PB5		in		SW2
PB6		in		SW4
PB7
PB8
PB9
PB10	out		ROM_CS
PB11	out		ROM_HOLD
PB12
PB13	out		BUZZER
PB14
PB15

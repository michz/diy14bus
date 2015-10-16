cowbus general prototyping firmware
===================================

# currently used board: cowbus-protoboard


# Temperature sensor I2C address: (MSB)   1 0 0 1 0 0 0   (LSB)



# pin configuration

## GPIOs


GPIO_0		GPIO(PORT_A, 15)    SW-1
GPIO_1		GPIO(PORT_B, 3)     
GPIO_2		GPIO(PORT_B, 4)     
GPIO_3		GPIO(PORT_B, 5)     
GPIO_4		GPIO(PORT_B, 6)     I2C-SCL
GPIO_5		GPIO(PORT_B, 7)     I2C-SDA
GPIO_6		GPIO(PORT_B, 8)     SW-2
GPIO_7		GPIO(PORT_B, 9)     SW-3
GPIO_8      GPIO(PORT_B, 10)    
GPIO_9		GPIO(PORT_B, 11)    LED-R
GPIO_10		GPIO(PORT_B, 12)    LED-G
GPIO_11		GPIO(PORT_B, 13)    LED-B
GPIO_12		GPIO(PORT_B, 14)    SW-4
GPIO_13		GPIO(PORT_A, 0)     
GPIO_14		GPIO(PORT_A, 1)     
GPIO_15		GPIO(PORT_A, 2)     
GPIO_16		GPIO(PORT_A, 3)     
GPIO_17		GPIO(PORT_A, 4)     BUZ


            GPIO(PORT_B, 0)     nRF-IRQ
            GPIO(PORT_B, 1)     nRF-CSN
            GPIO(PORT_B, 2)     nRF-CE
            GPIO(PORT_A, 5)     nRF-SCK
            GPIO(PORT_A, 6)     nRF-MISO
            GPIO(PORT_A, 7)     nRF-MOSI
           
// DO NOT USE:
            GPIO(PORT_A, 13)    SWDIO
            GPIO(PORT_A, 14)    SWCLK


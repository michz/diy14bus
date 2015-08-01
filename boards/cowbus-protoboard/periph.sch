EESchema Schematic File Version 2
LIBS:cowbus-protoboard-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS: STM32F030C8T6
LIBS:nrf24l01plus-module
LIBS:i2c
LIBS:led_rgb_reichelt
LIBS:ts5204
LIBS:cowbus-protoboard-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title "cowbus protoboard"
Date "2015-07-15"
Rev "0.9"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SW_PUSH SW1
U 1 1 55A693A0
P 1350 2550
F 0 "SW1" H 1500 2660 50  0000 C CNN
F 1 "SW1" H 1350 2470 50  0000 C CNN
F 2 "lib:Button_SMD_Schurter_LSG" H 1350 2550 60  0001 C CNN
F 3 "" H 1350 2550 60  0000 C CNN
	1    1350 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1350 1000 1350 2250
$Comp
L +3V3 #PWR051
U 1 1 55A697D8
P 1350 1000
F 0 "#PWR051" H 1350 850 50  0001 C CNN
F 1 "+3V3" H 1350 1140 50  0000 C CNN
F 2 "" H 1350 1000 60  0000 C CNN
F 3 "" H 1350 1000 60  0000 C CNN
	1    1350 1000
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 55A69A3C
P 1950 2550
F 0 "SW2" H 2100 2660 50  0000 C CNN
F 1 "SW2" H 1950 2470 50  0000 C CNN
F 2 "lib:Button_SMD_Schurter_LSG" H 1950 2550 60  0001 C CNN
F 3 "" H 1950 2550 60  0000 C CNN
	1    1950 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1950 1000 1950 2250
$Comp
L +3V3 #PWR052
U 1 1 55A69A43
P 1950 1000
F 0 "#PWR052" H 1950 850 50  0001 C CNN
F 1 "+3V3" H 1950 1140 50  0000 C CNN
F 2 "" H 1950 1000 60  0000 C CNN
F 3 "" H 1950 1000 60  0000 C CNN
	1    1950 1000
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 55A69AC6
P 2500 2550
F 0 "SW3" H 2650 2660 50  0000 C CNN
F 1 "SW3" H 2500 2470 50  0000 C CNN
F 2 "lib:Button_SMD_Schurter_LSG" H 2500 2550 60  0001 C CNN
F 3 "" H 2500 2550 60  0000 C CNN
	1    2500 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2500 1000 2500 2250
$Comp
L +3V3 #PWR053
U 1 1 55A69ACD
P 2500 1000
F 0 "#PWR053" H 2500 850 50  0001 C CNN
F 1 "+3V3" H 2500 1140 50  0000 C CNN
F 2 "" H 2500 1000 60  0000 C CNN
F 3 "" H 2500 1000 60  0000 C CNN
	1    2500 1000
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW4
U 1 1 55A69ADA
P 3100 2550
F 0 "SW4" H 3250 2660 50  0000 C CNN
F 1 "SW4" H 3100 2470 50  0000 C CNN
F 2 "lib:Button_SMD_Schurter_LSG" H 3100 2550 60  0001 C CNN
F 3 "" H 3100 2550 60  0000 C CNN
	1    3100 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3100 1000 3100 2250
$Comp
L +3V3 #PWR054
U 1 1 55A69AE1
P 3100 1000
F 0 "#PWR054" H 3100 850 50  0001 C CNN
F 1 "+3V3" H 3100 1140 50  0000 C CNN
F 2 "" H 3100 1000 60  0000 C CNN
F 3 "" H 3100 1000 60  0000 C CNN
	1    3100 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 2850 1350 3100
Wire Wire Line
	1950 2850 1950 3300
Wire Wire Line
	2500 2850 2500 3500
Wire Wire Line
	3100 2850 3100 3700
Wire Wire Line
	1350 3100 1200 3100
Wire Wire Line
	1950 3300 1200 3300
Wire Wire Line
	2500 3500 1200 3500
Wire Wire Line
	3100 3700 1200 3700
Text HLabel 1200 3100 0    60   Input ~ 0
SW_1
Text HLabel 1200 3300 0    60   Input ~ 0
SW_2
Text HLabel 1200 3500 0    60   Input ~ 0
SW_3
Text HLabel 1200 3700 0    60   Input ~ 0
SW_4
$Comp
L +3V3 #PWR055
U 1 1 55A6A1D5
P 3850 1000
F 0 "#PWR055" H 3850 850 50  0001 C CNN
F 1 "+3V3" H 3850 1140 50  0000 C CNN
F 2 "" H 3850 1000 60  0000 C CNN
F 3 "" H 3850 1000 60  0000 C CNN
	1    3850 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2850 3850 4000
Wire Wire Line
	3850 4000 1200 4000
Wire Wire Line
	4050 2850 4050 4200
Wire Wire Line
	4050 4200 1200 4200
Wire Wire Line
	4250 2850 4250 4400
Wire Wire Line
	4250 4400 1200 4400
Text HLabel 1200 4000 0    60   Input ~ 0
LED_R
Text HLabel 1200 4200 0    60   Input ~ 0
LED_G
Text HLabel 1200 4400 0    60   Input ~ 0
LED_B
Text Notes 1250 4300 0    79   ~ 0
TODO: Verifizieren, ob LED-Pinbelegung \nmit ausgewählter (TODO!) übereinstimmt
$Comp
L CONN_01X02 P4
U 1 1 55A7DA4B
P 5100 2600
F 0 "P4" H 5100 2750 50  0000 C CNN
F 1 "BUZ" V 5200 2600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 5100 2600 60  0001 C CNN
F 3 "" H 5100 2600 60  0000 C CNN
	1    5100 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2550 4900 2550
Wire Wire Line
	4750 2550 4750 1000
$Comp
L +3V3 #PWR056
U 1 1 55A7DC62
P 4750 1000
F 0 "#PWR056" H 4750 850 50  0001 C CNN
F 1 "+3V3" H 4750 1140 50  0000 C CNN
F 2 "" H 4750 1000 60  0000 C CNN
F 3 "" H 4750 1000 60  0000 C CNN
	1    4750 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2650 4750 2650
Wire Wire Line
	4750 2650 4750 4700
Wire Wire Line
	4750 4700 1200 4700
Text HLabel 1200 4700 0    79   Input ~ 0
BUZ
Wire Wire Line
	7050 2500 6900 2500
Wire Wire Line
	7050 2600 6900 2600
$Comp
L GND #PWR057
U 1 1 55A7545F
P 7450 5350
F 0 "#PWR057" H 7450 5100 50  0001 C CNN
F 1 "GND" H 7450 5200 50  0000 C CNN
F 2 "" H 7450 5350 60  0000 C CNN
F 3 "" H 7450 5350 60  0000 C CNN
	1    7450 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3100 7450 5350
$Comp
L +3V3 #PWR058
U 1 1 55A75598
P 7450 1000
F 0 "#PWR058" H 7450 850 50  0001 C CNN
F 1 "+3V3" H 7450 1140 50  0000 C CNN
F 2 "" H 7450 1000 60  0000 C CNN
F 3 "" H 7450 1000 60  0000 C CNN
	1    7450 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2300 7450 1000
$Comp
L C C11
U 1 1 55A7575C
P 6050 2700
F 0 "C11" H 6075 2800 50  0000 L CNN
F 1 "100n" H 6075 2600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6088 2550 30  0001 C CNN
F 3 "" H 6050 2700 60  0000 C CNN
	1    6050 2700
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR059
U 1 1 55A7583B
P 6050 1000
F 0 "#PWR059" H 6050 850 50  0001 C CNN
F 1 "+3V3" H 6050 1140 50  0000 C CNN
F 2 "" H 6050 1000 60  0000 C CNN
F 3 "" H 6050 1000 60  0000 C CNN
	1    6050 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1000 6050 2550
$Comp
L GND #PWR060
U 1 1 55A7591A
P 6050 5350
F 0 "#PWR060" H 6050 5100 50  0001 C CNN
F 1 "GND" H 6050 5200 50  0000 C CNN
F 2 "" H 6050 5350 60  0000 C CNN
F 3 "" H 6050 5350 60  0000 C CNN
	1    6050 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 2850 6050 5350
$Comp
L GND #PWR061
U 1 1 55A75AB9
P 8050 5350
F 0 "#PWR061" H 8050 5100 50  0001 C CNN
F 1 "GND" H 8050 5200 50  0000 C CNN
F 2 "" H 8050 5350 60  0000 C CNN
F 3 "" H 8050 5350 60  0000 C CNN
	1    8050 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 2500 8050 5350
Wire Wire Line
	8050 2500 7850 2500
Wire Wire Line
	7850 2600 8050 2600
Connection ~ 8050 2600
Wire Wire Line
	7850 2700 8050 2700
Connection ~ 8050 2700
Wire Wire Line
	7050 2900 6550 2900
Wire Wire Line
	6550 2900 6550 1850
$Comp
L R R3
U 1 1 55A75DAC
P 6550 1700
F 0 "R3" V 6630 1700 50  0000 C CNN
F 1 "100k" V 6550 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6480 1700 30  0001 C CNN
F 3 "" H 6550 1700 30  0000 C CNN
	1    6550 1700
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR062
U 1 1 55A75DDC
P 6550 1000
F 0 "#PWR062" H 6550 850 50  0001 C CNN
F 1 "+3V3" H 6550 1140 50  0000 C CNN
F 2 "" H 6550 1000 60  0000 C CNN
F 3 "" H 6550 1000 60  0000 C CNN
	1    6550 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 1550 6550 1000
Text HLabel 6900 2500 0    60   Input ~ 0
SCL
Text HLabel 6900 2600 0    60   Input ~ 0
SDA
$Comp
L CONN_01X05 P5
U 1 1 55A96376
P 9550 3150
F 0 "P5" H 9550 3450 50  0000 C CNN
F 1 "USART_DEBUG" V 9650 3150 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05" H 9550 3150 60  0001 C CNN
F 3 "" H 9550 3150 60  0000 C CNN
	1    9550 3150
	-1   0    0    1   
$EndComp
NoConn ~ 9750 3350
NoConn ~ 9750 2950
Wire Wire Line
	9750 3050 10150 3050
Wire Wire Line
	9750 3150 10150 3150
Wire Wire Line
	9750 3250 9950 3250
Wire Wire Line
	9950 3250 9950 5350
$Comp
L GND #PWR063
U 1 1 55A968F0
P 9950 5350
F 0 "#PWR063" H 9950 5100 50  0001 C CNN
F 1 "GND" H 9950 5200 50  0000 C CNN
F 2 "" H 9950 5350 60  0000 C CNN
F 3 "" H 9950 5350 60  0000 C CNN
	1    9950 5350
	1    0    0    -1  
$EndComp
Text HLabel 10150 3050 2    79   Input ~ 0
RX
Text HLabel 10150 3150 2    79   Input ~ 0
TX
Text Notes 9250 3350 2    60   ~ 0
Belegung\nUSART-\nUSB-Adapter:\n\n3V3\nTXD\nRXD\nGND\n+5V
$Comp
L LM75AD U5
U 1 1 55BB9F38
P 7450 2700
F 0 "U5" H 7450 2700 60  0000 C CNN
F 1 "LM75AD" H 7700 3050 60  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 7450 2700 60  0000 C CNN
F 3 "" H 7450 2700 60  0000 C CNN
	1    7450 2700
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR064
U 1 1 55BBE42A
P 4050 1000
F 0 "#PWR064" H 4050 850 50  0001 C CNN
F 1 "+3V3" H 4050 1140 50  0000 C CNN
F 2 "" H 4050 1000 60  0000 C CNN
F 3 "" H 4050 1000 60  0000 C CNN
	1    4050 1000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR065
U 1 1 55BBE453
P 4250 1000
F 0 "#PWR065" H 4250 850 50  0001 C CNN
F 1 "+3V3" H 4250 1140 50  0000 C CNN
F 2 "" H 4250 1000 60  0000 C CNN
F 3 "" H 4250 1000 60  0000 C CNN
	1    4250 1000
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 55BBE474
P 3850 1700
F 0 "R4" V 3930 1700 50  0000 C CNN
F 1 "150" V 3850 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3780 1700 30  0001 C CNN
F 3 "" H 3850 1700 30  0000 C CNN
	1    3850 1700
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 55BBE4DE
P 4050 1700
F 0 "R5" V 4130 1700 50  0000 C CNN
F 1 "150" V 4050 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3980 1700 30  0001 C CNN
F 3 "" H 4050 1700 30  0000 C CNN
	1    4050 1700
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 55BBE526
P 4250 1700
F 0 "R6" V 4330 1700 50  0000 C CNN
F 1 "150" V 4250 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4180 1700 30  0001 C CNN
F 3 "" H 4250 1700 30  0000 C CNN
	1    4250 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1550 3850 1000
Wire Wire Line
	4050 1000 4050 1550
Wire Wire Line
	4250 1550 4250 1000
Wire Wire Line
	3850 2450 3850 1850
Wire Wire Line
	4050 1850 4050 2450
Wire Wire Line
	4250 2450 4250 1850
$Comp
L LED_RGB_reichelt D1
U 1 1 55BB7526
P 4050 2650
F 0 "D1" H 4050 3075 50  0000 C CNN
F 1 "LED_RGB_reichelt" H 4050 3000 50  0000 C CNN
F 2 "LEDs:LED_RGB_PLLC-6" V 3650 2650 50  0000 C CNN
F 3 "" H 4050 2600 50  0000 C CNN
	1    4050 2650
	0    -1   -1   0   
$EndComp
$EndSCHEMATC

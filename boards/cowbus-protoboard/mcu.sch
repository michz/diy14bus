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
Sheet 2 6
Title "cowbus protoboard"
Date "2015-07-15"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32F030C8T6 U1
U 1 1 55A4F1CE
P 7750 3300
F 0 "U1" H 6250 5200 60  0000 C CNN
F 1 "STM32F030C8T6" H 9000 1400 60  0000 C CNN
F 2 "Housings_QFP:LQFP-48_7x7mm_Pitch0.5mm" H 7750 3300 40  0001 C CIN
F 3 "" H 7750 3300 60  0000 C CNN
	1    7750 3300
	1    0    0    -1  
$EndComp
$Sheet
S 4800 6600 1150 450 
U 55A50CD7
F0 "PowerSupply" 60
F1 "power_supply.sch" 60
$EndSheet
$Sheet
S 1700 6050 900  950 
U 55A51BAC
F0 "radio+eeprom" 60
F1 "radio.sch" 60
F2 "SCK" I L 1700 6250 60 
F3 "MOSI" I L 1700 6450 60 
F4 "MISO" I L 1700 6650 60 
F5 "CE" I R 2600 6650 60 
F6 "CSN" I R 2600 6250 60 
F7 "IRQ" I R 2600 6450 60 
F8 "SCL" I L 1700 6850 60 
F9 "SDA" I R 2600 6850 60 
$EndSheet
$Comp
L GND #PWR05
U 1 1 55A547FE
P 7600 5550
F 0 "#PWR05" H 7600 5300 50  0001 C CNN
F 1 "GND" H 7600 5400 50  0000 C CNN
F 2 "" H 7600 5550 60  0000 C CNN
F 3 "" H 7600 5550 60  0000 C CNN
	1    7600 5550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 55A54837
P 7750 5550
F 0 "#PWR06" H 7750 5300 50  0001 C CNN
F 1 "GND" H 7750 5400 50  0000 C CNN
F 2 "" H 7750 5550 60  0000 C CNN
F 3 "" H 7750 5550 60  0000 C CNN
	1    7750 5550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 55A54869
P 8050 5550
F 0 "#PWR07" H 8050 5300 50  0001 C CNN
F 1 "GND" H 8050 5400 50  0000 C CNN
F 2 "" H 8050 5550 60  0000 C CNN
F 3 "" H 8050 5550 60  0000 C CNN
	1    8050 5550
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR08
U 1 1 55A548DE
P 7600 1150
F 0 "#PWR08" H 7600 1000 50  0001 C CNN
F 1 "+3V3" H 7600 1290 50  0000 C CNN
F 2 "" H 7600 1150 60  0000 C CNN
F 3 "" H 7600 1150 60  0000 C CNN
	1    7600 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR09
U 1 1 55A54917
P 7750 1150
F 0 "#PWR09" H 7750 1000 50  0001 C CNN
F 1 "+3V3" H 7750 1290 50  0000 C CNN
F 2 "" H 7750 1150 60  0000 C CNN
F 3 "" H 7750 1150 60  0000 C CNN
	1    7750 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR010
U 1 1 55A54949
P 8050 1150
F 0 "#PWR010" H 8050 1000 50  0001 C CNN
F 1 "+3V3" H 8050 1290 50  0000 C CNN
F 2 "" H 8050 1150 60  0000 C CNN
F 3 "" H 8050 1150 60  0000 C CNN
	1    8050 1150
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 P3
U 1 1 55A56EE6
P 2950 1850
F 0 "P3" H 2950 2150 50  0000 C CNN
F 1 "SWD" H 2950 1550 50  0000 C CNN
F 2 "lib:CORTEX_header_SMD" H 2950 650 60  0001 C CNN
F 3 "" H 2950 650 60  0000 C CNN
	1    2950 1850
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR011
U 1 1 55A57211
P 2550 1150
F 0 "#PWR011" H 2550 1000 50  0001 C CNN
F 1 "+3V3" H 2550 1290 50  0000 C CNN
F 2 "" H 2550 1150 60  0000 C CNN
F 3 "" H 2550 1150 60  0000 C CNN
	1    2550 1150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 55A5724D
P 2550 2550
F 0 "#PWR012" H 2550 2300 50  0001 C CNN
F 1 "GND" H 2550 2400 50  0000 C CNN
F 2 "" H 2550 2550 60  0000 C CNN
F 3 "" H 2550 2550 60  0000 C CNN
	1    2550 2550
	1    0    0    -1  
$EndComp
Text Label 3750 1650 2    60   ~ 0
SWDIO
Text Label 3750 2050 2    60   ~ 0
NRST
Text Label 3750 1750 2    60   ~ 0
SWCLK
Text Label 9850 3000 2    60   ~ 0
SWDIO
Text Label 9850 3100 2    60   ~ 0
SWCLK
Text Label 5750 1700 0    60   ~ 0
NRST
$Comp
L C C1
U 1 1 55A5BADD
P 1200 4550
F 0 "C1" H 1225 4650 50  0000 L CNN
F 1 "20p" H 1225 4450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1238 4400 30  0001 C CNN
F 3 "" H 1200 4550 60  0000 C CNN
	1    1200 4550
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 55A5BBCA
P 1800 4550
F 0 "C2" H 1825 4650 50  0000 L CNN
F 1 "20p" H 1825 4450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1838 4400 30  0001 C CNN
F 3 "" H 1800 4550 60  0000 C CNN
	1    1800 4550
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 55A5BCB3
P 1500 4150
F 0 "Y1" H 1500 4300 50  0000 C CNN
F 1 "8MHz" H 1500 4000 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-SD_SMD" H 1500 4150 60  0001 C CNN
F 3 "" H 1500 4150 60  0000 C CNN
	1    1500 4150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 55A5CA36
P 1200 4850
F 0 "#PWR013" H 1200 4600 50  0001 C CNN
F 1 "GND" H 1200 4700 50  0000 C CNN
F 2 "" H 1200 4850 60  0000 C CNN
F 3 "" H 1200 4850 60  0000 C CNN
	1    1200 4850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 55A5CA84
P 1800 4850
F 0 "#PWR014" H 1800 4600 50  0001 C CNN
F 1 "GND" H 1800 4700 50  0000 C CNN
F 2 "" H 1800 4850 60  0000 C CNN
F 3 "" H 1800 4850 60  0000 C CNN
	1    1800 4850
	1    0    0    -1  
$EndComp
Text Label 1200 3600 3    60   ~ 0
OSC_IN
Text Label 1800 3600 3    60   ~ 0
OSC_OUT
$Comp
L C C3
U 1 1 55A5D614
P 2500 4550
F 0 "C3" H 2525 4650 50  0000 L CNN
F 1 "10p" H 2525 4450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2538 4400 30  0001 C CNN
F 3 "" H 2500 4550 60  0000 C CNN
	1    2500 4550
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 55A5D61A
P 3100 4550
F 0 "C4" H 3125 4650 50  0000 L CNN
F 1 "10p" H 3125 4450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3138 4400 30  0001 C CNN
F 3 "" H 3100 4550 60  0000 C CNN
	1    3100 4550
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y2
U 1 1 55A5D620
P 2800 4150
F 0 "Y2" H 2800 4300 50  0000 C CNN
F 1 "32,768kHz" H 2800 4000 50  0000 C CNN
F 2 "lib:crystal_SMD_CPFB" H 2800 4150 60  0001 C CNN
F 3 "" H 2800 4150 60  0000 C CNN
	1    2800 4150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 55A5D626
P 2500 4850
F 0 "#PWR015" H 2500 4600 50  0001 C CNN
F 1 "GND" H 2500 4700 50  0000 C CNN
F 2 "" H 2500 4850 60  0000 C CNN
F 3 "" H 2500 4850 60  0000 C CNN
	1    2500 4850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 55A5D62C
P 3100 4850
F 0 "#PWR016" H 3100 4600 50  0001 C CNN
F 1 "GND" H 3100 4700 50  0000 C CNN
F 2 "" H 3100 4850 60  0000 C CNN
F 3 "" H 3100 4850 60  0000 C CNN
	1    3100 4850
	1    0    0    -1  
$EndComp
Text Label 2500 3600 3    60   ~ 0
OSC32_IN
Text Label 3100 3600 3    60   ~ 0
OSC32_OUT
Text Label 5550 3400 0    60   ~ 0
OSC_IN
Text Label 5550 3500 0    60   ~ 0
OSC_OUT
Text Label 5550 4000 0    60   ~ 0
OSC32_IN
Text Label 5550 4100 0    60   ~ 0
OSC32_OUT
Text Label 1150 6250 0    60   ~ 0
SCK
Text Label 1150 6450 0    60   ~ 0
MOSI
Text Label 1150 6650 0    60   ~ 0
MISO
Text Label 3100 6250 2    60   ~ 0
CSN
Text Label 3100 6450 2    60   ~ 0
IRQ
Text Label 3100 6650 2    60   ~ 0
CE
Text Label 9850 2200 2    60   ~ 0
SCK
Text Label 9850 2300 2    60   ~ 0
MISO
Text Label 9850 2400 2    60   ~ 0
MOSI
Text Label 9850 3400 2    60   ~ 0
IRQ
Text Label 9850 3500 2    60   ~ 0
CSN
Text Label 9850 3600 2    60   ~ 0
CE
$Comp
L GND #PWR017
U 1 1 55A57289
P 3450 2550
F 0 "#PWR017" H 3450 2300 50  0001 C CNN
F 1 "GND" H 3450 2400 50  0000 C CNN
F 2 "" H 3450 2550 60  0000 C CNN
F 3 "" H 3450 2550 60  0000 C CNN
	1    3450 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR018
U 1 1 55A6DF93
P 5500 2000
F 0 "#PWR018" H 5500 1750 50  0001 C CNN
F 1 "GND" H 5500 1850 50  0000 C CNN
F 2 "" H 5500 2000 60  0000 C CNN
F 3 "" H 5500 2000 60  0000 C CNN
	1    5500 2000
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 55A6E479
P 3450 2300
F 0 "C5" H 3475 2400 50  0000 L CNN
F 1 "100n" H 3475 2200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3488 2150 30  0001 C CNN
F 3 "" H 3450 2300 60  0000 C CNN
	1    3450 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 5550 8050 5300
Wire Wire Line
	7750 5300 7750 5550
Wire Wire Line
	7600 5550 7600 5300
Wire Wire Line
	7600 1300 7600 1150
Wire Wire Line
	7750 1150 7750 1300
Wire Wire Line
	8050 1150 8050 1300
Wire Wire Line
	2550 1650 2700 1650
Wire Wire Line
	2550 1150 2550 1650
Wire Wire Line
	2550 1750 2550 2550
Wire Wire Line
	2550 1750 2700 1750
Wire Wire Line
	2700 1850 2550 1850
Connection ~ 2550 1850
Wire Wire Line
	9450 3000 9850 3000
Wire Wire Line
	9450 3100 9850 3100
Wire Wire Line
	6050 1700 5750 1700
Wire Wire Line
	1200 4700 1200 4850
Wire Wire Line
	1800 4850 1800 4700
Wire Wire Line
	1800 3600 1800 4400
Wire Wire Line
	1800 4150 1650 4150
Wire Wire Line
	1200 3600 1200 4400
Wire Wire Line
	1200 4150 1350 4150
Connection ~ 1200 4150
Connection ~ 1800 4150
Wire Wire Line
	2500 4700 2500 4850
Wire Wire Line
	3100 4850 3100 4700
Wire Wire Line
	3100 3600 3100 4400
Wire Wire Line
	3100 4150 2950 4150
Wire Wire Line
	2500 3600 2500 4400
Wire Wire Line
	2500 4150 2650 4150
Connection ~ 2500 4150
Connection ~ 3100 4150
Wire Wire Line
	6050 3400 5550 3400
Wire Wire Line
	6050 3500 5550 3500
Wire Wire Line
	6050 4000 5550 4000
Wire Wire Line
	6050 4100 5550 4100
Wire Wire Line
	1700 6250 1150 6250
Wire Wire Line
	1700 6450 1150 6450
Wire Wire Line
	1700 6650 1150 6650
Wire Wire Line
	2600 6250 3100 6250
Wire Wire Line
	2600 6450 3100 6450
Wire Wire Line
	2600 6650 3100 6650
Wire Wire Line
	9450 2200 9850 2200
Wire Wire Line
	9450 2300 9850 2300
Wire Wire Line
	9450 2400 9850 2400
Wire Wire Line
	9450 3400 9850 3400
Wire Wire Line
	9450 3500 9850 3500
Wire Wire Line
	9450 3600 9850 3600
Wire Wire Line
	9450 3200 10200 3200
Wire Wire Line
	9450 3700 10200 3700
Wire Wire Line
	9450 3800 10200 3800
Wire Wire Line
	9450 3900 10200 3900
Wire Wire Line
	9450 4000 10200 4000
Wire Wire Line
	9450 4100 10200 4100
Wire Wire Line
	9450 4200 10200 4200
Wire Wire Line
	9450 4300 10200 4300
Wire Wire Line
	9450 4400 10200 4400
Wire Wire Line
	9450 4500 10200 4500
Wire Wire Line
	9450 4600 10200 4600
Wire Wire Line
	9450 4700 10200 4700
Wire Wire Line
	9450 4800 10200 4800
Wire Wire Line
	5500 2000 5500 1850
Wire Wire Line
	5500 1850 6050 1850
Wire Wire Line
	3450 2450 3450 2550
Wire Wire Line
	3200 1650 3750 1650
Wire Wire Line
	3750 1750 3200 1750
Wire Wire Line
	3200 2050 3750 2050
Wire Wire Line
	3450 2150 3450 2050
Connection ~ 3450 2050
$Comp
L VCC #PWR019
U 1 1 55A61A9B
P 1750 900
F 0 "#PWR019" H 1750 750 50  0001 C CNN
F 1 "VCC" H 1750 1050 50  0000 C CNN
F 2 "" H 1750 900 60  0000 C CNN
F 3 "" H 1750 900 60  0000 C CNN
	1    1750 900 
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR020
U 1 1 55A61AE5
P 2150 1150
F 0 "#PWR020" H 2150 1000 50  0001 C CNN
F 1 "+3V3" H 2150 1290 50  0000 C CNN
F 2 "" H 2150 1150 60  0000 C CNN
F 3 "" H 2150 1150 60  0000 C CNN
	1    2150 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 900  1750 1050
Wire Wire Line
	1750 1050 1300 1050
Wire Wire Line
	2150 1150 2150 1500
Wire Wire Line
	2150 1500 1300 1500
Text HLabel 1300 1050 0    60   Input ~ 0
V_MCU_IN
Text HLabel 1300 1500 0    60   Input ~ 0
3V3_MCU_OUT
Text HLabel 10200 3700 2    60   Input ~ 0
GPIO1
Text HLabel 10200 3800 2    60   Input ~ 0
GPIO2
Text HLabel 10200 3900 2    60   Input ~ 0
GPIO3
Text HLabel 10200 4000 2    60   Input ~ 0
GPIO4
Text HLabel 10200 4100 2    60   Input ~ 0
GPIO5
Text HLabel 10200 4200 2    60   Input ~ 0
GPIO6
Text HLabel 10200 4300 2    60   Input ~ 0
GPIO7
Text HLabel 10200 3200 2    60   Input ~ 0
GPIO0
Text HLabel 10200 4400 2    60   Input ~ 0
GPIO8
Text HLabel 10200 4500 2    60   Input ~ 0
GPIO9
Text HLabel 10200 4600 2    60   Input ~ 0
GPIO10
Text HLabel 10200 4700 2    60   Input ~ 0
GPIO11
Text HLabel 10200 4800 2    60   Input ~ 0
GPIO12
Wire Wire Line
	9450 1700 10200 1700
Wire Wire Line
	9450 1800 10200 1800
Wire Wire Line
	9450 1900 10200 1900
Wire Wire Line
	9450 2000 10200 2000
Wire Wire Line
	9450 2100 10200 2100
Text HLabel 10200 1700 2    60   Input ~ 0
GPIO13
Text HLabel 10200 1800 2    60   Input ~ 0
GPIO14
Text HLabel 10200 1900 2    60   Input ~ 0
GPIO15
Text HLabel 10200 2000 2    60   Input ~ 0
GPIO16
Text HLabel 10200 2100 2    60   Input ~ 0
GPIO17
Wire Wire Line
	2600 6850 3100 6850
Wire Wire Line
	1700 6850 1150 6850
Text Label 3100 6850 2    60   ~ 0
SDA
Text Label 1150 6850 0    60   ~ 0
SCL
Text HLabel 4500 2700 0    60   Input ~ 0
GPIO5
Text HLabel 4500 2900 0    60   Input ~ 0
GPIO4
Text Label 5200 2700 2    60   ~ 0
SDA
Text Label 5200 2900 2    60   ~ 0
SCL
$Comp
L R R1
U 1 1 55A8ED0D
P 4700 2350
F 0 "R1" V 4780 2350 50  0000 C CNN
F 1 "4k7" V 4700 2350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4630 2350 30  0001 C CNN
F 3 "" H 4700 2350 30  0000 C CNN
	1    4700 2350
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 55A8EDC5
P 4950 2350
F 0 "R2" V 5030 2350 50  0000 C CNN
F 1 "4k7" V 4950 2350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4880 2350 30  0001 C CNN
F 3 "" H 4950 2350 30  0000 C CNN
	1    4950 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 2700 4500 2700
Wire Wire Line
	4500 2900 5200 2900
Wire Wire Line
	4700 2500 4700 2700
Connection ~ 4700 2700
Wire Wire Line
	4950 2500 4950 2900
Connection ~ 4950 2900
$Comp
L +3V3 #PWR021
U 1 1 55A90A74
P 4700 1150
F 0 "#PWR021" H 4700 1000 50  0001 C CNN
F 1 "+3V3" H 4700 1290 50  0000 C CNN
F 2 "" H 4700 1150 60  0000 C CNN
F 3 "" H 4700 1150 60  0000 C CNN
	1    4700 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR022
U 1 1 55A90A7A
P 4950 1150
F 0 "#PWR022" H 4950 1000 50  0001 C CNN
F 1 "+3V3" H 4950 1290 50  0000 C CNN
F 2 "" H 4950 1150 60  0000 C CNN
F 3 "" H 4950 1150 60  0000 C CNN
	1    4950 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2200 4950 1150
Wire Wire Line
	4700 2200 4700 1150
Wire Wire Line
	9450 2700 9850 2700
Wire Wire Line
	9450 2600 9850 2600
Text HLabel 9850 2600 2    60   Input ~ 0
TX
Text HLabel 9850 2700 2    60   Input ~ 0
RX
Wire Wire Line
	5400 3900 6050 3900
Text HLabel 5400 3900 0    60   Input ~ 0
GPIO18
NoConn ~ 6050 2150
NoConn ~ 6050 3600
NoConn ~ 6050 3700
NoConn ~ 9450 2800
NoConn ~ 9450 2900
NoConn ~ 9450 2500
NoConn ~ 9450 4900
NoConn ~ 2700 1950
NoConn ~ 2700 2050
NoConn ~ 3200 1850
NoConn ~ 3200 1950
$EndSCHEMATC

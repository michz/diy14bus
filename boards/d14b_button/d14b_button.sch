EESchema Schematic File Version 2
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
LIBS:special
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
LIBS:STM32F030F4P6TR
LIBS:nrf24l01plus-module
LIBS:tps61221
LIBS:d14b_button-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L nRF24L01+-Module U2
U 1 1 5480655E
P 9450 2700
F 0 "U2" H 8800 3000 60  0000 C CNN
F 1 "nRF24L01+-Module" H 9450 2700 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9550 2300 60  0001 C CNN
F 3 "" H 9550 2300 60  0000 C CNN
	1    9450 2700
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 5480667B
P 6800 1150
F 0 "SW1" H 6950 1260 50  0000 C CNN
F 1 "SW_PUSH" H 6800 1070 50  0000 C CNN
F 2 "d14b_libs:TACTILE_SW" H 6800 1150 60  0001 C CNN
F 3 "" H 6800 1150 60  0000 C CNN
	1    6800 1150
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 548067BC
P 6800 1450
F 0 "SW2" H 6950 1560 50  0000 C CNN
F 1 "SW_PUSH" H 6800 1370 50  0000 C CNN
F 2 "d14b_libs:TACTILE_SW" H 6800 1450 60  0001 C CNN
F 3 "" H 6800 1450 60  0000 C CNN
	1    6800 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 2550 10600 2550
Wire Wire Line
	10300 2700 10600 2700
Wire Wire Line
	10300 2850 10600 2850
Wire Wire Line
	9450 3100 9450 4300
Wire Wire Line
	9450 2100 9450 2300
$Comp
L GND #PWR01
U 1 1 54806F87
P 9450 4300
F 0 "#PWR01" H 9450 4300 30  0001 C CNN
F 1 "GND" H 9450 4230 30  0001 C CNN
F 2 "" H 9450 4300 60  0000 C CNN
F 3 "" H 9450 4300 60  0000 C CNN
	1    9450 4300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 548070FB
P 2900 5200
F 0 "#PWR02" H 2900 5200 30  0001 C CNN
F 1 "GND" H 2900 5130 30  0001 C CNN
F 2 "" H 2900 5200 60  0000 C CNN
F 3 "" H 2900 5200 60  0000 C CNN
	1    2900 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 2200 4900 2200
Wire Wire Line
	4750 2300 4900 2300
Text GLabel 4900 2200 2    60   Input ~ 0
MISO
Text GLabel 4900 2300 2    60   Input ~ 0
MOSI
Text GLabel 10600 2700 2    60   Input ~ 0
MOSI
Text GLabel 10600 2850 2    60   Input ~ 0
MISO
Wire Wire Line
	4750 2100 4900 2100
Text GLabel 4900 2100 2    60   Input ~ 0
SCK
Text GLabel 10600 2550 2    60   Input ~ 0
SCK
Wire Wire Line
	7100 1150 7200 1150
Connection ~ 7200 1150
Wire Wire Line
	7200 1450 7100 1450
Connection ~ 7200 1450
Wire Wire Line
	8550 2550 8350 2550
Wire Wire Line
	8550 2700 8350 2700
Wire Wire Line
	8550 2850 8350 2850
Wire Wire Line
	4750 3300 4900 3300
Wire Wire Line
	4750 3400 4900 3400
Wire Wire Line
	4750 3500 4900 3500
Text GLabel 4900 3300 2    60   Input ~ 0
CE
Text GLabel 4900 3400 2    60   Input ~ 0
CSN
Text GLabel 4900 3500 2    60   Input ~ 0
IRQ
$Comp
L CP2 C2
U 1 1 5480AD1C
P 7650 2800
F 0 "C2" H 7650 2900 40  0000 L CNN
F 1 "10u" H 7656 2715 40  0000 L CNN
F 2 "SMD_Packages:SMD-1206" H 7688 2650 30  0001 C CNN
F 3 "" H 7650 2800 60  0000 C CNN
	1    7650 2800
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5480ADD3
P 7300 2800
F 0 "C1" H 7300 2900 40  0000 L CNN
F 1 "100n" H 7306 2715 40  0000 L CNN
F 2 "SMD_Packages:SMD-1206" H 7338 2650 30  0001 C CNN
F 3 "" H 7300 2800 60  0000 C CNN
	1    7300 2800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5480AE86
P 7650 4300
F 0 "#PWR08" H 7650 4300 30  0001 C CNN
F 1 "GND" H 7650 4230 30  0001 C CNN
F 2 "" H 7650 4300 60  0000 C CNN
F 3 "" H 7650 4300 60  0000 C CNN
	1    7650 4300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5480AE99
P 7300 4300
F 0 "#PWR09" H 7300 4300 30  0001 C CNN
F 1 "GND" H 7300 4230 30  0001 C CNN
F 2 "" H 7300 4300 60  0000 C CNN
F 3 "" H 7300 4300 60  0000 C CNN
	1    7300 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 4300 7650 3000
Wire Wire Line
	7650 2600 7650 2100
Wire Wire Line
	7300 2100 7300 2600
Wire Wire Line
	7300 3000 7300 4300
Text GLabel 8350 2550 0    60   Input ~ 0
CE
Text GLabel 8350 2700 0    60   Input ~ 0
CSN
Text GLabel 8350 2850 0    60   Input ~ 0
IRQ
Wire Wire Line
	7200 800  7200 1450
$Comp
L BATTERY BT?
U 1 1 54896B73
P 1300 6050
F 0 "BT?" H 1300 6250 50  0000 C CNN
F 1 "BATTERY" H 1300 5860 50  0000 C CNN
F 2 "" H 1300 6050 60  0000 C CNN
F 3 "" H 1300 6050 60  0000 C CNN
	1    1300 6050
	0    1    1    0   
$EndComp
$Comp
L USB-MICRO-B CON?
U 1 1 54896BA2
P 1300 7200
F 0 "CON?" H 1000 7550 50  0000 C CNN
F 1 "USB-MICRO-B" H 1150 6850 50  0000 C CNN
F 2 "" H 1300 7100 50  0000 C CNN
F 3 "" H 1300 7100 50  0000 C CNN
	1    1300 7200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54896FB7
P 1300 6350
F 0 "#PWR?" H 1300 6350 30  0001 C CNN
F 1 "GND" H 1300 6280 30  0001 C CNN
F 2 "" H 1300 6350 60  0000 C CNN
F 3 "" H 1300 6350 60  0000 C CNN
	1    1300 6350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54896FE4
P 2800 6250
F 0 "#PWR?" H 2800 6250 30  0001 C CNN
F 1 "GND" H 2800 6180 30  0001 C CNN
F 2 "" H 2800 6250 60  0000 C CNN
F 3 "" H 2800 6250 60  0000 C CNN
	1    2800 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 5750 2450 5750
$Comp
L C C?
U 1 1 54898D66
P 2050 5550
F 0 "C?" H 2050 5650 40  0000 L CNN
F 1 "10 μF" H 2056 5465 40  0000 L CNN
F 2 "" H 2088 5400 30  0000 C CNN
F 3 "" H 2050 5550 60  0000 C CNN
	1    2050 5550
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR_SMALL L?
U 1 1 54898DB7
P 2200 5950
F 0 "L?" H 2200 6050 50  0000 C CNN
F 1 "INDUCTOR_SMALL" H 2200 5900 50  0000 C CNN
F 2 "" H 2200 5950 60  0000 C CNN
F 3 "" H 2200 5950 60  0000 C CNN
	1    2200 5950
	1    0    0    -1  
$EndComp
$Comp
L TPS61221 U?
U 1 1 548991BF
P 2950 5800
F 0 "U?" H 2650 6150 40  0000 C CNN
F 1 "TPS61221" H 3100 6150 40  0000 C CNN
F 2 "SO6" H 2950 5850 35  0000 C CIN
F 3 "" H 2950 5800 60  0000 C CNN
	1    2950 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 5750 2300 5550
Wire Wire Line
	2300 5550 2450 5550
Connection ~ 2300 5750
Wire Wire Line
	1950 5950 1850 5950
Wire Wire Line
	1850 5950 1850 5750
Connection ~ 1850 5750
$Comp
L C C?
U 1 1 5489AA0A
P 4050 5950
F 0 "C?" H 4050 6050 40  0000 L CNN
F 1 "10 μF" H 4056 5865 40  0000 L CNN
F 2 "" H 4088 5800 30  0000 C CNN
F 3 "" H 4050 5950 60  0000 C CNN
	1    4050 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 5750 4400 5750
$Comp
L R R?
U 1 1 5489AAC5
P 3750 6000
F 0 "R?" V 3830 6000 40  0000 C CNN
F 1 "R" V 3757 6001 40  0000 C CNN
F 2 "" V 3680 6000 30  0000 C CNN
F 3 "" H 3750 6000 30  0000 C CNN
	1    3750 6000
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5489AB22
P 3750 6500
F 0 "R?" V 3830 6500 40  0000 C CNN
F 1 "R" V 3757 6501 40  0000 C CNN
F 2 "" V 3680 6500 30  0000 C CNN
F 3 "" H 3750 6500 30  0000 C CNN
	1    3750 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 5950 3450 6250
Wire Wire Line
	3450 6250 3750 6250
$Comp
L GNDPWR #PWR?
U 1 1 5489AB82
P 2050 5350
F 0 "#PWR?" H 2050 5150 40  0001 C CNN
F 1 "GNDPWR" H 2050 5220 40  0000 C CNN
F 2 "" H 2050 5300 60  0000 C CNN
F 3 "" H 2050 5300 60  0000 C CNN
	1    2050 5350
	-1   0    0    1   
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 5489ABB0
P 3100 6250
F 0 "#PWR?" H 3100 6050 40  0001 C CNN
F 1 "GNDPWR" H 3100 6120 40  0000 C CNN
F 2 "" H 3100 6200 60  0000 C CNN
F 3 "" H 3100 6200 60  0000 C CNN
	1    3100 6250
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 5489ABC9
P 4050 6150
F 0 "#PWR?" H 4050 5950 40  0001 C CNN
F 1 "GNDPWR" H 4050 6020 40  0000 C CNN
F 2 "" H 4050 6100 60  0000 C CNN
F 3 "" H 4050 6100 60  0000 C CNN
	1    4050 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 6250 3100 6250
Wire Wire Line
	2950 6250 2950 6150
Connection ~ 2950 6250
$Comp
L GND #PWR?
U 1 1 5489AC6B
P 3750 6750
F 0 "#PWR?" H 3750 6750 30  0001 C CNN
F 1 "GND" H 3750 6680 30  0001 C CNN
F 2 "" H 3750 6750 60  0000 C CNN
F 3 "" H 3750 6750 60  0000 C CNN
	1    3750 6750
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X?
U 1 1 54AF9828
P 1050 2900
F 0 "X?" H 1050 3050 60  0000 C CNN
F 1 "8M" H 1050 2750 60  0000 C CNN
F 2 "" H 1050 2900 60  0000 C CNN
F 3 "" H 1050 2900 60  0000 C CNN
	1    1050 2900
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 54AF99C9
P 2650 900
F 0 "C?" H 2650 1000 40  0000 L CNN
F 1 "100n" H 2656 815 40  0000 L CNN
F 2 "" H 2688 750 30  0000 C CNN
F 3 "" H 2650 900 60  0000 C CNN
	1    2650 900 
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54AF9BEB
P 3650 900
F 0 "C?" H 3650 1000 40  0000 L CNN
F 1 "10n" H 3656 815 40  0000 L CNN
F 2 "" H 3688 750 30  0000 C CNN
F 3 "" H 3650 900 60  0000 C CNN
	1    3650 900 
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54AF9C52
P 4050 900
F 0 "C?" H 4050 1000 40  0000 L CNN
F 1 "1u" H 4056 815 40  0000 L CNN
F 2 "" H 4088 750 30  0000 C CNN
F 3 "" H 4050 900 60  0000 C CNN
	1    4050 900 
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54AF9CB4
P 2350 900
F 0 "C?" H 2350 1000 40  0000 L CNN
F 1 "4.7u" H 2356 815 40  0000 L CNN
F 2 "" H 2388 750 30  0000 C CNN
F 3 "" H 2350 900 60  0000 C CNN
	1    2350 900 
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54AF9D47
P 1350 2700
F 0 "C?" H 1350 2800 40  0000 L CNN
F 1 "20p" H 1356 2615 40  0000 L CNN
F 2 "" H 1388 2550 30  0000 C CNN
F 3 "" H 1350 2700 60  0000 C CNN
	1    1350 2700
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 54AF9DC5
P 750 2700
F 0 "C?" H 750 2800 40  0000 L CNN
F 1 "20p" H 756 2615 40  0000 L CNN
F 2 "" H 788 2550 30  0000 C CNN
F 3 "" H 750 2700 60  0000 C CNN
	1    750  2700
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA0D1
P 2350 1100
F 0 "#PWR?" H 2350 1100 30  0001 C CNN
F 1 "GND" H 2350 1030 30  0001 C CNN
F 2 "" H 2350 1100 60  0000 C CNN
F 3 "" H 2350 1100 60  0000 C CNN
	1    2350 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA18C
P 2650 1100
F 0 "#PWR?" H 2650 1100 30  0001 C CNN
F 1 "GND" H 2650 1030 30  0001 C CNN
F 2 "" H 2650 1100 60  0000 C CNN
F 3 "" H 2650 1100 60  0000 C CNN
	1    2650 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA1CD
P 3650 1100
F 0 "#PWR?" H 3650 1100 30  0001 C CNN
F 1 "GND" H 3650 1030 30  0001 C CNN
F 2 "" H 3650 1100 60  0000 C CNN
F 3 "" H 3650 1100 60  0000 C CNN
	1    3650 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA1EE
P 4050 1100
F 0 "#PWR?" H 4050 1100 30  0001 C CNN
F 1 "GND" H 4050 1030 30  0001 C CNN
F 2 "" H 4050 1100 60  0000 C CNN
F 3 "" H 4050 1100 60  0000 C CNN
	1    4050 1100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA49B
P 1050 2500
F 0 "#PWR?" H 1050 2500 30  0001 C CNN
F 1 "GND" H 1050 2430 30  0001 C CNN
F 2 "" H 1050 2500 60  0000 C CNN
F 3 "" H 1050 2500 60  0000 C CNN
	1    1050 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	1350 2500 750  2500
Connection ~ 1050 2500
$Comp
L CONN_02X10 P?
U 1 1 54AFAC94
P 6550 3450
F 0 "P?" H 6550 4000 50  0000 C CNN
F 1 "CONN_02X10" V 6550 3450 50  0000 C CNN
F 2 "" H 6550 2250 60  0000 C CNN
F 3 "" H 6550 2250 60  0000 C CNN
	1    6550 3450
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 54AFBA14
P 5450 2000
F 0 "R?" V 5530 2000 40  0000 C CNN
F 1 "R" V 5457 2001 40  0000 C CNN
F 2 "" V 5380 2000 30  0000 C CNN
F 3 "" H 5450 2000 30  0000 C CNN
	1    5450 2000
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 54AFBB0B
P 5450 1800
F 0 "R?" V 5530 1800 40  0000 C CNN
F 1 "R" V 5457 1801 40  0000 C CNN
F 2 "" V 5380 1800 30  0000 C CNN
F 3 "" H 5450 1800 30  0000 C CNN
	1    5450 1800
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 54AFBB5E
P 5450 1600
F 0 "R?" V 5530 1600 40  0000 C CNN
F 1 "R" V 5457 1601 40  0000 C CNN
F 2 "" V 5380 1600 30  0000 C CNN
F 3 "" H 5450 1600 30  0000 C CNN
	1    5450 1600
	0    1    1    0   
$EndComp
$Comp
L LED_RCBG D?
U 1 1 54AFC019
P 6000 1800
F 0 "D?" H 5925 2150 50  0000 C CNN
F 1 "LED_RCBG" H 5975 1450 50  0000 C CNN
F 2 "" H 6000 1750 50  0000 C CNN
F 3 "" H 6000 1750 50  0000 C CNN
	1    6000 1800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFD92F
P 6300 1800
F 0 "#PWR?" H 6300 1800 30  0001 C CNN
F 1 "GND" H 6300 1730 30  0001 C CNN
F 2 "" H 6300 1800 60  0000 C CNN
F 3 "" H 6300 1800 60  0000 C CNN
	1    6300 1800
	0    -1   -1   0   
$EndComp
$Comp
L STM32F050C6 U?
U 1 1 54AFE9EC
P 3050 3200
F 0 "U?" H 1550 5100 60  0000 C CNN
F 1 "STM32F050C6" H 4300 1300 60  0000 C CNN
F 2 "LQFP48" H 3050 3200 40  0000 C CIN
F 3 "" H 3050 3200 60  0000 C CNN
	1    3050 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B01216
P 3050 5200
F 0 "#PWR?" H 3050 5200 30  0001 C CNN
F 1 "GND" H 3050 5130 30  0001 C CNN
F 2 "" H 3050 5200 60  0000 C CNN
F 3 "" H 3050 5200 60  0000 C CNN
	1    3050 5200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B0123C
P 3350 5200
F 0 "#PWR?" H 3350 5200 30  0001 C CNN
F 1 "GND" H 3350 5130 30  0001 C CNN
F 2 "" H 3350 5200 60  0000 C CNN
F 3 "" H 3350 5200 60  0000 C CNN
	1    3350 5200
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54B015E8
P 2100 900
F 0 "C?" H 2100 1000 40  0000 L CNN
F 1 "100n" H 2106 815 40  0000 L CNN
F 2 "" H 2138 750 30  0000 C CNN
F 3 "" H 2100 900 60  0000 C CNN
	1    2100 900 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B01667
P 2100 1100
F 0 "#PWR?" H 2100 1100 30  0001 C CNN
F 1 "GND" H 2100 1030 30  0001 C CNN
F 2 "" H 2100 1100 60  0000 C CNN
F 3 "" H 2100 1100 60  0000 C CNN
	1    2100 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1700 5200 1700
Wire Wire Line
	5200 1700 5200 1600
Wire Wire Line
	4750 1800 5200 1800
Wire Wire Line
	4750 1900 5200 1900
Wire Wire Line
	5200 1900 5200 2000
$Comp
L GND #PWR?
U 1 1 54B083E9
P 6800 4100
F 0 "#PWR?" H 6800 4100 30  0001 C CNN
F 1 "GND" H 6800 4030 30  0001 C CNN
F 2 "" H 6800 4100 60  0000 C CNN
F 3 "" H 6800 4100 60  0000 C CNN
	1    6800 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 3100 6800 4100
Connection ~ 6800 3200
Connection ~ 6800 3300
Connection ~ 6800 3400
Connection ~ 6800 3500
Connection ~ 6800 3600
Connection ~ 6800 3700
Connection ~ 6800 3800
Connection ~ 6800 3900
Connection ~ 6800 3100
Wire Wire Line
	750  3400 1350 3400
Wire Wire Line
	1350 2900 1350 3300
$Comp
L R R?
U 1 1 54B0890E
P 750 3150
F 0 "R?" V 830 3150 40  0000 C CNN
F 1 "0" V 757 3151 40  0000 C CNN
F 2 "" V 680 3150 30  0000 C CNN
F 3 "" H 750 3150 30  0000 C CNN
	1    750  3150
	-1   0    0    1   
$EndComp
$Comp
L CRYSTAL X?
U 1 1 54B0A562
P 1000 3850
F 0 "X?" H 1000 4000 60  0000 C CNN
F 1 "32.768k" H 1000 3700 60  0000 C CNN
F 2 "" H 1000 3850 60  0000 C CNN
F 3 "" H 1000 3850 60  0000 C CNN
	1    1000 3850
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 54B0A568
P 800 3550
F 0 "C?" H 800 3650 40  0000 L CNN
F 1 "10p" H 806 3465 40  0000 L CNN
F 2 "" H 838 3400 30  0000 C CNN
F 3 "" H 800 3550 60  0000 C CNN
	1    800  3550
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 54B0A56E
P 800 4150
F 0 "C?" H 800 4250 40  0000 L CNN
F 1 "10p" H 806 4065 40  0000 L CNN
F 2 "" H 838 4000 30  0000 C CNN
F 3 "" H 800 4150 60  0000 C CNN
	1    800  4150
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 54B0A574
P 600 3850
F 0 "#PWR?" H 600 3850 30  0001 C CNN
F 1 "GND" H 600 3780 30  0001 C CNN
F 2 "" H 600 3850 60  0000 C CNN
F 3 "" H 600 3850 60  0000 C CNN
	1    600  3850
	0    1    1    0   
$EndComp
Wire Wire Line
	600  3550 600  4150
Connection ~ 600  3850
Wire Wire Line
	1350 3900 1200 3900
Wire Wire Line
	1200 3900 1200 3550
Wire Wire Line
	1200 3550 1000 3550
Wire Wire Line
	1350 4000 1200 4000
Wire Wire Line
	1200 4000 1200 4150
Wire Wire Line
	1200 4150 1000 4150
$Comp
L 3V3 #PWR?
U 1 1 54AFD499
P 1200 2000
F 0 "#PWR?" H 1200 2100 40  0001 C CNN
F 1 "3V3" H 1200 2125 40  0000 C CNN
F 2 "" H 1200 2000 60  0000 C CNN
F 3 "" H 1200 2000 60  0000 C CNN
	1    1200 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2000 1200 2050
Wire Wire Line
	1200 2050 1350 2050
$Comp
L JUMPER3 JP?
U 1 1 54AFD79C
P 750 1750
F 0 "JP?" H 800 1650 40  0000 L CNN
F 1 "JUMPER3" H 750 1850 40  0000 C CNN
F 2 "" H 750 1750 60  0000 C CNN
F 3 "" H 750 1750 60  0000 C CNN
	1    750  1750
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 54AFD7FD
P 1100 1750
F 0 "R?" V 1180 1750 40  0000 C CNN
F 1 "10k" V 1107 1751 40  0000 C CNN
F 2 "" V 1030 1750 30  0000 C CNN
F 3 "" H 1100 1750 30  0000 C CNN
	1    1100 1750
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFD975
P 750 2000
F 0 "#PWR?" H 750 1750 60  0001 C CNN
F 1 "GND" H 750 1850 60  0000 C CNN
F 2 "" H 750 2000 60  0000 C CNN
F 3 "" H 750 2000 60  0000 C CNN
	1    750  2000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFD989
P 750 1500
F 0 "#PWR?" H 750 1350 60  0001 C CNN
F 1 "+3V3" H 750 1640 60  0000 C CNN
F 2 "" H 750 1500 60  0000 C CNN
F 3 "" H 750 1500 60  0000 C CNN
	1    750  1500
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFDA66
P 2100 700
F 0 "#PWR?" H 2100 550 60  0001 C CNN
F 1 "+3V3" H 2100 840 60  0000 C CNN
F 2 "" H 2100 700 60  0000 C CNN
F 3 "" H 2100 700 60  0000 C CNN
	1    2100 700 
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFDA99
P 2350 700
F 0 "#PWR?" H 2350 550 60  0001 C CNN
F 1 "+3V3" H 2350 840 60  0000 C CNN
F 2 "" H 2350 700 60  0000 C CNN
F 3 "" H 2350 700 60  0000 C CNN
	1    2350 700 
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFDAC5
P 2650 700
F 0 "#PWR?" H 2650 550 60  0001 C CNN
F 1 "+3V3" H 2650 840 60  0000 C CNN
F 2 "" H 2650 700 60  0000 C CNN
F 3 "" H 2650 700 60  0000 C CNN
	1    2650 700 
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE3DB
P 2900 1200
F 0 "#PWR?" H 2900 1050 60  0001 C CNN
F 1 "+3V3" H 2900 1340 60  0000 C CNN
F 2 "" H 2900 1200 60  0000 C CNN
F 3 "" H 2900 1200 60  0000 C CNN
	1    2900 1200
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE407
P 3050 1200
F 0 "#PWR?" H 3050 1050 60  0001 C CNN
F 1 "+3V3" H 3050 1340 60  0000 C CNN
F 2 "" H 3050 1200 60  0000 C CNN
F 3 "" H 3050 1200 60  0000 C CNN
	1    3050 1200
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE433
P 3350 1200
F 0 "#PWR?" H 3350 1050 60  0001 C CNN
F 1 "+3V3" H 3350 1340 60  0000 C CNN
F 2 "" H 3350 1200 60  0000 C CNN
F 3 "" H 3350 1200 60  0000 C CNN
	1    3350 1200
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE45F
P 3650 700
F 0 "#PWR?" H 3650 550 60  0001 C CNN
F 1 "+3V3" H 3650 840 60  0000 C CNN
F 2 "" H 3650 700 60  0000 C CNN
F 3 "" H 3650 700 60  0000 C CNN
	1    3650 700 
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE48B
P 4050 700
F 0 "#PWR?" H 4050 550 60  0001 C CNN
F 1 "+3V3" H 4050 840 60  0000 C CNN
F 2 "" H 4050 700 60  0000 C CNN
F 3 "" H 4050 700 60  0000 C CNN
	1    4050 700 
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE5A1
P 7200 800
F 0 "#PWR?" H 7200 650 60  0001 C CNN
F 1 "+3V3" H 7200 940 60  0000 C CNN
F 2 "" H 7200 800 60  0000 C CNN
F 3 "" H 7200 800 60  0000 C CNN
	1    7200 800 
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE8D8
P 7300 2100
F 0 "#PWR?" H 7300 1950 60  0001 C CNN
F 1 "+3V3" H 7300 2240 60  0000 C CNN
F 2 "" H 7300 2100 60  0000 C CNN
F 3 "" H 7300 2100 60  0000 C CNN
	1    7300 2100
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE90B
P 7650 2100
F 0 "#PWR?" H 7650 1950 60  0001 C CNN
F 1 "+3V3" H 7650 2240 60  0000 C CNN
F 2 "" H 7650 2100 60  0000 C CNN
F 3 "" H 7650 2100 60  0000 C CNN
	1    7650 2100
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE9BC
P 9450 2100
F 0 "#PWR?" H 9450 1950 60  0001 C CNN
F 1 "+3V3" H 9450 2240 60  0000 C CNN
F 2 "" H 9450 2100 60  0000 C CNN
F 3 "" H 9450 2100 60  0000 C CNN
	1    9450 2100
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFEB56
P 6150 2900
F 0 "#PWR?" H 6150 2750 60  0001 C CNN
F 1 "+3V3" H 6150 3040 60  0000 C CNN
F 2 "" H 6150 2900 60  0000 C CNN
F 3 "" H 6150 2900 60  0000 C CNN
	1    6150 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 2900 6150 3000
Wire Wire Line
	6150 3000 6300 3000
$Comp
L +3V3 #PWR?
U 1 1 54AFEE44
P 4400 5750
F 0 "#PWR?" H 4400 5600 60  0001 C CNN
F 1 "+3V3" H 4400 5890 60  0000 C CNN
F 2 "" H 4400 5750 60  0000 C CNN
F 3 "" H 4400 5750 60  0000 C CNN
	1    4400 5750
	1    0    0    -1  
$EndComp
$EndSCHEMATC

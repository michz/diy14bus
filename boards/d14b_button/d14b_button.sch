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
P 9650 1850
F 0 "U2" H 9000 2150 60  0000 C CNN
F 1 "nRF24L01+-Module" H 9650 1850 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9750 1450 60  0001 C CNN
F 3 "" H 9750 1450 60  0000 C CNN
	1    9650 1850
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 5480667B
P 5850 4150
F 0 "SW1" H 6000 4260 50  0000 C CNN
F 1 "SW_PUSH" H 5850 4070 50  0000 C CNN
F 2 "d14b_libs:TACTILE_SW" H 5850 4150 60  0001 C CNN
F 3 "" H 5850 4150 60  0000 C CNN
	1    5850 4150
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 548067BC
P 5850 4450
F 0 "SW2" H 6000 4560 50  0000 C CNN
F 1 "SW_PUSH" H 5850 4370 50  0000 C CNN
F 2 "d14b_libs:TACTILE_SW" H 5850 4450 60  0001 C CNN
F 3 "" H 5850 4450 60  0000 C CNN
	1    5850 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 54806F87
P 9650 2250
F 0 "#PWR01" H 9650 2250 30  0001 C CNN
F 1 "GND" H 9650 2180 30  0001 C CNN
F 2 "" H 9650 2250 60  0000 C CNN
F 3 "" H 9650 2250 60  0000 C CNN
	1    9650 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 548070FB
P 3050 5650
F 0 "#PWR02" H 3050 5650 30  0001 C CNN
F 1 "GND" H 3050 5580 30  0001 C CNN
F 2 "" H 3050 5650 60  0000 C CNN
F 3 "" H 3050 5650 60  0000 C CNN
	1    3050 5650
	1    0    0    -1  
$EndComp
$Comp
L CP2 C2
U 1 1 5480AD1C
P 9250 1200
F 0 "C2" H 9250 1300 40  0000 L CNN
F 1 "10u" H 9256 1115 40  0000 L CNN
F 2 "SMD_Packages:SMD-1206" H 9288 1050 30  0001 C CNN
F 3 "" H 9250 1200 60  0000 C CNN
	1    9250 1200
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5480ADD3
P 8900 1200
F 0 "C1" H 8900 1300 40  0000 L CNN
F 1 "100n" H 8906 1115 40  0000 L CNN
F 2 "SMD_Packages:SMD-1206" H 8938 1050 30  0001 C CNN
F 3 "" H 8900 1200 60  0000 C CNN
	1    8900 1200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5480AE86
P 9250 1400
F 0 "#PWR08" H 9250 1400 30  0001 C CNN
F 1 "GND" H 9250 1330 30  0001 C CNN
F 2 "" H 9250 1400 60  0000 C CNN
F 3 "" H 9250 1400 60  0000 C CNN
	1    9250 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 5480AE99
P 8900 1400
F 0 "#PWR09" H 8900 1400 30  0001 C CNN
F 1 "GND" H 8900 1330 30  0001 C CNN
F 2 "" H 8900 1400 60  0000 C CNN
F 3 "" H 8900 1400 60  0000 C CNN
	1    8900 1400
	1    0    0    -1  
$EndComp
$Comp
L BATTERY BT?
U 1 1 54896B73
P 2900 7000
F 0 "BT?" H 2900 7200 50  0000 C CNN
F 1 "BATTERY" H 2900 6810 50  0000 C CNN
F 2 "" H 2900 7000 60  0000 C CNN
F 3 "" H 2900 7000 60  0000 C CNN
	1    2900 7000
	0    1    1    0   
$EndComp
$Comp
L USB-MICRO-B CON?
U 1 1 54896BA2
P 1550 7150
F 0 "CON?" H 1250 7500 50  0000 C CNN
F 1 "USB-MICRO-B" H 1400 6800 50  0000 C CNN
F 2 "" H 1550 7050 50  0000 C CNN
F 3 "" H 1550 7050 50  0000 C CNN
	1    1550 7150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54896FB7
P 2900 7300
F 0 "#PWR?" H 2900 7300 30  0001 C CNN
F 1 "GND" H 2900 7230 30  0001 C CNN
F 2 "" H 2900 7300 60  0000 C CNN
F 3 "" H 2900 7300 60  0000 C CNN
	1    2900 7300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54896FE4
P 4400 7200
F 0 "#PWR?" H 4400 7200 30  0001 C CNN
F 1 "GND" H 4400 7130 30  0001 C CNN
F 2 "" H 4400 7200 60  0000 C CNN
F 3 "" H 4400 7200 60  0000 C CNN
	1    4400 7200
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54898D66
P 3650 6500
F 0 "C?" H 3650 6600 40  0000 L CNN
F 1 "10 μF" H 3656 6415 40  0000 L CNN
F 2 "" H 3688 6350 30  0000 C CNN
F 3 "" H 3650 6500 60  0000 C CNN
	1    3650 6500
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR_SMALL L?
U 1 1 54898DB7
P 3800 6900
F 0 "L?" H 3800 7000 50  0000 C CNN
F 1 "INDUCTOR_SMALL" H 3800 6850 50  0000 C CNN
F 2 "" H 3800 6900 60  0000 C CNN
F 3 "" H 3800 6900 60  0000 C CNN
	1    3800 6900
	1    0    0    -1  
$EndComp
$Comp
L TPS61221 U?
U 1 1 548991BF
P 4550 6750
F 0 "U?" H 4250 7100 40  0000 C CNN
F 1 "TPS61221" H 4700 7100 40  0000 C CNN
F 2 "SO6" H 4550 6800 35  0000 C CIN
F 3 "" H 4550 6750 60  0000 C CNN
	1    4550 6750
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5489AA0A
P 5650 6900
F 0 "C?" H 5650 7000 40  0000 L CNN
F 1 "10u" H 5656 6815 40  0000 L CNN
F 2 "" H 5688 6750 30  0000 C CNN
F 3 "" H 5650 6900 60  0000 C CNN
	1    5650 6900
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5489AAC5
P 5350 6950
F 0 "R?" V 5430 6950 40  0000 C CNN
F 1 "R" V 5357 6951 40  0000 C CNN
F 2 "" V 5280 6950 30  0000 C CNN
F 3 "" H 5350 6950 30  0000 C CNN
	1    5350 6950
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5489AB22
P 5350 7450
F 0 "R?" V 5430 7450 40  0000 C CNN
F 1 "R" V 5357 7451 40  0000 C CNN
F 2 "" V 5280 7450 30  0000 C CNN
F 3 "" H 5350 7450 30  0000 C CNN
	1    5350 7450
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 5489AB82
P 3650 6300
F 0 "#PWR?" H 3650 6100 40  0001 C CNN
F 1 "GNDPWR" H 3650 6170 40  0000 C CNN
F 2 "" H 3650 6250 60  0000 C CNN
F 3 "" H 3650 6250 60  0000 C CNN
	1    3650 6300
	-1   0    0    1   
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 5489ABB0
P 4700 7200
F 0 "#PWR?" H 4700 7000 40  0001 C CNN
F 1 "GNDPWR" H 4700 7070 40  0000 C CNN
F 2 "" H 4700 7150 60  0000 C CNN
F 3 "" H 4700 7150 60  0000 C CNN
	1    4700 7200
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR?
U 1 1 5489ABC9
P 5650 7100
F 0 "#PWR?" H 5650 6900 40  0001 C CNN
F 1 "GNDPWR" H 5650 6970 40  0000 C CNN
F 2 "" H 5650 7050 60  0000 C CNN
F 3 "" H 5650 7050 60  0000 C CNN
	1    5650 7100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5489AC6B
P 5350 7700
F 0 "#PWR?" H 5350 7700 30  0001 C CNN
F 1 "GND" H 5350 7630 30  0001 C CNN
F 2 "" H 5350 7700 60  0000 C CNN
F 3 "" H 5350 7700 60  0000 C CNN
	1    5350 7700
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X?
U 1 1 54AF9828
P 1000 3550
F 0 "X?" H 1000 3700 60  0000 C CNN
F 1 "8M" H 1000 3400 60  0000 C CNN
F 2 "" H 1000 3550 60  0000 C CNN
F 3 "" H 1000 3550 60  0000 C CNN
	1    1000 3550
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 54AF99C9
P 2800 1350
F 0 "C?" H 2800 1450 40  0000 L CNN
F 1 "100n" H 2806 1265 40  0000 L CNN
F 2 "" H 2838 1200 30  0000 C CNN
F 3 "" H 2800 1350 60  0000 C CNN
	1    2800 1350
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54AF9BEB
P 3800 1350
F 0 "C?" H 3800 1450 40  0000 L CNN
F 1 "10n" H 3806 1265 40  0000 L CNN
F 2 "" H 3838 1200 30  0000 C CNN
F 3 "" H 3800 1350 60  0000 C CNN
	1    3800 1350
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54AF9C52
P 4200 1350
F 0 "C?" H 4200 1450 40  0000 L CNN
F 1 "1u" H 4206 1265 40  0000 L CNN
F 2 "" H 4238 1200 30  0000 C CNN
F 3 "" H 4200 1350 60  0000 C CNN
	1    4200 1350
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54AF9CB4
P 2500 1350
F 0 "C?" H 2500 1450 40  0000 L CNN
F 1 "4.7u" H 2506 1265 40  0000 L CNN
F 2 "" H 2538 1200 30  0000 C CNN
F 3 "" H 2500 1350 60  0000 C CNN
	1    2500 1350
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54AF9D47
P 800 3250
F 0 "C?" H 800 3350 40  0000 L CNN
F 1 "20p" H 806 3165 40  0000 L CNN
F 2 "" H 838 3100 30  0000 C CNN
F 3 "" H 800 3250 60  0000 C CNN
	1    800  3250
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 54AF9DC5
P 800 3850
F 0 "C?" H 800 3950 40  0000 L CNN
F 1 "20p" H 806 3765 40  0000 L CNN
F 2 "" H 838 3700 30  0000 C CNN
F 3 "" H 800 3850 60  0000 C CNN
	1    800  3850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA0D1
P 2500 1550
F 0 "#PWR?" H 2500 1550 30  0001 C CNN
F 1 "GND" H 2500 1480 30  0001 C CNN
F 2 "" H 2500 1550 60  0000 C CNN
F 3 "" H 2500 1550 60  0000 C CNN
	1    2500 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA18C
P 2800 1550
F 0 "#PWR?" H 2800 1550 30  0001 C CNN
F 1 "GND" H 2800 1480 30  0001 C CNN
F 2 "" H 2800 1550 60  0000 C CNN
F 3 "" H 2800 1550 60  0000 C CNN
	1    2800 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA1CD
P 3800 1550
F 0 "#PWR?" H 3800 1550 30  0001 C CNN
F 1 "GND" H 3800 1480 30  0001 C CNN
F 2 "" H 3800 1550 60  0000 C CNN
F 3 "" H 3800 1550 60  0000 C CNN
	1    3800 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA1EE
P 4200 1550
F 0 "#PWR?" H 4200 1550 30  0001 C CNN
F 1 "GND" H 4200 1480 30  0001 C CNN
F 2 "" H 4200 1550 60  0000 C CNN
F 3 "" H 4200 1550 60  0000 C CNN
	1    4200 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFA49B
P 600 3550
F 0 "#PWR?" H 600 3550 30  0001 C CNN
F 1 "GND" H 600 3480 30  0001 C CNN
F 2 "" H 600 3550 60  0000 C CNN
F 3 "" H 600 3550 60  0000 C CNN
	1    600  3550
	0    1    1    0   
$EndComp
$Comp
L CONN_02X10 P?
U 1 1 54AFAC94
P 9500 3800
F 0 "P?" H 9500 4350 50  0000 C CNN
F 1 "CONN_02X10" V 9500 3800 50  0000 C CNN
F 2 "" H 9500 2600 60  0000 C CNN
F 3 "" H 9500 2600 60  0000 C CNN
	1    9500 3800
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 54AFBA14
P 5600 2450
F 0 "R?" V 5680 2450 40  0000 C CNN
F 1 "R" V 5607 2451 40  0000 C CNN
F 2 "" V 5530 2450 30  0000 C CNN
F 3 "" H 5600 2450 30  0000 C CNN
	1    5600 2450
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 54AFBB0B
P 5600 2250
F 0 "R?" V 5680 2250 40  0000 C CNN
F 1 "R" V 5607 2251 40  0000 C CNN
F 2 "" V 5530 2250 30  0000 C CNN
F 3 "" H 5600 2250 30  0000 C CNN
	1    5600 2250
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 54AFBB5E
P 5600 2050
F 0 "R?" V 5680 2050 40  0000 C CNN
F 1 "R" V 5607 2051 40  0000 C CNN
F 2 "" V 5530 2050 30  0000 C CNN
F 3 "" H 5600 2050 30  0000 C CNN
	1    5600 2050
	0    1    1    0   
$EndComp
$Comp
L LED_RCBG D?
U 1 1 54AFC019
P 6150 2250
F 0 "D?" H 6075 2600 50  0000 C CNN
F 1 "LED_RCBG" H 6125 1900 50  0000 C CNN
F 2 "" H 6150 2200 50  0000 C CNN
F 3 "" H 6150 2200 50  0000 C CNN
	1    6150 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFD92F
P 6450 2250
F 0 "#PWR?" H 6450 2250 30  0001 C CNN
F 1 "GND" H 6450 2180 30  0001 C CNN
F 2 "" H 6450 2250 60  0000 C CNN
F 3 "" H 6450 2250 60  0000 C CNN
	1    6450 2250
	0    -1   -1   0   
$EndComp
$Comp
L STM32F050C6 U?
U 1 1 54AFE9EC
P 3200 3650
F 0 "U?" H 1700 5550 60  0000 C CNN
F 1 "STM32F050C6" H 4450 1750 60  0000 C CNN
F 2 "LQFP48" H 3200 3650 40  0000 C CIN
F 3 "" H 3200 3650 60  0000 C CNN
	1    3200 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B01216
P 3200 5650
F 0 "#PWR?" H 3200 5650 30  0001 C CNN
F 1 "GND" H 3200 5580 30  0001 C CNN
F 2 "" H 3200 5650 60  0000 C CNN
F 3 "" H 3200 5650 60  0000 C CNN
	1    3200 5650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B0123C
P 3500 5650
F 0 "#PWR?" H 3500 5650 30  0001 C CNN
F 1 "GND" H 3500 5580 30  0001 C CNN
F 2 "" H 3500 5650 60  0000 C CNN
F 3 "" H 3500 5650 60  0000 C CNN
	1    3500 5650
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 54B015E8
P 2250 1350
F 0 "C?" H 2250 1450 40  0000 L CNN
F 1 "100n" H 2256 1265 40  0000 L CNN
F 2 "" H 2288 1200 30  0000 C CNN
F 3 "" H 2250 1350 60  0000 C CNN
	1    2250 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B01667
P 2250 1550
F 0 "#PWR?" H 2250 1550 30  0001 C CNN
F 1 "GND" H 2250 1480 30  0001 C CNN
F 2 "" H 2250 1550 60  0000 C CNN
F 3 "" H 2250 1550 60  0000 C CNN
	1    2250 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 54B083E9
P 9750 4450
F 0 "#PWR?" H 9750 4450 30  0001 C CNN
F 1 "GND" H 9750 4380 30  0001 C CNN
F 2 "" H 9750 4450 60  0000 C CNN
F 3 "" H 9750 4450 60  0000 C CNN
	1    9750 4450
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 54B0890E
P 1250 3850
F 0 "R?" V 1330 3850 40  0000 C CNN
F 1 "0" V 1257 3851 40  0000 C CNN
F 2 "" V 1180 3850 30  0000 C CNN
F 3 "" H 1250 3850 30  0000 C CNN
	1    1250 3850
	0    -1   1    0   
$EndComp
$Comp
L CRYSTAL X?
U 1 1 54B0A562
P 1000 4650
F 0 "X?" H 1000 4800 60  0000 C CNN
F 1 "32.768k" H 1000 4500 60  0000 C CNN
F 2 "" H 1000 4650 60  0000 C CNN
F 3 "" H 1000 4650 60  0000 C CNN
	1    1000 4650
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 54B0A568
P 800 4350
F 0 "C?" H 800 4450 40  0000 L CNN
F 1 "10p" H 806 4265 40  0000 L CNN
F 2 "" H 838 4200 30  0000 C CNN
F 3 "" H 800 4350 60  0000 C CNN
	1    800  4350
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 54B0A56E
P 800 4950
F 0 "C?" H 800 5050 40  0000 L CNN
F 1 "10p" H 806 4865 40  0000 L CNN
F 2 "" H 838 4800 30  0000 C CNN
F 3 "" H 800 4950 60  0000 C CNN
	1    800  4950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 54B0A574
P 600 4650
F 0 "#PWR?" H 600 4650 30  0001 C CNN
F 1 "GND" H 600 4580 30  0001 C CNN
F 2 "" H 600 4650 60  0000 C CNN
F 3 "" H 600 4650 60  0000 C CNN
	1    600  4650
	0    1    1    0   
$EndComp
$Comp
L JUMPER3 JP?
U 1 1 54AFD79C
P 900 2200
F 0 "JP?" H 950 2100 40  0000 L CNN
F 1 "JUMPER3" H 900 2300 40  0000 C CNN
F 2 "" H 900 2200 60  0000 C CNN
F 3 "" H 900 2200 60  0000 C CNN
	1    900  2200
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 54AFD7FD
P 1250 2200
F 0 "R?" V 1330 2200 40  0000 C CNN
F 1 "10k" V 1257 2201 40  0000 C CNN
F 2 "" V 1180 2200 30  0000 C CNN
F 3 "" H 1250 2200 30  0000 C CNN
	1    1250 2200
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 54AFD975
P 900 2450
F 0 "#PWR?" H 900 2200 60  0001 C CNN
F 1 "GND" H 900 2300 60  0000 C CNN
F 2 "" H 900 2450 60  0000 C CNN
F 3 "" H 900 2450 60  0000 C CNN
	1    900  2450
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFD989
P 900 1950
F 0 "#PWR?" H 900 1800 60  0001 C CNN
F 1 "+3V3" H 900 2090 60  0000 C CNN
F 2 "" H 900 1950 60  0000 C CNN
F 3 "" H 900 1950 60  0000 C CNN
	1    900  1950
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFDA66
P 2250 1150
F 0 "#PWR?" H 2250 1000 60  0001 C CNN
F 1 "+3V3" H 2250 1290 60  0000 C CNN
F 2 "" H 2250 1150 60  0000 C CNN
F 3 "" H 2250 1150 60  0000 C CNN
	1    2250 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFDA99
P 2500 1150
F 0 "#PWR?" H 2500 1000 60  0001 C CNN
F 1 "+3V3" H 2500 1290 60  0000 C CNN
F 2 "" H 2500 1150 60  0000 C CNN
F 3 "" H 2500 1150 60  0000 C CNN
	1    2500 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFDAC5
P 2800 1150
F 0 "#PWR?" H 2800 1000 60  0001 C CNN
F 1 "+3V3" H 2800 1290 60  0000 C CNN
F 2 "" H 2800 1150 60  0000 C CNN
F 3 "" H 2800 1150 60  0000 C CNN
	1    2800 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE3DB
P 3050 1650
F 0 "#PWR?" H 3050 1500 60  0001 C CNN
F 1 "+3V3" H 3050 1790 60  0000 C CNN
F 2 "" H 3050 1650 60  0000 C CNN
F 3 "" H 3050 1650 60  0000 C CNN
	1    3050 1650
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE407
P 3200 1650
F 0 "#PWR?" H 3200 1500 60  0001 C CNN
F 1 "+3V3" H 3200 1790 60  0000 C CNN
F 2 "" H 3200 1650 60  0000 C CNN
F 3 "" H 3200 1650 60  0000 C CNN
	1    3200 1650
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE433
P 3500 1650
F 0 "#PWR?" H 3500 1500 60  0001 C CNN
F 1 "+3V3" H 3500 1790 60  0000 C CNN
F 2 "" H 3500 1650 60  0000 C CNN
F 3 "" H 3500 1650 60  0000 C CNN
	1    3500 1650
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE45F
P 3800 1150
F 0 "#PWR?" H 3800 1000 60  0001 C CNN
F 1 "+3V3" H 3800 1290 60  0000 C CNN
F 2 "" H 3800 1150 60  0000 C CNN
F 3 "" H 3800 1150 60  0000 C CNN
	1    3800 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE48B
P 4200 1150
F 0 "#PWR?" H 4200 1000 60  0001 C CNN
F 1 "+3V3" H 4200 1290 60  0000 C CNN
F 2 "" H 4200 1150 60  0000 C CNN
F 3 "" H 4200 1150 60  0000 C CNN
	1    4200 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE5A1
P 6150 3850
F 0 "#PWR?" H 6150 3700 60  0001 C CNN
F 1 "+3V3" H 6150 3990 60  0000 C CNN
F 2 "" H 6150 3850 60  0000 C CNN
F 3 "" H 6150 3850 60  0000 C CNN
	1    6150 3850
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE8D8
P 8900 1000
F 0 "#PWR?" H 8900 850 60  0001 C CNN
F 1 "+3V3" H 8900 1140 60  0000 C CNN
F 2 "" H 8900 1000 60  0000 C CNN
F 3 "" H 8900 1000 60  0000 C CNN
	1    8900 1000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE90B
P 9250 1000
F 0 "#PWR?" H 9250 850 60  0001 C CNN
F 1 "+3V3" H 9250 1140 60  0000 C CNN
F 2 "" H 9250 1000 60  0000 C CNN
F 3 "" H 9250 1000 60  0000 C CNN
	1    9250 1000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFE9BC
P 9650 1450
F 0 "#PWR?" H 9650 1300 60  0001 C CNN
F 1 "+3V3" H 9650 1590 60  0000 C CNN
F 2 "" H 9650 1450 60  0000 C CNN
F 3 "" H 9650 1450 60  0000 C CNN
	1    9650 1450
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFEB56
P 8450 3250
F 0 "#PWR?" H 8450 3100 60  0001 C CNN
F 1 "+3V3" H 8450 3390 60  0000 C CNN
F 2 "" H 8450 3250 60  0000 C CNN
F 3 "" H 8450 3250 60  0000 C CNN
	1    8450 3250
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54AFEE44
P 6000 6700
F 0 "#PWR?" H 6000 6550 60  0001 C CNN
F 1 "+3V3" H 6000 6840 60  0000 C CNN
F 2 "" H 6000 6700 60  0000 C CNN
F 3 "" H 6000 6700 60  0000 C CNN
	1    6000 6700
	1    0    0    -1  
$EndComp
Text Label 1500 2500 2    60   ~ 0
VBAT
$Comp
L C C?
U 1 1 54AFFDE5
P 1200 1350
F 0 "C?" H 1200 1450 40  0000 L CNN
F 1 "100n" H 1206 1265 40  0000 L CNN
F 2 "" H 1238 1200 30  0000 C CNN
F 3 "" H 1200 1350 60  0000 C CNN
	1    1200 1350
	1    0    0    -1  
$EndComp
Text Label 1200 1150 2    60   ~ 0
VBAT
$Comp
L GND #PWR?
U 1 1 54B00473
P 1200 1550
F 0 "#PWR?" H 1200 1300 60  0001 C CNN
F 1 "GND" H 1200 1400 60  0000 C CNN
F 2 "" H 1200 1550 60  0000 C CNN
F 3 "" H 1200 1550 60  0000 C CNN
	1    1200 1550
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 54B00744
P 1450 1150
F 0 "R?" V 1530 1150 40  0000 C CNN
F 1 "0" V 1457 1151 40  0000 C CNN
F 2 "" V 1380 1150 30  0000 C CNN
F 3 "" H 1450 1150 30  0000 C CNN
	1    1450 1150
	0    1    1    0   
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 54B00899
P 1700 1150
F 0 "#PWR?" H 1700 1000 60  0001 C CNN
F 1 "+3V3" H 1700 1290 60  0000 C CNN
F 2 "" H 1700 1150 60  0000 C CNN
F 3 "" H 1700 1150 60  0000 C CNN
	1    1700 1150
	1    0    0    -1  
$EndComp
Connection ~ 6150 4150
Connection ~ 6150 4450
Wire Wire Line
	2900 6700 4050 6700
Wire Wire Line
	3900 6700 3900 6500
Wire Wire Line
	3900 6500 4050 6500
Connection ~ 3900 6700
Wire Wire Line
	3550 6900 3450 6900
Wire Wire Line
	3450 6900 3450 6700
Connection ~ 3450 6700
Wire Wire Line
	5050 6700 6000 6700
Wire Wire Line
	5050 6900 5050 7200
Wire Wire Line
	5050 7200 5350 7200
Wire Wire Line
	4400 7200 4700 7200
Wire Wire Line
	4550 7200 4550 7100
Connection ~ 4550 7200
Wire Wire Line
	600  3250 600  3850
Connection ~ 600  3550
Wire Wire Line
	4900 2150 5350 2150
Wire Wire Line
	5350 2150 5350 2050
Wire Wire Line
	4900 2250 5350 2250
Wire Wire Line
	4900 2350 5350 2350
Wire Wire Line
	5350 2350 5350 2450
Wire Wire Line
	9750 3450 9750 4450
Connection ~ 9750 3550
Connection ~ 9750 3650
Connection ~ 9750 3750
Connection ~ 9750 3850
Connection ~ 9750 3950
Connection ~ 9750 4050
Connection ~ 9750 4150
Connection ~ 9750 4250
Connection ~ 9750 3450
Wire Wire Line
	600  4350 600  4950
Connection ~ 600  4650
Wire Wire Line
	1000 4350 1500 4350
Wire Wire Line
	1200 4950 1000 4950
Wire Wire Line
	8450 3350 9250 3350
Wire Wire Line
	1000 3250 1200 3250
Wire Wire Line
	1200 3250 1200 3750
Wire Wire Line
	1200 3750 1500 3750
Wire Wire Line
	1500 4450 1200 4450
Wire Wire Line
	1200 4450 1200 4950
Text Label 10750 1700 2    60   ~ 0
SCK
Text Label 10750 1850 2    60   ~ 0
MOSI
Text Label 10750 2000 2    60   ~ 0
MISO
Text Label 8500 1700 0    60   ~ 0
CE
Text Label 8500 1850 0    60   ~ 0
CSN
Text Label 8500 2000 0    60   ~ 0
IRQ
Text Label 5250 2550 2    60   ~ 0
SCK
Text Label 5250 2650 2    60   ~ 0
MISO
Text Label 5250 2750 2    60   ~ 0
MOSI
Text Label 5250 3750 2    60   ~ 0
CE
Text Label 5250 3850 2    60   ~ 0
CSN
Text Label 5250 3950 2    60   ~ 0
IRQ
Wire Wire Line
	4900 2550 5250 2550
Wire Wire Line
	4900 2650 5250 2650
Wire Wire Line
	4900 2750 5250 2750
Wire Wire Line
	4900 3750 5250 3750
Wire Wire Line
	4900 3850 5250 3850
Wire Wire Line
	4900 3950 5250 3950
Wire Wire Line
	8500 1700 8750 1700
Wire Wire Line
	8500 1850 8750 1850
Wire Wire Line
	8500 2000 8750 2000
Wire Wire Line
	10500 1700 10750 1700
Wire Wire Line
	10500 1850 10750 1850
Wire Wire Line
	10500 2000 10750 2000
Text Notes 1050 750  0    120  ~ 0
STM32F0
Text Notes 8600 750  0    120  ~ 0
NRF24L01
Text Notes 8700 3000 0    120  ~ 0
SWD
Text Notes 1200 6450 0    120  ~ 0
PSU
Text Notes 5450 6400 0    120  ~ 0
TODO\nPSU überarbeiten\nµC komplett beschalten\nSWD/JTAG auch mit RESET beschalten\nTaster für RESET
Text Notes 8750 5000 0    120  ~ 0
UART\n
$Comp
L CONN_01X03 P?
U 1 1 54B08A26
P 9500 5400
F 0 "P?" H 9500 5600 50  0000 C CNN
F 1 "CONN_01X03" V 9600 5400 50  0000 C CNN
F 2 "" H 9500 5400 60  0000 C CNN
F 3 "" H 9500 5400 60  0000 C CNN
	1    9500 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 5300 9300 5300
Wire Wire Line
	8900 5400 9300 5400
Text Label 8900 5300 0    60   ~ 0
UARTRX
Text Label 8900 5400 0    60   ~ 0
UARTTX
$Comp
L GND #PWR?
U 1 1 54B08EA3
P 9300 5500
F 0 "#PWR?" H 9300 5250 60  0001 C CNN
F 1 "GND" H 9300 5350 60  0000 C CNN
F 2 "" H 9300 5500 60  0000 C CNN
F 3 "" H 9300 5500 60  0000 C CNN
	1    9300 5500
	1    0    0    -1  
$EndComp
Text Label 5250 3050 2    60   ~ 0
UARTRX
Text Label 5250 2950 2    60   ~ 0
UARTTX
Wire Wire Line
	5250 2950 4900 2950
Wire Wire Line
	4900 3050 5250 3050
Text Label 5250 3350 2    60   ~ 0
SWDIO
Text Label 5250 3450 2    60   ~ 0
SWCLK
Wire Wire Line
	5250 3350 4900 3350
Wire Wire Line
	4900 3450 5250 3450
$Comp
L ZENERsmall D?
U 1 1 54B0A648
P 8450 3450
F 0 "D?" H 8450 3550 40  0000 C CNN
F 1 "Z5V1" H 8450 3350 30  0000 C CNN
F 2 "" H 8450 3450 60  0000 C CNN
F 3 "" H 8450 3450 60  0000 C CNN
	1    8450 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8450 3250 8450 3350
$Comp
L GND #PWR?
U 1 1 54B0A8DC
P 8450 3550
F 0 "#PWR?" H 8450 3550 30  0001 C CNN
F 1 "GND" H 8450 3480 30  0001 C CNN
F 2 "" H 8450 3550 60  0000 C CNN
F 3 "" H 8450 3550 60  0000 C CNN
	1    8450 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 3650 8600 3650
Text Label 8600 3650 0    60   ~ 0
SWDIO
Text Label 8900 3750 0    60   ~ 0
SWCLK
$Comp
L ZENERsmall D?
U 1 1 54B0AD67
P 8600 3750
F 0 "D?" H 8600 3850 40  0000 C CNN
F 1 "Z5V1" H 8600 3650 30  0000 C CNN
F 2 "" H 8600 3750 60  0000 C CNN
F 3 "" H 8600 3750 60  0000 C CNN
	1    8600 3750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 54B0AD6D
P 8600 3850
F 0 "#PWR?" H 8600 3850 30  0001 C CNN
F 1 "GND" H 8600 3780 30  0001 C CNN
F 2 "" H 8600 3850 60  0000 C CNN
F 3 "" H 8600 3850 60  0000 C CNN
	1    8600 3850
	1    0    0    -1  
$EndComp
$Comp
L ZENERsmall D?
U 1 1 54B0ADD7
P 8900 3850
F 0 "D?" H 8900 3950 40  0000 C CNN
F 1 "Z5V1" H 8900 3750 30  0000 C CNN
F 2 "" H 8900 3850 60  0000 C CNN
F 3 "" H 8900 3850 60  0000 C CNN
	1    8900 3850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 54B0ADDD
P 8900 3950
F 0 "#PWR?" H 8900 3950 30  0001 C CNN
F 1 "GND" H 8900 3880 30  0001 C CNN
F 2 "" H 8900 3950 60  0000 C CNN
F 3 "" H 8900 3950 60  0000 C CNN
	1    8900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 3750 9250 3750
NoConn ~ 9750 3350
NoConn ~ 9250 4150
NoConn ~ 9250 4250
$Comp
L SW_PUSH SW?
U 1 1 54B0F915
P 5850 4750
F 0 "SW?" H 6000 4860 50  0000 C CNN
F 1 "SW_PUSH" H 5850 4670 50  0000 C CNN
F 2 "d14b_libs:TACTILE_SW" H 5850 4750 60  0001 C CNN
F 3 "" H 5850 4750 60  0000 C CNN
	1    5850 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3850 6150 4750
Wire Wire Line
	4900 4150 5550 4150
Wire Wire Line
	4900 4250 5550 4250
Wire Wire Line
	5550 4250 5550 4450
Wire Wire Line
	4900 4350 5450 4350
Wire Wire Line
	5450 4350 5450 4750
Wire Wire Line
	5450 4750 5550 4750
$EndSCHEMATC

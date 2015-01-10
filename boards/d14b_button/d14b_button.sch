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
Title "Cowbus Demoboard (Schaltermodul)"
Date "Fr 09 Jan 2015"
Rev "2"
Comp "https://michz.github.io/diy14bus/"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L nRF24L01+-Module U1
U 1 1 5480655E
P 9650 1850
F 0 "U1" H 9000 2150 60  0000 C CNN
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
F 2 "TonisLibrary:Button_SMD_Schurter_LSG" H 5850 4150 60  0001 C CNN
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
F 2 "TonisLibrary:Button_SMD_Schurter_LSG" H 5850 4450 60  0001 C CNN
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
F 2 "Capacitors_SMD:c_elec_4x5.8" H 9288 1050 30  0001 C CNN
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
F 2 "Capacitors_SMD:C_0603" H 8938 1050 30  0001 C CNN
F 3 "" H 8900 1200 60  0000 C CNN
	1    8900 1200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 5480AE86
P 9250 1400
F 0 "#PWR03" H 9250 1400 30  0001 C CNN
F 1 "GND" H 9250 1330 30  0001 C CNN
F 2 "" H 9250 1400 60  0000 C CNN
F 3 "" H 9250 1400 60  0000 C CNN
	1    9250 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 5480AE99
P 8900 1400
F 0 "#PWR04" H 8900 1400 30  0001 C CNN
F 1 "GND" H 8900 1330 30  0001 C CNN
F 2 "" H 8900 1400 60  0000 C CNN
F 3 "" H 8900 1400 60  0000 C CNN
	1    8900 1400
	1    0    0    -1  
$EndComp
$Comp
L BATTERY BT1
U 1 1 54896B73
P 2600 7250
F 0 "BT1" H 2600 7450 50  0000 C CNN
F 1 "BATTERY" H 2600 7060 50  0000 C CNN
F 2 "" H 2600 7250 60  0001 C CNN
F 3 "" H 2600 7250 60  0000 C CNN
	1    2600 7250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR05
U 1 1 54896FB7
P 3500 6850
F 0 "#PWR05" H 3500 6850 30  0001 C CNN
F 1 "GND" H 3500 6780 30  0001 C CNN
F 2 "" H 3500 6850 60  0000 C CNN
F 3 "" H 3500 6850 60  0000 C CNN
	1    3500 6850
	1    0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 54898D66
P 3500 6650
F 0 "C15" H 3500 6750 40  0000 L CNN
F 1 "10u" H 3506 6565 40  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3538 6500 30  0001 C CNN
F 3 "" H 3500 6650 60  0000 C CNN
	1    3500 6650
	1    0    0    -1  
$EndComp
$Comp
L INDUCTOR_SMALL L1
U 1 1 54898DB7
P 4000 6650
F 0 "L1" H 4000 6750 50  0000 C CNN
F 1 "4.7u" H 4000 6600 50  0000 C CNN
F 2 "" H 4000 6650 60  0001 C CNN
F 3 "" H 4000 6650 60  0000 C CNN
	1    4000 6650
	1    0    0    -1  
$EndComp
$Comp
L TPS61221 U3
U 1 1 548991BF
P 4750 6500
F 0 "U3" H 4450 6850 40  0000 C CNN
F 1 "TPS61221" H 4900 6850 40  0000 C CNN
F 2 "" H 4750 6550 35  0001 C CIN
F 3 "" H 4750 6500 60  0000 C CNN
	1    4750 6500
	1    0    0    -1  
$EndComp
$Comp
L C C16
U 1 1 5489AA0A
P 5850 6650
F 0 "C16" H 5850 6750 40  0000 L CNN
F 1 "10u" H 5856 6565 40  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5888 6500 30  0001 C CNN
F 3 "" H 5850 6650 60  0000 C CNN
	1    5850 6650
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 54AF9828
P 1000 3550
F 0 "X1" H 1000 3700 60  0000 C CNN
F 1 "8M" H 1000 3400 60  0000 C CNN
F 2 "" H 1000 3550 60  0001 C CNN
F 3 "" H 1000 3550 60  0000 C CNN
	1    1000 3550
	0    -1   -1   0   
$EndComp
$Comp
L C C6
U 1 1 54AF99C9
P 2800 1350
F 0 "C6" H 2800 1450 40  0000 L CNN
F 1 "100n" H 2806 1265 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2838 1200 30  0001 C CNN
F 3 "" H 2800 1350 60  0000 C CNN
	1    2800 1350
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 54AF9BEB
P 3800 1350
F 0 "C7" H 3800 1450 40  0000 L CNN
F 1 "10n" H 3806 1265 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 3838 1200 30  0001 C CNN
F 3 "" H 3800 1350 60  0000 C CNN
	1    3800 1350
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 54AF9D47
P 800 3250
F 0 "C9" H 800 3350 40  0000 L CNN
F 1 "20p" H 806 3165 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 838 3100 30  0001 C CNN
F 3 "" H 800 3250 60  0000 C CNN
	1    800  3250
	0    -1   -1   0   
$EndComp
$Comp
L C C10
U 1 1 54AF9DC5
P 800 3850
F 0 "C10" H 800 3950 40  0000 L CNN
F 1 "20p" H 806 3765 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 838 3700 30  0001 C CNN
F 3 "" H 800 3850 60  0000 C CNN
	1    800  3850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR06
U 1 1 54AFA0D1
P 2500 1550
F 0 "#PWR06" H 2500 1550 30  0001 C CNN
F 1 "GND" H 2500 1480 30  0001 C CNN
F 2 "" H 2500 1550 60  0000 C CNN
F 3 "" H 2500 1550 60  0000 C CNN
	1    2500 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 54AFA18C
P 2800 1550
F 0 "#PWR07" H 2800 1550 30  0001 C CNN
F 1 "GND" H 2800 1480 30  0001 C CNN
F 2 "" H 2800 1550 60  0000 C CNN
F 3 "" H 2800 1550 60  0000 C CNN
	1    2800 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 54AFA1CD
P 3800 1550
F 0 "#PWR08" H 3800 1550 30  0001 C CNN
F 1 "GND" H 3800 1480 30  0001 C CNN
F 2 "" H 3800 1550 60  0000 C CNN
F 3 "" H 3800 1550 60  0000 C CNN
	1    3800 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 54AFA1EE
P 4200 1550
F 0 "#PWR09" H 4200 1550 30  0001 C CNN
F 1 "GND" H 4200 1480 30  0001 C CNN
F 2 "" H 4200 1550 60  0000 C CNN
F 3 "" H 4200 1550 60  0000 C CNN
	1    4200 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 54AFA49B
P 600 3550
F 0 "#PWR010" H 600 3550 30  0001 C CNN
F 1 "GND" H 600 3480 30  0001 C CNN
F 2 "" H 600 3550 60  0000 C CNN
F 3 "" H 600 3550 60  0000 C CNN
	1    600  3550
	0    1    1    0   
$EndComp
$Comp
L CONN_02X10 P1
U 1 1 54AFAC94
P 9450 3300
F 0 "P1" H 9450 3850 50  0000 C CNN
F 1 "CONN_02X10" V 9450 3300 50  0000 C CNN
F 2 "Connect:VASCH10x2" H 9450 2100 60  0001 C CNN
F 3 "" H 9450 2100 60  0000 C CNN
	1    9450 3300
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 54AFBA14
P 5600 2250
F 0 "R5" V 5680 2250 40  0000 C CNN
F 1 "680" V 5607 2251 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5530 2250 30  0001 C CNN
F 3 "" H 5600 2250 30  0000 C CNN
	1    5600 2250
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 54AFBB0B
P 5600 2050
F 0 "R3" V 5680 2050 40  0000 C CNN
F 1 "510" V 5607 2051 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5530 2050 30  0001 C CNN
F 3 "" H 5600 2050 30  0000 C CNN
	1    5600 2050
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 54AFBB5E
P 5600 1850
F 0 "R2" V 5680 1850 40  0000 C CNN
F 1 "680" V 5607 1851 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5530 1850 30  0001 C CNN
F 3 "" H 5600 1850 30  0000 C CNN
	1    5600 1850
	0    1    1    0   
$EndComp
$Comp
L LED_RCBG D1
U 1 1 54AFC019
P 6150 2050
F 0 "D1" H 6075 2400 50  0000 C CNN
F 1 "LED_RCBG" H 6125 1700 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x02" H 6150 2000 50  0001 C CNN
F 3 "" H 6150 2000 50  0000 C CNN
	1    6150 2050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 54AFD92F
P 6600 2600
F 0 "#PWR011" H 6600 2600 30  0001 C CNN
F 1 "GND" H 6600 2530 30  0001 C CNN
F 2 "" H 6600 2600 60  0000 C CNN
F 3 "" H 6600 2600 60  0000 C CNN
	1    6600 2600
	1    0    0    -1  
$EndComp
$Comp
L STM32F050C6 U2
U 1 1 54AFE9EC
P 3200 3650
F 0 "U2" H 1700 5550 60  0000 C CNN
F 1 "STM32F050C6" H 4450 1750 60  0000 C CNN
F 2 "Housings_QFP:LQFP-48_7x7mm_Pitch0.5mm" H 3200 3650 40  0000 C CIN
F 3 "" H 3200 3650 60  0000 C CNN
	1    3200 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 54B01216
P 3200 5650
F 0 "#PWR012" H 3200 5650 30  0001 C CNN
F 1 "GND" H 3200 5580 30  0001 C CNN
F 2 "" H 3200 5650 60  0000 C CNN
F 3 "" H 3200 5650 60  0000 C CNN
	1    3200 5650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 54B0123C
P 3500 5650
F 0 "#PWR013" H 3500 5650 30  0001 C CNN
F 1 "GND" H 3500 5580 30  0001 C CNN
F 2 "" H 3500 5650 60  0000 C CNN
F 3 "" H 3500 5650 60  0000 C CNN
	1    3500 5650
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 54B015E8
P 2250 1350
F 0 "C4" H 2250 1450 40  0000 L CNN
F 1 "100n" H 2256 1265 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 2288 1200 30  0001 C CNN
F 3 "" H 2250 1350 60  0000 C CNN
	1    2250 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 54B01667
P 2250 1550
F 0 "#PWR014" H 2250 1550 30  0001 C CNN
F 1 "GND" H 2250 1480 30  0001 C CNN
F 2 "" H 2250 1550 60  0000 C CNN
F 3 "" H 2250 1550 60  0000 C CNN
	1    2250 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 54B083E9
P 9700 3950
F 0 "#PWR015" H 9700 3950 30  0001 C CNN
F 1 "GND" H 9700 3880 30  0001 C CNN
F 2 "" H 9700 3950 60  0000 C CNN
F 3 "" H 9700 3950 60  0000 C CNN
	1    9700 3950
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 54B0890E
P 1250 3850
F 0 "R7" V 1330 3850 40  0000 C CNN
F 1 "0" V 1257 3851 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1180 3850 30  0001 C CNN
F 3 "" H 1250 3850 30  0000 C CNN
	1    1250 3850
	0    -1   1    0   
$EndComp
$Comp
L CRYSTAL X2
U 1 1 54B0A562
P 1000 4650
F 0 "X2" H 1000 4800 60  0000 C CNN
F 1 "32.768k" H 1000 4500 60  0000 C CNN
F 2 "" H 1000 4650 60  0001 C CNN
F 3 "" H 1000 4650 60  0000 C CNN
	1    1000 4650
	0    -1   -1   0   
$EndComp
$Comp
L C C11
U 1 1 54B0A568
P 800 4350
F 0 "C11" H 800 4450 40  0000 L CNN
F 1 "10p" H 806 4265 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 838 4200 30  0001 C CNN
F 3 "" H 800 4350 60  0000 C CNN
	1    800  4350
	0    1    1    0   
$EndComp
$Comp
L C C13
U 1 1 54B0A56E
P 800 4950
F 0 "C13" H 800 5050 40  0000 L CNN
F 1 "10p" H 806 4865 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 838 4800 30  0001 C CNN
F 3 "" H 800 4950 60  0000 C CNN
	1    800  4950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR016
U 1 1 54B0A574
P 600 4650
F 0 "#PWR016" H 600 4650 30  0001 C CNN
F 1 "GND" H 600 4580 30  0001 C CNN
F 2 "" H 600 4650 60  0000 C CNN
F 3 "" H 600 4650 60  0000 C CNN
	1    600  4650
	0    1    1    0   
$EndComp
$Comp
L JUMPER3 JP1
U 1 1 54AFD79C
P 900 2200
F 0 "JP1" H 950 2100 40  0000 L CNN
F 1 "JUMPER3" H 900 2300 40  0000 C CNN
F 2 "Connect:GS3" H 900 2200 60  0001 C CNN
F 3 "" H 900 2200 60  0000 C CNN
	1    900  2200
	0    -1   -1   0   
$EndComp
$Comp
L R R4
U 1 1 54AFD7FD
P 1250 2200
F 0 "R4" V 1330 2200 40  0000 C CNN
F 1 "10k" V 1257 2201 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1180 2200 30  0001 C CNN
F 3 "" H 1250 2200 30  0000 C CNN
	1    1250 2200
	0    1    1    0   
$EndComp
$Comp
L GND #PWR017
U 1 1 54AFD975
P 900 2450
F 0 "#PWR017" H 900 2200 60  0001 C CNN
F 1 "GND" H 900 2300 60  0000 C CNN
F 2 "" H 900 2450 60  0000 C CNN
F 3 "" H 900 2450 60  0000 C CNN
	1    900  2450
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR018
U 1 1 54AFD989
P 900 1950
F 0 "#PWR018" H 900 1800 60  0001 C CNN
F 1 "+3V3" H 900 2090 60  0000 C CNN
F 2 "" H 900 1950 60  0000 C CNN
F 3 "" H 900 1950 60  0000 C CNN
	1    900  1950
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR019
U 1 1 54AFDA66
P 2250 1150
F 0 "#PWR019" H 2250 1000 60  0001 C CNN
F 1 "+3V3" H 2250 1290 60  0000 C CNN
F 2 "" H 2250 1150 60  0000 C CNN
F 3 "" H 2250 1150 60  0000 C CNN
	1    2250 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR020
U 1 1 54AFDA99
P 2500 1150
F 0 "#PWR020" H 2500 1000 60  0001 C CNN
F 1 "+3V3" H 2500 1290 60  0000 C CNN
F 2 "" H 2500 1150 60  0000 C CNN
F 3 "" H 2500 1150 60  0000 C CNN
	1    2500 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR021
U 1 1 54AFDAC5
P 2800 1150
F 0 "#PWR021" H 2800 1000 60  0001 C CNN
F 1 "+3V3" H 2800 1290 60  0000 C CNN
F 2 "" H 2800 1150 60  0000 C CNN
F 3 "" H 2800 1150 60  0000 C CNN
	1    2800 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR022
U 1 1 54AFE3DB
P 3050 1650
F 0 "#PWR022" H 3050 1500 60  0001 C CNN
F 1 "+3V3" H 3050 1790 60  0000 C CNN
F 2 "" H 3050 1650 60  0000 C CNN
F 3 "" H 3050 1650 60  0000 C CNN
	1    3050 1650
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR023
U 1 1 54AFE407
P 3200 1650
F 0 "#PWR023" H 3200 1500 60  0001 C CNN
F 1 "+3V3" H 3200 1790 60  0000 C CNN
F 2 "" H 3200 1650 60  0000 C CNN
F 3 "" H 3200 1650 60  0000 C CNN
	1    3200 1650
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR024
U 1 1 54AFE433
P 3500 1650
F 0 "#PWR024" H 3500 1500 60  0001 C CNN
F 1 "+3V3" H 3500 1790 60  0000 C CNN
F 2 "" H 3500 1650 60  0000 C CNN
F 3 "" H 3500 1650 60  0000 C CNN
	1    3500 1650
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR025
U 1 1 54AFE45F
P 3800 1150
F 0 "#PWR025" H 3800 1000 60  0001 C CNN
F 1 "+3V3" H 3800 1290 60  0000 C CNN
F 2 "" H 3800 1150 60  0000 C CNN
F 3 "" H 3800 1150 60  0000 C CNN
	1    3800 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR026
U 1 1 54AFE48B
P 4200 1150
F 0 "#PWR026" H 4200 1000 60  0001 C CNN
F 1 "+3V3" H 4200 1290 60  0000 C CNN
F 2 "" H 4200 1150 60  0000 C CNN
F 3 "" H 4200 1150 60  0000 C CNN
	1    4200 1150
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR027
U 1 1 54AFE5A1
P 6150 3850
F 0 "#PWR027" H 6150 3700 60  0001 C CNN
F 1 "+3V3" H 6150 3990 60  0000 C CNN
F 2 "" H 6150 3850 60  0000 C CNN
F 3 "" H 6150 3850 60  0000 C CNN
	1    6150 3850
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR028
U 1 1 54AFE8D8
P 8900 1000
F 0 "#PWR028" H 8900 850 60  0001 C CNN
F 1 "+3V3" H 8900 1140 60  0000 C CNN
F 2 "" H 8900 1000 60  0000 C CNN
F 3 "" H 8900 1000 60  0000 C CNN
	1    8900 1000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR029
U 1 1 54AFE90B
P 9250 1000
F 0 "#PWR029" H 9250 850 60  0001 C CNN
F 1 "+3V3" H 9250 1140 60  0000 C CNN
F 2 "" H 9250 1000 60  0000 C CNN
F 3 "" H 9250 1000 60  0000 C CNN
	1    9250 1000
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR030
U 1 1 54AFE9BC
P 9650 1450
F 0 "#PWR030" H 9650 1300 60  0001 C CNN
F 1 "+3V3" H 9650 1590 60  0000 C CNN
F 2 "" H 9650 1450 60  0000 C CNN
F 3 "" H 9650 1450 60  0000 C CNN
	1    9650 1450
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR031
U 1 1 54AFEB56
P 8400 2750
F 0 "#PWR031" H 8400 2600 60  0001 C CNN
F 1 "+3V3" H 8400 2890 60  0000 C CNN
F 2 "" H 8400 2750 60  0000 C CNN
F 3 "" H 8400 2750 60  0000 C CNN
	1    8400 2750
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR032
U 1 1 54AFEE44
P 6200 6450
F 0 "#PWR032" H 6200 6300 60  0001 C CNN
F 1 "+3V3" H 6200 6590 60  0000 C CNN
F 2 "" H 6200 6450 60  0000 C CNN
F 3 "" H 6200 6450 60  0000 C CNN
	1    6200 6450
	1    0    0    -1  
$EndComp
Text Label 1250 2500 0    60   ~ 0
VBAT
$Comp
L C C3
U 1 1 54AFFDE5
P 1200 1350
F 0 "C3" H 1200 1450 40  0000 L CNN
F 1 "100n" H 1206 1265 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 1238 1200 30  0001 C CNN
F 3 "" H 1200 1350 60  0000 C CNN
	1    1200 1350
	1    0    0    -1  
$EndComp
Text Label 1200 1150 2    60   ~ 0
VBAT
$Comp
L GND #PWR033
U 1 1 54B00473
P 1200 1550
F 0 "#PWR033" H 1200 1300 60  0001 C CNN
F 1 "GND" H 1200 1400 60  0000 C CNN
F 2 "" H 1200 1550 60  0000 C CNN
F 3 "" H 1200 1550 60  0000 C CNN
	1    1200 1550
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 54B00744
P 1450 1150
F 0 "R1" V 1530 1150 40  0000 C CNN
F 1 "0" V 1457 1151 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 1380 1150 30  0001 C CNN
F 3 "" H 1450 1150 30  0000 C CNN
	1    1450 1150
	0    1    1    0   
$EndComp
$Comp
L +3V3 #PWR034
U 1 1 54B00899
P 1700 1150
F 0 "#PWR034" H 1700 1000 60  0001 C CNN
F 1 "+3V3" H 1700 1290 60  0000 C CNN
F 2 "" H 1700 1150 60  0000 C CNN
F 3 "" H 1700 1150 60  0000 C CNN
	1    1700 1150
	1    0    0    -1  
$EndComp
Connection ~ 6150 4150
Connection ~ 6150 4450
Wire Wire Line
	3750 6650 3650 6650
Wire Wire Line
	3650 6650 3650 6450
Connection ~ 3650 6450
Wire Wire Line
	5250 6450 6200 6450
Wire Wire Line
	600  3250 600  3850
Connection ~ 600  3550
Wire Wire Line
	4900 2250 5350 2250
Wire Wire Line
	9700 2950 9700 3950
Connection ~ 9700 3050
Connection ~ 9700 3150
Connection ~ 9700 3250
Connection ~ 9700 3350
Connection ~ 9700 3450
Connection ~ 9700 3550
Connection ~ 9700 3650
Connection ~ 9700 3750
Connection ~ 9700 2950
Wire Wire Line
	600  4350 600  4950
Connection ~ 600  4650
Wire Wire Line
	1000 4350 1500 4350
Wire Wire Line
	1200 4950 1000 4950
Wire Wire Line
	8400 2850 9200 2850
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
Text Notes 8650 2500 0    120  ~ 0
SWD
Text Notes 750  6050 0    120  ~ 0
PSU
Text Notes 7800 3850 0    120  ~ 0
UART\n
$Comp
L CONN_01X03 P2
U 1 1 54B08A26
P 8550 4250
F 0 "P2" H 8550 4450 50  0000 C CNN
F 1 "CONN_01X03" V 8650 4250 50  0000 C CNN
F 2 "Connect:PINHEAD1-3" H 8550 4250 60  0001 C CNN
F 3 "" H 8550 4250 60  0000 C CNN
	1    8550 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4150 8350 4150
Wire Wire Line
	7950 4250 8350 4250
Text Label 7950 4150 0    60   ~ 0
UARTRX
Text Label 7950 4250 0    60   ~ 0
UARTTX
$Comp
L GND #PWR035
U 1 1 54B08EA3
P 8350 4350
F 0 "#PWR035" H 8350 4100 60  0001 C CNN
F 1 "GND" H 8350 4200 60  0000 C CNN
F 2 "" H 8350 4350 60  0000 C CNN
F 3 "" H 8350 4350 60  0000 C CNN
	1    8350 4350
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
L ZENERsmall D3
U 1 1 54B0A648
P 8400 2950
F 0 "D3" H 8400 3050 40  0000 C CNN
F 1 "Z5V1" H 8400 2850 30  0000 C CNN
F 2 "Diodes_SMD:Diode-MiniMELF_Standard" H 8400 2950 60  0001 C CNN
F 3 "" H 8400 2950 60  0000 C CNN
	1    8400 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8400 2750 8400 2850
$Comp
L GND #PWR036
U 1 1 54B0A8DC
P 8400 3050
F 0 "#PWR036" H 8400 3050 30  0001 C CNN
F 1 "GND" H 8400 2980 30  0001 C CNN
F 2 "" H 8400 3050 60  0000 C CNN
F 3 "" H 8400 3050 60  0000 C CNN
	1    8400 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 3150 8550 3150
Text Label 8550 3150 0    60   ~ 0
SWDIO
Text Label 8800 3250 0    60   ~ 0
SWCLK
$Comp
L ZENERsmall D4
U 1 1 54B0AD67
P 8550 3250
F 0 "D4" H 8550 3350 40  0000 C CNN
F 1 "Z5V1" H 8550 3150 30  0000 C CNN
F 2 "Diodes_SMD:Diode-MiniMELF_Standard" H 8550 3250 60  0001 C CNN
F 3 "" H 8550 3250 60  0000 C CNN
	1    8550 3250
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR037
U 1 1 54B0AD6D
P 8550 3350
F 0 "#PWR037" H 8550 3350 30  0001 C CNN
F 1 "GND" H 8550 3280 30  0001 C CNN
F 2 "" H 8550 3350 60  0000 C CNN
F 3 "" H 8550 3350 60  0000 C CNN
	1    8550 3350
	1    0    0    -1  
$EndComp
$Comp
L ZENERsmall D5
U 1 1 54B0ADD7
P 8800 3350
F 0 "D5" H 8800 3450 40  0000 C CNN
F 1 "Z5V1" H 8800 3250 30  0000 C CNN
F 2 "Diodes_SMD:Diode-MiniMELF_Standard" H 8800 3350 60  0001 C CNN
F 3 "" H 8800 3350 60  0000 C CNN
	1    8800 3350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR038
U 1 1 54B0ADDD
P 8800 3450
F 0 "#PWR038" H 8800 3450 30  0001 C CNN
F 1 "GND" H 8800 3380 30  0001 C CNN
F 2 "" H 8800 3450 60  0000 C CNN
F 3 "" H 8800 3450 60  0000 C CNN
	1    8800 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 3250 9200 3250
NoConn ~ 9700 2850
NoConn ~ 9200 3650
NoConn ~ 9200 3750
$Comp
L SW_PUSH SW4
U 1 1 54B0F915
P 5850 4750
F 0 "SW4" H 6000 4860 50  0000 C CNN
F 1 "SW_PUSH" H 5850 4670 50  0000 C CNN
F 2 "TonisLibrary:Button_SMD_Schurter_LSG" H 5850 4750 60  0001 C CNN
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
	5450 4750 5550 4750
Wire Wire Line
	1500 2500 1250 2500
Connection ~ 3500 6450
$Comp
L PWR_FLAG #FLG039
U 1 1 54B14A07
P 1250 1150
F 0 "#FLG039" H 1250 1245 30  0001 C CNN
F 1 "PWR_FLAG" H 1250 1330 30  0000 C CNN
F 2 "" H 1250 1150 60  0000 C CNN
F 3 "" H 1250 1150 60  0000 C CNN
	1    1250 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 1150 1200 1150
Text Label 1250 2050 0    60   ~ 0
NRST
Wire Wire Line
	1500 2050 1250 2050
Text Label 8950 3550 0    60   ~ 0
NRST
$Comp
L ZENERsmall D6
U 1 1 54B1B9F1
P 8950 3650
F 0 "D6" H 8950 3750 40  0000 C CNN
F 1 "Z5V1" H 8950 3550 30  0000 C CNN
F 2 "Diodes_SMD:Diode-MiniMELF_Standard" H 8950 3650 60  0001 C CNN
F 3 "" H 8950 3650 60  0000 C CNN
	1    8950 3650
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR040
U 1 1 54B1B9F7
P 8950 3750
F 0 "#PWR040" H 8950 3750 30  0001 C CNN
F 1 "GND" H 8950 3680 30  0001 C CNN
F 2 "" H 8950 3750 60  0000 C CNN
F 3 "" H 8950 3750 60  0000 C CNN
	1    8950 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 3550 9200 3550
Wire Wire Line
	9200 3350 8950 3350
Wire Wire Line
	8950 3350 8950 3450
Wire Wire Line
	8950 3450 8800 3450
$Comp
L CAPAPOL C5
U 1 1 54B1C241
P 2500 1350
F 0 "C5" H 2550 1450 40  0000 L CNN
F 1 "4.7u" H 2550 1250 40  0000 L CNN
F 2 "Capacitors_SMD:c_elec_4x5.8" H 2600 1200 30  0001 C CNN
F 3 "" H 2500 1350 300 0000 C CNN
	1    2500 1350
	1    0    0    -1  
$EndComp
$Comp
L CAPAPOL C8
U 1 1 54B1C439
P 4200 1350
F 0 "C8" H 4250 1450 40  0000 L CNN
F 1 "1u" H 4250 1250 40  0000 L CNN
F 2 "Capacitors_SMD:c_elec_4x5.8" H 4300 1200 30  0001 C CNN
F 3 "" H 4200 1350 300 0000 C CNN
	1    4200 1350
	1    0    0    -1  
$EndComp
NoConn ~ 9200 3450
NoConn ~ 9200 2950
NoConn ~ 9200 3050
$Comp
L JUMPER3 JP3
U 1 1 54B1F253
P 3000 6450
F 0 "JP3" H 3050 6350 40  0000 L CNN
F 1 "JUMPER3" H 3000 6550 40  0000 C CNN
F 2 "Connect:GS3" H 3000 6450 60  0001 C CNN
F 3 "" H 3000 6450 60  0000 C CNN
	1    3000 6450
	0    -1   -1   0   
$EndComp
$Comp
L MOSFET_N Q1
U 1 1 54B25F08
P 6300 5050
F 0 "Q1" H 6310 5220 60  0000 R CNN
F 1 "MOSFET_N" H 6310 4900 60  0000 R CNN
F 2 "SMD_Packages:DPAK-2-1EP_GDS" H 6300 5050 60  0001 C CNN
F 3 "" H 6300 5050 60  0000 C CNN
	1    6300 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 5050 4900 5050
$Comp
L CONN_01X02 P3
U 1 1 54B262BA
P 6800 4650
F 0 "P3" H 6800 4800 50  0000 C CNN
F 1 "PIEZO_BUZZ" V 6900 4650 50  0000 C CNN
F 2 "Connect:PINHEAD1-2" H 6800 4650 60  0001 C CNN
F 3 "" H 6800 4650 60  0000 C CNN
	1    6800 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 4700 6400 4700
Wire Wire Line
	6400 4700 6400 4850
$Comp
L +3V3 #PWR041
U 1 1 54B2639E
P 6400 4500
F 0 "#PWR041" H 6400 4350 60  0001 C CNN
F 1 "+3V3" H 6400 4640 60  0000 C CNN
F 2 "" H 6400 4500 60  0000 C CNN
F 3 "" H 6400 4500 60  0000 C CNN
	1    6400 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 4500 6400 4600
Wire Wire Line
	6400 4600 6600 4600
$Comp
L GND #PWR042
U 1 1 54B26505
P 6400 5250
F 0 "#PWR042" H 6400 5250 30  0001 C CNN
F 1 "GND" H 6400 5180 30  0001 C CNN
F 2 "" H 6400 5250 60  0000 C CNN
F 3 "" H 6400 5250 60  0000 C CNN
	1    6400 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2150 5350 2150
Wire Wire Line
	5350 2150 5350 2050
Wire Wire Line
	4900 2050 5300 2050
Wire Wire Line
	5300 2050 5300 1850
Wire Wire Line
	5300 1850 5350 1850
$Comp
L R R6
U 1 1 54B2C2FF
P 5700 2600
F 0 "R6" V 5780 2600 40  0000 C CNN
F 1 "680" V 5707 2601 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5630 2600 30  0001 C CNN
F 3 "" H 5700 2600 30  0000 C CNN
	1    5700 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 2350 5350 2350
Wire Wire Line
	5350 2350 5350 2600
$Comp
L LED D2
U 1 1 54B2C3A2
P 6150 2600
F 0 "D2" H 6150 2700 50  0000 C CNN
F 1 "LED" H 6150 2500 50  0000 C CNN
F 2 "LEDs:LED-0603" H 6150 2600 60  0001 C CNN
F 3 "" H 6150 2600 60  0000 C CNN
	1    6150 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 2050 6600 2050
Wire Wire Line
	6600 2050 6600 2600
Wire Wire Line
	6600 2600 6350 2600
Connection ~ 6600 2600
Wire Wire Line
	5350 2600 5450 2600
NoConn ~ 4900 2450
NoConn ~ 1500 3950
NoConn ~ 1500 4050
NoConn ~ 1500 4250
NoConn ~ 4900 2850
NoConn ~ 4900 3150
NoConn ~ 4900 3250
NoConn ~ 4900 3550
NoConn ~ 4900 4950
NoConn ~ 4900 5150
NoConn ~ 4900 5250
NoConn ~ 4900 4050
Text Notes 9300 4300 0    120  ~ 0
RESET-BTN
Text Label 9650 4600 0    60   ~ 0
NRST
$Comp
L SW_PUSH SW3
U 1 1 54B328EE
P 10400 4600
F 0 "SW3" H 10550 4710 50  0000 C CNN
F 1 "SW_PUSH" H 10400 4520 50  0000 C CNN
F 2 "TonisLibrary:Button_SMD_Schurter_LSG" H 10400 4600 60  0001 C CNN
F 3 "" H 10400 4600 60  0000 C CNN
	1    10400 4600
	1    0    0    -1  
$EndComp
$Comp
L C C12
U 1 1 54B3296C
P 10400 4850
F 0 "C12" H 10400 4950 40  0000 L CNN
F 1 "100n" H 10406 4765 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 10438 4700 30  0001 C CNN
F 3 "" H 10400 4850 60  0000 C CNN
	1    10400 4850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR043
U 1 1 54B32AEB
P 10900 4650
F 0 "#PWR043" H 10900 4650 30  0001 C CNN
F 1 "GND" H 10900 4580 30  0001 C CNN
F 2 "" H 10900 4650 60  0000 C CNN
F 3 "" H 10900 4650 60  0000 C CNN
	1    10900 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 4600 10100 4600
Wire Wire Line
	10700 4600 10700 4850
Wire Wire Line
	10700 4600 10900 4600
Wire Wire Line
	10900 4600 10900 4650
Wire Wire Line
	10700 4850 10600 4850
Wire Wire Line
	10100 4600 10100 4850
Wire Wire Line
	10100 4850 10200 4850
$Comp
L GND #PWR044
U 1 1 54B34385
P 5850 6850
F 0 "#PWR044" H 5850 6850 30  0001 C CNN
F 1 "GND" H 5850 6780 30  0001 C CNN
F 2 "" H 5850 6850 60  0000 C CNN
F 3 "" H 5850 6850 60  0000 C CNN
	1    5850 6850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR045
U 1 1 54B34455
P 4750 6850
F 0 "#PWR045" H 4750 6850 30  0001 C CNN
F 1 "GND" H 4750 6780 30  0001 C CNN
F 2 "" H 4750 6850 60  0000 C CNN
F 3 "" H 4750 6850 60  0000 C CNN
	1    4750 6850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR046
U 1 1 54B34784
P 2600 7550
F 0 "#PWR046" H 2600 7550 30  0001 C CNN
F 1 "GND" H 2600 7480 30  0001 C CNN
F 2 "" H 2600 7550 60  0000 C CNN
F 3 "" H 2600 7550 60  0000 C CNN
	1    2600 7550
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 54B34C40
P 5450 6700
F 0 "R9" V 5530 6700 40  0000 C CNN
F 1 "0" V 5457 6701 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5380 6700 30  0001 C CNN
F 3 "" H 5450 6700 30  0000 C CNN
	1    5450 6700
	1    0    0    -1  
$EndComp
Connection ~ 5450 6450
Wire Wire Line
	5250 6650 5300 6650
Wire Wire Line
	5300 6650 5300 6950
Wire Wire Line
	5300 6950 5450 6950
$Comp
L R R10
U 1 1 54B34DCF
P 5450 7200
F 0 "R10" V 5530 7200 40  0000 C CNN
F 1 "*" V 5457 7201 40  0000 C CNN
F 2 "Resistors_SMD:R_0603" V 5380 7200 30  0001 C CNN
F 3 "" H 5450 7200 30  0000 C CNN
	1    5450 7200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR047
U 1 1 54B34E2E
P 5450 7450
F 0 "#PWR047" H 5450 7450 30  0001 C CNN
F 1 "GND" H 5450 7380 30  0001 C CNN
F 2 "" H 5450 7450 60  0000 C CNN
F 3 "" H 5450 7450 60  0000 C CNN
	1    5450 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 6950 3000 6950
Wire Wire Line
	3000 6950 3000 6700
$Comp
L R R8
U 1 1 54B371E3
P 2450 6650
F 0 "R8" V 2530 6650 40  0000 C CNN
F 1 "10, 2.5W" V 2457 6651 40  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM15mm" V 2380 6650 30  0001 C CNN
F 3 "" H 2450 6650 30  0000 C CNN
	1    2450 6650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR048
U 1 1 54B372CF
P 2700 6650
F 0 "#PWR048" H 2700 6650 30  0001 C CNN
F 1 "GND" H 2700 6580 30  0001 C CNN
F 2 "" H 2700 6650 60  0000 C CNN
F 3 "" H 2700 6650 60  0000 C CNN
	1    2700 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 6200 2300 6200
Connection ~ 5850 6450
Wire Wire Line
	2200 6650 2000 6650
$Comp
L PWR_FLAG #FLG049
U 1 1 54B38F3F
P 2100 6650
F 0 "#FLG049" H 2100 6745 30  0001 C CNN
F 1 "PWR_FLAG" H 2100 6830 30  0000 C CNN
F 2 "" H 2100 6650 60  0000 C CNN
F 3 "" H 2100 6650 60  0000 C CNN
	1    2100 6650
	-1   0    0    1   
$EndComp
Wire Wire Line
	3100 6450 4250 6450
Wire Wire Line
	4250 6250 4100 6250
Wire Wire Line
	4100 6250 4100 6450
Connection ~ 4100 6450
$Comp
L PWR_FLAG #FLG050
U 1 1 54B39DCF
P 3500 6450
F 0 "#FLG050" H 3500 6545 30  0001 C CNN
F 1 "PWR_FLAG" H 3500 6630 30  0000 C CNN
F 2 "" H 3500 6450 60  0000 C CNN
F 3 "" H 3500 6450 60  0000 C CNN
	1    3500 6450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR051
U 1 1 54B3A2BD
P 4000 7550
F 0 "#PWR051" H 4000 7550 30  0001 C CNN
F 1 "GND" H 4000 7480 30  0001 C CNN
F 2 "" H 4000 7550 60  0000 C CNN
F 3 "" H 4000 7550 60  0000 C CNN
	1    4000 7550
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG052
U 1 1 54B3A2FA
P 4000 7550
F 0 "#FLG052" H 4000 7645 30  0001 C CNN
F 1 "PWR_FLAG" H 4000 7730 30  0000 C CNN
F 2 "" H 4000 7550 60  0000 C CNN
F 3 "" H 4000 7550 60  0000 C CNN
	1    4000 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4550 5450 4550
Wire Wire Line
	5450 4550 5450 4750
NoConn ~ 4900 4650
Text Notes 7750 5150 0    120  ~ 0
EEPROM über SPI
NoConn ~ 4900 4350
NoConn ~ 4900 4450
Text Label 8100 5850 0    60   ~ 0
SCK
Text Label 9500 5550 2    60   ~ 0
MISO
Text Label 9500 5850 2    60   ~ 0
MOSI
Text Label 5400 4750 2    60   ~ 0
ROM_CS
Text Label 5400 4850 2    60   ~ 0
ROM_HOLD
Wire Wire Line
	5400 4750 4900 4750
Wire Wire Line
	4900 4850 5400 4850
Text Label 8100 5550 0    60   ~ 0
ROM_CS
Text Label 9500 5750 2    60   ~ 0
ROM_HOLD
$Comp
L +3V3 #PWR053
U 1 1 54B40E80
P 7900 5850
F 0 "#PWR053" H 7900 5700 60  0001 C CNN
F 1 "+3V3" H 7900 5990 60  0000 C CNN
F 2 "" H 7900 5850 60  0000 C CNN
F 3 "" H 7900 5850 60  0000 C CNN
	1    7900 5850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR054
U 1 1 54B40EBC
P 9650 5650
F 0 "#PWR054" H 9650 5650 30  0001 C CNN
F 1 "GND" H 9650 5580 30  0001 C CNN
F 2 "" H 9650 5650 60  0000 C CNN
F 3 "" H 9650 5650 60  0000 C CNN
	1    9650 5650
	1    0    0    -1  
$EndComp
$Comp
L C C14
U 1 1 54B40EF8
P 10250 5700
F 0 "C14" H 10250 5800 40  0000 L CNN
F 1 "100n" H 10256 5615 40  0000 L CNN
F 2 "Capacitors_SMD:C_0603" H 10288 5550 30  0001 C CNN
F 3 "" H 10250 5700 60  0000 C CNN
	1    10250 5700
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR055
U 1 1 54B4109F
P 10250 5500
F 0 "#PWR055" H 10250 5350 60  0001 C CNN
F 1 "+3V3" H 10250 5640 60  0000 C CNN
F 2 "" H 10250 5500 60  0000 C CNN
F 3 "" H 10250 5500 60  0000 C CNN
	1    10250 5500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR056
U 1 1 54B410DC
P 10250 5900
F 0 "#PWR056" H 10250 5900 30  0001 C CNN
F 1 "GND" H 10250 5830 30  0001 C CNN
F 2 "" H 10250 5900 60  0000 C CNN
F 3 "" H 10250 5900 60  0000 C CNN
	1    10250 5900
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X04 P4
U 1 1 54B41ABF
P 8750 5700
F 0 "P4" H 8750 5950 50  0000 C CNN
F 1 "EEPROM_SPI" H 8750 5450 50  0000 C CNN
F 2 "SMD_Packages:MSOP-8" H 8750 4500 60  0001 C CNN
F 3 "" H 8750 4500 60  0000 C CNN
	1    8750 5700
	1    0    0    -1  
$EndComp
Text Notes 9750 6100 0    39   ~ 0
Pinbelegung:\n1 #CS\n2 SO\n3 #WP\n4 VSS\n5 VCC\n6 #HOLD\n7 SCK\n8 SI\n\nChip:  25AA640AT-I/MS (64K von Digikey)
Wire Wire Line
	8100 5550 8500 5550
Wire Wire Line
	8100 5850 8500 5850
Wire Wire Line
	9000 5550 9500 5550
Wire Wire Line
	9000 5750 9500 5750
Wire Wire Line
	9650 5650 9000 5650
Wire Wire Line
	9000 5850 9500 5850
Wire Wire Line
	7900 5850 8050 5850
Wire Wire Line
	8050 5850 8050 5750
Wire Wire Line
	8050 5750 8500 5750
$Comp
L JUMPER3 JP2
U 1 1 54B435C7
P 7650 5650
F 0 "JP2" H 7700 5550 40  0000 L CNN
F 1 "JUMPER3" H 7650 5750 40  0000 C CNN
F 2 "Connect:GS3" H 7650 5650 60  0001 C CNN
F 3 "" H 7650 5650 60  0000 C CNN
	1    7650 5650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7750 5650 8500 5650
$Comp
L +3V3 #PWR057
U 1 1 54B4381C
P 7650 5400
F 0 "#PWR057" H 7650 5250 60  0001 C CNN
F 1 "+3V3" H 7650 5540 60  0000 C CNN
F 2 "" H 7650 5400 60  0000 C CNN
F 3 "" H 7650 5400 60  0000 C CNN
	1    7650 5400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR058
U 1 1 54B4385B
P 7650 5900
F 0 "#PWR058" H 7650 5900 30  0001 C CNN
F 1 "GND" H 7650 5830 30  0001 C CNN
F 2 "" H 7650 5900 60  0000 C CNN
F 3 "" H 7650 5900 60  0000 C CNN
	1    7650 5900
	1    0    0    -1  
$EndComp
Text Notes 7050 5500 0    39   ~ 0
auf high setzen
$Comp
L USB-MICRO-B CON1
U 1 1 54B45CE7
P 1300 6600
F 0 "CON1" H 1000 6950 50  0000 C CNN
F 1 "USB-MICRO-B" H 1150 6250 50  0000 C CNN
F 2 "Connect:USB_Micro-B" H 1300 6500 50  0001 C CNN
F 3 "" H 1300 6500 50  0000 C CNN
	1    1300 6600
	-1   0    0    -1  
$EndComp
NoConn ~ 800  6400
NoConn ~ 800  6500
NoConn ~ 800  6700
NoConn ~ 800  6800
NoConn ~ 1800 6500
NoConn ~ 1800 6600
NoConn ~ 1800 6700
Wire Wire Line
	1800 6400 2300 6400
Wire Wire Line
	2300 6400 2300 6200
Wire Wire Line
	2000 6650 2000 6800
Wire Wire Line
	2000 6800 1800 6800
Text Label 10800 3600 2    60   ~ 0
NRST
Text Label 10250 2900 2    60   ~ 0
SWCLK
Text Label 10650 3750 2    60   ~ 0
SWDIO
$Comp
L R R11
U 1 1 54B12F0E
P 9950 3250
F 0 "R11" V 10030 3250 40  0000 C CNN
F 1 "10k" V 9957 3251 40  0000 C CNN
F 2 "" V 9880 3250 30  0000 C CNN
F 3 "" H 9950 3250 30  0000 C CNN
	1    9950 3250
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 54B12F9E
P 10350 3250
F 0 "R12" V 10430 3250 40  0000 C CNN
F 1 "10k" V 10357 3251 40  0000 C CNN
F 2 "" V 10280 3250 30  0000 C CNN
F 3 "" H 10350 3250 30  0000 C CNN
	1    10350 3250
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 54B12FEC
P 10550 3250
F 0 "R13" V 10630 3250 40  0000 C CNN
F 1 "10k" V 10557 3251 40  0000 C CNN
F 2 "" V 10480 3250 30  0000 C CNN
F 3 "" H 10550 3250 30  0000 C CNN
	1    10550 3250
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR059
U 1 1 54B1303F
P 10450 2850
F 0 "#PWR059" H 10450 2700 60  0001 C CNN
F 1 "+3V3" H 10450 2990 60  0000 C CNN
F 2 "" H 10450 2850 60  0000 C CNN
F 3 "" H 10450 2850 60  0000 C CNN
	1    10450 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 2850 10550 3000
Wire Wire Line
	10350 2850 10350 3000
Wire Wire Line
	10550 3500 10550 3600
Wire Wire Line
	10550 3600 10800 3600
Wire Wire Line
	10650 3750 10350 3750
Wire Wire Line
	10350 3750 10350 3500
Text Notes 10700 3150 0    60   ~ 0
Pull-Up\nPull-Down
$Comp
L PWR_FLAG #FLG060
U 1 1 54B144E6
P 2100 6400
F 0 "#FLG060" H 2100 6495 30  0001 C CNN
F 1 "PWR_FLAG" H 2100 6580 30  0000 C CNN
F 2 "" H 2100 6400 60  0000 C CNN
F 3 "" H 2100 6400 60  0000 C CNN
	1    2100 6400
	1    0    0    -1  
$EndComp
Connection ~ 2100 6400
Connection ~ 2100 6650
Wire Wire Line
	10350 2850 10550 2850
Connection ~ 10450 2850
Wire Wire Line
	10250 2900 9950 2900
Wire Wire Line
	9950 2900 9950 3000
$Comp
L GND #PWR061
U 1 1 54B15754
P 9950 3500
F 0 "#PWR061" H 9950 3500 30  0001 C CNN
F 1 "GND" H 9950 3430 30  0001 C CNN
F 2 "" H 9950 3500 60  0000 C CNN
F 3 "" H 9950 3500 60  0000 C CNN
	1    9950 3500
	1    0    0    -1  
$EndComp
$EndSCHEMATC

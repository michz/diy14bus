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
LIBS:cowbus-protoboard-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
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
L APE8865N-33-HF-3 U?
U 1 1 55A5144A
P 5800 4100
F 0 "U?" H 5500 4350 40  0000 C CNN
F 1 "APE8865N-33-HF-3" H 5800 4300 40  0000 C CNN
F 2 "SOT-23" H 5800 4200 35  0000 C CIN
F 3 "" H 5800 4100 60  0000 C CNN
	1    5800 4100
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 55A51451
P 4450 4150
F 0 "C?" H 4475 4250 50  0000 L CNN
F 1 "1u" H 4475 4050 50  0000 L CNN
F 2 "" H 4488 4000 30  0000 C CNN
F 3 "" H 4450 4150 60  0000 C CNN
	1    4450 4150
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 55A51458
P 7400 4150
F 0 "C?" H 7425 4250 50  0000 L CNN
F 1 "2u2" H 7425 4050 50  0000 L CNN
F 2 "" H 7438 4000 30  0000 C CNN
F 3 "" H 7400 4150 60  0000 C CNN
	1    7400 4150
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 55A515B6
P 5250 3450
F 0 "#PWR?" H 5250 3300 50  0001 C CNN
F 1 "VCC" H 5250 3600 50  0000 C CNN
F 2 "" H 5250 3450 60  0000 C CNN
F 3 "" H 5250 3450 60  0000 C CNN
	1    5250 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4050 5350 4050
Wire Wire Line
	5250 3450 5250 4050
$Comp
L +3V3 #PWR?
U 1 1 55A515EF
P 6400 3700
F 0 "#PWR?" H 6400 3550 50  0001 C CNN
F 1 "+3V3" H 6400 3840 50  0000 C CNN
F 2 "" H 6400 3700 60  0000 C CNN
F 3 "" H 6400 3700 60  0000 C CNN
	1    6400 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 4050 6400 4050
Wire Wire Line
	6400 4050 6400 3700
$Comp
L GND #PWR?
U 1 1 55A51658
P 5800 4600
F 0 "#PWR?" H 5800 4350 50  0001 C CNN
F 1 "GND" H 5800 4450 50  0000 C CNN
F 2 "" H 5800 4600 60  0000 C CNN
F 3 "" H 5800 4600 60  0000 C CNN
	1    5800 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 4600 5800 4400
$Comp
L VCC #PWR?
U 1 1 55A5185F
P 4450 3450
F 0 "#PWR?" H 4450 3300 50  0001 C CNN
F 1 "VCC" H 4450 3600 50  0000 C CNN
F 2 "" H 4450 3450 60  0000 C CNN
F 3 "" H 4450 3450 60  0000 C CNN
	1    4450 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 55A51873
P 4450 4600
F 0 "#PWR?" H 4450 4350 50  0001 C CNN
F 1 "GND" H 4450 4450 50  0000 C CNN
F 2 "" H 4450 4600 60  0000 C CNN
F 3 "" H 4450 4600 60  0000 C CNN
	1    4450 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 55A51887
P 7400 4600
F 0 "#PWR?" H 7400 4350 50  0001 C CNN
F 1 "GND" H 7400 4450 50  0000 C CNN
F 2 "" H 7400 4600 60  0000 C CNN
F 3 "" H 7400 4600 60  0000 C CNN
	1    7400 4600
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 55A518AE
P 7400 3700
F 0 "#PWR?" H 7400 3550 50  0001 C CNN
F 1 "+3V3" H 7400 3840 50  0000 C CNN
F 2 "" H 7400 3700 60  0000 C CNN
F 3 "" H 7400 3700 60  0000 C CNN
	1    7400 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4000 7400 3700
Wire Wire Line
	7400 4600 7400 4300
Wire Wire Line
	4450 4600 4450 4300
Wire Wire Line
	4450 3450 4450 4000
$Comp
L GND #PWR?
U 1 1 55A95D68
P 8250 4600
F 0 "#PWR?" H 8250 4350 50  0001 C CNN
F 1 "GND" H 8250 4450 50  0000 C CNN
F 2 "" H 8250 4600 60  0000 C CNN
F 3 "" H 8250 4600 60  0000 C CNN
	1    8250 4600
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR?
U 1 1 55A95D6E
P 8250 3700
F 0 "#PWR?" H 8250 3550 50  0001 C CNN
F 1 "+3V3" H 8250 3840 50  0000 C CNN
F 2 "" H 8250 3700 60  0000 C CNN
F 3 "" H 8250 3700 60  0000 C CNN
	1    8250 3700
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 55A95D76
P 8250 4150
F 0 "C?" H 8275 4250 50  0000 L CNN
F 1 "100n" H 8275 4050 50  0000 L CNN
F 2 "" H 8288 4000 30  0000 C CNN
F 3 "" H 8250 4150 60  0000 C CNN
	1    8250 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 4000 8250 3700
Wire Wire Line
	8250 4600 8250 4300
$EndSCHEMATC

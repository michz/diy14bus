---
layout: post
title:  "Welchen Chip"
date:   2014-11-26 18:00:00
categories: [Hardware]
tags: [Hardware, ARM]
author: jschnurrer
---

Welchen Mikrocontroller für die Endhardware
====

*Anmerkung: Diskussionen bitte irgendwo, wo man tatsächlich auch diskutieren kann.
([Piratenpad](https://piratenpad.de/p/diy14bus) z.B.)*

# [STM32](http://de.farnell.com/webapp/wcs/stores/servlet/Search?catalogId=15001&langId=-3&storeId=10161&categoryId=700000004185&sort=P_PRICE&st=STM32&pageSize=25&showResults=true&pf=310031672,310060087,310078320,310089495)

##	[STM32F030F4P6TR](http://de.farnell.com/stmicroelectronics/stm32f030f4p6tr/mcu-32bit-cortex-m0-48mhz-tssop/dp/2432084)

*   Kosten <1€ pro Stück
*   Vorteil: Ähnlich zum F3, in den wir uns jetzt schon eingearbeitet haben. (Noch zu checken)
*   Auch über JTAG mit USB-PROG programmierbar, dann sparen wir uns den zweiten µC für die Programmierung. So weit muss es aber gar nicht kommen, wir nehmen uns einfach den JTAG von einem st-link vom Eval-Board.
    UPDATE: Das funktioniert nicht so wie gedacht. Es kann mit dem St-Link nur der ARM des jeweiligen Boards programmiert werden, weil der µC für die Programmierung die Device-ID des montierten ARMs kennt. Beim Programmieren kommt daher folgende Fehlermeldung:

        $ make flash
        st-flash write bin/stm32f3discovery/first-test.hex 0x8000000
        2014-11-26T22:42:10 INFO src/stlink-common.c: Loading device parameters....
        2014-11-26T22:42:10 WARN src/stlink-common.c: unknown chip id! 0xe0042000
        make: *** [flash] Fehler 255

    Macht ja auch Sinn, sonst kauft sich jeder ein STM32F0 board für 10€ und nicht den Programmer für 30€. Den USB-Prog versuch ich dann morgen.


*   Was spricht dagegen?



---
layout: post
title:  "STM32F3 Grundlagen"
date:   2014-11-24 23:59:59
categories: [Grundlagen]
tags: [STM32F3-Discovery, ARM, Pinbelegung]
author: jschnurrer
---

# STM32F3-Discovery - Was steht wo?

* Die Dateien sind auf der [Homepage des Herstellers](http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF254044) zu finden


## MB1035.pdf - "Schematic"

* USER-Taster an PA0


## DM00043574.pdf: "RM0316 - Reference manual"

* SPI-Konfiguration auf Seite 867


## DM00058181.pdf: "Datasheet - production data"

Alternate PIN Functions ab Seite 35:

    PA0 Platz Taster!
    PA1 Platz für diese anderen Pins
    PA2 Platz für diese anderen Pins
    PA3 Platz für diese anderen Pins
    PA4 SPI1_NSS
    PA5 SPI1_SCK
    PA6 SPI1_MISO
    PA7 SPI1_MOSI

* An dem SPI-Bus hängt auch der L3GD20 dran, aber der CS von dem ist auf PE3, daher kein Problem.


## Abkürzungen:
* RCC: Reset and Clock Controller



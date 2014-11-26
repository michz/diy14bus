---
layout: post
title:  "STM32F3 Grundlagen"
date:   2014-11-24 23:59:59
categories: [Grundlagen]
tags: [STM32F3-Discovery, ARM, Pinbelegung]
author: jschnurrer
---

# STM32F3-Discovery - Was steht wo?

* bevor man nachschaut, wo man was implementiert, erst mal schauen, obs entsprechende Sachen nicht schon gibt:
* /diy14bus/RIOT/cpu/stm32f3 




* Die Dateien sind auf der [Homepage vom STM32F3-Discovery Board](http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF254044) und auf der [Homepage vom STM32F303](http://www.st.com/web/en/catalog/mmc/SC1169/SS1576/LN1531) zu finden


## MB1035.pdf - "Schematic"

* USER-Taster an PA0


## DM00043574.pdf: "RM0316 - Reference manual"

### SPI-Konfiguration auf Seite 867

The configuration procedure is almost the same for master and slave. For specific mode
setups, follow the dedicated chapters. When a standard communication is to be initialized,
perform these steps:

1. Write proper GPIO registers: Configure GPIO for MOSI, MISO and SCK pins. (Schritte sind beschrieben auf Seite 148)

2. Write to the SPI_CR1 register:
* a) Configure the serial clock baud rate using the BR[2:0] bits (Note: 4).
* b) Configure the CPOL and CPHA bits combination to define one of the four relationships between the data transfer and the serial clock (CPHA must be cleared in NSSP mode). (Note: 2).
* c) Select simplex or half-duplex mode by configuring RXONLY or BIDIMODE and BIDIOE (RXONLY and BIDIMODE can't be set at the same time).
* d) Configure the LSBFIRST bit to define the frame format (Note: 2).
* e) Configure the CRCL and CRCEN bits if CRC is needed (while SCK clock signal is at idle state).
* f) Configure SSM and SSI (Note: 2 & 3).
* g) Configure the MSTR bit (in multimaster NSS configuration, avoid conflict state on NSS if master is configured to prevent MODF error).

3. Write to SPI_CR2 register:
* a) Configure the DS[3:0] bits to select the data length for the transfer.
* b) Configure SSOE (Note: 1 & 2 & 3).
* c) Set the FRF bit if the TI protocol is required (keep NSSP bit cleared in TI mode).
* d) Set the NSSP bit if the NSS pulse mode between two data units is required (keep CHPA and TI bits cleared in NSSP mode).
* e) Configure the FRXTH bit. The RXFIFO threshold must be aligned to the read access size for the SPIx_DR register.
* f) Initialize LDMA_TX and LDMA_RX bits if DMA is used in packed mode.

4. Write to SPI_CRCPR register: Configure the CRC polynomial if needed.

5. Write proper DMA registers: Configure DMA streams dedicated for SPI Tx and Rx in DMA registers if the DMA streams are used.

### Procedure for enabling SPI auf Seite 868
Das sollte für uns alles uninteressant sein, daher setze ich einfach das SPE-bit auf 1.

### RXFIFO and TXFIFO auf Seite 868

* A read access to the SPIx_DR register returns the oldest value stored in RXFIFO that has
not been read yet. 
* A write access to the SPIx_DR stores the written data in the TXFIFO at
the end of a send queue.

    var = GPIOA.SPI1_DR; //lesen

    GPIOA.SPI1_DR = var; //schreiben

Das Register ist 32-bit breit. Wie empfange/sende ich da 8-bit?


## DM00058181.pdf: "Datasheet - production data"

Alternate PIN Functions ab Seite 35

    PA0 Platz Taster!
    PA1 Platz für diese anderen Pins
    PA2 Platz für diese anderen Pins
    PA3 Platz für diese anderen Pins
    PA4 SPI1_NSS
    PA5 SPI1_SCK
    PA6 SPI1_MISO
    PA7 SPI1_MOSI

* An dem SPI hängt auch der L3GD20 dran, aber der CS von dem ist auf PE3, daher kein Problem.

* Der SPI auf Port A ist für jeden beteiligten Pin Alternate Funtion Nummer 5 -> AF5 (Seite 41)


## Abkürzungen:
* RCC: Reset and Clock Controller

SPI status flags
* TXE: Tx buffer empty flag
* RXNE: Rx buffer not empty
* BSY: Busy flag



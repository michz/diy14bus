---
layout: post
title:  "ARM-Toolchain - bis es läuft..."
date:   2014-11-22 20:00:00
categories: [Grundlagen]
tags: [ARM, Programmierung, Funktionieren]
author: jschnurrer
---

# Anleitung, wie man das Projekt von einem frischen Linux Mint auf das STM32F3-Board bringt

Wir haben uns meines Wissens aufs F3 im Master geeinigt.


## 1. arm-none-eabi-gcc nachinstallieren

    sudo apt-get remove binutils-arm-none-eabi gcc-arm-none-eabi
    sudo add-apt-repository ppa:terry.guo/gcc-arm-embedded
    sudo apt-get update
    sudo apt-get install gcc-arm-none-eabi

## 2. weitere notwendige Pakete

    sudo apt-get install libc6-dev-i386 gcc-multilib libgcc-4.8-dev bridge-utils 

* libc6-dev-i386 für die predefs.h
* gcc-multilib für die asm/socket.h


## 3. ST-Link installieren

    git clone https://github.com/texane/stlink
    cd stlink
    ./autogen.sh
    ./configure
    make

danach den Ordner stlink irgendwo platzieren (ich habe meinen Home-Ordner genommen)

	cd .. //um wieder aus dem Ordner stlink eins höher zu gehen
	cp -R stlink ~/stlink

Setting up udev rules:

	cd ~/stlink
	sudo cp 49-stlinkv2.rules /etc/udev/rules.d/
    sudo udevadm control --reload-rules
    sudo udevadm trigger


## 4. Das Projekt auschecken
Siehe Post zu Git-Grundlagen

    git clone https://github.com/michz/diy14bus
    cd diy14bus
    git submodule init
    git submodule update
    git checkout master  //nicht nötig, da standard.


## 5. in diy14bus/first-test/ wechseln
Zum Bauen 

    make

aufrufen. Nun sollte es ohne Probleme zumindest bauen. Nun das STM32F3-Board über USB anstecken und mit

    make flash

programmieren. Nach dem Betätigen vom Reset-Taster auf dem Board sollte die LED blinken.

   
Wenn ich etwas vergessen habe, einfach dazu schreiben :)



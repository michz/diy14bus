---
layout: post
title:  "Erste (Repository-)Schrite"
date:   2014-12-05 12:00:00
categories: [Grundlagen]
tags: [Git]
author: mzapf
---

# Aktuellen Entwicklungsstand klonen und Arbeitsumgebung einrichten
(Anmerkung: Nach negativer Erfahrung mit der Submodul-Funktionalität von Git
haben wir uns dazu entschlossen, den RIOT-OS-Fork getrennt vom
Applikationsrepository zu verwalten.)

Zunächst sollte ein leerer Ordner angelegt werden, der als Arbeitsverzeichnis
für das komplette Projekt dient:
    mkdir arbeitsverzeichnis

Anschließend werden die beiden Repositories geklont:
    git clone git@github.com:michz/diy14bus.git
    git clone git@github.com:patkan/RIOT.git

Fertig. Wie die Toolchain eingerichtet wird,
ist beispielhaft im Artikel
[ARM-Toolchain - bis es läuft...](http://michz.github.io/diy14bus/2014/11/Arm-Toolchain/)
beschrieben.



# Woher weiß unsere Applikation, wo RIOT liegt?
Im Anwendungs-Makefile muss der Pfad zu RIOT angegeben werden.

Beispiel:

```make
    # name of your application
    APPLICATION = first-test-f1

    # If no BOARD is found in the environment, use this default:
    BOARD ?= stm32f0discovery-diy

    ######## THIS IS THE IMPORTANT LINE ########
    # This has to be the absolute path to the RIOT base directory:
    RIOTBASE ?= $(CURDIR)/../../RIOT/

    # Modules required by this application
    USEMODULE += cc110x_spi
    USEMODULE += cc110x_legacy


    # Change this to 0 show compiler invocation lines by default:
    QUIET ?= 1

    include $(RIOTBASE)/Makefile.include
```

Die Zeile, in der die Variable `RIOTBASE` definiert wird, stimmt exakt so,
wenn die Repositories wie oben auf derselben Verzeichnisebene liegen.
Dies ist der Entwicklungsstandard und sollte so eingehalten werden,
damit die anderen Entwickler nicht bei jedem Kompilieren das Makefile
anpassen müssen.


# Umgang mit den Repositories
Beide Repositories (RIOT-OS-Fork mit dem Betriebssystem
und das diy14bus-Repository mit den Anwendungen und Projektdateien)
sind völlig unabhängig voneinander zu betrachten und zu behandeln.

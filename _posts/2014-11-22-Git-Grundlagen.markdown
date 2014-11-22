---
layout: post
title:  "Git Grundlagen"
date:   2014-11-22 20:00:00
categories: [Grundlagen]
tags: [Git]
author: jschnurrer
---

# Grundlagen für Git:

## Projekt auschecken (lokale Kopie anlegen)

    git clone ssh://git@github.com/michz/diy14bus
    cd diy14bus
    git submodule init
    git submodule update
    git checkout master //Für den Quellcode. (Nicht notwendig, da standard)
    git checkout gh-pages //Für die Blogeinträge

## Die Änderungen hochladen

    git add neue_datei.txt //für neue Dateien oder einfach mit -A
    git commit -a -m "My changes" 
    git push origin master //oder statt "master" dann "gh-pages" für Blogeinträge

## lokale Kopie aktualisieren
Ich will mein lokales Repository auf neusten Stand holen ohne löschen und git clone

Mache ich immer mit

    git checkout master -f

Bügelt halt alles nieder, was lokal noch vorhanden ist, lässt aber nur lokal vorhandene Dateien in Ruhe (war für mich noch nie ein Problem)

Gibt es eine elegantere Möglichkeit? Ein checkout ohne -f zählt nur die Differenzen auf und ein pull holt nur die neuen Dateien und lässt die Modifizierten in Ruhe.




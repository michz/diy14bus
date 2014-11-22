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
    git clone https://github.com/michz/diy14bus
    cd diy14bus
    git submodule init
    git submodule update

### Für den Quellcode
    git checkout master

### Für die Blogeinträge
    git checkout gh_pages

## Die Änderungen hochladen

    git add neue_datei.txt //für neue Dateien oder einfach mit -a
    git commit -m "My changes" 
    git push origin master //oder statt "master" dann "gh_pages" für Blogeinträge

## lokale Kopie aktualisieren
Ich will mein lokales Repository auf neusten Stand holen ohne löschen und git clone

Mache ich immer mit
    git checkout master -f
Bügelt halt alles nieder, was lokal noch vorhanden ist, lässt aber nur lokal vorhandene Dateien in Ruhe (war für mich noch nie ein Problem)

Gibt es eine elegantere Möglichkeit? Ein checkout ohne -f zählt nur die Differenzen auf und ein pull holt nur die neuen Dateien und lässt die Modifizierten in Ruhe.




---
layout: post
title:  "Git Grundlagen"
date:   2014-11-22 20:00:00
categories: [Grundlagen]
tags: [Git]
author: jschnurrer
---

# Grundlagen für Git
**DEPRECATED / VARLTET! Die nachfolgende Anleitung ist veraltet und kann
nicht mehr verwendet werden. Inzwischen sind beide Repositories einzeln,
es wird kein Submodul mehr verwendet.
Siehe auch: [Erste (Repository-)Schritte](http://michz.github.io/diy14bus/2014/12/Erste-Repo-Schritte/)**


(Anmerkung: Die folgenden "Erste Schritte"-Beschreibungen beziehen sich auf das
Entwickeln im master-Branch. Arbeitet man auf einem anderen Branch, ist "master"
durch den entsprechenden Namen zu ersetzen.)

## Projekt auschecken (lokale Kopie anlegen)

    git clone ssh://git@github.com/michz/diy14bus
    cd diy14bus
    git submodule init
    git submodule update
    git checkout master   //Für den Quellcode (nicht notwendig, da standard)
    git checkout gh-pages //Für die Blogeinträge

## Die Änderungen hochladen

    git add neue_datei.txt //für neue Dateien oder einfach mit -A
    git commit -m "description of my changes"
    git push origin master //oder statt "master" dann "gh-pages" für Blogeinträge

## Änderungen in Submodul commiten
Hat man Änderungen in einem Git-Submodul vorgenommen (z.B. im RIOT-Verzeichnis an den
Board-Dateien gearbeitet), müssen diese doppelt bekannt gemacht werden:
(Annahme: Das Submodul heißt "RIOT")

    // sicherstellen, dass man IM Submodulpfad ist, z.B. durch   cd RIOT
    git add <geänderte Dateien>
    git commit -m "description of my changes"
    git push origin master
    cd .. // in ein Verzeichnis wechseln, das OBERHALB des Submoduls liegt
    git add RIOT
    git commit -m "updated submodule"
    git push origin master

Jetzt weiß auch das "Hauptrepository", dass das Submodul angepasst wurde und
zeigt wieder auf den aktuellsten Commit.

## lokale Kopie aktualisieren
Ich will mein lokales Repository auf neusten Stand holen ohne löschen und git clone

Mache ich immer mit

    git checkout master -f

Bügelt halt alles nieder, was lokal noch vorhanden ist, lässt aber nur lokal vorhandene Dateien in Ruhe (war für mich noch nie ein Problem)

Gibt es eine elegantere Möglichkeit? Ein checkout ohne -f zählt nur die Differenzen auf und ein pull holt nur die neuen Dateien und lässt die Modifizierten in Ruhe.




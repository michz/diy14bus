---
layout: post
title:  "Erstes Brainstorming und Projektbeginn"
date:   2014-10-31 15:47:42
categories: [Projektstruktur]
tags: [Projektbeginn, Ideen]
author: pkanzler
---

Angefangen hat das Projekt mit der Suche nach einem Projekt, das man zusammen realisieren könnte durch Michi und Patrick.
Dabei kam die Idee auf, eine Alternative zu den, zugegebenermaßen bereits vielzähligen Heimbussystemen, zu bauen.

Im Rahmen der Veranstaltung [DIY14][diy14] hat sich dann ein Team gebildet, um dieses Bussystem zu entwickeln.
Das Team besteht aus:

* Michael Zapf
* Robin Backhaus
* Patrick Kanzler
* Josef Schnurrer

Dieser Post soll die Entwicklungen bis zum Einführen dieses Blogs beschreiben.

## Entwicklung Infrastruktur
Als Infrastruktur wird ein [GitHub-Repository][github] verwendet.
Michi hat es angelegt und die anderen als collaborator eingetragen.
Zur Dokumentation und zur Erstellung der ersten [Konzeptpräsentation][presentation], wurde der Branch `doc` angelegt.

## Ziel
Ziel des Projektes ist ein Hausbaussystem.
Hausbus meint ein Netz von Sensoren und Aktoren, welche Ereignisse erzeugen und darauf reagieren können.
Als besonderes Merkmal soll das System aus einzelnen, kostengünstigen, sich selbst vermaschenden Knoten bestehen.
Um keine unbrauchbare Insellösung zu entwickeln, soll das Meshnetzwerk über ein ebenfalls selbst gebautes Gateway Verbindung zu einer [openHAB][openhab]-Instanz aufnehmen können.

## Name
Die Wahl des Namen fiel nicht leicht.
Wir haben uns darauf geeinigt, dass wir das Projekt DIY14BUS nennen und auch so anmelden.
Wenn dann später mehr über Technologie und Funktionsumfang bekannt ist, ist es hoffentlich leichter, einen "richtigen" Namen zu wählen.

## Betriebssystem
Um das Rad nicht neu zu erfinden, bietet es sich an, ein eingebettetes Betriebssystem auf den Knoten einzusetzen.
Relativ früh wurde uns der Tipp gegeben, "RIOT OS" anzuschauen.
RIOT OS ist ein Betriebssystem für den Bereich embedded, welches auf das Thema Internet of Things optimiert wurde.
Damit bietet es gegenüber Konkurrenten, wie chibiOS oder FreeRTOS den Vorteil, dass einiges, wie eine saubere Netzwerkkommunikation mit Unterstützung für IPv6 bereits implementiert ist.
Es soll 6LoWPAN zum Einsatz kommen, um auf den doch relativ schwachen Knotengeräten Ressourcen zu sparen.

## Hardware
Für die Hardware standen verschiedene Plattformen zur Verfügung. Dies wurde im Piratenpad diskutiert.



[diy14]: http://www7.cs.fau.de/de/teaching/diy-2014w/
[github]: https://github.com/michz/diy14bus
[presentation]: https://github.com/michz/diy14bus/tree/doc/doc
[openhab]: http://www.openhab.org/

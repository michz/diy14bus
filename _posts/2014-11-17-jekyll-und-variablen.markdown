---
layout: post
title:  "Jekyll und Variablen"
date:   2014-11-17 07:53:12
categories: [Infrastruktur]
tags: [Jekyll, Variablen]
author: pkanzler
--- 
Gerade beobachtet: Ich habe mit `assign` eine Variable im default-Template gesetzt.
Diese scheint nicht im post-Template, dieses wird für einen normalen Blog-Post verwendet, verfügbar gewesen zu sein.

Die Lösung war die Variablen-Definition in das post-Template zu schieben.
Ich verstehe gerade noch nicht ganz wodurch das entsteht, aber man sollte es sich für die Zukunft merken.
---
layout: post
title:  "Virtuelles Netzwerk unter Linux"
date:   2014-11-22 17:00:00
categories: [Infrastruktur]
tags: [Netzwerk, Funk, Linux, Simulation]
author: mzapf
---
Es war gewünscht, mittels virtueller Netzwerkinterfaces (tap devices) und
virtuellen Netzwerkbrücken eine virtuelle Netzwerkinfrastruktur aufzubauen,
um Routing-Mechanismen am PC entwickeln und testen zu können.

Das Problem ist, dass ein tap-Device jederzeit nur einer Bridge zugeordnet sein
kann, Bridges aber nicht mit Bridges verknüpft werden können.
Damit ist bisher nur ein einzelnes, flaches, komplett verbundenes Netz möglich.

Lösung: noch keine

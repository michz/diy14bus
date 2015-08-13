cowbus protoboard - a prototyping board
=======================================

Core components
---------------
* CPU: [STM32F030C8T6]
* Radio: nrf24l01+
* LDO: [TS5204]
* EEPROM: [24LC04B-I/SN]

On periphery board:
* Temperatur Sensor: [LM 75]
* Buzzer: Some piezo that does not draw more than 25mA and works with 3,3V,
    for example: [EKULIT SMD-P16]
* LED: [LRTB G6TG]


I2C-Bus
-------

This board provides a I2C bus.
Following addresses are reserved:

* 1010xxx (serial EEPROM; where x is either 1 or 0)
* 1001000 (temperature sensor on periphery board)


License
-------
This board is licensed under
[Creative Commons Attribution 4.0 International (CC BY 4.0)](https://creativecommons.org/licenses/by/4.0/)
![CC BY 4.0 logo](https://licensebuttons.net/l/by/4.0/88x31.png)


[STM32F030C8T6]: http://www.digikey.de/product-detail/de/STM32F030C8T6/497-14043-ND/4357252

[EKULIT SMD-P16]: https://www.reichelt.de/Signalakustik/SMD-P16/3/index.html?ACTION=3&GROUPID=6560&ARTICLE=145909&OFFSET=500&WKID=0&
[LM 75]: https://www.reichelt.de/Temperatursensoren/LM-75-SMD/3/index.html?ACTION=3&GROUPID=6672&ARTICLE=49349&SEARCH=i2c%20temperatur%20sensor&OFFSET=500&WKID=0&
[TS5204]: https://www.reichelt.de/ICs-TLC-TSA-/TS-5204-CX33/3/index.html?ACTION=3&GROUPID=5480&ARTICLE=115980&OFFSET=500&WKID=0&
[24LC04B-I/SN]: https://www.reichelt.de/EEPROM-seriell-Microchip/24LC04B-I-SN/3/index.html?ACTION=3&GROUPID=4511&ARTICLE=40074&OFFSET=500&WKID=0&
[LRTB G6TG]: https://www.reichelt.de/SMD-LEDs-Multi-Color/LRTB-G6TG/3/index.html?ACTION=3&GROUPID=3036&ARTICLE=65109&OFFSET=500&WKID=0&

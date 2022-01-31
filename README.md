# DeskBot©

A Little Robot With Lot's of Potential...

<hr />

## Features✨

- RGB LED Strip Control
- Clock
- Weather
- Alarms
- Sync to Spotify Music and Play / Pause
- Control Basic LED Strip Patterns from The Web Server

<hr />

## Circuitry🔌

Parts Needed...

- NodeMCU CP2102
- Arduino Nano R3
- SSD1306 OLED Display
- Capacitive Touch Sensor
- Piezo Buzzers
- DS3231 RTC Module
- WS2812 RGB LED Strip
- Power Supply (5V 10A AC to DC)
- 180Ω - 220Ω Resistors
- 100uf Capaciticator
- Red and Green LED
- Switches (For Break Connections when Uploading a Sketch)
- Wires and Breadboards to Make Connections

<br>

> To Calculate The Amp of the Power Supply

```
Every LED consists of 3 Red, Green, Blue lights.

That Single LED Uses 20mA.

So a LED With Full Brightness with White Color uses 60mA.


Minimum Amps Needed at full Power Usage = NUM_OF_LEDS * 60
```

![Circuit](./Assests/DeskBot_Circuit.png)

<hr />

<br>

## Bot Casing🤖

<br>

![Case Design](./Assests/Deskbot_Case.png)

<hr />

<br>

## Libraries Used🔧

- [Spotify API Arduino](https://github.com/witnessmenow/spotify-api-arduino)

- [Cute Buzzer Sounds](https://github.com/GypsyRobot/CuteBuzzerSounds)

- [FastLED](https://github.com/FastLED/FastLED)

<img src="./Assests/Deskbot_image.png" align="right" width="80%">

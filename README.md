arduino
=======

All my arduino code

@todo use the followign ref: https://rastating.github.io/using-a-jhd162a-lcd-screen-with-an-arduino-uno/


Arduino uno
-----------

![Board Arduino uno](board_base.jpg)

Seeduino sensor Chassis V1.1. X1
--------------------------------
![Board Seeeduino sensor chassis V1.1 x1 global view](chassis3.jpg)

![Board Seeeduino sensor chassis V1.1 x1](chasiss5.jpg)

All the connector have a connection to GND & VCC & SIGNAL

### A1
* Signal A1 - connect to analog 1
* VCC
* GND

A2

A3

A4

A5

IIC

UART

D8

D9

D10

D11

D12

### Bus
![Bus Connections](BUS.jpg)

### Peripherals 

#### LCD 1602 (BUS)

![LCD Pins](lcd/LCD16x2%20Pins.png)

The LCD bus wirings is as follow

| Bus 1 / Arduino Pin | JHD 162 A |
|---------------------|-----------|
| VCC | VCC |
| D2 | Registry Select |
| D3 | RW |
| D4 | Enable |
| D5 | D4 |
| D6 | D5 |
| D7 | D6 |
| D8 | D7 |
| D9 | / |
| GND | VSS|



Classic code linking is matching the following schema

![classic code sample linking](lcd/Arduino-Wiring-Fritzing-Connections-with-16x2-Character-LCD.png)

```arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

LiquidCrystal(rs, enable, d4, d5, d6, d7) 
```

According to the [documentation of lcd constructor](https://www.arduino.cc/en/Reference/LiquidCrystalConstructor) the constructor take at least 4 data bus pin d4-->d7


So we should have the following code with BUS 1

```arduino
LiquidCrystal lcd(2, 3, 4, 5, 6, 7, 8);
```


```arduino
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16,2); // don't know why 16,1 is high contrast
  lcd.print("hello, world!");
}

void loop() {}
```







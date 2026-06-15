# Circuit Connections

## Push Button

Push Button Pin 1 -> Arduino D2

Push Button Pin 3 -> Arduino GND

Arduino Configuration:

pinMode(D2, INPUT_PULLUP)

---

## LED Indicator

Arduino D13 -> 1kΩ Resistor -> LED Anode (+)

LED Cathode (-) -> Arduino GND

---

## Relay Module

Relay IN -> Arduino D8

Relay VCC -> Arduino 5V

Relay GND -> Arduino GND

---

## Solenoid Valve

12V Adapter Positive -> Relay COM

Relay NO -> Solenoid Valve Positive

Solenoid Valve Negative -> 12V Adapter Negative

---

## Safety Note

The solenoid valve must never be powered directly from the Arduino.

Use the relay module and external 12V power supply.

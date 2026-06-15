# Hardware Documentation

## Project 1: Debounced Button LED Toggle

### Components Used

* Arduino Uno/Nano
* Push Button (SKS49)
* LED
* 220 Ω Resistor
* Breadboard
* Jumper Wires

### Connections

#### Push Button

* Arduino Pin D2 → Push Button
* Push Button → GND
* Internal pull-up resistor enabled using `INPUT_PULLUP`

#### LED

* Arduino Pin D13 → 220 Ω Resistor → LED Anode (+)
* LED Cathode (-) → GND

### Working

The push button is connected using the Arduino's internal pull-up resistor. When the button is pressed, Pin D2 reads LOW. Software debouncing is used to prevent false triggering caused by switch bounce. Each valid button press toggles the LED state.

---

## Project 2: Relay Controlled Solenoid Valve

### Components Used

* Arduino Uno/Nano
* 5V Relay Module
* Solenoid Valve
* External Power Supply
* Jumper Wires

### Connections

#### Relay Module

* Arduino D7 → Relay IN
* Arduino 5V → Relay VCC
* Arduino GND → Relay GND

#### Solenoid Valve

* External Supply Positive → Relay COM
* Relay NO → Solenoid Valve Positive
* Solenoid Valve Negative → External Supply Negative

### Safety Note

The solenoid valve is never connected directly to an Arduino GPIO pin. The relay module provides electrical isolation and allows the Arduino to safely switch higher current loads.

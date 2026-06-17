# Components List

## Hardware Components

| Sl. No. | Component                         | Quantity    |
| ------- | --------------------------------- | ----------- |
| 1       | Arduino UNO                       | 1           |
| 2       | LM393 Soil Moisture Sensor Module | 1           |
| 3       | YL-69 Soil Moisture Probe         | 1           |
| 4       | 5V Relay Module (Active LOW)      | 1           |
| 5       | 12V DC Solenoid Valve             | 1           |
| 6       | LED (5 mm)                        | 1           |
| 7       | 1kΩ Resistor                      | 1           |
| 8       | Breadboard                        | 1           |
| 9       | Jumper Wires (Male-Male)          | As Required |
| 10      | 12V DC Power Supply               | 1           |
| 11      | USB Cable for Arduino Programming | 1           |

## Software Requirements

| Sl. No. | Software        | Purpose                        |
| ------- | --------------- | ------------------------------ |
| 1       | Arduino IDE 2.x | Program Development and Upload |
| 2       | Git             | Version Control                |
| 3       | GitHub          | Repository Management          |

## Pin Connections Summary

| Arduino Pin | Connected Component                |
| ----------- | ---------------------------------- |
| A0          | LM393 Soil Sensor A0               |
| D8          | Relay IN                           |
| D13         | LED (+ through 1kΩ resistor)       |
| 5V          | Sensor VCC, Relay VCC              |
| GND         | Sensor GND, Relay GND, LED Cathode |

## Power Connections

| Device               | Supply                    |
| -------------------- | ------------------------- |
| Arduino UNO          | USB (5V)                  |
| Relay Module         | Arduino 5V                |
| Soil Moisture Sensor | Arduino 5V                |
| Solenoid Valve       | External 12V Power Supply |

## Total Components Used

* Arduino UNO – 1
* Soil Moisture Sensor System (LM393 + YL-69) – 1 Set
* Relay Module – 1
* Solenoid Valve – 1
* LED – 1
* Resistor – 1
* Breadboard – 1
* Jumper Wires – As Required
* 12V Power Supply – 1
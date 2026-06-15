# Manual Irrigation Toggle (Phase 1 Capstone)

## Objective
Develop a manual irrigation controller using Arduino Uno, push button, relay module, and solenoid valve.

## Features
- Single button irrigation trigger
- Configurable irrigation duration
- Relay-controlled valve operation
- Serial event logging with timestamps
- Debounced push button input

## Hardware Used
- Arduino Uno
- Push Button
- Relay Module (5V)
- Solenoid Valve (12V)
- 12V Power Supply
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|------------|------------|
| Push Button | D2 |
| Relay IN | D8 |
| LED Indicator | D13 |

## Working
1. User presses the push button.
2. Arduino validates the button press.
3. Relay energizes.
4. Solenoid valve opens.
5. Valve remains open for configured duration.
6. Event is logged to Serial Monitor.
7. Relay turns OFF after timeout.

## Serial Output Example

Valve OPENED
Timestamp: 15234 ms

Valve CLOSED
Timestamp: 20234 ms

## Methodology
The system integrates a push button and relay module to implement manual irrigation control. A debounced button press activates the relay, opening the solenoid valve for a configurable duration. Event timestamps are recorded using the Arduino millis() function and displayed through Serial Monitor.

## Repository Structure

src/ → Arduino source code

docs/ → Documentation and diagrams

media/ → Demo videos and images

## Release
Tag:
v0.1-manual

## Author
Pranavu P Pillai

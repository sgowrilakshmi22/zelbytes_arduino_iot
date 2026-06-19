
# Task 3 – DC Motor PWM Control with Emergency Stop

## Objective
Control a DC motor using PWM and implement an interrupt-driven emergency stop system.

## Features
- PWM speed control (0–255) through Serial Monitor
- Emergency stop using hardware interrupt
- Solenoid valve control
- LED indication of motor status
- Serial feedback messages

## Hardware
- Arduino Uno
- DC Motor
- MOSFET/Transistor Driver
- Solenoid Valve
- Relay Module
- Push Button (E-Stop)
- LED + 1kΩ Resistor
- External 12V Supply

## Folder Structure
- src/ : Arduino source code
- docs/ : Schematics and documentation
- images/ : Hardware photos
- logs/ : Test results

## Usage
1. Upload sketch.
2. Open Serial Monitor at 9600 baud.
3. Enter PWM values (0–255).
4. Press E-Stop button to stop motor and close valve.

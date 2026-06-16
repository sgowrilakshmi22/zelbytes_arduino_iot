# Manual Irrigation Toggle (Phase 1 Capstone)

## Objective
Develop a manual irrigation controller using Arduino Uno, push button, relay module, and solenoid valve.

## Components Used

- Arduino Uno
- Push Button
- LED
- 1kΩ Resistor
- 5V Relay Module
- 12V Solenoid Valve
- 12V DC Adapter
- Jumper Wires

## Methodology

1. Connected the push button to Arduino pin D2 using internal pull-up configuration.
2. Connected relay module input to D8.
3. Connected LED indicator to D13 through a 1kΩ resistor.
4. Connected solenoid valve to a 12V supply through relay contacts.
5. Implemented software debouncing.
6. Activated valve upon button press.
7. Logged timestamps using millis().
8. Automatically closed the valve after the configured duration.

## Result

The irrigation controller successfully opened and closed the solenoid valve using a single button press while recording irrigation events in the Serial Monitor.

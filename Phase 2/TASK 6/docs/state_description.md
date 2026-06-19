# System Behaviour

## Normal Mode
- User enters PWM value through Serial Monitor.
- Motor runs at selected speed.
- LED ON when motor runs.
- Valve can be opened or closed independently.

## Emergency Stop
- Interrupt triggers immediately.
- Motor PWM set to 0.
- Valve closes.
- LED OFF.
- Serial Monitor displays:
  E-STOP ACTIVATED

# docs/state_machine.md

# Irrigation State Machine

## States

### IDLE

System monitors soil moisture and humidity.

### IRRIGATING

Relay ON.
Solenoid valve OPEN.

### COOLDOWN

Relay OFF.
Waiting period before next irrigation.

### FAULT

Triggered when DHT22 fails 3 consecutive readings.

## State Diagram

IDLE
↓
IRRIGATING
↓
COOLDOWN
↓
IDLE

Any State
↓
FAULT (DHT22 failure ×3)

## Transition Conditions

| Current State | Condition                         | Next State |
| ------------- | --------------------------------- | ---------- |
| IDLE          | Moisture < 30% and Humidity > 40% | IRRIGATING |
| IRRIGATING    | 10 sec elapsed                    | COOLDOWN   |
| COOLDOWN      | 5 sec elapsed                     | IDLE       |
| Any           | DHT fail ×3                       | FAULT      |

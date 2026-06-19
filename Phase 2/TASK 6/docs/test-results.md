# Test Results

## Task 6: DC Motor PWM Control with Emergency Stop

### Test Environment
- Arduino Uno
- DC Motor with PWM Driver
- 5V Relay Module
- 12V Solenoid Valve
- LED Indicator
- Push Button (E-Stop)
- Serial Monitor @ 9600 baud

---

## Test 1: PWM Speed Control

| Command | Expected Result | Observed Result | Status |
|----------|----------------|----------------|---------|
| M255 | Motor runs at maximum speed | Motor Speed = 255 displayed | PASS |
| M125 | Motor runs at medium speed | Motor Speed = 125 displayed | PASS |

### Serial Output
```
Motor Speed = 255
Motor Speed = 125
```

---

## Test 2: Valve Open Operation

| Command | Expected Result | Observed Result | Status |
|----------|----------------|----------------|---------|
| OPEN | Relay activates and valve opens | Valve Opened displayed | PASS |

### Serial Output
```
Valve Opened
```

---

## Test 3: Valve Close Operation

| Command | Expected Result | Observed Result | Status |
|----------|----------------|----------------|---------|
| CLOSE | Relay deactivates and valve closes | Valve Closed displayed | PASS |

### Serial Output
```
Valve Closed
```

---

## Test 4: Emergency Stop Function

| Action | Expected Result | Observed Result | Status |
|----------|----------------|----------------|---------|
| Press E-Stop Button | Motor stops immediately | E-STOP BUTTON ACTIVATED displayed | PASS |
| Press E-Stop Button | Valve closes immediately | Valve closed successfully | PASS |
| Press E-Stop Button | LED turns OFF | LED OFF | PASS |

### Serial Output
```
E-STOP BUTTON ACTIVATED
```

---

## Test 5: System Reset

| Command | Expected Result | Observed Result | Status |
|----------|----------------|----------------|---------|
| RESET | System exits emergency state | SYSTEM RESET displayed | PASS |

### Serial Output
```
SYSTEM RESET
```

---

## Combined System Test

### Sequence Performed
```
M255
M125
OPEN
CLOSE
E-STOP
RESET
M255
E-STOP
```

### Observed Output
```
Motor Speed = 255
Motor Speed = 125
Valve Opened
Valve Closed
E-STOP BUTTON ACTIVATED
SYSTEM RESET
Motor Speed = 255
E-STOP BUTTON ACTIVATED
```

### Result
- PWM motor control operates correctly.
- Valve open/close commands function correctly.
- Emergency stop interrupt immediately halts system operation.
- Reset command restores normal operation.
- System meets all Task 3 requirements.

## Overall Status

**PASS ✅**

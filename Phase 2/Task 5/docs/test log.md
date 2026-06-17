# docs/test_log.md

# Test Log

## Test 1: Normal Operation

Input:
Moisture = 20%
Humidity = 60%

Expected:
IDLE → IRRIGATING → COOLDOWN → IDLE

Result:
PASS

---

## Test 2: Wet Soil

Input:
Moisture = 80%

Expected:
Remain in IDLE

Result:
PASS

---

## Test 3: DHT22 Failure

Input:
Disconnect DHT22

Observed:

DHT Failure Count: 1
DHT Failure Count: 2
DHT Failure Count: 3

STATE -> FAULT

Result:
PASS

---

## Test 4: Relay Operation

Expected:
Relay energizes during irrigation.

Result:
PASS

---

## Test 5: Solenoid Valve

Expected:
Water flows only during irrigation.

Result:
PASS

# docs/wiring_diagram.md

## Arduino Connections

### DHT22

VCC → 5V
DATA → D2
GND → GND

### Capacitive Soil Sensor

VCC → 5V
AOUT → A0
GND → GND

### Relay Module

VCC → 5V
IN → D8
GND → GND

### LED

Anode → D13 through 1kΩ resistor
Cathode → GND

### Solenoid Valve

Relay COM → +12V

Relay NO → Solenoid +

Solenoid − → 12V GND

# docs/methodology.md

# Methodology

1. Read soil moisture using the capacitive sensor.
2. Convert raw analog value into percentage.
3. Read humidity from DHT22.
4. Compare readings with predefined thresholds.
5. If moisture is below 30% and humidity exceeds 40%, start irrigation.
6. Activate relay and open solenoid valve.
7. Continue irrigation for 10 seconds.
8. Enter cooldown state for 5 seconds.
9. Return to IDLE.
10. If DHT22 fails three consecutive readings, enter FAULT state and disable irrigation.

# hardware/components_list.md

# Components List

1 Arduino UNO

1 Capacitive Soil Moisture Sensor v1.2

1 DHT22 Sensor

1 Relay Module (5V)

1 Solenoid Valve (12V DC)

1 LED

1 Resistor (1kΩ)

1 Breadboard

Jumper Wires

1 12V Power Supply

# results/calibration_data.txt

Calibration Results

Dry Soil Reading : 850

Wet Soil Reading : 350

Moisture Threshold : 30%

Humidity Threshold : 40%

# results/irrigation_cycle_log.txt

STATE -> IDLE

Moisture: 18%
Humidity: 62%

STATE -> IRRIGATING

Relay ON
Solenoid OPEN

10 Seconds Completed

STATE -> COOLDOWN

5 Seconds Completed

STATE -> IDLE

# results/fault_state_log.txt

DHT Failure Count: 1

DHT Failure Count: 2

DHT Failure Count: 3

STATE -> FAULT

Relay OFF

Solenoid CLOSED

LED BLINKING

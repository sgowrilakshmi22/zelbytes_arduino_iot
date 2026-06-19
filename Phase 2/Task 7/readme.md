# Sensor Data Logging

## Objective
Log environmental sensor data for 30 minutes using serial CSV capture.

## Sensors Used
- DHT11 Temperature & Humidity Sensor
- Soil Moisture Sensor
- LDR Light Sensor

## Logged Parameters
1. Timestamp (ms)
2. Temperature (°C)
3. Humidity (%)
4. Soil Moisture
5. Light Level

## Hardware
- Arduino Uno
- DHT11 Sensor
- Soil Moisture Sensor
- LDR Module
- USB Cable

## Wiring

| Sensor | Arduino Pin |
|----------|-------------|
| DHT11 Data | D2 |
| Soil Sensor AO | A0 |
| LDR AO | A1 |
| VCC | 5V |
| GND | GND |

## How to Reproduce

1. Upload `sensor_logger.ino`.
2. Open Serial Monitor at 9600 baud.
3. Close Serial Monitor.
4. Open Serial Plotter or Serial Logger software.
5. Save incoming serial data as CSV.
6. Let system run for 30 minutes.
7. Store captured file as `data/sample_log.csv`.

## CSV Format

timestamp,temp,humidity,soil,light

Example:

1000,29.1,65.0,520,710

## Sample Dataset

A sample capture containing more than 50 rows is included in:

data/sample_log.csv

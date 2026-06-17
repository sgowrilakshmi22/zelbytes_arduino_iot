# Methodology

## 1. Objective

The objective of this project is to develop an automatic irrigation system using an Arduino UNO and a soil moisture sensor. The system monitors the moisture level of the soil and automatically controls a solenoid valve through a relay module to provide water when the soil becomes dry.

---

## 2. Hardware Components

* Arduino UNO
* LM393 Soil Moisture Sensor Module
* YL-69 Soil Moisture Probe
* 5V Relay Module (Active LOW)
* 12V DC Solenoid Valve
* LED
* 1kΩ Resistor
* 12V Power Supply
* Jumper Wires

---

## 3. System Design

The soil moisture sensor continuously measures the moisture content of the soil and sends an analog signal to the Arduino UNO through pin A0. The Arduino processes the sensor reading and converts it into a moisture percentage.

A predefined moisture threshold is used to determine whether the soil is dry or wet.

* If the moisture percentage falls below the threshold value, the Arduino activates the relay module.
* The relay energizes the 12V solenoid valve, allowing water to flow.
* The LED is turned ON to indicate irrigation.
* If the moisture percentage rises above the threshold value, the Arduino deactivates the relay and closes the solenoid valve.
* The LED is turned OFF.

---

## 4. Working Procedure

### Step 1: Soil Moisture Measurement

The LM393 soil moisture sensor measures the conductivity of the soil through the YL-69 probe and produces an analog voltage proportional to the moisture content.

### Step 2: Data Acquisition

The Arduino reads the analog output of the sensor using analog pin A0 and obtains a raw sensor value.

### Step 3: Moisture Percentage Calculation

The raw sensor value is mapped into a moisture percentage ranging from 0% to 100%.

* 0% represents completely dry soil.
* 100% represents fully wet soil.

### Step 4: Decision Making

The calculated moisture percentage is compared with a predefined threshold value.

* Moisture < 30% → Soil is considered dry.
* Moisture ≥ 30% → Soil is considered sufficiently wet.

### Step 5: Irrigation Control

When the soil is dry:

* Relay is activated (Active LOW).
* Solenoid valve opens.
* Water is supplied to the plant.
* LED turns ON.

When the soil is wet:

* Relay is deactivated.
* Solenoid valve closes.
* Water supply stops.
* LED turns OFF.

### Step 6: Continuous Monitoring

The system continuously repeats the measurement and control process at regular intervals to maintain proper soil moisture levels.

---

## 5. Flowchart

Start

↓

Read Soil Moisture Sensor

↓

Convert Reading to Moisture Percentage

↓

Is Moisture < Threshold?

├── Yes → Relay ON → Solenoid ON → LED ON

└── No → Relay OFF → Solenoid OFF → LED OFF

↓

Repeat

---

## 6. Result

The developed irrigation system successfully automates the watering process by monitoring soil moisture levels and controlling a solenoid valve through a relay module. This reduces manual intervention and ensures efficient water usage while maintaining adequate soil moisture for plant growth.

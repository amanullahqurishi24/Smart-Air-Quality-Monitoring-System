# 🌬️ Smart Air Quality Monitoring System

An IoT-based indoor air quality monitoring system designed to monitor air quality, smoke, gas, temperature, and humidity in real time.

## 📌 Project Overview

The Smart Air Quality Monitoring System is an IoT project designed for indoor environments such as:

- 🏠 Homes
- 🏪 Shops
- 🏥 Hospitals
- 🏢 Offices
- 🏫 Schools
- 🎓 Universities

The system uses an ESP32 microcontroller and environmental sensors to collect information about the indoor environment. The collected data can be monitored through a connected application.

> **Note:** This project monitors indoor air conditions, smoke/gas-related sensor levels, temperature, and humidity. It is **not a fire-detection system**.

---

## 🎯 Problem Statement

Indoor air quality is an important factor affecting human health and safety.

In many indoor environments, harmful gases, smoke, and poor ventilation may go unnoticed because there is no continuous monitoring system.

Traditional monitoring methods may require manual inspection and do not provide continuous real-time information.

This project was developed to provide an affordable IoT-based solution for monitoring indoor environmental conditions and helping users identify abnormal air-quality and gas/smoke sensor readings.

---

## 💡 Objectives

The main objectives of this project are:

- Monitor indoor air quality.
- Detect changes in air-quality sensor readings.
- Monitor gas/smoke-related sensor levels.
- Measure temperature.
- Measure humidity.
- Collect sensor data using ESP32.
- Provide real-time monitoring capability.
- Present the collected information through a user-friendly application.
- Provide a low-cost solution suitable for indoor environments.

---

## ⚙️ Main Features

- Real-time environmental monitoring
- MQ-135 air-quality sensor
- MQ-2 gas/smoke sensor
- DHT-22 temperature and humidity sensor
- ESP32-based IoT controller
- Wi-Fi connectivity
- Mobile application support
- Cloud/Firebase integration
- Configurable sensor thresholds
- Indoor environmental monitoring

---

## 🧰 Hardware Components

| Component | Purpose |
|---|---|
| ESP32 | Main microcontroller and Wi-Fi connectivity |
| MQ-135 | Air-quality / gas-related sensing |
| MQ-2 | Gas and smoke-related sensing |
| DHT-22 | Temperature and humidity measurement |

### Suggested ESP32 Connections

| Sensor | ESP32 Pin |
|---|---|
| MQ-135 Analog Output | GPIO 34 |
| MQ-2 Analog Output | GPIO 35 |
| DHT-22 Data | GPIO 4 |

> These are the connections used in the recreated reference sketch. Verify the physical wiring before connecting the hardware.

---

## 💻 Software & Technologies

- **ESP32**
- **Arduino IDE**
- **C/C++**
- **Firebase Realtime Database**
- **React Native**
- **Wi-Fi**
- **GitHub**

---

## 🏗️ System Architecture

```text
┌─────────────────────┐
│     MQ-135 Sensor   │
│   Air Quality Data  │
└──────────┬──────────┘
           │
           │
┌──────────▼──────────┐
│      MQ-2 Sensor    │
│   Gas/Smoke Data    │
└──────────┬──────────┘
           │
           │
┌──────────▼──────────┐
│      DHT-22         │
│ Temperature/Humidity│
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│        ESP32        │
│ Data Collection     │
│ Processing + Wi-Fi  │
└──────────┬──────────┘
           │
           │ Wi-Fi
           ▼
┌─────────────────────┐
│ Firebase / Cloud    │
│ Data Storage        │
└──────────┬──────────┘
           │
           ▼
┌─────────────────────┐
│   Mobile Application│
│ Monitoring Interface│
└─────────────────────┘

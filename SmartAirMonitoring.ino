/*
  Smart Air Quality Monitoring System
  -------------------------------------------------
  Platform: ESP32
  Sensors:
    - MQ-135: indoor air-quality / smoke-related sensor
    - MQ-2: gas / smoke sensor
    - DHT-22: temperature and humidity

  IMPORTANT:
  - This is a portfolio/reference sketch based on the sensor models
    provided for the project. Verify the GPIO wiring before powering
    the hardware.
  - MQ-135 and MQ-2 readings are raw ADC values unless calibrated.
    Do NOT present them as exact ppm/AQI values without calibration.
  - Keep Wi-Fi/Firebase credentials out of public GitHub code.

  Suggested wiring:
    MQ-135 AO -> GPIO 34
    MQ-2   AO -> GPIO 35
    DHT-22 DATA -> GPIO 4
    Sensors GND -> ESP32 GND
    DHT-22 VCC -> appropriate supply

  Note:
  GPIO 34 and GPIO 35 are input-only ESP32 pins and are suitable for
  analog sensor outputs.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <DHT.h>

// -------------------------
// Wi-Fi configuration
// -------------------------
// Replace these locally. Do NOT commit real credentials to GitHub.
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

// -------------------------
// Pin configuration
// -------------------------
#define MQ135_PIN 34
#define MQ2_PIN   35
#define DHT_PIN   4
#define DHT_TYPE  DHT22

DHT dht(DHT_PIN, DHT_TYPE);

// -------------------------
// Monitoring intervals
// -------------------------
const unsigned long SENSOR_INTERVAL = 2000;
unsigned long lastSensorRead = 0;

// -------------------------
// Optional thresholds
// -------------------------
// These are example raw ADC thresholds only.
// They MUST be calibrated for the actual sensors/environment.
const int MQ135_WARNING_THRESHOLD = 1800;
const int MQ2_WARNING_THRESHOLD   = 1800;

void connectToWiFi() {
  Serial.print("Connecting to Wi-Fi");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  unsigned long start = millis();

  while (WiFi.status() != WL_CONNECTED &&
         millis() - start < 15000) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Wi-Fi connected.");
    Serial.print("ESP32 IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Wi-Fi connection failed.");
    Serial.println("Continuing in local sensor-monitoring mode.");
  }
}

void printSensorData() {
  int mq135Value = analogRead(MQ135_PIN);
  int mq2Value = analogRead(MQ2_PIN);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  Serial.println("----------------------------------------");
  Serial.println("Smart Air Quality Monitoring System");

  Serial.print("MQ-135 Air Quality Raw Value: ");
  Serial.println(mq135Value);

  Serial.print("MQ-2 Gas/Smoke Raw Value: ");
  Serial.println(mq2Value);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT-22: Sensor reading failed.");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  // These are simple project-level warnings, not certified safety alarms.
  if (mq135Value >= MQ135_WARNING_THRESHOLD) {
    Serial.println("WARNING: MQ-135 reading is above the configured threshold.");
  } else {
    Serial.println("MQ-135 status: Normal");
  }

  if (mq2Value >= MQ2_WARNING_THRESHOLD) {
    Serial.println("WARNING: MQ-2 reading is above the configured threshold.");
  } else {
    Serial.println("MQ-2 status: Normal");
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("========================================");
  Serial.println("Smart Air Quality Monitoring System");
  Serial.println("ESP32 Starting...");
  Serial.println("========================================");

  analogReadResolution(12);

  dht.begin();

  connectToWiFi();

  Serial.println("Sensors initialized.");
}

void loop() {
  if (millis() - lastSensorRead >= SENSOR_INTERVAL) {
    lastSensorRead = millis();
    printSensorData();
  }
}

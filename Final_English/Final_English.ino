#include <DHT.h>

#define DHTPIN A0        // DHT11 connected to Digital Pin 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN A1     // Soil Moisture Sensor on Analog Pin A1
#define LDR_PIN A2      // LDR Sensor on Analog Pin A2

void setup() {
    Serial.begin(9600);
    dht.begin();
}

void loop() {
    Serial.println("\n🔹 READING SENSOR VALUES 🔹");
    Serial.println("--------------------------------");

    // Read DHT11 Temperature & Humidity
    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();
    Serial.print("🌡️ Temperature: "); Serial.print(temp); Serial.println(" °C");
    Serial.print("💧 Humidity: "); Serial.print(humidity); Serial.println(" %");
    Serial.println("--------------------------------");
    delay(1000);  // Slow Display

    // Read Soil Moisture Sensor
    int soilMoisture = analogRead(SOIL_PIN);
    Serial.print("🌱 Soil Moisture: "); Serial.print(soilMoisture);
    if (soilMoisture > 800) {
        Serial.println(" (Dry Soil, Needs Water)");
    } else if (soilMoisture >= 400 && soilMoisture <= 600) {
        Serial.println(" (Medium Moisture)");
    } else {
        Serial.println(" (Wet Soil)");
    }
    Serial.println("--------------------------------");
    delay(1000);

    // Read LDR Sensor (Light Intensity)
    int lightLevel = analogRead(LDR_PIN);
    Serial.print("☀️ Light Intensity: "); Serial.print(lightLevel);
    if (lightLevel > 800) {
        Serial.println(" (Bright)");
    } else if (lightLevel >= 100 && lightLevel <= 800) {
        Serial.println(" (Moderate Light)");
    } else {
        Serial.println(" (Dark)");
    }
    Serial.println("--------------------------------");
    
    delay(1000);  // Slower display cycle for better readability
}

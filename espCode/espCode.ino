#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>

#define DHTPIN A0        // DHT11 connected to Analog Pin A0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define SOIL_PIN A1     // Soil Moisture Sensor on Analog Pin A1
#define LDR_PIN A2      // LDR Sensor on Analog Pin A2

const char* ssid = "Aadil's iPhone";  // Replace with your WiFi SSID
const char* password = "987654321";  // Replace with your WiFi password
const char* serverURL = "http://your_backend_ip_or_host/data"; // Backend API endpoint

WiFiClient client;
HTTPClient http;

void setup() {
    Serial.begin(115200);
    dht.begin();
    
    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");
}

void loop() {
    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();
    int soilMoisture = analogRead(SOIL_PIN);
    int lightLevel = analogRead(LDR_PIN);

    // Print sensor values
    Serial.println("\nSENSOR VALUES:");
    Serial.println("----------------------");
    Serial.print("Temperature: "); Serial.print(temp); Serial.println(" C");
    Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
    Serial.print("Soil Moisture: "); Serial.println(soilMoisture);
    Serial.print("Light Intensity: "); Serial.println(lightLevel);
    Serial.println("----------------------");

    // Send data to backend
    if (WiFi.status() == WL_CONNECTED) {
        http.begin(client, serverURL);
        http.addHeader("Content-Type", "application/json");

        String payload = "{";
        payload += "\"temperature\": " + String(temp) + ",";
        payload += "\"humidity\": " + String(humidity) + ",";
        payload += "\"soil_moisture\": " + String(soilMoisture) + ",";
        payload += "\"light_intensity\": " + String(lightLevel);
        payload += "}";

        int httpResponseCode = http.POST(payload);
        Serial.print("HTTP Response Code: ");
        Serial.println(httpResponseCode);

        http.end();
    }

    delay(5000);  // Wait before sending the next set of data
}

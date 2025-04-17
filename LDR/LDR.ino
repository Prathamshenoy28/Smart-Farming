const int ldrPin = A2;  // LDR connected to Analog Pin A0

void setup() {
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    int ldrValue = analogRead(ldrPin);  // Read LDR value
    Serial.print("Light Intensity: ");
    Serial.println(ldrValue);  // Print value to Serial Monitor
    delay(500);  // Wait for 500ms
}

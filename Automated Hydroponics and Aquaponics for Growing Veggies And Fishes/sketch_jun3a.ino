#define MOISTURE_SENSOR_PIN A0
#define RELAY_PIN 7

// Define moisture threshold
const int moisture_threshold = 520; // Adjust this value based on your sensor and soil

void setup() {
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Ensure relay is initially off
  Serial.begin(9600);
}

void loop() {
  // Read moisture level
  int moisture_level = analogRead(MOISTURE_SENSOR_PIN);
  Serial.println(analogRead(MOISTURE_SENSOR_PIN));
  // Check if moisture level is below threshold
  if (moisture_level > moisture_threshold) {
    // Turn on pump
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Moisture level is low. Watering plant.");
    // Run the pump for 5 seconds (adjust as needed)
    delay(5000);
    // Turn off pump
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Watering complete.");
  }

  // Delay before next reading
  delay(2000); // Adjust delay as needed
}
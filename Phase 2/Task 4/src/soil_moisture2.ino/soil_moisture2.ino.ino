#define SOIL_PIN A0
#define RELAY_PIN 8
#define LED_PIN 13

// Calibration values (adjust after testing)
const int DRY_VALUE = 850;
const int WET_VALUE = 250;

// Irrigation starts below this moisture %
const int MOISTURE_THRESHOLD = 30;

void setup() {

  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  // Active LOW relay OFF
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(LED_PIN, LOW);

  Serial.println("================================");
  Serial.println("SMART IRRIGATION SYSTEM");
  Serial.println("================================");
}

void loop() {

  // Read sensor
  int soilRaw = analogRead(SOIL_PIN);

  // Convert to percentage
  int moisturePercent =
      map(soilRaw, DRY_VALUE, WET_VALUE, 0, 100);

  moisturePercent =
      constrain(moisturePercent, 0, 100);

  Serial.print("Raw Value: ");
  Serial.print(soilRaw);

  Serial.print(" | Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Dry Soil
  if (moisturePercent < MOISTURE_THRESHOLD) {

    digitalWrite(RELAY_PIN, LOW);   // Active LOW relay ON
    digitalWrite(LED_PIN, HIGH);

    Serial.println("SOIL DRY -> RELAY ON -> VALVE ON");
  }

  // Wet Soil
  else {

    digitalWrite(RELAY_PIN, HIGH);  // Active LOW relay OFF
    digitalWrite(LED_PIN, LOW);

    Serial.println("SOIL WET -> RELAY OFF -> VALVE OFF");
  }

  Serial.println("--------------------------------");

  delay(1000);
}
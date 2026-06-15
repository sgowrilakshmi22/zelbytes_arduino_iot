#define BUTTON_PIN 2
#define RELAY_PIN 8
#define LED_PIN 13

#define IRRIGATION_TIME 5000   // Valve ON time in milliseconds (5 sec)

bool valveActive = false;
unsigned long valveStartTime = 0;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

int buttonState = HIGH;
int lastButtonReading = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Manual Irrigation Controller Started");
}

void loop() {

  int reading = digitalRead(BUTTON_PIN);

  // Debounce
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      // Button Pressed
      if (buttonState == LOW && !valveActive) {

        valveActive = true;
        valveStartTime = millis();

        digitalWrite(RELAY_PIN, HIGH);
        digitalWrite(LED_PIN, HIGH);

        Serial.println("-------------------");
        Serial.println("Valve OPENED");
        Serial.print("Timestamp: ");
        Serial.print(valveStartTime);
        Serial.println(" ms");
      }
    }
  }

  lastButtonReading = reading;

  // Auto Close Valve
  if (valveActive &&
      (millis() - valveStartTime >= IRRIGATION_TIME)) {

    valveActive = false;

    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PIN, LOW);

    Serial.println("Valve CLOSED");
    Serial.print("Timestamp: ");
    Serial.print(millis());
    Serial.println(" ms");
    Serial.println("-------------------");
  }
}

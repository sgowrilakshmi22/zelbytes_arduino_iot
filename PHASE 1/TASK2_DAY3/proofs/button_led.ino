const int BTN_PIN = 2;    // SKS49 button → Pin 2 & GND
const int LED_PIN = 13;   // 1kΩ → LED → GND

const unsigned long DEBOUNCE_MS = 50;

bool ledState        = false;
bool lastReading     = HIGH;
bool stableState     = HIGH;
unsigned long lastChangeTime = 0;

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP); // internal pull-up, no external resistor needed
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  bool reading = digitalRead(BTN_PIN);

  if (reading != lastReading) {
    lastChangeTime = millis();
    lastReading = reading;
  }

  if ((millis() - lastChangeTime) >= DEBOUNCE_MS) {
    if (reading != stableState) {
      stableState = reading;

      if (stableState == LOW) {        // falling edge = button pressed
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
      }
    }
  }
}

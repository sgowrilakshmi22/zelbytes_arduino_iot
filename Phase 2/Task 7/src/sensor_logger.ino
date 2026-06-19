#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define SOIL_PIN A0
#define LDR_PIN A1

DHT dht(DHTPIN, DHTTYPE);

const unsigned long LOG_INTERVAL = 30000UL; // 30 seconds
const int MAX_SAMPLES = 60;

unsigned long previousMillis = 0;
int sampleCount = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  delay(2000);

  Serial.println("timestamp,time,temp,humidity,soil,light");

  previousMillis = millis() - LOG_INTERVAL;
}

void loop() {

  if (sampleCount >= MAX_SAMPLES) {
    Serial.println("DATA_COLLECTION_COMPLETE");
    while (1);
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= LOG_INTERVAL) {

    previousMillis = currentMillis;

    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    int soil = analogRead(SOIL_PIN);
    int light = analogRead(LDR_PIN);

    if (isnan(temp) || isnan(hum)) {
      Serial.println("DHT_ERROR");
      return;
    }

    unsigned long totalSeconds = currentMillis / 1000;

    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    char timeString[9];
    sprintf(timeString, "%02d:%02d:%02d",
            hours, minutes, seconds);

    Serial.print(currentMillis);
    Serial.print(",");

    Serial.print(timeString);
    Serial.print(",");

    Serial.print(temp, 1);
    Serial.print(",");

    Serial.print(hum, 1);
    Serial.print(",");

    Serial.print(soil);
    Serial.print(",");

    Serial.println(light);

    sampleCount++;
  }
}

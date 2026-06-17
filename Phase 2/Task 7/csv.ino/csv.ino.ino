#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define SOIL_PIN A0
#define LDR_PIN A1

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  delay(2000); // Allow DHT22 to stabilize

  Serial.println("timestamp,temp,humidity,soil,light");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int soil = analogRead(A0);
  int light = analogRead(A1);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT Error");
  } else {
    Serial.print(millis());
    Serial.print(",");

    Serial.print(temperature);
    Serial.print(",");

    Serial.print(humidity);
    Serial.print(",");

    Serial.print(soil);
    Serial.print(",");

    Serial.println(light);
  }

  delay(1000); // Log every second
}

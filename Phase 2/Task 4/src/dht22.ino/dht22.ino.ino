#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println("Starting DHT22...");
  delay(3000);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("DHT22 Read Failed!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" C  Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }

  delay(2000);
}
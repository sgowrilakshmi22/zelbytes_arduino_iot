#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define LDR_PIN A0
#define SOIL_PIN A1

#define TRIG_PIN 9
#define ECHO_PIN 10

DHT dht(DHTPIN, DHTTYPE);

unsigned long lastLog = 0;
const unsigned long LOG_INTERVAL = 2000;

void setup()
{
  Serial.begin(9600);

  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println(F("time_ms,light_raw,temp,hum,distance_cm,soil_pct"));
}

float getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if(duration == 0)
    return -1;

  return duration * 0.0343 / 2.0;
}

void loop()
{
  if(millis() - lastLog >= LOG_INTERVAL)
  {
    lastLog = millis();

    int lightRaw = analogRead(LDR_PIN);

    int soilRaw = analogRead(SOIL_PIN);

    int soilPct = map(soilRaw,
                      1023,
                      0,
                      0,
                      100);

    float temp = dht.readTemperature();
    float hum  = dht.readHumidity();

    float distance = getDistance();

    Serial.print(millis());
    Serial.print(",");

    Serial.print(lightRaw);
    Serial.print(",");

    if(isnan(temp))
      Serial.print(F("ERR"));
    else
      Serial.print(temp);

    Serial.print(",");

    if(isnan(hum))
      Serial.print(F("ERR"));
    else
      Serial.print(hum);

    Serial.print(",");

    Serial.print(distance);
    Serial.print(",");

    Serial.println(soilPct);
  }
}
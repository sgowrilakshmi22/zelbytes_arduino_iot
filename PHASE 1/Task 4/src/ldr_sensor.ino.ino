
#define LDR_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int ldr = analogRead(LDR_PIN);

  Serial.print("LDR Raw: ");
  Serial.println(ldr);

  delay(1000);
}

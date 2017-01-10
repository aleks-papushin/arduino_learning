#define BUZZER_PIN 3
#define LDR_PIN A0
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

}

void loop() {
//  analogWrite(BUZZER_PIN, 255);
  int ldrv, frequency; //ldrv-напряжение на выходе фоторезистора
  ldrv = analogRead(LDR_PIN);
  frequency = map(ldrv, 0, 1023, 20000, 0);
  tone(BUZZER_PIN, frequency, 5000);

}

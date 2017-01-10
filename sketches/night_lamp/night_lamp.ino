#define LED_PIN  11
#define LED_PIN10  10
#define LDR_PIN  A0
#define POT_PIN  A1

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN10, OUTPUT);
}

void loop() {
  int lightness = analogRead(LDR_PIN);
  int threshold = analogRead(POT_PIN);  

  boolean tooDark = lightness < threshold;
  int voltage = map(lightness, 0, threshold, 255, 0);

  if (lightness < threshold) {
    // ...включаем освещение
    analogWrite(LED_PIN, voltage);
    if (lightness < threshold * 0.5) {
      analogWrite(LED_PIN, voltage);
      voltage = map(lightness, 0, threshold * 0.5, 255, 0);
      analogWrite(LED_PIN10, voltage);
    }
  } else {
    // ...иначе свет не нужен — выключаем его
    analogWrite(LED_PIN, 0);
    analogWrite(LED_PIN10, 0);    
  }
}

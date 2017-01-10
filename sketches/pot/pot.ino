#define LED_PIN9 9
#define LED_PIN5 5
#define POT_PIN A0
void setup() {  
  pinMode(LED_PIN9, OUTPUT);
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN5, OUTPUT);
}

void loop() {
 int rotation, brightness9, brightness5;
 rotation = analogRead(POT_PIN);
 brightness9 = rotation / 4;
 brightness5 = brightness9 / 8;
 analogWrite(LED_PIN9, brightness9);
 analogWrite(LED_PIN5, brightness5);
}

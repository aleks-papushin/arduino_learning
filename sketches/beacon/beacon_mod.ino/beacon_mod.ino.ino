#define LED_PIN9 9
#define LED_PIN10 10
#define DELAY_1 250

float uIncrement = 1;
int voltage1 = 0;
int voltage2 = 0;

void setup() {
  pinMode(LED_PIN9, OUTPUT);
  pinMode(LED_PIN10, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN9, voltage1);
  analogWrite(LED_PIN10, voltage2);
//  if (voltage1 >= 255) {
//    uIncrement = -1 * (1 + 0.0001 * pow(voltage1, 2));  // 1 + 0.0001*(x^2)
//  }
//  else if (voltage1 <= 1) {
//    uIncrement = 1 + 0.0001 * pow(voltage1, 2);
//  }

  if ((voltage1 >= 255 && uIncrement > 0) || (voltage1 <= 0 && uIncrement < 0)) {
    uIncrement *= -1;
  }
  
  uIncrement = 1 + 0.001 * pow(voltage1, 2);
  voltage1 += uIncrement;
  //voltage2 = 255 - voltage1;
  delay(30);
}

  

#define BUZZER_PIN 13
#define FIRST_KEY_PIN 6
#define KEY_COUNT 7

int notes[] = {523, 587, 659, 698, 784, 880, 988};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 7; ++i) {
    int keyPin = i + FIRST_KEY_PIN;
    boolean keyDown = digitalRead(keyPin);
    if (keyDown) {
//      int frequency = 2000 + i * 500;
      tone(BUZZER_PIN, notes[i], 20);
    }
  }
}

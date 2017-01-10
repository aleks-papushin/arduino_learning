#define LED_PIN 9
#define DOT 100
#define DASH DOT*3
#define PAUSE DOT // pause between parts of the same letter
#define LETTER_PAUSE DOT*3 // pause between letters
#define WORD_PAUSE DOT*7 // pause between words

#define SIGN_LEN 3

char ABC[] = {'s', 'o'};
int MORSE_ABC[][3] = {{DOT, DOT, DOT}, {DASH, DASH, DASH}};

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  morseBuzzer(0);
  morseBuzzer(1);
  morseBuzzer(0);  
  delay(WORD_PAUSE);
}

void morseLetter(int letterPlace) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_PIN, 1);
    delay(MORSE_ABC[letterPlace][i]);
    digitalWrite(LED_PIN, 0);
    delay(PAUSE);        
  }
  delay(LETTER_PAUSE);
}

void morseBuzzer(int letter) {
  for (int i = 0; i < 3; i++) {
    tone(LED_PIN, 500);
    delay(MORSE_ABC[letter][i]);
    analogWrite(LED_PIN, 0);
    delay(PAUSE);
    analogWrite(LED_PIN, 1);
  }
  delay(LETTER_PAUSE);
}


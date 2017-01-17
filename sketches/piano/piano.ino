#define BUZZER_PIN 13
#define FIRST_KEY_PIN 6
#define KEY_COUNT 7
#define OCTAVE_PLUS 4
#define OCTAVE_MINUS 5

#include "tones.h"

int tones[] = {NOTE_B0,  \
  NOTE_C1,  NOTE_D1,  NOTE_E1,  NOTE_F1,  NOTE_G1,  NOTE_A1,  NOTE_B1,  \
  NOTE_C2,  NOTE_D2,  NOTE_E2,  NOTE_F2,  NOTE_G2,  NOTE_A2,  NOTE_B2,  \
  NOTE_C3,  NOTE_D3,  NOTE_E3,  NOTE_F3,  NOTE_G3,  NOTE_A3,  NOTE_B3,  \
  NOTE_C4,  NOTE_D4,  NOTE_E4,  NOTE_F4,  NOTE_G4,  NOTE_A4,  NOTE_B4,  \
  NOTE_C5,  NOTE_D5,  NOTE_E5,  NOTE_F5,  NOTE_G5,  NOTE_A5,  NOTE_B5,  \
  NOTE_C6,  NOTE_D6,  NOTE_E6,  NOTE_F6,  NOTE_G6,  NOTE_A6,  NOTE_B6,  \
  NOTE_C7,  NOTE_D7,  NOTE_E7,  NOTE_F7,  NOTE_G7,  NOTE_A7,  NOTE_B7,  \
  NOTE_C8,  NOTE_D8};
//int notes[] = {523, 587, 659, 698, 784, 880, 988};

int current_octave = 4;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // switch octave if should
  for (int i = 0; i < 2; ++i) { // iterate between octave pins
    int octave_pin = i + OCTAVE_PLUS; 
    boolean keyDown = digitalRead(octave_pin);
    if (keyDown) switch_octave(octave_pin);
  }

  // play note if should 
  for (int i = 0; i < 7; ++i) {
    int keyPin = i + FIRST_KEY_PIN;
    boolean keyDown = digitalRead(keyPin);
    if (keyDown) play_tone(i);
  }
}

void switch_octave(int octave_pin) {
  if (can_switch_octave(current_octave, octave_pin)) {
    current_octave += octave_pin;    
  }  
}

boolean can_switch_octave(int current, int pin) {
  return ((current == 0 && pin == OCTAVE_MINUS) || (current == 8 && pin == OCTAVE_PLUS));
}

void play_tone(int note) {
  if (note != 0) note = (note * (current_octave - 1)) + note; // CHECK!!
  if (can_play(note)) {
    tone(BUZZER_PIN, tones[note], 20);
  }
}

boolean can_play(int note) {
  if (note >= 0 && note < sizeof(tones) / sizeof(int)) return true; // COMPARING MAY NOT WORK PROPERLY!! NEED TO BE CHECKED.
  else return false; 
}


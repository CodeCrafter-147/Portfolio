
#define NUM_SENSORS 8
#define OK_PIN 9
#define BUZZER_PIN 8
#define PRESS 0
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988

int melody[] = { NOTE_E5, NOTE_E5, 0, NOTE_E5, 0, NOTE_C5, NOTE_E5, 0, NOTE_G5 };
int NNote[] = { 0, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5 };
int noteDurations[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10 };

void RobotSetup() {
  Serial.begin(115200);
  for (int i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  Beep(100);
  delay(50);
  Beep(100);

  for (int thisNote = 0; thisNote < 9; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
  }
}
void OK() {
  while (1) {
    if (digitalRead(OK_PIN) == PRESS) {
      break;
    }
  }
  Beep(100);
  delay(500);
}
void Beep(int delayb) {
  tone(8, NOTE_G5, delayb);
  delay(delayb);
  noTone(8);
}
int OK_PUSH() {
  if (digitalRead(OK_PIN) == PRESS) return PRESS;
  else {
    return 1;
  }
}
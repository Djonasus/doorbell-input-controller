#include <Keypad.h>

float BUZZER_PIN = 2;

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  // welcome();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
  }

  if (Serial.available() > 0) {
    String str = Serial.readString();

    if (str == "startup") {
      welcome();
    } else if(str == "error") {
      error();
    } else {
      // :(
    }
  }
}

//

void welcome() {
  tone(BUZZER_PIN, 300);
  delay(200);
  tone(BUZZER_PIN, 900);
  delay(200);
  tone(BUZZER_PIN, 1200);
  delay(400);
  noTone(BUZZER_PIN);
}

void error() {
  tone(BUZZER_PIN, 700);
  delay(300);
  tone(BUZZER_PIN, 400);
  delay(400);
  noTone(BUZZER_PIN);
}
#include <Keypad.h>

const int ROWS = 4;
const int COLS = 3;
char tt[3] = { '3', '5', '8' };
char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int n = 0;

void setup() {
  Serial.begin(9600);

  delay(200);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // read the input from the keypad
  char key = keypad.getKey();

  // if a key is pressed
  if (key) {
    Serial.println(key);
    if (key == tt[n]) {
      n++;
    } else {
      n = 0;
    }

    if (n == 3) {
      Serial.println("Password is correct...Door open");
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      n = 0;
    }
  }
}

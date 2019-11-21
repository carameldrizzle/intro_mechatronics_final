#include <Keypad.h>
#include <NewPing.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int enable1 = 11;
int enable2 = 10;
int A = 0;
int B = 1;

int trigPin = 12;
int echoPin = 12;
const int MAX_DISTANCE = 350;

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

float duration, distance;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);

}

void loop() {
  char customKey1 = customKeypad.getKey();

  if (customKey1 == '9') {
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);

    int lSensor = analogRead(A0);

    if (lSensor < 200) {
      analogWrite (enable1, 255); // left
      analogWrite (enable2, 240);
    }
    else {
      delay(50);

      duration = sonar.ping();
      distance = (duration / 2) * .0343;

      if (distance < 10) {
        analogWrite (enable1, 0);
        analogWrite (enable2, 240);
      }
    }
  }  
}

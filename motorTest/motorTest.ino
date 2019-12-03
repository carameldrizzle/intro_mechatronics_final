//#include <Keypad.h>
//#include <NewPing.h>

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

//Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

int enable1 = 11;
int enable2 = 10;
int A = 1;
int B = 2;
int leftPin = A0; 

int echoPin = 13;
int trigPin = 12;
const int MAX_DISTANCE = 350;

//NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

float duration, distance;

void setup() {
  Serial.begin(9600); 
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
}

void loop() {
  delay(4000);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  Serial.print("hey");
//  rbt_forward();
//  delay(3000);
//  Serial.print("middle");
//  rbt_stop();
//  delay(3000);
//  Serial.print("end");  
  // char customKey1 = customKeypad.getKey();

  // Testing US
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(5);
//  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH); 
//  Serial.println("duration");
//  Serial.println(duration);
//  distance = microsecondsToInches(duration);
//  Serial.println("distance");
//  Serial.println(distance);
//  delay(1000);
//  if (distance > 5) {
//    rbt_stop();
//    rbt_left();
//    Serial.println("turn left");
//  }
  
//  if (customKey1 == '9') {
//    digitalWrite(A, LOW);
//    digitalWrite(B, HIGH);
//
//    int lSensor = analogRead(A0);
//
//    if (lSensor < 200) {
//      analogWrite (enable1, 255); // left
//      analogWrite (enable2, 240);
//    }
//    else {
//      delay(50);
//
//      duration = sonar.ping();
//      distance = (duration / 2) * .0343;
//
//      if (distance < 10) {
//        analogWrite (enable1, 0);
//        analogWrite (enable2, 240);
//      }
//    }
//  }
}

double microsecondsToInches(double microseconds) {
  return microseconds / 74 / 2;
}

void rbt_stop() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
}

void rbt_forward() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
}

void rbt_left(int left, int right) {
  analogWrite(enable1, left); // left
  analogWrite(enable2, right);
}

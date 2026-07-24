#include <Servo.h>

const int BUTTON = 2;
const int LED_LEFT = 6;
const int LED_MID = 7;
const int LED_RIGHT = 8;
const int SL = 9;
const int SM = 10;
const int SR = 11;
const int J = A0;

Servo sl;
Servo sm;
Servo sr;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(4));

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_MID, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  sl.attach(SL);
  sm.attach(SM);
  sr.attach(SR);

  sl.write(90); // 180 up, 90 down
  sm.write(0); // 90 up, 0 down              
  sr.write(90); // 90 down, 0 up
}

int count = 0;
int hs = 0;

void loop() {
  int dir = digitalRead(BUTTON);
  Serial.println(dir);
  int jsValue = analogRead(J);
  Serial.println(jsValue);
  if (jsValue > 800) {
    digitalWrite(LED_LEFT, HIGH);
    digitalWrite(LED_MID, LOW);
    digitalWrite(LED_RIGHT, LOW);
    if (dir == 0) {
      sl.write(90);
      ++hs;
    }
  }
  else if (jsValue > 200) {
    digitalWrite(LED_LEFT, LOW);
    digitalWrite(LED_MID, HIGH);
    digitalWrite(LED_RIGHT, LOW);
    if (dir == 0) {
      sm.write(0);
      ++hs;
    }
  }
  else {
    digitalWrite(LED_LEFT, LOW);
    digitalWrite(LED_MID, LOW);
    digitalWrite(LED_RIGHT, HIGH);
    if (dir == 0) {
      sr.write(90);
      ++hs;
    }
  }
  if (count % 200 == 0) {
    count = 0;
    int s = random(1,4);
    switch(s) {
      case 1:
        sl.write(180);
        break;
      case 2:
        sr.write(0);
        break;
      case 3:
        sm.write(90);
    }
  }
  ++count;
}
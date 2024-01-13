#include "JOYSTICK.h"

JOYSTICK::JOYSTICK(int joystickPin, int directionPin, int leftPin, int middlePin, int rightPin) {
  joystick_ = joystickPin;
  directionRead_ = directionPin;
  leftLED_ = leftPin;
  middleLED_ = middlePin;
  rightLED_ = rightPin;
  pinMode(joystick_, INPUT_PULLUP);
  pinMode(leftLED_, OUTPUT);
  pinMode(middleLED_, OUTPUT);
  pinMode(rightLED_, OUTPUT);
  resetLights();
}

void JOYSTICK::resetLights() { // turns off all lights
  digitalWrite(leftLED_, LOW);
  digitalWrite(middleLED_, LOW);
  digitalWrite(rightLED_, LOW);
}

void JOYSTICK::checkDirection() { // reads direction from joystick
  directionNum_ = analogRead(directionRead_);
  Serial.println(directionNum_);
  if (directionNum_ > 800) {
    direction_ = 0;
  }
  else if (directionNum_ > 200) {
    direction_ = 1;
  }
  else {
    direction_ = 2;
  }
  showDirection();
}

void JOYSTICK::showDirection() { //shows direction using LEDs
  resetLights();
  switch(direction_) {
    case 0:
      digitalWrite(leftLED_, HIGH);
      break;
    case 1:
      digitalWrite(middleLED_, HIGH);
      break;
    case 2:
      digitalWrite(rightLED_, HIGH);
      break;
  }
}
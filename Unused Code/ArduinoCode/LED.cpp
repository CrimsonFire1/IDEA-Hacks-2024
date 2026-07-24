// LED.cpp
#include "LED.h"

LED::LED(int redPin, int yellowPin, int greenPin) { // initializes pins
  red_ = redPin;
  yellow_ = yellowPin;
  green_ = greenPin;

  pinMode(red_, OUTPUT);
  pinMode(yellow_, OUTPUT);
  pinMode(green_, OUTPUT);
}

void LED::resetHealth(){ // resets health to 6 and changes LED color to green
  digitalWrite(green_, HIGH);
  digitalWrite(yellow_, LOW);
  digitalWrite(red_, LOW);
  health = 6;
}

void LED::hit() { // subtracts 1 from health and 
  --health;
  if (health > 4) {
    digitalWrite(green_, HIGH);
    digitalWrite(yellow_, LOW);
    digitalWrite(red_, LOW);
  }
  else if (health > 2) {
    digitalWrite(green_, LOW);
    digitalWrite(yellow_, HIGH);
    digitalWrite(red_, LOW);
  }
  else {
    digitalWrite(green_, LOW);
    digitalWrite(yellow_, LOW);
    digitalWrite(red_, HIGH);
  }
  // TODO: if health is 0, end game appropriately
}
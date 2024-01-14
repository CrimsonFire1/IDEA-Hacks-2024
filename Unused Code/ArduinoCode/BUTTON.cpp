// BUTTON.cpp
#include "BUTTON.h"

BUTTON::BUTTON(int pin) {
  displayAmmo();
  pin_ = pin;
  pinMode(pin_, INPUT);
}

bool BUTTON::pressed() {
  buttonState = digitalRead(pin_);
  Serial.println(buttonState);
  if (buttonState == 0 && buttonState != priorState) {
    -- ammo;
    displayAmmo();
    priorState = buttonState;
    return true;
  }
  else {
    displayAmmo();
    priorState = buttonState;
    return false;
  }
}
  
void BUTTON::shoot() {

}

void BUTTON::displayAmmo() {

}
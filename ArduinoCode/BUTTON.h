// BUTTON.h
#ifndef BUTTON_h
#define BUTTON_h

#include <Arduino.h>

class BUTTON {
  public:
    BUTTON(int pin);
    bool pressed();
  
  private:
    void shoot();
    void displayAmmo();
    int pin_;
    int ammo = 0;
    int buttonState;
    int priorState = 1;
};

#endif // for BUTTON.h
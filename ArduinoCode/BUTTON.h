// BUTTON.h
#ifndef BUTTON_h
#define BUTTON_h

#include <Arduino.h>

class BUTTON {
  public:
    BUTTON(int pin);
    void pressed();
  
  private:
    void shoot();
    void displayAmmo();
    int pin_;
    int ammo = 0;
};

#endif // for BUTTON.h
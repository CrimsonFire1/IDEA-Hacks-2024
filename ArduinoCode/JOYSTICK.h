// JOYSTICK.h
#ifndef JOYSTICK_h
#define JOYSTICK_h

#include <Arduino.h>

class JOYSTICK {
  public:
    JOYSTICK(int joystickPin, int directionPin, int leftPin, int middlePin, int rightPin);
    void checkDirection();
  
  private:
    void resetLights();
    void showDirection();
    int joystick_;
    int directionRead_;
    int leftLED_;
    int middleLED_;
    int rightLED_;
    int directionNum_;
    int direction_;
};

#endif // for JOYSTICK.h
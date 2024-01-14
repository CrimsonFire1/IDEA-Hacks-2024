// LED.h
#ifndef LED_h
#define LED_h

#include <Arduino.h>

class LED {
  public:
    LED(int redPin, int yellowPin, int greenPin);
    void resetHealth();
    void hit();
  
  private:
    int red_;
    int yellow_;
    int green_;
    int health = 6;
};

#endif // for LED.h
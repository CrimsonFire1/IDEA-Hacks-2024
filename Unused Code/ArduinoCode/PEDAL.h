// PEDAL.h
#ifndef PEDAL_h
#define PEDAL_h

#include <Arduino.h>

class PEDAL {
  public:
    PEDAL(int pin);
    void pressed();
    
  private:
    void duck();
    const int pin_;
};

#endif // for PEDAL.h
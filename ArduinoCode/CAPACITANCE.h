// CAPACITANCE.h
#ifndef CAPACITANCE_h
#define CAPACITANCE_h

#include <Arduino.h>

class CAPACITANCE {
  public:
    CAPACITANCE(int pin);
    void pressed();
  
  private:
    void recharge();
    const int pin_;
};

#endif // for CAPACITANCE.h
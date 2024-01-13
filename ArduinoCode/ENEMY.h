// ENEMY.h
#ifndef ENEMY_h
#define ENEMY_h

#include <Arduino.h>

class ENEMY {
  public:
    ENEMY(int pos);
    int getPosition();
    void change(int randNum);
  
  private:
    void determinePosition(int randNum);
    int position_ = 0;
};

#endif // for ENEMY.h
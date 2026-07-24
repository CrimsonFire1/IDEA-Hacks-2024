#include "ENEMY.h"

ENEMY::ENEMY(int pos) {
  position_ = pos;
}

int ENEMY::getPosition() {
  return position_;
}

void ENEMY::change(int randNum) {
  if (randNum > 7) {
    determinePosition(randNum);
  }
}

void ENEMY::determinePosition(int randNum) {
  if (position_ != 3) {
    position_ = randNum % 4;
  }
  else {
    position_ = 3;
  }
  // TODO: move servos to show where person is
}
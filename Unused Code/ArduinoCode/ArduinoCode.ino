// main code: ArduinoCode.ino
#include "LED.h"
#include "BUTTON.h"
#include "PEDAL.h"
#include "CAPACITANCE.h"
#include "JOYSTICK.h"
#include "ENEMY.h"

LED playerLED(3, 4, 5);
LED enemyLED(3, 4, 5);
BUTTON shooter(6);
JOYSTICK point(2, A0, 9, 10, 11);
ENEMY murdoc(0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(4);
  enemyLED.resetHealth();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (shooter.pressed()) {
    if (point.checkDirection() == murdoc.getPosition()) {
      enemyLED.hit();
    }
  }
  else {
    point.checkDirection();
  }
  delay(500);
}

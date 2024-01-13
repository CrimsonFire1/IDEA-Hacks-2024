// main code: ArduinoCode.ino
#include "LED.h"
#include "BUTTON.h"
#include "PEDAL.h"
#include "CAPACITANCE.h"
#include "JOYSTICK.h"

LED player(3, 4, 5);
LED enemy(4, 5, 6);
BUTTON shooter(7);
JOYSTICK point(2, A0, 3, 4, 5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //player.resetHealth();
}

void loop() {
  // put your main code here, to run repeatedly:
  point.checkDirection();
}

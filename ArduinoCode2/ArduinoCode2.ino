#include <Servo.h>

// defining pins
const int BUTTON = 2;
const int FIRE_GREEN = 3;
const int FIRE_YELLOW = 4;
const int FIRE_RED = 5;
const int LED_LEFT = 6;
const int LED_MIDDLE = 7;
const int LED_RIGHT = 8;
const int SERVO_LEFT = 9;
const int SERVO_MIDDLE = 10;
const int SERVO_RIGHT = 11;
const int TOUCH_SENSOR = 12;
const int END_GAME_LED = 13;
const int JS_VRX = A0; // joystick VRX

// creating servo objects
Servo leftServo;
Servo middleServo;
Servo rightServo;

// creating global constants
const int GAME_TIME = 10000000000000000;
const int MAX_FIRE_DANGER = 6;
const int MAX_WATER_IN_TANK = 4;
const int FILL_TIME = 2000;
const int RESET = -1;
const int ALL = -2;

// creating variables for directions
const int LEFT = 0;
const int MIDDLE = 1;
const int RIGHT = 2;
const int HIDDEN = 3;

// initializes miscellaneous variables
int fireRisk = MAX_FIRE_DANGER;
int firePosition = HIDDEN;
bool fullTank = true;
int waterAmount = MAX_WATER_IN_TANK;
int fillWater = 0;
int joystickPos = MIDDLE;
bool buttonPressed = 0;
bool priorButtonState = 0;

// servo positions
int rsPos = 0;
int msPos = 0;
int lsPos = 0;

// functions
int joystickDirection();
void waterLED(int pos);
void fireLED(int level);
void moveFire();

// count to help with timing
int timer = 0;

void setup() {
  Serial.begin(9600);

  randomSeed(analogRead(4));

  // setting pin modes
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(FIRE_GREEN, OUTPUT);
  pinMode(FIRE_YELLOW, OUTPUT);
  pinMode(FIRE_RED, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_MIDDLE, OTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(TOUCH_SENSOR, INPUT);
  pinMode(END_GAME_LED, OUTPUT);
  pinMode(A0, INPUT_PULLUP);

  // attaching servos
  leftServo.attach(SERVO_LEFT);
  middleServo.attach(SERVO_MIDDLE);
  rightServo.attach(SERVO_RIGHT);

  // turns on red fire LED
  digitalWrite(FIRE_RED, HIGH);
}

void loop() {
  if (fireRisk == 0) { // end game when no more fire
    waterLED(RESET);
    fireLED(fireRisk);
    digitalWrite(END_GAME_LED, HIGH);
    return;
  }

  if (timer == GAME_TIME) {
    waterLED(RESET);
    fireLED(fireRisk);
    digitalWrite(END_GAME_LED, HIGH);
    return;
  }

  buttonPressed = digitalRead(BUTTON);

  if (waterAmount == 0) { //if no water
    if (timer % 100 > 50) { // blinks water LEDs when water needs to be filled
      waterLED(ALL);
    }
    else {
      waterLED(RESET);
    }

    if (digitalRead(TOUCH_SENSOR)) { // uses touch sensor to fill water
      ++fillWater;
      if (fillWater == FILL_TIME) {
        waterAmount = MAX_WATER_IN_TANK;
        fillWater = 0;
        waterLED(RESET);
      }
    }
  }
  else if (buttonPressed && (priorButtonState == 0)) { // if button is pressed, shoots water at fire
    --waterAmount;
    joystickPos = joystickDirection();
    waterLED(joystickPos);
    if (joystickPos == firePosition) {
      --fireRisk;
      fireLED(fireRisk);
    }
    priorButtonState = 1;
  }
  else if (!buttonPressed) {
    waterLED(RESET);
    priorButtonState = 0;
  }

  if ((random(1, 10) >  7) && (timer % 300 == 0)) {
    moveFire();
  }

  ++timer;
}

int joystickDirection() {
  int jsValue = analogRead(JS_VRX);
  if (jsValue > 800) {
    return LEFT;
  }
  else if (jsValue > 200) {
    return MIDDLE;
  }
  else {
    return RIGHT;
  }
}

void waterLED(int pos) {
  digitalWrite(LED_LEFT, LOW);
  digitalWrite(LED_MIDDLE, LOW);
  digitalWrite(LED_RIGHT, LOW);
  switch(pos) {
    case RESET:
      digitalWrite(LED_LEFT, LOW);
      digitalWrite(LED_MIDDLE, LOW);
      digitalWrite(LED_RIGHT, LOW);
      break;
    case LEFT:
      digitalWrite(LED_LEFT, HIGH);
      digitalWrite(LED_MIDDLE, LOW);
      digitalWrite(LED_RIGHT, LOW);
      break;
    case MIDDLE:
      digitalWrite(LED_LEFT, LOW);
      digitalWrite(LED_MIDDLE, HIGH);
      digitalWrite(LED_RIGHT, LOW);
      break;
    case RIGHT:
      digitalWrite(LED_LEFT, LOW);
      digitalWrite(LED_MIDDLE, LOW);
      digitalWrite(LED_RIGHT, HIGH);
      break;
    case ALL:
      digitalWrite(LED_LEFT, HIGH);
      digitalWrite(LED_MIDDLE, HIGH);
      digitalWrite(LED_RIGHT, HIGH);
      break;
  }
}

void fireLED(int level) {
  if ((level / MAX_FIRE_DANGER) > 0.8) {
    digitalWrite(FIRE_RED, HIGH);
    digitalWrite(FIRE_YELLOW, LOW);
    digitalWrite(FIRE_GREEN, LOW);
  }
  else if ((level / MAX_FIRE_DANGER) > 0.4) {
    digitalWrite(FIRE_RED, LOW);
    digitalWrite(FIRE_YELLOW, HIGH);
    digitalWrite(FIRE_GREEN, LOW);
  }
  else if ((level / MAX_FIRE_DANGER) > 0.0) {
    digitalWrite(FIRE_RED, LOW);
    digitalWrite(FIRE_YELLOW, LOW);
    digitalWrite(FIRE_GREEN, HIGH);
  }
  else {
    digitalWrite(FIRE_RED, LOW);
    digitalWrite(FIRE_YELLOW, LOW);
    digitalWrite(FIRE_GREEN, LOW);
  }
}

void moveFire() {
  if (firePosition == HIDDEN) {
    firePosition = random(0, 2);
    switch(firePosition) {
      case LEFT:
        leftServo.write(90);
        break;
      case MIDDLE:
        middleServo.write(90);
        break;
      case RIGHT:
        rightServo.write(90);
        break;
    }
  }
  else {
    switch(firePosition) {
      case LEFT:
        leftServo.write(0);
        break;
      case MIDDLE:
        middleServo.write(0);
        break;
      case RIGHT:
        rightServo.write(0);
        break;
    }
    firePosition == HIDDEN;
  }
}
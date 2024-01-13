#include <Servo.h>

const int JS_SW = 2; // joystick SW
const int BUTTON = 3;
const int ENEMY_GREEN = 4;
const int ENEMY_YELLOW = 5;
const int ENEMY_RED = 6;
const int LED_LEFT = 7;
const int LED_MIDDLE = 8;
const int SERVO_LEFT = 9;
const int SERVO_MIDDLE = 10;
const int SERVO_RIGHT = 11;
const int LED_RIGHT = 12;
const int TOUCH_SENSOR = 13;
const int JS_VRX = A0; // joystick VRX

Servo leftServo;
Servo middleServo;
Servo rightServo;

const int LEFT = 0;
const int MIDDLE = 1;
const int RIGHT = 2;
const int HIDDEN = 3;

int enemyHealth = 6;
bool ammoFull = true;

// servo positions
int rsPos = 0;
int msPos = 0;
int lsPos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(JS_SW, INPUT_PULLUP);
  pinMode(BUTTON, INPUT);
  pinMode(ENEMY_GREEN, OUTPUT);
  pinMode(ENEMY_YELLOW, OUTPUT);
  pinMode(ENEMY_RED, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_MIDDLE, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(TOUCH_SENSOR, INPUT);
  pinMode(A0, INPUT_PULLUP);

  leftServo.attach(SERVO_LEFT);
  //middleServo.attach(SERVO_MIDDLE);
  //rightServo.attach(SERVO_RIGHT);

  digitalWrite(ENEMY_GREEN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  leftServo.write(0);
  delay(1000);
  leftServo.write(180);
  delay(1000);
}


//This controls the Drivetrain of the robot

// LIBRARIES
//----------
#include <Servo.h>

Servo ARM_LEFT_SERVO;
Servo ARM_RIGHT_SERVO;
// Motor LEFT and Motor RIGHT PIN assignment
const int MOTOR_LEFT_PIN = 2;
const int MOTOR_RIGHT_PIN = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MOTOR_LEFT_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(MOTOR_RIGHT_PIN, HIGH);
  //delay(5000);
}

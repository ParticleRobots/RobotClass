#include <Servo.h>

Servo servoBase; 
int axisX = A1;
int axisY = A0;
int buttenPin = 13;
int buttenPinValue = 0;
int axisXValue = 0;
int axisYValue = 0;
int infraredPin = 3;
int infraredPin5V = 2;
int infraredValue = 0;
int servoValue = 0;

void setup() {
  pinMode(axisX, INPUT);
  pinMode(axisY, INPUT);
  pinMode(buttenPin, INPUT_PULLUP);
  pinMode(infraredPin, INPUT_PULLUP);
  pinMode(infraredPin5V, OUTPUT);
  digitalWrite(infraredPin5V, HIGH);
  Serial.begin(9600);
  servoBase.attach(9);
}

void loop() {
  axisXValue = analogRead(axisX);
  axisYValue = analogRead(axisY);
  buttenPinValue = digitalRead(buttenPin);
  infraredValue = digitalRead(infraredPin);
  servoValue = map(axisYValue, 0, 1023, 0, 180);
  servoBase.write(servoValue);
  delay(15);
  Serial.print(servoValue);
  Serial.print("UpDown:");
  Serial.print(axisYValue);
  Serial.print(",");
  Serial.print("LeftRight");
  Serial.print(axisXValue);
  Serial.print(", ");
  Serial.print(buttenPinValue);
  Serial.println("");
  Serial.print(infraredValue);

//  infraredValue = map( 

}

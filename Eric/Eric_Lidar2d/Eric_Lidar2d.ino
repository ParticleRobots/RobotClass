#include <Servo.h>

int infraredPin = 3;
int infraredPin5V = 2;
int infraredValue = 0;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(infraredPin, INPUT_PULLUP);
  pinMode(infraredPin5V, OUTPUT);
  digitalWrite(infraredPin5V, HIGH);
}

void loop() {

   

  for (pos = 0; pos <= 180; pos+= 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    infraredValue = digitalRead(infraredPin);
    Serial.print(infraredValue);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos-= 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    infraredValue = digitalRead(infraredPin);
    Serial.print(infraredValue);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  Serial.println("");
  delay(1000);
}
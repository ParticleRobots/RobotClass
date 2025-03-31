#include <Servo.h> 

Servo myservo;    // Create servo object to control the first servo
Servo myservo2;   // Create servo object to control the second servo

int pos1 = 0;      // Variable to store the position of the first servo
int pos2 = 0;      // Variable to store the position of the second servo

unsigned long previousMillis1 = 0;   // Store last time servo 1 moved
unsigned long previousMillis2 = 0;   // Store last time servo 2 moved
const long interval1 = 20;           // Time interval for servo 1 movement
const long interval2 = 30;           // Time interval for servo 2 movement

void setup() { 
  // Initialize the servo pins
  myservo.attach(7);   // Attaches the first servo to pin 7
  myservo2.attach(8);  // Attaches the second servo to pin 8
} 

void loop() { 
  unsigned long currentMillis1 = millis();  // Get the current time for servo 1
  unsigned long currentMillis2 = millis();  // Get the current time for servo 2

  // Move the first servo with a smooth oscillation from 0 to 180 and back
  if (currentMillis1 - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis1;  // Update the last time servo 1 moved

    // Move from 0 to 180 degrees
    if (pos1 <= 180) {
      myservo.write(pos1);  // Move servo 1 from 0 to 180 degrees
      pos1++;
    }
    // Move back from 180 to 0 degrees
    else if (pos1 > 180 && pos1 <= 360) {
      myservo.write(360 - pos1);  // Move servo 1 back from 180 to 0 degrees
      pos1++;
    }

    // Reset position to 0 after completing the full cycle
    if (pos1 > 360) {
      pos1 = 0;
    }
  }

  // Move the second servo with a smooth oscillation from 0 to 180 and back
  if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;  // Update the last time servo 2 moved

    // Move from 0 to 180 degrees
    if (pos2 <= 180) {
      myservo2.write(pos2);  // Move servo 2 from 0 to 180 degrees
      pos2++;
    }
    // Move back from 180 to 0 degrees
    else if (pos2 > 180 && pos2 <= 360) {
      myservo2.write(360 - pos2);  // Move servo 2 back from 180 to 0 degrees
      pos2++;
    }

    // Reset position to 0 after completing the full cycle
    if (pos2 > 360) {
      pos2 = 0;
    }
  }
}

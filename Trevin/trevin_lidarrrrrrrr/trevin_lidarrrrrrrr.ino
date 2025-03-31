//by trevin this is a lidar program and done on Oct. 5 2024
#include <Servo.h>

Servo thing; // create servo object to control a servo
 int pod = 0;


// This program control a joystick
// by Trevin

int lefight = A1;
int upown = A0;

int high = 5;
int low = 1;

int VUP = 0;
int VLR = 0; // This stores the Left and Right value from the joystick

int kitu = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  thing.attach(9); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  VUP = analogRead(upown);
  VLR = analogRead(lefight);

  thing.write (VLR);
  delay (15);



  


}

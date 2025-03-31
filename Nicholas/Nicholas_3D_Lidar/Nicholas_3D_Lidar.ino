#include <Servo.h>

Servo myservo1;
Servo myservo2;

int pininfared = 2;
int infaredvalue = -1;


void setup() {
  // put your setup code here, to run once:
myservo1.attach(9);
myservo2.attach(10);
pinMode(pininfared, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println(infaredvalue);
for(int counter = 0; counter <= 180; counter = counter + 5){
  infaredvalue = digitalRead(pininfared);
  Serial.print(infaredvalue);
  myservo1.write(counter);
  delay(50);
}
Serial.println();
for(int counter = 180; counter >= 0; counter = counter - 5){
  infaredvalue = digitalRead(pininfared);
  Serial.print(infaredvalue);
  myservo1.write(counter);
  delay(50);
}
}

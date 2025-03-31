#include <Servo.h>  // Include the Servo library

Servo myServo;  // Create a Servo object

int joysticktoservo=0;
int pinled=13;
int joystickx=A0;
int joysticky=A1;
int valuex=0;
int valuey=0;

void setup() {
  // put your setup code here, to run once:
myServo.attach(9);
pinMode(pinled,OUTPUT);
pinMode(joystickx,INPUT);
pinMode(joysticky,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinled,HIGH);
delay(100);
//Serial.println("Led turn on");
digitalWrite(pinled,LOW);
delay(100);
//Serial.println("Led turn off");
valuex=analogRead(joystickx);
valuey=analogRead(joysticky);
Serial.print("Value x = ");
Serial.println(valuex);
Serial.print("value y = ");
Serial.println(valuey);
joysticktoservo=map(valuex,0,1023,0,180);
myServo.write(joysticktoservo);
Serial.print("Map = ");
Serial.println(joysticktoservo);
}

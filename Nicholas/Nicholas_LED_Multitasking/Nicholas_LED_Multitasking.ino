#include <Servo.h>

Servo myservo;
Servo myservo1;
int pos = 1;
int pos1 = 0;
int counter = 0;

unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;
const long interval = 15;
const long interval1 = 55;

int ledPin = 13;
int ledState = LOW;
unsigned long previousMillis = 0;
long OnTime = 250;
long OffTime = 1750;

int ledPin1 = 12;
int ledState1 = LOW;
unsigned long previousMillis1 = 0;
long OnTime1 = 1250;
long OffTime1 = 750;

void setup() {
  // put your setup code here, to run once:
myservo.attach(7);
myservo1.attach(8);
pinMode(ledPin, OUTPUT);
pinMode(ledPin1, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long currentMillis = millis();
Serial.println();
Serial.println(counter);
Serial.println(currentMillis);
Serial.println(previousMillis);
Serial.println(currentMillis - previousMillis);
if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
{
  
  ledState = LOW;
  previousMillis = currentMillis;
  digitalWrite(ledPin, ledState);
}
else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
{
  ledState = HIGH;
  previousMillis = currentMillis;
  digitalWrite(ledPin, ledState);
}

if((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
{
  ledState1 = LOW;
  previousMillis1 = currentMillis;
  digitalWrite(ledPin1, ledState1);
}
else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
{
  ledState1 = HIGH;
  previousMillis1 = currentMillis;
  digitalWrite(ledPin1, ledState1);
}


if (currentMillis - previousMillis2 >= interval) {
  previousMillis2 = currentMillis;
  if (pos <= 180) {
    myservo.write(pos);
    pos++;
  }
  else if (pos > 180 && pos <= 360) {
    myservo.write(360 - pos);
    pos++;
  }

  if (pos > 360) {
    pos = 0;
  }
}

if (currentMillis - previousMillis3 >= interval) {
  previousMillis3 = currentMillis;
  if (pos1 <= 180) {
    myservo1.write(pos1);
    pos1++;
  }
  else if (pos1 > 180 && pos1 <= 360) {
    myservo1.write(360 - pos1);
    pos1++;
  }

  if (pos1 > 360) {
    pos1 = 0;
  }
}
counter++;
}

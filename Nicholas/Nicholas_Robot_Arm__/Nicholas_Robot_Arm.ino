#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
int keyboard_input = 0;
int electropin = 7;

void setup() {
  // put your setup code here, to run once:
pinMode(electropin, OUTPUT);
myservo1.attach(9);
myservo2.attach(10);
myservo3.attach(11);
Serial.begin(9600);
Serial.println("Setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
pickup();
delay(500);
myservo1.write(100);
delay(500);
myservo1.write(130);
delay(500);
place();
delay(500);
/*keyboard_input = Serial.parseInt();
//Serial.println(keyboard_input);
if (keyboard_input > 1) {
if (keyboard_input <= 1180 and keyboard_input >= 1000) {
  keyboard_input = keyboard_input - 1000;
  myservo1.write(keyboard_input);
  delay(50);
  Serial.println("Angle for motor 1: ");
  Serial.println(keyboard_input);
}
if (keyboard_input <= 2180 and keyboard_input >= 2000) {
  keyboard_input = keyboard_input - 2000;
  myservo2.write(keyboard_input);
  delay(50);
  Serial.println("Angle for motor 2: ");
  Serial.println(keyboard_input);
}
if (keyboard_input <= 3180 and keyboard_input >= 3000) {
  keyboard_input = keyboard_input - 3000;
  myservo3.write(keyboard_input);
  delay(50);
  Serial.println("Angle for motor 3: ");
  Serial.println(keyboard_input);
}
}
/*delay(50);
homing();
electromagnet_on();*/
}

void pickup() {
  Serial.println("Pickup started");
  myservo2.write(100);
  delay(500);
  myservo1.write(60);
  delay(150);
  myservo2.write(55);
  delay(150);
  myservo3.write(160);
  delay(150);
  electromagnet_on();
  delay(5000);
  myservo2.write(85);
  delay(150);
  Serial.println("Pickup done");
  delay(150);
}

void place() {
  Serial.println("Placing started");

  myservo1.write(160);
  delay(150);
  myservo2.write(55);
  delay(150);
  electromagnet_off();
  delay(150);
  Serial.println("Placing done");
}

void test_electromagnet() {
digitalWrite(electropin, HIGH);
Serial.println("Electromagnet on");
delay(5000);
digitalWrite(electropin, LOW);
Serial.println("Electromagnet off");
delay(5000);
}

void electromagnet_on() {
digitalWrite(electropin, HIGH);
Serial.println("Electromagnet on");
}

void electromagnet_off() {
digitalWrite(electropin, LOW);
Serial.println("Electromagnet off");
}

void homing() {
  Serial.println("Homing started");
  myservo1.write(0);
  delay(50);
  myservo2.write(0);
  delay(50);
  myservo3.write(0);
  delay(50);
  Serial.println("Homing done");
}

void test_servo_all() {
for(int counter = 0; counter <= 180; counter = counter + 1){
  myservo1.write(counter);
  myservo2.write(counter);
  myservo3.write(counter);
  delay(50);
  Serial.println(counter);
}
for(int counter = 180; counter >= 0; counter = counter - 1){
  myservo1.write(counter);
  myservo2.write(counter);
  myservo3.write(counter);
  delay(50);
  Serial.println(counter);
}
}

void test_servo1() {
for(int counter = 0; counter <= 180; counter = counter + 1){
  myservo1.write(counter);
  delay(50);
  Serial.println(counter);
}
for(int counter = 180; counter >= 0; counter = counter - 1){
  myservo1.write(counter);
  delay(50);
  Serial.println(counter);
}
}

void test_servo2() {
  for(int counter = 0; counter <= 180; counter = counter + 1){
  myservo2.write(counter);
  delay(50);
  Serial.println(counter);
}
for(int counter = 180; counter >= 0; counter = counter - 1){
  myservo2.write(counter);
  delay(50);
  Serial.println(counter);
}
}
void test_servo3() {
  for(int counter = 0; counter <= 180; counter = counter + 1){
  myservo3.write(counter);
  delay(50);
  Serial.println(counter);
}
for(int counter = 180; counter >= 0; counter = counter - 1){
  myservo3.write(counter);
  delay(50);
  Serial.println(counter);
}
}

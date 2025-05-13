#include<Servo.h>
Servo Motor1;
Servo Motor2;
Servo Motor3;
int MagnetPin = 7;
int speed_min = 55;
int speed_mid = 30;
int speed_max = 5;
int keyboard = 0;
int pos = 0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

Motor1.attach(8);
Motor2.attach(9);
Motor3.attach(10);
pinMode(MagnetPin, OUTPUT);
Serial.println("Setup Completed");
}


void loop() {
//   put your main code here, to run repeatedly:
//homing();
keyboard = Serial.parseInt();
if (keyboard > 0){
  

if (1000<=keyboard<=1180){
  pos = (keyboard - 1000);
  Motor1.write(pos);
  delay (speed_min);
  Serial.println (pos);
}

if (2000<=keyboard<=2180){
  pos = (keyboard - 2000);
  Motor2.write(pos);
  delay (speed_min);
  Serial.println (pos);
}
if (3000<=keyboard<=3180){
  pos = (keyboard - 3000);
  Motor3.write(pos);
  delay (speed_min);
  Serial.println (pos);
}
}



//Motor3.write(keyboard);

//Motor1Test();
//Motor2Test();
//Motor3Test();
//ET();
}

void homing(){
 Serial.println("Homing has started");
 Motor1.write(0);
  delay(speed_min);
 Motor2.write(0);
  delay(speed_min);
 Motor3.write(0);
  delay(speed_min);
Serial.println("Homin completed");
  
}

void Motor1Test (){
Serial.println("Motor1 Test Start");
  for(int pos = 0; pos <= 180; pos ++){
    Motor1.write(pos);
    //Serial.print(pos);
    delay(speed_mid);
  }
  for(int pos = 180; pos >= 0; pos --){
    Motor1.write(pos);
    //Serial.print(pos);
    delay(speed_max);
  }
  Serial.println("Motor1 Test Completed");
}

void Motor2Test (){
Serial.println("Motor 2Test Start");
  for(int pos = 0; pos <= 180; pos ++){
    Motor2.write(pos);
    //Serial.println(pos);
    delay(speed_mid);
  }
  for(int pos = 180; pos >= 0; pos --){
    Motor2.write(pos);
    //Serial.println(pos);
    delay(speed_max);
  }
  Serial.println("Motor2 Test Completed");
}


void Motor3Test (){
Serial.println("Motor3 Test Start");
  for(int pos = 0; pos <= 180; pos ++){
    Motor3.write(pos);
    //Serial.println(pos);
    delay(speed_max);
  }
  for(int pos = 180; pos >= 0; pos --){
    Motor3.write(pos);
    //Serial.println(pos);
    delay(speed_mid);
  }
  Serial.println("Motor3 Test Completed");
}


void ET() {

  digitalWrite(MagnetPin, LOW);
  Serial.println("EM Dectivated");
  delay(5000);

  digitalWrite(MagnetPin, HIGH);
  Serial.println("EM Activated");
  delay(5000);
}

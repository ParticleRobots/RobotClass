#include<Servo.h>
Servo Motor1;
Servo Motor2;
Servo Motor3;
int MagnetPin = 7;
int speed_min = 55;
int speed_mid = 25;
int speed_max = 5;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

Motor1.attach(9);
Motor2.attach(10);
Motor3.attach(11);
pinMode(MagnetPin, OUTPUT);
Serial.println("Setup Completed");

}

void loop() {
  // put your main code here, to run repeatedly:
//Motor1Test();
//Motor3Test();
//ET();
}

void Motor1Test (){
Serial.println("Motor Test Start");
  for(int pos = 0; pos <= 180; pos ++){
    Motor1.write(pos);
    Serial.println(pos);
    delay(speed_mid);
  }
  for(int pos = 180; pos >= 0; pos --){
    Motor1.write(pos);
    Serial.println(pos);
    delay(speed_max);
  }
  Serial.println("Motor Test Completed");
}

void Motor3Test (){
Serial.println("Motor Test Start");
  for(int pos = 0; pos <= 180; pos ++){
    Motor3.write(pos);
    Serial.println(pos);
    delay(speed_max);
  }
  for(int pos = 180; pos >= 0; pos --){
    Motor3.write(pos);
    Serial.println(pos);
    delay(speed_mid);
  }
  Serial.println("Motor Test Completed");
}


void ET() {

  digitalWrite(MagnetPin, LOW);
  Serial.println("EM Dectivated");
  delay(5000);

  digitalWrite(MagnetPin, HIGH);
  Serial.println("EM Activated");
  delay(5000);
}

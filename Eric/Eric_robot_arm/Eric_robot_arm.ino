#include <Servo.h>

Servo rightShoulder;
Servo rightArmJoint;
Servo rightHand;
int rightMagnet = 7;
int delayTime = 10;

void setup() {
  // put your setup code here, to run once:
  rightShoulder.attach(8);
  rightArmJoint.attach(9);
  rightHand.attach(10);
  pinMode(rightMagnet, OUTPUT);
  Serial.begin(9600);
  Serial.println("setup ready");



}

void loop() {
  // put your main code here, to run repeatedly:
  //  testRightShoulder();
  //  testRightArmJoint();
  //  testRightHand();
  
//  testRightMagnet();
  activateMagnet();
  delay(5000);
  testRight();
  testRight();
  testRight();
  deactivateMagnet();
  testRightShoulder();
}

void testRightShoulder() {
  for (int i = 0; i < 180; i++) {
    rightShoulder.write(i);
    Serial.println(i);
    delay(delayTime);
  }
  for (int i = 180; i > 0; i--) {
    rightShoulder.write(i);
    Serial.println(i);
    delay(delayTime);
  }

}
void testRightArmJoint() {
  for (int i = 0; i < 180; i++) {
    rightArmJoint.write(i);
    Serial.println(i);
    delay(delayTime);
  }
  for (int i = 180; i > 0; i--) {
    rightArmJoint.write(i);
    Serial.println(i);
    delay(delayTime);
  }
}

void testRightHand() {
  for (int i = 0; i < 180; i++) {
    rightHand.write(i);
    Serial.println(i);
    delay(delayTime);
  }
  for (int i = 180; i > 0; i--) {
    rightHand.write(i);
    Serial.println(i);
    delay(delayTime);
  }


}
void testRight() {
  for (int i = 0; i < 180; i++) {
    rightShoulder.write(i);
    rightArmJoint.write(i);
    rightHand.write(i);
    Serial.println(i);
    delay(delayTime);
  }
  for (int i = 180; i > 0; i--) {
    rightShoulder.write(i);
    rightArmJoint.write(i);
    rightHand.write(i);
    Serial.println(i);
    delay(delayTime);
  }


}
void testRightMagnet() {
  digitalWrite(rightMagnet, HIGH);
  Serial.println("right magnet activated");
  delay(5000);
  digitalWrite(rightMagnet, LOW);
  Serial.println("right magnet deactivated");
  delay(5000);
}

void activateMagnet(){
  digitalWrite(rightMagnet, HIGH);
  Serial.println("right magnet activated");
}

void deactivateMagnet(){
   digitalWrite(rightMagnet, LOW);
   Serial.println("right magnet deactivated");
}

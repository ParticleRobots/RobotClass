#include <Servo.h>


Servo one;
Servo two;
Servo three;
 int D = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int electromagnet = 7;
int pulseWidth = 0;
int T = 25;
int menu = -1;
int TD = 55;
int start = 0;
int finish = 0;

void setup() {
  // put your setup code here, to run once:
one.attach(8);
two.attach(9);
three.attach(10);
pinMode(electromagnet, OUTPUT); Serial.begin(9600);


}

/*
 * pick
 * 1 = 180
 * 2 = 1110
 * 3 = 
  */

void loop() {

 D = Serial.parseInt();

 delay(100);
if(D > 0){
   Serial.println(D);



if (D == 1){
  homing();
}
else if(D == 2){
  pick();
}
else if(D == 3){
  place();
}
else if(D ==4){
  vertical();
}
else if(D ==5){
  electro();
}else if(D ==6){
  horizontal();
}
else if(D ==7){
  elbow();
}
 else if(D ==8){
  obstacle();
} else{
    Serial.println("option not valid");
  }}
// D = Serial.parseInt();
// Serial.println(D);
// delay(500);
//
// if (D > 0 && D < 1000){
//     pulseWidth = map(D, 0, 180, 1000, 2000);
//  three.writeMicroseconds(pulseWidth);
// }
//
// if (D > 1000 && D < 2000){
// pulseWidth = map(D-1000, 0, 180, 1000, 2000);
//  two.writeMicroseconds(pulseWidth);
// }
//  if (D > 2000){
//
//     pulseWidth = map(D-2000, 0, 180, 1000, 2000);
//  one.writeMicroseconds(pulseWidth);
//  }

// Pick
   

// avoid obstacle
   // D = Serial.parseInt();
// Serial.println(D);
// delay(500);

 
 
 // put your main code here, to run repeatedly:
// if (Serial.available() > 0) {
//    menu = Serial.parseInt(); 
// Serial.println(menu);
// }
//
//  pulseWidth = map(55, 0, 180, 1000, 2000);
//  one.writeMicroseconds(pulseWidth);// in steps of 1 degree  
//  delay(TD);
  
  /*pulseWidth = map(55, 0, 180, 1000, 2000);
  one.writeMicroseconds(pulseWidth);// in steps of 1 degree  
  delay(200);
  
  pulseWidth = map(165, 0, 180, 1000, 2000);
  one.writeMicroseconds(pulseWidth);// in steps of 1 degree  
  delay(200);*/   
  
//
// horizontal();
   //electro();
  //homing();
//vertical();
//horizontal();
//elbow();



}

void electro(){
  Serial.print("electromagnet activated");
  digitalWrite(electromagnet, LOW);
  delay(5000);
  Serial.print("electromagnet deactivated");
  digitalWrite(electromagnet, HIGH);
  delay(5000);
}


void movearm(){
  int count = 0;
  for(count = start; count <= finish; count += 1){
  pulseWidth = map(count, 0, 180, 1000, 2000);
  one.writeMicroseconds(pulseWidth);
    delay(T);             
}
}

void homing(){
   pulseWidth = map(0, 0, 180, 1000, 2000);
 Serial.println("start homing");
  one.writeMicroseconds(pulseWidth);
  delay(T);
  two.writeMicroseconds(pulseWidth);
  delay(T);
  three.writeMicroseconds(pulseWidth);
  delay(T);
  Serial.println("end homing");
  
}


void vertical(){
   Serial.println("start vertical");
    
  for(pos1 = 0; pos1 <= 180; pos1 += 1) // goes from 0 degrees to 180 degrees 
  {  
     pulseWidth = map(pos1, 0, 180, 1000, 2000);
  two.writeMicroseconds(pulseWidth);// in steps of 1 degree 
    //one.write(pos1);              // tell servo to go to position in variable 'pos' 
    delay(T);                       // waits 15ms for the servo to reach the position 
  } 

  for(pos1 = 180; pos1 >= 0; pos1 -= 1)
  {
    pulseWidth = map(pos1, 0, 180, 1000, 2000);
    two.writeMicroseconds(pulseWidth);
    delay(T);
  }
  Serial.println("end vertical");
}


void horizontal(){
  Serial.println("start horizontal");

    for(pos1 = 0; pos1 <= 165; pos1 += 1) // goes from 0 degrees to 180 degrees 
  {  
     pulseWidth = map(pos1, 0, 180, 1000, 2000);
  one.writeMicroseconds(pulseWidth);// in steps of 1 degree 
    //one.write(pos1);              // tell servo to go to position in variable 'pos' 
    delay(T);                       // waits 15ms for the servo to reach the position 
  } 

  for(pos1 = 25; pos1 >= 0; pos1 -= 1)
  {
    pulseWidth = map(pos1, 0, 180, 1000, 2000);
    one.writeMicroseconds(pulseWidth);
    delay(T);
}
Serial.println("end horizontal");
}

void elbow(){
  Serial.println("start elbow");
    for(pos1 = 0; pos1 <= 180; pos1 += 1) // goes from 0 degrees to 180 degrees 
  {  
     pulseWidth = map(pos1, 0, 180, 1000, 2000);
  three.writeMicroseconds(pulseWidth);// in steps of 1 degree 
    //one.write(pos1);              // tell servo to go to position in variable 'pos' 
    delay(T);                       // waits 15ms for the servo to reach the position 
  } 
  

  for(pos1 = 180; pos1 >= 0; pos1 -= 1)
  {
    pulseWidth = map(pos1, 0, 180, 1000, 2000);
    three.writeMicroseconds(pulseWidth);
    delay(T);

}
Serial.println("end elbow");
}

void pick(){
   pulseWidth = map(180, 0, 180, 1000, 2000);
  three.writeMicroseconds(pulseWidth);
  delay(600);
     pulseWidth = map(1, 0, 180, 1000, 2000);
  two.writeMicroseconds(pulseWidth);
   delay(600);
     pulseWidth = map(180, 0, 180, 1000, 2000);
  one.writeMicroseconds(pulseWidth);
   delay(600);
    Serial.println("pick");
  digitalWrite(electromagnet, HIGH);
  delay(500); 
  delay(2000);
}

  void obstacle(){
   pulseWidth = map(90, 0, 180, 1000, 2000);
  three.writeMicroseconds(pulseWidth);
  delay(600);
     pulseWidth = map(90, 0, 180, 1000, 2000);
  two.writeMicroseconds(pulseWidth);
   delay(600);
     pulseWidth = map(90, 0, 180, 1000, 2000);
  one.writeMicroseconds(pulseWidth);
   delay(600);
    Serial.println("avoid obstacle");
  digitalWrite(electromagnet, HIGH);
  delay(500); 
  delay(2000);
  }
  
    void place(){
    pulseWidth = map(180, 0, 180, 1000, 2000);
  three.writeMicroseconds(pulseWidth);
   delay(600);
    pulseWidth = map(1, 0, 180, 1000, 2000);
  two.writeMicroseconds(pulseWidth);
   delay(600);
    pulseWidth = map(180, 0, 180, 1000, 2000);
  one.writeMicroseconds(pulseWidth);
   delay(600);
   Serial.println("place");
  digitalWrite(electromagnet, LOW);
  delay(500);
  delay(2000);
    }

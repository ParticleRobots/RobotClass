// this is a piano code


#include "pitches.h"

const int threshold = 10;

int notes[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_A4
};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
//  // put your main code here, to run repeatedly:
//  for (int thisSensor = 0; thisSensor < 5; thisSensor++) {
//    // get a sensor reading:
//    int sensorReading = analogRead(thisSensor);
//
//    // if the sensor is pressed hard enough:
//    if (sensorReading > threshold) {
//      // play the note corresponding to this sensor:
//      tone(7, notes[thisSensor], 20);
//    }
//  }
delay (10);
Cari();
Dori();
Erie();
Gary();
Andy();

}

void Cari() {
  int sensorReading = analogRead(0);
 if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(7, notes[0], 75);{
      Serial.println ("Hello Cari.");} 
}
}
void Dori() {
  int sensorReading = analogRead(1);
 if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(7, notes[1], 75);{
      Serial.println ("Hello Dori.");}
 }
}
void Erie() {
  int sensorReading = analogRead(2);
 if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(7, notes[2], 75);{
      Serial.println ("Hello Erie.");} 
}
}
void Gary() {
  int sensorReading = analogRead(3);
 if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(7, notes[3], 75);{
      Serial.println ("Hello Gary.");} 
}
}
void Andy() {
  int sensorReading = analogRead(4);
 if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(7, notes[4], 75);{
      Serial.println ("Hello Andy.");} 
}
}
      

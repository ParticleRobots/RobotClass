
//by trevin this is a lidar program and done on Oct. 5 2024
#include <Servo.h>

Servo thing; // create servo object to control a servo
Servo thing2;
int pod = 0;
int sensorpin = 2;
int sensorstate = 0;
int count = 0;
int count2 = 0;
int hello = 0;
// The detections are performed every 15 deg
int Number[] = {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180};
// value 0 means nothing is detected
// value 1 means there is an obstacle
int Detect[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:
  // put your setup code here, to run once:
  Serial.begin(9600);
  thing.attach(30);
  thing2.attach(40);

  pinMode (sensorpin, INPUT_PULLUP);

  for (hello = 0; hello <= 180; hello = hello + 15) {
    Serial.println(hello);
  }

  for (hello = 180; hello >= 0; hello = hello - 15) {
    Serial.println(hello);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  int polly;
  int dino;
  for (polly = 0; polly <= 12; polly++) {
    thing.write(Number[polly]);

    sensorstate = digitalRead(sensorpin);


    if (count == 0 || count < 13) {
      count++;
      Serial.print("[");
      Serial.print(Number[polly]);
      Serial.print(",");
      Serial.print (sensorstate);
      Serial.print("] ");
      Serial.println("");
      delay(1300);
    }


    if (count >= 13) {
      Serial.println("");
      
      
      count = 0;
    }
    
    
    
    for (dino = 0; dino <= 12; dino++) {

      thing2.write(Number[dino]);
      sensorstate = digitalRead(sensorpin);


      if (count2 == 0 || count2 < 13) {
        count2++;
        Serial.print("[");
        Serial.print(Number[dino]);
        Serial.print(",");
        Serial.print (sensorstate);
        Serial.print("] ");
        delay(100);
      }


      if (count2 >= 13) {
        Serial.println("");
        count2 = 0;
      }
    }
  }



  for (polly = 12; polly >= 0; polly--) {
    thing.write(Number[polly]);
    sensorstate = digitalRead(sensorpin);


    if (count == 0 || count < 13) {
      count++;
      Serial.print("[");
      Serial.print(Number[polly]);
      Serial.print(",");
      Serial.print (sensorstate);
      Serial.print("] ");
      delay(500);
    }


    if (count >= 13) {
      Serial.println("");
      count = 0;
    }
  }
}

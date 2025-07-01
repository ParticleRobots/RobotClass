#include<Servo.h>
Servo Motor1;
Servo Motor2;
Servo Motor3;
Servo Motor4;
Servo Motor5;
Servo Motor6;
int MagnetPin = 7;
int MagnetPin2 = 6;
int speed_min = 55;
int speed_mid = 30;
int speed_max = 5;
int keyboard = 0;
int pos = 0;
int posa = 0;
int posb = 0;
int posc = 0;
int posd = 0;
int pose = 0;
int ending = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Motor1.attach(8);
  Motor2.attach(9);
  Motor3.attach(10);
  pinMode(MagnetPin, OUTPUT);
  Serial.println("Left Setup Completed");
  pos = 90;
  posa = 90;
  posb = 90;

  Motor4.attach(3);
  Motor5.attach(2);
  Motor6.attach(4);
  pinMode(MagnetPin2, OUTPUT);
  Serial.println("Right Setup Completed");
  posc = 90;
  posd = 90;
  pose = 90;
}


void loop() {
  //   put your main code here, to run repeatedly:
  //homing();
  keyboard = Serial.parseInt();
  if (keyboard > 0) {

    if (keyboard == 1) {
      Motor1Test();
    }

    else if (keyboard == 2) {
      Motor2Test();
    }

    else if (keyboard == 3) {
      Motor3Test();
    }
    else if (keyboard == 4) {
      Motor4Test();
    }
    else if (keyboard == 5) {
      Motor5Test();
    }
    else if (keyboard == 6) {
      Motor6Test();
    }
    else if (keyboard == 7) {
      ET_activated();
    }
    else if (keyboard == 8) {
      ET_deactivated();
    }
    else if (keyboard == 9) {
      ET_activated2();
    }
    else if (keyboard == 10) {
      ET_deactivated2();
    }
    else if (keyboard == 11) {
      pick();
    }

    else if ((1000 <= keyboard) && (1180 >= keyboard)) {
      ending = (keyboard - 1000);

      for (int initial = pos; initial <= ending; initial ++) {
        Motor1.write(initial);
        delay (speed_mid);
        pos = ending;

      }

      for (int initial = pos; initial >= ending; initial --) {
        Motor1.write(initial);
        delay (speed_mid);
        pos = ending;
      }

      //      Motor1.write(pos);
      //      delay (speed_mid);
      Serial.println("=== 1000");
      Serial.println (pos);
    }

    else if ((2000 <= keyboard) && (2180 >= keyboard)) {
      ending = (keyboard - 2000);
      for (int initial = posa; initial <= ending; initial ++) {
        Motor2.write(initial);
        delay (speed_mid);
        posa = ending;

      }

      for (int initial = posa; initial >= ending; initial --) {
        Motor2.write(initial);
        delay (speed_mid);
        posa = ending;
      }
      Serial.println("=== 2000");
      Serial.println (posa);
    }
    else if ((3000 <= keyboard) && (3180 >= keyboard)) {
      ending = (keyboard - 3000);
      for (int initial = posb; initial <= ending; initial ++) {
        Motor3.write(initial);
        delay (speed_mid);
        posb = ending;

      }

      for (int initial = posb; initial >= ending; initial --) {
        Motor3.write(initial);
        delay (speed_mid);
        posb = ending;
      }
      Serial.println("=== 3000");
      Serial.println (posb);
    }

    else if ((4000 <= keyboard) && (4180 >= keyboard)) {
      ending = (keyboard - 4000);
      for (int initial = posc; initial <= ending; initial ++) {
        Motor4.write(initial);
        delay (speed_mid);
        posc = ending;

      }

      for (int initial = posc; initial >= ending; initial --) {
        Motor4.write(initial);
        delay (speed_mid);
        posc = ending;
      }
      Serial.println("=== 4000");
      Serial.println (posc);
    }

    else if ((5000 <= keyboard) && (5180 >= keyboard)) {
      ending = (keyboard - 5000);
      for (int initial = posd; initial <= ending; initial ++) {
        Motor5.write(initial);
        delay (speed_mid);
        posd = ending;

      }

      for (int initial = posd; initial >= ending; initial --) {
        Motor5.write(initial);
        delay (speed_mid);
        posd = ending;
      }
      Serial.println("=== 5000");
      Serial.println (posd);
    }

    else if ((6000 <= keyboard) && (6180 >= keyboard)) {
      ending = (keyboard - 6000);
      for (int initial = pose; initial <= ending; initial ++) {
        Motor6.write(initial);
        delay (speed_mid);
        pose = ending;

      }

      for (int initial = pose; initial >= ending; initial --) {
        Motor6.write(initial);
        delay (speed_mid);
        pose = ending;
      }
      Serial.println("=== 6000");
      Serial.println (pose);
    }
    else {
      Serial.println("error");
    }
  }



  //Motor3.write(keyboard);

  //Motor1Test();
  //Motor2Test();
  //Motor3Test();
  //ET();
}

void homing() {
  Serial.println("Homing has started");
  Motor1.write(90);
  delay(speed_min);
  Motor2.write(90);
  delay(speed_min);
  Motor3.write(90);
  delay(speed_min);
  Motor4.write(90);
  delay(speed_min);
  Motor5.write(90);
  delay(speed_min);
  Motor6.write(90);
  delay(speed_min);
  Serial.println("Homing completed");

}

void Motor1Test () {
  Serial.println("Motor1 Test Start");
  for (int pos = 0; pos <= 180; pos ++) {
    Motor1.write(pos);
    //Serial.print(pos);
    delay(speed_mid);
  }
  for (int pos = 180; pos >= 0; pos --) {
    Motor1.write(pos);
    //Serial.print(pos);
    delay(speed_max);
  }
  Serial.println("Motor1 Test Completed");
}

void Motor2Test () {
  Serial.println("Motor 2Test Start");
  for (int pos = 0; pos <= 180; pos ++) {
    Motor2.write(pos);
    //Serial.println(pos);
    delay(speed_mid);
  }
  for (int pos = 180; pos >= 0; pos --) {
    Motor2.write(pos);
    //Serial.println(pos);
    delay(speed_max);
  }
  Serial.println("Motor2 Test Completed");
}


void Motor3Test () {
  Serial.println("Motor3 Test Start");
  for (int pos = 0; pos <= 180; pos ++) {
    Motor3.write(pos);
    //Serial.println(pos);
    delay(speed_max);
  }
  for (int pos = 180; pos >= 0; pos --) {
    Motor3.write(pos);
    //Serial.println(pos);
    delay(speed_mid);
  }
  Serial.println("Motor3 Test Completed");
}

void Motor4Test () {
  Serial.println("Motor4 Test Start");
  for (int pos = 0; pos <= 180; pos ++) {
    Motor4.write(pos);
    //Serial.print(pos);
    delay(speed_mid);
  }
  for (int pos = 180; pos >= 0; pos --) {
    Motor4.write(pos);
    //Serial.print(pos);
    delay(speed_max);
  }
  Serial.println("Motor4 Test Completed");
}

void Motor5Test () {
  Serial.println("Motor5 Test Start");
  for (int pos = 0; pos <= 180; pos ++) {
    Motor5.write(pos);
    //Serial.print(pos);
    delay(speed_mid);
  }
  for (int pos = 180; pos >= 0; pos --) {
    Motor5.write(pos);
    //Serial.print(pos);
    delay(speed_max);
  }
  Serial.println("Motor5 Test Completed");
}

void Motor6Test () {
  Serial.println("Motor6 Test Start");
  for (int pos = 0; pos <= 180; pos ++) {
    Motor6.write(pos);
    //Serial.print(pos);
    delay(speed_mid);
  }
  for (int pos = 180; pos >= 0; pos --) {
    Motor6.write(pos);
    //Serial.print(pos);
    delay(speed_max);
  }
  Serial.println("Motor6 Test Completed");
}

void ET() {

  digitalWrite(MagnetPin, LOW);
  Serial.println("EM Dectivated");
  delay(5000);

  digitalWrite(MagnetPin, HIGH);
  Serial.println("EM Activated");
  delay(5000);
}


void ET_activated() {
  digitalWrite(MagnetPin, HIGH);
  Serial.println("EM Activated");
}

void ET_deactivated() {
  digitalWrite(MagnetPin, LOW);
  Serial.println("EM Deactivated");
}

void ET_activated2() {
  digitalWrite(MagnetPin2, HIGH);
  Serial.println("EM Activated2");
}

void ET_deactivated2() {
  digitalWrite(MagnetPin2, LOW);
  Serial.println("EM Deactivated2");
}

void pick () {
  ET_activated();
  delay(100);
//  Motor3.write(150);
//  delay(speed_mid);
for (int initial = posb; initial <= 150; initial ++) {
        Motor3.write(initial);
        delay (speed_mid);
        posb = ending;
}

//  Motor2.write(235);
//  delay(speed_mid);
for (int initial = posa; initial >= 35; initial --) {
        Motor2.write(initial);
        delay (speed_mid);
        posa = ending;
}

  //Motor1.write(180);
  //delay(speed_mid);
  for (int initial = pos; initial <= 180; initial ++) {
    Motor1.write(initial);
    delay (speed_mid);
    pos = ending;

  }
}

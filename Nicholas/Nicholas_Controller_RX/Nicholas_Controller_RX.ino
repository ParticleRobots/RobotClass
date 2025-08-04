#include <Servo.h>

Servo Servo_left1;
Servo Servo_left2;
Servo Servo_left3;
Servo Servo_right1;
Servo Servo_right2;
Servo Servo_right3;

int left_electromagnet = 6;
int right_electromagnet = 7;

int delay_time = 15;

byte angles[8];
byte lastangles[8];

bool receiving = false;
byte index = 0;


void setup() {
  // put your setup code here, to run once:
  Servo_left1.attach(8);
  Servo_left2.attach(9);
  Servo_left3.attach(10);
  Servo_right1.attach(3);
  Servo_right2.attach(2);
  Servo_right3.attach(4);

  delay(500);

  pinMode(left_electromagnet, OUTPUT);
  pinMode(right_electromagnet, OUTPUT);
  digitalWrite(left_electromagnet, LOW);
  digitalWrite(right_electromagnet, LOW);

  Serial.begin(9600);
  Serial1.begin(9600);

  delay(500);

  Serial.println("Setup done");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial1.available()) {
    char incoming = Serial1.read();

    if (incoming == '<') {
      receiving = true;
      index = 0;
    }
    else if (incoming == '>' && receiving) {
      receiving = false;

      for (int i = 0; i < 8; i++) {
        Serial.print(angles[i]);
        Serial.print(i < 7 ? ", " : "\n");
      }

      Servo_left1.write(angles[0]);
      delay(delay_time);
      Servo_left2.write(angles[1]);
      delay(delay_time);
      Servo_left3.write(angles[2]);
      delay(delay_time);
      Servo_right1.write(angles[4]);
      delay(delay_time);
      Servo_right2.write(angles[5]);
      delay(delay_time);
      Servo_right3.write(angles[6]);
      delay(delay_time);
      if (angles[3] == 0) {
        digitalWrite(right_electromagnet, HIGH);
      }
      else {
        digitalWrite(right_electromagnet, LOW);
      }
      if (angles[7] == 0) {
        digitalWrite(left_electromagnet, HIGH);
      }
      else {
        digitalWrite(left_electromagnet, LOW);
      }
      

      Serial1.write('A');
    }
    else if (receiving && index < 8) {
      angles[index++] = (byte)incoming;
    }
  }
}

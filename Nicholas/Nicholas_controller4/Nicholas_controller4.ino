int left_switch = 2;
int right_switch = 3;
int left_yaxis = A2;
int left_xaxis = A3;
int right_yaxis = A0;
int right_xaxis = A1;

int delta = 5;
int temp = 0;

int left_switch_value = 0;
int right_switch_value = 0;
int left_yaxis_value = 0;
int left_xaxis_value = 0;
int right_yaxis_value = 0;
int right_xaxis_value = 0;
int Servo_left1 = 0;
int Servo_right1 = 0;
int Servo_left2 = 0;
int Servo_right2 = 0;
int Servo_left3 = 0;
int Servo_right3 = 0;

int right_pushup = 6;
int right_pushdown = 7;
int left_pushup = 8;
int left_pushdown = 9;
int right_eswitch = 12;
int left_eswitch = 13;

int right_pushup_value = 0;
int right_pushdown_value = 0;
int left_pushup_value = 0;
int left_pushdown_value = 0;
int right_eswitch_value = 0;
int left_eswitch_value = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(left_switch, INPUT_PULLUP);
  pinMode(right_switch, INPUT_PULLUP);
  pinMode(left_yaxis, INPUT);
  pinMode(left_xaxis, INPUT);
  pinMode(right_yaxis, INPUT);
  pinMode(right_xaxis, INPUT);
  pinMode(right_pushup, INPUT_PULLUP);
  pinMode(right_pushdown, INPUT_PULLUP);
  pinMode(left_pushup, INPUT_PULLUP);
  pinMode(left_pushdown, INPUT_PULLUP);
  pinMode(right_eswitch, INPUT_PULLUP);
  pinMode(left_eswitch, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  left_switch_value = digitalRead(left_switch);
  right_switch_value = digitalRead(right_switch);
  left_yaxis_value = analogRead(left_yaxis); //up = 0
  left_xaxis_value = analogRead(left_xaxis); //left = 1023
  right_yaxis_value = analogRead(right_yaxis); //up = 0
  right_xaxis_value = analogRead(right_xaxis); //right = 1023
  right_pushup_value = digitalRead(right_pushup);
  right_pushdown_value = digitalRead(right_pushdown);
  left_pushup_value = digitalRead(left_pushup);
  left_pushdown_value = digitalRead(left_pushdown);
  right_eswitch_value = digitalRead(right_eswitch);
  left_eswitch_value = digitalRead(left_eswitch);

  Servo_left1 = map(left_yaxis_value, 0, 1023, 0, 180);
  Servo_right1 = map(right_yaxis_value, 0, 1023, 0, 180);
  Servo_left2 = map(left_xaxis_value, 0, 1023, 0, 180);
  Servo_right2 = map (right_xaxis_value, 0, 1023, 0, 180);

  // if (left_pushup_value == 0) {
  //   if (Servo_left3 <= 180) {
  //     Servo_left3 = Servo_left3 + delta;
  //     // 180 - Servo_left3 = 0
  //   }
  // }
  if (left_pushup_value == 0) {
    if (temp < 180) {
      temp = temp + delta;
    }
  }
  if (left_pushdown_value == 0) {
    if (temp > 0) {
      temp = temp - delta;
    }
  }

  if (right_pushup_value == 0) {
    if (Servo_right3 < 180) {
      Servo_right3 = Servo_right3 + delta;
    }
  }
  if (right_pushdown_value == 0) {
    if (Servo_right3 > 0) {
      Servo_right3 = Servo_right3 - delta;
    }
  }

  Servo_left3 = 180 - temp;
  /*Serial.print(Servo_left3);
  delay(50);
  Serial.print(", ");
  Serial.println(Servo_right3);
  delay(50);*/

//Serial.println(right_eswitch_value);
//Serial.println(left_eswitch_value);
  Serial.write('<');
  Serial.write((byte)Servo_left1);
  Serial.write((byte)Servo_left2);
  Serial.write((byte)Servo_left3);
  Serial.write((byte)left_eswitch_value);
  Serial.write((byte)Servo_right1);
  Serial.write((byte)Servo_right2);
  Serial.write((byte)Servo_right3);
  Serial.write((byte)right_eswitch_value);
  Serial.write('>');

  unsigned long startTime = millis();
  while (true) {
    if (Serial.available()) {
      char ack = Serial.read();
      if (ack == 'A') {
        break;
      }
    }


    if (millis() - startTime > 500) {
      Serial.println("ACK timeout");
      break;
    }
  }

//  Serial.print("LeftX: ");
//  Serial.print(Servo_left3);
//  Serial.print(", ls: ");
//  Serial.print(left_switch_value);
//  Serial.print(", rs: ");
//  Serial.print(right_switch_value);
//  Serial.print(", ljy: ");
//  Serial.print(left_yaxis_value);
//  Serial.print(", ljx: ");
//  Serial.print(left_xaxis_value);
//  Serial.print(", rjy: ");
//  Serial.print(right_yaxis_value);
//  Serial.print(", rjx: ");
//  Serial.print(right_xaxis_value);
//  Serial.print(", les: ");
//  Serial.print(left_eswitch_value);
//  Serial.print(", res: ");
//  Serial.print(right_eswitch_value);
//  Serial.print(", lpu: ");
//  Serial.print(left_pushup_value);
//  Serial.print(", lpd: ");
//  Serial.print(left_pushdown_value);
//  Serial.print(", rpu: ");
//  Serial.print(right_pushup_value);
//  Serial.print(", rpd: ");
//  Serial.println(right_pushdown_value);
}

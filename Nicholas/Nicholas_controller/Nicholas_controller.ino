int left_switch = 2;
int right_switch = 3;
int left_yaxis = A2;
int left_xaxis = A3;
int right_yaxis = A0;
int right_xaxis = A1;

int left_switch_value = 0;
int right_switch_value = 0;
int left_yaxis_value = 0;
int left_xaxis_value = 0;
int right_yaxis_value = 0;
int right_xaxis_value = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(left_switch, INPUT_PULLUP);
pinMode(right_switch, INPUT_PULLUP);
pinMode(left_yaxis, INPUT);
pinMode(left_xaxis, INPUT);
pinMode(right_yaxis, INPUT);
pinMode(right_xaxis, INPUT);
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
Serial.print("ls: ");
Serial.print(left_switch_value);
Serial.print(", rs: ");
Serial.print(right_switch_value);
Serial.print(", ljy: ");
Serial.print(left_yaxis_value);
Serial.print(", ljx: ");
Serial.print(left_xaxis_value);
Serial.print(", rjy: ");
Serial.print(right_yaxis_value);
Serial.print(", rjx: ");
Serial.println(right_xaxis_value);
}

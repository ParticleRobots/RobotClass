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

int right_pushup = 5;
int right_pushdown = 6;
int left_pushup = 8;
int left_pushdown = 9;
int right_eswitch = 10;
int left_eswitch = 11;

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
Serial.print(right_xaxis_value);
Serial.print(", les: ");
Serial.print(left_eswitch_value);
Serial.print(", res: ");
Serial.print(right_eswitch_value);
Serial.print(", lpu: ");
Serial.print(left_pushup_value);
Serial.print(", lpd: ");
Serial.print(left_pushdown_value);
Serial.print(", rpu: ");
Serial.print(right_pushup_value);
Serial.print(", rpd: ");
Serial.println(right_pushdown_value);
}

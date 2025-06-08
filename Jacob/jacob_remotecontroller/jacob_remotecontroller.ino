int sensorupdown = A2;
int sensorleftright = A0;
int sensorupdown2 = A3;
int sensorleftright2 = A1;

int valueupdown = 0;
int valueleftright = 0;
int valueupdown2 = 0;
int valueleftright2 = 0;

int switch1 = 6;
int switch2 = 7;
int valueswitch = 0;
int valueswitch2 = 0;
int elbowup = 2;
int elbowdown = 3;
int elbowup2 = 8;
int elbowdown2 = 9;
int valueelbowup = 0;
int valueelbowup2 = 0;
int valueelbowdown = 0;
int valueelbowdown2 = 0;
int magnet = 10;
int magnet2 = 11;
int valuemagnet = 0;
int valuemagnet2 = 0;






void setup() {
pinMode(switch1, INPUT_PULLUP);
pinMode(switch2, INPUT_PULLUP);
pinMode(sensorupdown, INPUT);
pinMode(sensorleftright, INPUT);
pinMode(sensorupdown2, INPUT);
pinMode(sensorleftright2, INPUT);
pinMode(elbowup, INPUT_PULLUP);
pinMode(elbowdown, INPUT_PULLUP);
pinMode(elbowdown2, INPUT_PULLUP);
pinMode(elbowup2, INPUT_PULLUP);
pinMode(magnet, INPUT_PULLUP);
pinMode(magnet2, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
 valueupdown = analogRead(sensorupdown);
valueupdown2 = analogRead(sensorupdown2);
 valueleftright = analogRead(sensorleftright);
valueleftright2 = analogRead(sensorleftright2);
valueswitch = digitalRead(switch1);
valueswitch2 = digitalRead(switch2);
valueelbowup = digitalRead(elbowup);
valueelbowup2 = digitalRead(elbowup2);
valueelbowdown = digitalRead(elbowdown);
valueelbowdown2 = digitalRead(elbowdown2);
valuemagnet = digitalRead(magnet);
valuemagnet2 = digitalRead(magnet2);

Serial.print(valuemagnet);
Serial.print(valuemagnet2);
Serial.print(valueupdown);
Serial.print(valueupdown2);
Serial.print(valueleftright);
Serial.print(valueleftright2);
Serial.print(valueelbowup);
Serial.print(valueelbowup2);
Serial.print(valueelbowdown);
Serial.print(valueelbowdown2);
delay(100);

Serial.println();
}

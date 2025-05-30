int Button=13;
int UpDown=A6;
int LeftRight=A7;
int Button_value=0;
int UpDown_value=0;
int LeftRight_value=0;

int BlueLED=9;//A8;
int RedLED=10;//A9;


void setup() {
  // put your setup code here, to run once:
pinMode(Button,INPUT_PULLUP);
pinMode(UpDown,INPUT);
pinMode(LeftRight,INPUT);

pinMode(BlueLED,OUTPUT);
pinMode(RedLED,OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Button_value=digitalRead(Button);
UpDown_value=analogRead(UpDown);
Serial.println(UpDown_value=analogRead(UpDown));
LeftRight_value=analogRead(LeftRight);

/*if(UpDown_value>100){
  digitalWrite(RedLED,HIGH);
}
else{
  digitalWrite(RedLED,LOW);
}
if(LeftRight_value>100){
  digitalWrite(BlueLED,HIGH);
}
else{
  digitalWrite(BlueLED,LOW);
}*/

int dimmer_red=map(UpDown_value,0,1023,0,255);
Serial.print("Dimmer red");
Serial.println(dimmer_red);
analogWrite(RedLED,dimmer_red);

int dimmer_blue=map(LeftRight_value,0,1023,0,255);
Serial.print("Dimmer Blue");
Serial.println(dimmer_blue);
analogWrite(BlueLED,dimmer_blue);

}




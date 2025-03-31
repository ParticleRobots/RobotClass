
int redpin = 6;
int greenpin = 5;
//hello is useless
int hello = 1;
int state = LOW;
int state2 = LOW;
long ontime = 450;
long offtime = 450;
long ontime2 = 300;
long offtime2 = 300;
unsigned long premillis = 0;
unsigned long premillis2 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (redpin, OUTPUT);
  pinMode (greenpin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(pin, hello);
//  delay (1000);
//  digitalWrite(pin, LOW);
//  delay (1000);

unsigned long nowmillis = millis();
unsigned long nowmillis2 = millis();
if ((state == HIGH) && (nowmillis - premillis >= ontime))
{
  state = LOW; //turn it off
  premillis = nowmillis; //remember the time
  digitalWrite(redpin, state); //update the actual LED
}
else if ((state == LOW) && (nowmillis - premillis >= offtime))
{
  state = HIGH; //turn it on
  premillis = nowmillis; //remember the time
  digitalWrite(redpin, state); //update the actual LED
}


if ((state2 == HIGH) && (nowmillis2 - premillis2 >= ontime2))
{
  state2 = LOW; //turn it off
  premillis2 = nowmillis2; //remember the time
  digitalWrite(greenpin, state2); //update the actual LED
}
else if ((state2 == LOW) && (nowmillis2 - premillis2 >= offtime2))
{
  state2 = HIGH; //turn it on
  premillis2 = nowmillis2; //remember the time
  digitalWrite(greenpin, state2); //update the actual LED
}
}

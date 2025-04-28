 int led1_pin = 7;
 int ledState1 = LOW;
 unsigned long previousMillis1 = 0;
 long Ontime1 = 250;
 long Offtime1 = 750;

 int led2_pin = 6;
 int ledState2 = LOW;
 unsigned long previousMillis2 = 0;
 long Ontime2 = 550;
 long Offtime2 = 450;

 int led3_pin = 8;
 int ledState3 = LOW;
 unsigned long previousMillis3 = 0;
 long Ontime3 = 333;
 long Offtime3 = 667;
 
void setup() {
  // put your setup code here, to run once:
pinMode(led1_pin, OUTPUT);
pinMode(led2_pin, OUTPUT);
pinMode(led3_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long currentMillis = millis();

if ((ledState1 == HIGH) && (currentMillis - previousMillis1 >= Ontime1))
{
  ledState1 = LOW;
  previousMillis1 = currentMillis;
  digitalWrite(led1_pin, ledState1);
}
else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= Offtime1))
{
ledState1 = HIGH;
previousMillis1 = currentMillis;
digitalWrite(led1_pin, ledState1);
}

if ((ledState2 == HIGH) && (currentMillis - previousMillis2 >= Ontime2))
{
  ledState2 = LOW;
  previousMillis2 = currentMillis;
  digitalWrite(led2_pin, ledState2);
}
else if ((ledState2 == LOW) && (currentMillis - previousMillis2 >= Offtime2))
{
ledState2 = HIGH;
previousMillis2 = currentMillis;
digitalWrite(led2_pin, ledState2);
}

if ((ledState3 == HIGH) && (currentMillis - previousMillis3 >= Ontime3))
{
  ledState3 = LOW;
  previousMillis3 = currentMillis;
  digitalWrite(led3_pin, ledState3);
}
else if ((ledState3 == LOW) && (currentMillis - previousMillis3 >= Offtime3))
{
ledState3 = HIGH;
previousMillis3 = currentMillis;
digitalWrite(led3_pin, ledState3);
}
}

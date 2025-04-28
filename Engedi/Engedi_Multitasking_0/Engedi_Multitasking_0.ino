 int led1_pin = 7;
 int led2_pin = 6;

void setup() {
  // put your setup code here, to run once:
pinMode(led1_pin, OUTPUT);
pinMode(led2_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led1_pin, HIGH);
delay(1000);
digitalWrite(led1_pin, LOW);
delay(1000);
digitalWrite(led2_pin, HIGH);
delay(1000);
digitalWrite(led2_pin, LOW);
delay(1000);
}

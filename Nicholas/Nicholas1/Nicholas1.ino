int pinled=13;

void setup() {
  // put your setup code here, to run once:
pinMode(pinled,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(pinled,HIGH);
delay(500);
Serial.println("Led turn on");
digitalWrite(pinled,LOW);
delay(500);
Serial.println("Led turn off");
}

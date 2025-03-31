void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(9, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(6, LOW);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

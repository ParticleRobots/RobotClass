int trigger_pin = 9;
int echo_pin = 8;
float distance = 0;
float speedofsound = 0.034;
float timeofsense = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (trigger_pin, OUTPUT);
  pinMode (echo_pin, INPUT);
  Serial.begin (9600);
  Serial.println ("setup ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (trigger_pin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigger_pin, LOW);
  timeofsense = pulseIn (echo_pin, HIGH);
  distance = speedofsound * timeofsense / 2 ;
  distance = distance * 10;
  delay (500);
  //Serial.println (distance);
  if (distance <= 200) {
    Serial.println ("stop");
  } else {
    Serial.println (distance);
  }

}

int trigger = 9;
int echo = 8;
float speedofsound = 0.343;
float distance = 0;
float duration = 0;
int led_light = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led_light, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (speedofsound * duration) / 2;
  if (distance < 6000) {
    Serial.println(distance);
    if (distance >= 100 and distance <= 300) {
      digitalWrite(led_light, HIGH);
    }
    else {
      digitalWrite(led_light, LOW);
    }
  }
  delay(50);
}

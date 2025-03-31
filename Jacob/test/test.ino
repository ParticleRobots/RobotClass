#include <Servo.h>


class Ultrasonic
{
  int trigPin;
  int echopin;
  float duration;
  float distance;
  unsigned long previousMillis;
   long interval;

public:
Ultrasonic(int trig, int echo, long i)
{
  
  duration = 0;
  distance = 0;
  echopin = echo;
  trigPin = trig;
  previousMillis = 0;
  interval = i;
  pinMode(trigPin, OUTPUT);
  pinMode(echopin, INPUT);
}

void Update()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echopin, HIGH);
    distance = 0.017 * duration;
  
  Serial.print("distance:");
  Serial.print(interval);
  Serial.print(":");
  Serial.print(distance);
  Serial.println("cm");
    
  }
}

};

class Sweeper
{
  Servo servo;              // the servo
  int pos;              // current servo position 
  int increment;        // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate; // last update of position

public: 
  Sweeper(int interval)
  {
    updateInterval = interval;
    increment = 1;
  }
  
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update()
  {
    if((millis() - lastUpdate) > updateInterval)  // time to update
    {
      lastUpdate = millis();
      pos += increment;
      servo.write(pos);
      Serial.println(pos);
      if ((pos >= 180) || (pos <= 0)) // end of sweep
      {
        // reverse direction
        increment = -increment;
      }
    }
  }
};



Sweeper sweeper1(1);
Sweeper sweeper2(1);
//Sweeper sweeper3(100);

Ultrasonic sensor1( 2, 3, 5000);
//Ultrasonic sensor2( 4, 5, 50);
//Ultrasonic sensor3( 6, 7, 50);

//Music peppaPig(melody, noteDurations, 11, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sweeper1.Attach(9);
  sweeper2.Attach(10);
  //sweeper3.Attach(11);
   pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sweeper1.Update();
  sweeper2.Update();
  //sweeper3.Update();
  sensor1.Update();
  //sensor2.Update();
  //sensor3.Update();
  //peppaPig.Update();
}

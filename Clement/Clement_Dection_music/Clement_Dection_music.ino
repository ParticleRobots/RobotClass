
int trigPin = 9;    // TRIG pin
int echoPin = 8;    // ECHO pin

float duration_us, distance_cm;

#include "pitches.h"

#define BUZZER_PIN 11
#include <Servo.h>

Servo ARM_LEFT_SERVO;
Servo ARM_RIGHT_SERVO;
// Motor LEFT and Motor RIGHT PIN assignment
const int MOTOR_LEFT_PIN = 2;
const int MOTOR_RIGHT_PIN = 3;

int melody[] = {
  NOTE_E5, NOTE_D5, NOTE_FS4, NOTE_GS4, 
  NOTE_CS5, NOTE_B4, NOTE_D4, NOTE_E4, 
  NOTE_B4, NOTE_A4, NOTE_CS4, NOTE_E4,
  NOTE_A4
};

int durations[] = {
  8, 8, 4, 4,
  8, 8, 4, 4,
  8, 8, 4, 4,
  2
};

void setup() {
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_PIN, OUTPUT);
}

void playMusic(int size)
{
    for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER_PIN);
    }
}
 
void loop() 
{
  int size = sizeof(durations) / sizeof(int);
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.println(distance_cm);
  if(distance_cm <= 50 && distance_cm >= 25)
  {
    if(distance_cm <= 20)
    {
      digitalWrite(MOTOR_LEFT_PIN, HIGH);
      digitalWrite(MOTOR_RIGHT_PIN, HIGH);
    }
    else
    {
      playMusic(size);
      digitalWrite(MOTOR_LEFT_PIN, LOW);
      digitalWrite(MOTOR_RIGHT_PIN, LOW);
      delay(50);
    }
  } else {
  digitalWrite(MOTOR_LEFT_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_PIN, HIGH);
  delay(50);
  }
}

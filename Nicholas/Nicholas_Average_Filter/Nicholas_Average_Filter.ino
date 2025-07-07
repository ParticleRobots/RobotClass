const int trigPin = 9;
const int echoPin = 8;

const int numReadings = 5;
const int numReadingsMed = 7;
float readings[numReadings];
float readingsMed[numReadingsMed];
int readIndex = 0;
int readIndexMed = 0;
float total = 0;
float average = 0;
float medianDistance;

long duration;
float distance;
float tempReadingsMed[numReadingsMed];

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
for (int i = 0; i < numReadings; i++) {
  readings[i] = 0;
}
for (int i = 0; i < numReadingsMed; i++) {
  readingsMed[i] = 0;
}
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = duration * 0.0343 / 2;
distance = distance * 1000;

total = total - readings[readIndex];
readings[readIndex] = distance;
total = total + readings[readIndex];
readIndex = (readIndex + 1) % numReadings;

average = total/numReadings;

readingsMed[readIndexMed] = distance;

readIndexMed = (readIndexMed + 1) % numReadingsMed;

for (int i = 0; i < numReadingsMed - 1; i++) {
  for (int j = i + 1; j < numReadingsMed; j++) {
    if (readingsMed[i] > readingsMed[j]) {
      float temp = readingsMed[i];
      readingsMed[i] = readingsMed[j];
      readingsMed[j] = temp;
    }
  }
}

medianDistance = readingsMed[numReadingsMed / 2];

Serial.print("Raw Distance:");
Serial.print(distance);
Serial.print(",");
Serial.print("Average Distance:");
Serial.print(average);
Serial.print(",");
Serial.print("Median Distance:");
Serial.println(medianDistance);

delay(200);
}

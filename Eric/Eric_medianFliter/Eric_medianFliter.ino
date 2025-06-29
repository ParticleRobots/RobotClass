const int triggerPin = 8;
const int echoPin = 9;
const int numReadings = 7; 
float reading[numReadings];
float tempReadings[numReadings];
int readIndex = 0;
long duration;
float distance; 
float medianDistance; 

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  for(int i = 0; i < numReadings; i++){
    reading[i] = 0;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (triggerPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (triggerPin, LOW); 

  duration = pulseIn(echoPin , HIGH);
  distance = duration * 0.343 / 2;
  reading[readIndex] = distance;
  readIndex = (readIndex + 1) % numReadings;

  for (int i = 0; i < numReadings; i++) {
    tempReadings[i] = reading[i];
  }

  for(int i = 0; i < numReadings - 1; i++){
    for(int j = i + 1; j < numReadings; j++){
      if(tempReadings[i] > tempReadings[j]){
        float temp = tempReadings[i];
        tempReadings[i] = tempReadings[j]; 
        tempReadings[j] = temp;
        }
      }
    }

    medianDistance = tempReadings[numReadings / 2];
    //Serial.print("median distance: ");
    //Serial.print(medianDistance);
    //Serial.print(" mm");
    Serial.print("distance:");
    Serial.print(distance);
    Serial.print(",");
    Serial.print("medianDistance:");
    Serial.println(medianDistance);    
    delay(200);
}

const int triggerPin = 8;
const int echoPin = 9;
const int numReadings = 15; 
float reading[numReadings];
int readIndex = 0;
float total = 0;
float average = 0;
long duration;
float distance; 


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

   total = total - reading[readIndex];
   reading[readIndex] = distance;
   total = total + reading[readIndex];
   readIndex = (readIndex + 1) % numReadings;
   average = total / numReadings;

//   Serial.print("smoothed distance: ");
    Serial.print("distance:");
    Serial.print(distance);
    Serial.print(",");
    Serial.print("average:");
    Serial.println(average);
//   Serial.println(" mm");

   delay(200);
}

int triggerPin = 8;
int echoPin = 9;
float distance = 0;
float speedOfSound = 0.034;
float timeOfSense = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode (triggerPin, OUTPUT); 
  pinMode (echoPin, INPUT);
  Serial.begin(9600);
  //Serial.println("setup ready");

}  

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (triggerPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (triggerPin, LOW);
  timeOfSense = pulseIn (echoPin, HIGH);
  distance = (speedOfSound * timeOfSense / 2) * 10;
   Serial.println(distance);
  if(distance >= 200 && distance <= 500){
   
    //Serial.println("mm");
  }
  delay(10);
  //Serial.print(distance / 100 );
  //Serial.println("m");
  
  
  
}

  
int axisX = A0;
int axisY = A1;
int buttenPin = 13;
int buttenPinValue = 0;
int axisXValue = 0;
int axisYValue = 0;
int ledPin = 9;
int ledPin2 = 10;
int infraredPin = 8;
int infraredValue = 0;
int outputLed = 0;
int outputLed2 = 0;

void setup() {
  pinMode(axisX, INPUT);
  pinMode(axisY, INPUT);
  pinMode(buttenPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(infraredPin, INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {
  axisXValue = analogRead(axisX);
  axisYValue = analogRead(axisY);
  buttenPinValue = digitalRead(buttenPin);
  infraredValue = digitalRead(infraredPin);
  Serial.print("UpDown:");
  Serial.print(axisYValue);
  Serial.print(",");
  Serial.print("LeftRight");
  Serial.print(axisXValue);
  Serial.print(", ");
  Serial.print(buttenPinValue);
  Serial.println("");
  Serial.print(outputLed);
  Serial.print(infraredValue);

  outputLed = map(axisYValue, 0, 1023, 0, 255);
  outputLed2 = map(axisXValue, 0, 1023, 0, 255);
  infraredValue = map( 
  analogWrite(ledPin, outputLed);
  analogWrite(ledPin2, outputLed2);
}

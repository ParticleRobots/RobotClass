const int button = 5;
const int y = A2;
const int x = A3;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xMap = map(analogRead(x), 0, 1024, 0, 100);
  int yMap = map(analogRead(y), 0, 1024, 0, 100);
  Serial.println(xMap);
  Serial.print(yMap);
}

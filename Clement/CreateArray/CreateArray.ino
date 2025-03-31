

int count = 0;
int A[] = {};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (int i = 0; i < 180; i = i + 1) {
    A[i] = 0;
  }




}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print(" HERE ");
  if (count >= 0 && count < 180) {
    Serial.print(count);
    Serial.print(" ");
    Serial.println(A[count]);
      count = count + 1;
  } else {
    //count = 0;
    //Serial.println("bye bye");
  }
}

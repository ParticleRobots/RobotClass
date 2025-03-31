// This program control a joystick
// by Trevin

int lefight = A1;
int upown = A0;

int high = 5;
int low = 1;

int VUP = 0;
int VLR = 0; // This stores the Left and Right value from the joystick

int kitu = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  VUP = analogRead(upown);
  VLR = analogRead(lefight);



  //int kitu = 0;
  
  /*
    for (hello = 0; hello <= 10; hello++) {
      Serial.print(hello);
      Serial.print(",");
    for (kitu = 0; kitu <= 10; kitu++) {
      Serial.println(kitu);}
    }
  */

  // while (hello < 8){
  //  Serial.println(hello);
  //  hello++;
  // }

//  int myNumbers[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
//  //myNumbers[5] = 99;
//  //Serial.println(myNumbers[0-7]);
//
//  if (kitu == 0) {
//
//    for (hello = 0; hello < 8; hello++) {
//      Serial.println(myNumbers[hello]);
//    }
//
//  }
//  kitu++;
//
KOKO();
int result=0;
result=Jimmy ( -2,-5);
Serial.println (result); 
  //  switch (VUP) {
  //    case 0:
  //    Serial.println("I lost my balloon");
  //    break;
  //    case 1023:
  //    Serial.println("I forgot to go to my ballet recital");
  //    break;
  //    case 505:
  //    Serial.println("I lost 505 dollars");
  //    break;
  //    default:
  //    Serial.println("my computer has 1000 errors");



}
int Jimmy (int i_like_it, int thing) {
  int it_is = 9;
  it_is =i_like_it*thing;
  return it_is;
}






void KOKO() {int hello = 0;
  int myNumbers[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
  //myNumbers[5] = 99;
  //Serial.println(myNumbers[0-7]);

  if (kitu == 0) {

    for (hello = 0; hello < 8; hello++) {
      Serial.println(myNumbers[hello]);
    }

  }
  kitu++;


}






/*
  Serial.print("UD");
  Serial.println(VUP);
  Serial.print(",");
  Serial.print("LR");
  Serial.print(VLR);
*/

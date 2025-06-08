//calculatorrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr

// Single digit
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

//Double digit
int ax = 23;
int bx = 25;
int cx = 27;
int dx = 29;
int ex = 31;
int fx = 33;
int gx = 35;

int p0 = 40;
int p1 = 41;
int p2 = 42;
int p3 = 43;
int p4 = 44;
int p5 = 45;
int p6 = 46;
int p7 = 47;


int p8 = 48;
int p9 = 49;

int pinplus = 14;
int pinminus = 15;
int pintimes = 16;
int pindivide = 17;
int pinC = 18; //this pin will clear everything
int pindelete = 19;

int pinenter = 53;

int var1 = -1;
int var2 = -1;
int operation = -1;
int result = -1;

int ten = 0;
int dig = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode (a, OUTPUT );
  pinMode (b, OUTPUT );
  pinMode (c, OUTPUT );
  pinMode (d, OUTPUT );
  pinMode (e, OUTPUT );
  pinMode (f, OUTPUT );
  pinMode (g, OUTPUT );

  pinMode (ax, OUTPUT );
  pinMode (bx, OUTPUT );
  pinMode (cx, OUTPUT );
  pinMode (dx, OUTPUT );
  pinMode (ex, OUTPUT );
  pinMode (fx, OUTPUT );
  pinMode (gx, OUTPUT );

  pinMode (p0, INPUT_PULLUP);
  pinMode (p1, INPUT_PULLUP);
  pinMode (p2, INPUT_PULLUP);
  pinMode (p3, INPUT_PULLUP);
  pinMode (p4, INPUT_PULLUP);
  pinMode (p5, INPUT_PULLUP);
  pinMode (p6, INPUT_PULLUP);
  pinMode (p7, INPUT_PULLUP);
  pinMode (p8, INPUT_PULLUP);
  pinMode (p9, INPUT_PULLUP);

  pinMode (pinplus, INPUT_PULLUP);
  pinMode (pinminus, INPUT_PULLUP);
  pinMode (pintimes, INPUT_PULLUP);
  pinMode (pindivide, INPUT_PULLUP);
  pinMode (pinC, INPUT_PULLUP);
  pinMode (pindelete, INPUT_PULLUP);

  pinMode (pinenter, INPUT_PULLUP);


}

void loop() {
  // put your main code here, to run repeatedly:

  int d0 = digitalRead(p0);
  if (d0 == LOW) {
    digit0();
    if (operation == -1) {
      var1 = 0;
    }
    else {
      var2 = 0;
    }
  }
  int d1 = digitalRead(p1);
  if (d1 == LOW) {
    digit1();
    if (operation == -1) {
      var1 = 1;
    }
    else {
      var2 = 1;
    }
  }
  int d2 = digitalRead(p2);
  if (d2 == LOW) {
    digit2();
    if (operation == -1) {
      var1 = 2;
    }
    else {
      var2 = 2;
    }
  }
  int d3 = digitalRead(p3);
  if (d3 == LOW) {
    digit3();
    if (operation == -1) {
      var1 = 3;
    }
    else {
      var2 = 3;
    }
  }
  int d4 = digitalRead(p4);
  if (d4 == LOW) {
    digit4();
    if (operation == -1) {
      var1 = 4;
    }
    else {
      var2 = 4;
    }
  }
  int d5 = digitalRead(p5);
  if (d5 == LOW) {
    digit5();
    if (operation == -1) {
      var1 = 5;
    }
    else {
      var2 = 5;
    }
  }
  int d6 = digitalRead(p6);
  if (d6 == LOW) {
    digit6();
    if (operation == -1) {
      var1 = 6;
    }
    else {
      var2 = 6;
    }
  }
  int d7 = digitalRead(p7);
  if (d7 == LOW) {
    digit7();
    if (operation == -1) {
      var1 = 7;
    }
    else {
      var2 = 7;
    }
  }
  int d8 = digitalRead(p8);
  if (d8 == LOW) {
    digit8();
    if (operation == -1) {
      var1 = 8;
    }
    else {
      var2 = 8;
    }
  }
  int d9 = digitalRead(p9);
  if (d9 == LOW) {
    digit9();
    if (operation == -1) {
      var1 = 9;
    }
    else {
      var2 = 9;
    }
  }

  // +
  int valplus = digitalRead(pinplus);
  if (valplus == LOW) {
    if ( var1 > -1) {
      operation  = 0;
    }
  }
  // -
  int valminus = digitalRead(pinminus);
  if (valminus == LOW) {
    if ( var1 > -1) {
      operation  = 1;
    }
  }
  // *
  int valtimes = digitalRead(pintimes);
  if (valtimes == LOW) {
    if (var1 > -1) {
      operation = 2;
    }
  }
  //÷
  int valdivide = digitalRead(pindivide);
  if (valdivide == LOW) {
    if (var1 > -1) {
      operation = 3;
    }
  }
  // clear
  int valC = digitalRead(pinC);
  if (valC == LOW) {
    var1 = -1;
    var2 = -1;
    operation = -1;
    result = -1;
    digitblank();
    tenblank();
  }
  // delete
  int valD = digitalRead(pindelete);
  if (valD == LOW) {
    dig = ten;
    tenblank();
    show_digitdig();
  }
  // =
  int valenter = digitalRead(pinenter);
  if (valenter == LOW) {
    if (operation == 0 && var1 > -1 && var2 > -1 ) {
      result = var1 + var2;
    }

    if (operation == 1 && var1 > -1 && var2 > -1 ) {
      result = var1 - var2;

    }

    if (operation == 2 && var1 > -1 && var2 > -1 ) {
      result = var1 * var2;

    }

    if (operation == 3 && var1 > -1 && var2 > -1 ) {
      result = var1 / var2;

    }
    if (result >= 100 or result <= -10) {
      digitR();
      digitE();
    }
    else {
      if (result < 0) {
        digitnegative();
        dig = result % 10;
        dig = abs(dig);
        show_digitdig();
        Serial.print ("digneg");
       Serial.println (dig);
      }
      else {
        Serial.println (result);


        ten = result / 10;
        dig = result % 10;

        Serial.println (ten);
        Serial.println (dig);


        show_digitdig();

        show_digitten();

        var1 = result;
        delay (500);
      }
    }
  }

}
void digitblank() {

  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);

}


void digitR() {

  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, LOW);
  digitalWrite (f, HIGH);
  digitalWrite (g, LOW);

}


void digit1() {

  digitalWrite (a, HIGH);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
}


void digit2() {

  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, HIGH);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, HIGH);
  digitalWrite (g, LOW);
}


void digit3() {

  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, LOW);
}


void digit4() {

  digitalWrite (a, HIGH);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}


void digit5() {

  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, HIGH);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}


void digit6() {

  digitalWrite (a, LOW);
  digitalWrite (b, HIGH);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}


void digit7() {

  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);
}


void digit8() {

  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}


void digit9() {

  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, HIGH);
  digitalWrite (f, LOW);
  digitalWrite (g, LOW);
}


void digit0() {

  digitalWrite (a, LOW);
  digitalWrite (b, LOW);
  digitalWrite (c, LOW);
  digitalWrite (d, LOW);
  digitalWrite (e, LOW);
  digitalWrite (f, LOW);
  digitalWrite (g, HIGH);
}



// double digit
void tenblank() {

  digitalWrite (ax, HIGH);
  digitalWrite (bx, HIGH);
  digitalWrite (cx, HIGH);
  digitalWrite (dx, HIGH);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, HIGH);
  digitalWrite (gx, HIGH);
}


void digitE() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, HIGH);
  digitalWrite (cx, HIGH);
  digitalWrite (dx, LOW);
  digitalWrite (ex, LOW);
  digitalWrite (fx, LOW);
  digitalWrite (gx, LOW);
}


void digit10() {

  digitalWrite (ax, HIGH);
  digitalWrite (bx, LOW);
  digitalWrite (cx, LOW);
  digitalWrite (dx, HIGH);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, HIGH);
  digitalWrite (gx, HIGH);
}


void digit20() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, LOW);
  digitalWrite (cx, HIGH);
  digitalWrite (dx, LOW);
  digitalWrite (ex, LOW);
  digitalWrite (fx, HIGH);
  digitalWrite (gx, LOW);
}


void digit30() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, LOW);
  digitalWrite (cx, LOW);
  digitalWrite (dx, LOW);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, HIGH);
  digitalWrite (gx, LOW);
}


void digit40() {

  digitalWrite (ax, HIGH);
  digitalWrite (bx, LOW);
  digitalWrite (cx, LOW);
  digitalWrite (dx, HIGH);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, LOW);
  digitalWrite (gx, LOW);
}


void digit50() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, HIGH);
  digitalWrite (cx, LOW);
  digitalWrite (dx, LOW);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, LOW);
  digitalWrite (gx, LOW);
}


void digit60() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, HIGH);
  digitalWrite (cx, LOW);
  digitalWrite (dx, LOW);
  digitalWrite (ex, LOW);
  digitalWrite (fx, LOW);
  digitalWrite (gx, LOW);
}


void digit70() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, LOW);
  digitalWrite (cx, LOW);
  digitalWrite (dx, HIGH);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, HIGH);
  digitalWrite (gx, HIGH);
}


void digit80() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, LOW);
  digitalWrite (cx, LOW);
  digitalWrite (dx, LOW);
  digitalWrite (ex, LOW);
  digitalWrite (fx, LOW);
  digitalWrite (gx, LOW);
}


void digit90() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, LOW);
  digitalWrite (cx, LOW);
  digitalWrite (dx, LOW);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, LOW);
  digitalWrite (gx, LOW);
}


void digit00() {

  digitalWrite (ax, LOW);
  digitalWrite (bx, LOW);
  digitalWrite (cx, LOW);
  digitalWrite (dx, LOW);
  digitalWrite (ex, LOW);
  digitalWrite (fx, LOW);
  digitalWrite (gx, HIGH);
}

void digitnegative() {

  digitalWrite (ax, HIGH);
  digitalWrite (bx, HIGH);
  digitalWrite (cx, HIGH);
  digitalWrite (dx, HIGH);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, HIGH);
  digitalWrite (gx, LOW);
}



//switch

void show_digitdig()
{

  switch (dig) {
    //      case -9:
    //        digit9();
    //        break;
    //      case -8:
    //        digit8()
    //        break;
    //      case -7:
    //        digit7();
    //        break;
    //      case -6:
    //        digit6();
    //        digitnegative();
    //        break;
    //      case -5:
    //        digit5();
    //        digitnegative();
    //        break;
    //      case -4:
    //        digit4();
    //        digitnegative();
    //        break;
    //      case -3:
    //        digit3();
    //        digitnegative();
    //        break;
    //      case -2:
    //        digit2();
    //        digitnegative();
    //        break;
    //      case -1:
    //        digit1();
    //        digitnegative();
    //        break;
    case 0:
      digit0();
      break;
    case 1:
      digit1();
      break;
    case 2:
      digit2();
      break;
    case 3:
      digit3();
      break;
    case 4:
      digit4();
      break;
    case 5:
      digit5();
      break;
    case 6:
      digit6();
      break;
    case 7:
      digit7();
      break;
    case 8:
      digit8();
      break;
    case 9:
      digit9();
      break;

  }
}



void show_digitten()
{

  switch (ten) {

    case 0:
      digit00();
      break;
    case 1:
      digit10();
      break;
    case 2:
      digit20();
      break;
    case 3:
      digit30();
      break;
    case 4:
      digit40();
      break;
    case 5:
      digit50();
      break;
    case 6:
      digit60();
      break;
    case 7:
      digit70();
      break;
    case 8:
      digit80();
      break;
    case 9:
      digit90();
      break;

  }
}


//
//          if (result > 9 && result < 20){
//      digit10();
//    }

//      case 10:
//        digit0();
//        digit10();
//        break;
//      case 11:
//        digit1();
//        digit10();
//        break;
//      case 18:
//        digit8();
//        digit10();
//     //   break;
//    }

//  int d9 = digitalRead(p9);
//  if (d9 == LOW) {
//    digit9();
//  }
//  int d9 = digitalRead(p9);
//  if (d9 == LOW) {
//    digit9();
//  }
//  int d9 = digitalRead(p9);
//  if (d9 == LOW) {
//    digit9();
//  }

//digit1();
//delay(500);
//digit2();
//delay(500);
//digit3();
//delay(500);
//digit4();
//delay(500);
//digit5();
//delay(500);
//digit6();
//delay(500);
//digit7();
//delay(500);
//digit8();
//delay(500);
//digit9();
//delay(500);
//digit0();
//delay(500);

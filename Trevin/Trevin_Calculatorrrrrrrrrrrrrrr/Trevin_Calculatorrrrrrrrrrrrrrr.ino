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
  // clear
  int valC = digitalRead(pinC);
  if (valC == LOW) {
    var1 = -1;
    var2 = -1;
    operation = -1;
    result = -1;
    digitblank();
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

    Serial.println (result);

    switch (result) {
      case -9:
        digit9();
        digitnegative();
        break;
      case -8:
        digit8();
        digitnegative();
        break;  
      case -7:
        digit7();
        digitnegative();
        break;
      case -6:
        digit6();
        digitnegative();
        break;
      case -5:
        digit5();
        digitnegative();
        break;
      case -4:
        digit4();
        digitnegative();
        break;
      case -3:
        digit3();
        digitnegative();
        break;
      case -2:
        digit2();
        digitnegative();
        break;
      case -1:
        digit1();
        digitnegative();
        break;
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


}
void digitblank() {

  digitalWrite (a, HIGH);
  digitalWrite (b, HIGH);
  digitalWrite (c, HIGH);
  digitalWrite (d, HIGH);
  digitalWrite (e, HIGH);
  digitalWrite (f, HIGH);
  digitalWrite (g, HIGH);

  digitalWrite (ax, HIGH);
  digitalWrite (bx, HIGH);
  digitalWrite (cx, HIGH);
  digitalWrite (dx, HIGH);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, HIGH);
  digitalWrite (gx, HIGH);
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

void digitnegative() {

  digitalWrite (ax, HIGH);
  digitalWrite (bx, HIGH);
  digitalWrite (cx, HIGH);
  digitalWrite (dx, HIGH);
  digitalWrite (ex, HIGH);
  digitalWrite (fx, HIGH);
  digitalWrite (gx, LOW);
}

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

const int xPin = 11;
const int yPin = 12;
const int xy_select = 13;
int selection = 0;

int mappedX = 0;
int mappedY = 0;

int d1e = 8;
int d1d = 7;
int d1c = 6;
int d1dp = 0;
int d1g = 2;
int d1f = 3;
int d1a = 4;
int d1b = 5;

int d1 = 9;
int d2 = 10;

int d1enable = 4;
int x = 0;

int units = 0;
int tens = 0;

int refresh = 2;

bool d1en = false;
bool d2en = false;

bool xy_state = false;
bool lastxystate = HIGH;
bool button_pressed = false;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d1e, OUTPUT);
  pinMode(d1d, OUTPUT);
  pinMode(d1c, OUTPUT);
  pinMode(d1dp, OUTPUT);
  pinMode(d1g, OUTPUT);
  pinMode(d1f, OUTPUT);
  pinMode(d1a, OUTPUT);
  pinMode(d1b, OUTPUT);
  pinMode(d1enable, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(xy_select, INPUT_PULLUP);
  digitalWrite(d1enable, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  selection = digitalRead(xy_select);

  if (selection != lastxystate) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (selection == LOW && !button_pressed) {
      xy_state = !xy_state;
      //Serial.print("State is now: ");
      //Serial.println(xy_state ? "ON" : "OFF");
      button_pressed = true;
    }

    if (selection == HIGH && button_pressed) {
      button_pressed = false;
    }
  }

  lastxystate = selection;
  
  int pulseX, pulseY;
  int accelerationX, accelerationY;
  pulseX = pulseIn(xPin, HIGH);
  pulseY = pulseIn(yPin, HIGH);
  accelerationX = ((pulseX / 10) - 500) * 8;
  accelerationY = ((pulseY / 10) - 500) * 8;

  mappedX = map(accelerationX, -999, 999, -90, 90);
  mappedY = map(accelerationY, -999, 999, -90, 90);

  if (xy_state == true) {
    x = mappedY;
    if (x < 0) {
      x = mappedY * -1;
    }
  }
  else {
    x = mappedX;
    if (x < 0) {
      x = mappedX * -1;
    }
  }

  units = x % 10;
  tens = (x / 10) % 10;

  digitalWrite(d1, LOW);
  d1_dis_tens();
  delay(refresh);
  digitalWrite(d1, HIGH);
  digitalWrite(d2, LOW);
  d2_dis_units();
  delay(refresh);
  digitalWrite(d2, HIGH);
}

void d1_dis_tens() {
  switch (tens) {
    case 0:
      d10();
      break;
    case 1:
      d11();
      break;
    case 2:
      d12();
      break;
    case 3:
      d13();
      break;
    case 4:
      d14();
      break;
    case 5:
      d15();
      break;
    case 6:
      d16();
      break;
    case 7:
      d17();
      break;
    case 8:
      d18();
      break;
    case 9:
      d19();
      break;
  }
}

void d2_dis_units() {
  switch (units) {
    case 0:
      d20();
      break;
    case 1:
      d21();
      break;
    case 2:
      d22();
      break;
    case 3:
      d23();
      break;
    case 4:
      d24();
      break;
    case 5:
      d25();
      break;
    case 6:
      d26();
      break;
    case 7:
      d27();
      break;
    case 8:
      d28();
      break;
    case 9:
      d29();
      break;
  }
}

void d1clear() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, LOW);
  digitalWrite(d1c, LOW);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, LOW);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, LOW);
  digitalWrite(d1b, LOW);
}

void d10() {
  digitalWrite(d1e, HIGH);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, LOW);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d11() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, LOW);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, LOW);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, LOW);
  digitalWrite(d1b, HIGH);
}

void d12() {
  digitalWrite(d1e, HIGH);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, LOW);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d13() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d14() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, LOW);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, LOW);
  digitalWrite(d1b, HIGH);
}

void d15() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, LOW);
}

void d16() {
  digitalWrite(d1e, HIGH);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, LOW);
}

void d17() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, LOW);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, LOW);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d18() {
  digitalWrite(d1e, HIGH);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d19() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d20() {
  digitalWrite(d1e, HIGH);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, LOW);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d21() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, LOW);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, LOW);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, LOW);
  digitalWrite(d1b, HIGH);
}

void d22() {
  digitalWrite(d1e, HIGH);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, LOW);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d23() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d24() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, LOW);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, LOW);
  digitalWrite(d1b, HIGH);
}

void d25() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, LOW);
}

void d26() {
  digitalWrite(d1e, HIGH);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, LOW);
}

void d27() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, LOW);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, LOW);
  digitalWrite(d1f, LOW);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d28() {
  digitalWrite(d1e, HIGH);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}

void d29() {
  digitalWrite(d1e, LOW);
  digitalWrite(d1d, HIGH);
  digitalWrite(d1c, HIGH);
  digitalWrite(d1dp, LOW);
  digitalWrite(d1g, HIGH);
  digitalWrite(d1f, HIGH);
  digitalWrite(d1a, HIGH);
  digitalWrite(d1b, HIGH);
}


// fengming is sigma
//PIN 
int joystickleft_updown = A3;
int joystickleft_leftright = A2; //up = 0
int joystickleft_button = 3;
int joystickright_updown = A4;
int joystickright_leftright = A5;
int joystickright_button = 7;
// for saving values
int joystickleft_updown_value = 0;
int joystickleft_leftright_value = 0;
int joystickleft_button_value = 0;
int joystickright_updown_value = 0;
int joystickright_leftright_value = 0;
int joystickright_button_value = 0;



void setup() {
                                                                                                                    // put your setup code here, to run once:
  pinMode(joystickleft_updown, INPUT);
  pinMode(joystickleft_leftright, INPUT);
  pinMode(joystickright_updown, INPUT);
  pinMode(joystickright_leftright, INPUT);
  pinMode(joystickleft_button, INPUT);
  pinMode(joystickright_button, INPUT);

  
  Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:
  joystickleft_updown_value = analogRead(joystickleft_updown);
  Serial.print("Left - updown = ");
  Serial.println(joystickleft_updown_value);
  joystickleft_leftright_value = analogRead(joystickleft_leftright);
  Serial.print("Left - leftright = ");
  Serial.println(joystickleft_leftright_value);
  joystickleft_button_value = digitalRead(joystickleft_button);
  Serial.print("Left - button = ");
  Serial.println(joystickleft_button_value);
  
  
    joystickright_updown_value = analogRead(joystickright_updown);
  Serial.print("right - updown = ");
  Serial.println(joystickright_updown_value);
  joystickright_leftright_value = analogRead(joystickright_leftright);
  Serial.print("right - leftright = ");
  Serial.println(joystickright_leftright_value);
  joystickright_button_value = digitalRead(joystickright_button);
  Serial.print("right - button = ");
  Serial.println(joystickright_button_value);

  Serial.println("1");
}

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
// fengming is sigma
//PIN 
int joystickleft_updown = A3;
int joystickleft_leftright = A2; //up = 0
int joystickleft_button = 3;
int joystickright_updown = A4;
int joystickright_leftright = A5;
int joystickright_button = 6;
// for saving values
int joystickleft_updown_value = 0;
int joystickleft_leftright_value = 0;
int joystickleft_button_value = 0;
int joystickright_updown_value = 0;
int joystickright_leftright_value = 0;
int joystickright_button_value = 0;
// we are going to concatenate all of this information as one whole package.
// ID + L + R + S
// FM + 0 + 0 + 0
String message_to_remote_controller = "FM000";
String message_left_joystick = "0"; 
String message_right_joystick = "0";
String message_shooting_button = "0";
String message_ID = "FM";  
//message_to_remote_controller = "FM000";//message_ID + message_left_joystick + message_right_joystick + message_shooting_button;     
void setup() {
                                                                                                                    // put your setup code here, to run once:
  pinMode(joystickleft_updown, INPUT);
  pinMode(joystickleft_leftright, INPUT);
  pinMode(joystickright_updown, INPUT);
  pinMode(joystickright_leftright, INPUT);
  pinMode(joystickleft_button, INPUT_PULLUP);
  pinMode(joystickright_button, INPUT_PULLUP);

   // Initialize ASK Object
    rf_driver.init();
  
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
  Serial.println(message_to_remote_controller);

//  L   R   S
//  --------------------
//  up  x   x     FMF00
//  ba  x   x     FMB00

  
  if (joystickleft_updown_value == 0) {
     message_left_joystick = "F";
    }
  else if (joystickleft_updown_value == 1023) {
    message_left_joystick = "B";
    }
   else if (joystickleft_leftright_value ==  1023) {
    message_left_joystick = "L";
    }
  else if (joystickleft_leftright_value == 0) {
    message_left_joystick = "R";
    }
   else {
    message_left_joystick = "0";
    }


  // RIGHT JOYSTICK
  //===========================================================
  // sigma   
  if (joystickright_updown_value == 0) {
     message_right_joystick = "F";
    }
  else if (joystickright_updown_value == 1023) {
    message_right_joystick = "B";
    }
   else if (joystickright_leftright_value ==  1023) {
    message_right_joystick = "L";
    }
  else if (joystickright_leftright_value == 0) {
    message_right_joystick = "R";
    }
   else {
    message_right_joystick = "0";
    }



 if (joystickright_button_value == 0) {
     message_shooting_button = "S";
    }
  else if (joystickleft_button_value == 0) {
    message_shooting_button = "S";
    }
   else {
    message_shooting_button = "0";
    }
String result = message_ID + message_left_joystick + message_right_joystick + message_shooting_button;
Serial.println(result);



const char *msg = result.c_str() ;
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1);
    
}

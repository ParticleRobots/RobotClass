#include <SoftwareSerial.h>

SoftwareSerial xbeeSerial(10, 11); //RX, TX

const byte numAngles = 8;
byte angles[numAngles];

bool receiving = false;
byte index = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xbeeSerial.begin(9600);
  Serial.println("Ready to receive");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (xbeeSerial.available()) {
    char incoming = xbeeSerial.read();

    if (incoming == '<') {
      receiving = true;
      index = 0;
    }
    else if (incoming == '>' && receiving) {
      receiving = false;
      Serial.print("Received angles: ");
      for (int i = 0; i < numAngles; i++) {
        Serial.print(angles[i]);
        if (i <numAngles - 1) Serial.print(", ");
        
        xbeeSerial.write('A');
      }
      Serial.println();
    }
        else if (receiving && index < numAngles) {
      angles[index++] = (byte)incoming;
    }
  }
}

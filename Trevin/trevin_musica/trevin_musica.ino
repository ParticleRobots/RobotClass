//trevin lalala, play music

#include "pitches.h"

//notes in melody
int melody[] = {
  NOTE_G4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_G3, NOTE_G3, NOTE_B3, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 8, 8, 8, 8, 4, 4
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 11; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(8);
  }
}

void loop() {

  // no need to repeat the melody.
}

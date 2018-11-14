/* Output pin */
#define PIN 13
/* Change to 2 for a slower version of the song, the bigger the number the slower the song */
#define SPEED 1.3
/* Defining note frequency */
#define C4  262
#define D4  294
#define E4  330
#define F4  349
#define G4  392
#define A4  440
#define B4  494
#define C5  523
#define D5  587
#define E5  659
#define F5  698
#define G5  784
#define A5  880
#define B5  988
/* Note of the song, 0 is a rest/pulse */
const int notes[] = {
  E4, G4, A4, A4, 0,
  A4, B4, C5, C5, 0,
  C5, D5, B4, B4, 0,
  A4, G4, A4, 0,

  E4, G4, A4, A4, 0,
  A4, B4, C5, C5, 0,
  C5, D5, B4, B4, 0,
  A4, G4, A4, 0,

  E4, G4, A4, A4, 0,
  A4, C5, D5, D5, 0,
  D5, E5, F5, F5, 0,
  E5, D5, E5, A4, 0,

  A4, B4, C5, C5, 0,
  D5, E5, A4, 0,
  A4, C5, B4, B4, 0,
  C5, A4, B4, 0,

  A4, A4,
  /* Repeat of first part */
  A4, B4, C5, C5, 0,
  C5, D5, B4, B4, 0,
  A4, G4, A4, 0,

  E4, G4, A4, A4, 0,
  A4, B4, C5, C5, 0,
  C5, D5, B4, B4, 0,
  A4, G4, A4, 0,

  E4, G4, A4, A4, 0,
  A4, C5, D5, D5, 0,
  D5, E5, F5, F5, 0,
  E5, D5, E5, A4, 0,

  A4, B4, C5, C5, 0,
  D5, E5, A4, 0,
  A4, C5, B4, B4, 0,
  C5, A4, B4, 0,
  /* End of Repeat */

  E5, 0, 0, F5, 0, 0,
  E5, E5, 0, G5, 0, E5, D5, 0, 0,
  D5, 0, 0, C5, 0, 0,
  B4, C5, 0, B4, 0, A4,

  E5, 0, 0, F5, 0, 0,
  E5, E5, 0, G5, 0, E5, D5, 0, 0,
  D5, 0, 0, C5, 0, 0,
  B4, C5, 0, B4, 0, A4
};
/* duration of each note (in ms) Quarter Note is set to 250 ms */
const int durations[] = {
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125,
  250, 125, 250, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 375,

  250, 125,
  //Rpeat of First Part
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 125,

  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 250, 125, 125,
  125, 125, 125, 250, 125,

  125, 125, 250, 125, 125,
  250, 125, 250, 125,
  125, 125, 250, 125, 125,
  125, 125, 375, 375,
  //End of Repeat

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500,

  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 125, 125, 125, 375,
  250, 125, 375, 250, 125, 375,
  125, 125, 125, 125, 125, 500
};

void setup() {
  Serial.begin(9600);
  for (int x = 0; x < 203; x++) {       /* 203 is the total number of music notes in the song */
    int wait = durations[x] * SPEED;
    tone(PIN, notes[x], wait);        /* tone(pin,frequency,duration) */
    Serial.write("Notes : ");
    Serial.println(notes[x]);
    Serial.write("Times : ");
    Serial.println(wait);
    delay(wait);
  }                        /* delay is used so it doesn't go to the next loop before tone is finished playing */
}

void loop() {

}

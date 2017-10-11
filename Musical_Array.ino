// Musical Arpeggio: ii V I Progression

int noteC = 523;
int noteD = 587;
int noteE = 659;
int noteF = 699;
int noteG = 784;
int noteA = 880;
int noteB = 988;
int noteChigh = 1047;
int noteDhigh = 1175;
int noteEhigh = 1319;
int noteFhigh = 1397;

int dMinor[] = {noteD, noteF, noteA, noteChigh};
int gSeven[] = {noteG, noteB, noteDhigh, noteFhigh};
int cMaj[] = {noteC, noteE, noteG, noteB};

int wholeNote = 1000;
int halfNote = 500;
int quartNote = 250;
int dotHalf = 750;
int dotQuart = 375;
int extraWhole = 1250;
int eightNote = 125;
int fiveBeats = 1250;
int fourAndHalfBeats = 1125;

int outPin = 4;
int noteLength = 500;
int restLength = 500;

int melody[] = {noteD, noteF, noteA, noteF, noteD, noteChigh, noteF,
                noteG, noteB, noteDhigh, noteB, noteG, noteFhigh, noteB,
                noteC, noteE, noteG, noteE, noteC, noteB, noteE,
                noteC, noteE, noteG, noteE, noteC, noteB, noteE};
                
int durations[] = {quartNote, quartNote, quartNote, eightNote, eightNote, halfNote, halfNote, 
                   quartNote, quartNote, quartNote, eightNote, eightNote, halfNote, halfNote, 
                   quartNote, quartNote, quartNote, eightNote, eightNote, halfNote, halfNote, 
                   quartNote, quartNote, quartNote, eightNote, eightNote, halfNote, halfNote}; 

void setup() {
}

void loop() {
  playSequence();
  noTone(outPin);
  delay(2000);
  chordDminor();
  chordG7();
  chordCmaj();
  chordCmaj();
  noTone(outPin);
  delay(5000); 
}

void playSequence() {
  for (int i = 0; i < 28; i++)
  {
    playNoteAndBeat(melody[i], durations[i]);
  }
}

void playNoteAndBeat(int pitch, int beat) {
  tone(outPin, pitch);
  delay(beat);
  
  
}

void chordDminor() {
  for (int i = 0; i < 4; i++)
  {
    playNote(dMinor[i]);
  }  
}

void chordG7() {
  for (int i = 0; i < 4; i++)
  {
    playNote(gSeven[i]);
  }  
}

void chordCmaj() {
  for (int i = 0; i < 4; i++)
  {
    playNote(cMaj[i]);
  }  
}

void playNote(int note) {
  tone(outPin, note);
  delay(noteLength);
  noTone(outPin);  
  delay(restLength);
}

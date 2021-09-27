// ISR flags
volatile bool flagIncreasePulseCount = false;

const int PROX_AUGER_1_PIN = 2;
unsigned short pulsecount = 0;

void setupProximity() {
    /** !! INPUT proximity switches IF LOW detection = TRUE */
  // set pin mode
  pinMode(PROX_AUGER_1_PIN, INPUT_PULLUP);

  // ATTACH INTERRUPT EVENTS
  attachInterrupt(digitalPinToInterrupt(PROX_AUGER_1_PIN), PROX_AUGER_1_ISR, CHANGE);
}

void PROX_AUGER_1_ISR() {
  pulsecount++;
  Serial.println(pulsecount);
}

void proximityLoop() {
}

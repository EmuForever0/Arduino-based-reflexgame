const int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12, 13}; // the LED pin numbers
const int buttonPin = 2; // BUTTON PIN
const int buzzerPin = 0; // BUZZER PIN

int sequenceLength = 9; 
bool gameRunning = false;
unsigned long timer;

// Sound
void setup() {
  for (int i = 0; i < sequenceLength; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (!gameRunning) {
    startGame();
  } else {
    if (millis() - timer >= 1000) { 
      gameRunning = false;
      checkResult();
    }
  }
}

void startGame() {
  gameRunning = true;
  timer = millis();
 
  for (int i = 0; i < sequenceLength; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200); 
    digitalWrite(ledPins[i], LOW);
  }

  
  digitalWrite(ledPins[8], HIGH);
}

void checkResult() {
  if (digitalRead(buttonPin) == LOW) {
    
    victorySound();
  } else {
    
    loseSound();
  }
  
  for (int i = 0; i < sequenceLength; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void victorySound() {
  tone(buzzerPin, 1000, 500); // Victory chime
  delay(500);
}

void loseSound() {
  tone(buzzerPin, 500, 500); // Defeat/Loss sound  || | || |_
  delay(500);
}

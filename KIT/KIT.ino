int currentLED = 6;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(currentLED, HIGH);
  delay(100);      
  digitalWrite(currentLED, LOW);

  if(currentLED == 13) { 
    currentLED = 6;
  }
  else{
    ++currentLED;
  }
}

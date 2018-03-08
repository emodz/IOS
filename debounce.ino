
const int ledPin = 13; 
const int buttonPin = 2; 
bool buttonState = LOW; //if button is not pressed state is low
bool ledState = -1; //if negative led off
long lastDebounce = 0;  // the last time led was on
long debounceDelay = 50;  //if the led flickers debounce time increases by 50 
 
 
void setup() {// assign outputs and inputs
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
 
void loop() {
  buttonState = digitalRead(buttonPin);
 
  //create delay
  if ( (millis() - lastDebounce) > debounceDelay) {
 
    //press button
    if ( (buttonState == HIGH) && (ledState < 0) ) {
      digitalWrite(ledPin, HIGH); //turn LED on
      ledState = HIGH; //state on
      lastDebounce = millis(); //set time
    }
    else if ( (buttonState == HIGH) && (ledState > 0) ) {
      digitalWrite(ledPin, LOW); //turn LED off
      ledState = LOW; //state off
      lastDebounce = millis(); //set time
    }
  }
 
}

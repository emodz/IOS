// Confetti Cannon 
// Eric Modzelewski
int startPin = 2; //Start button
int stopPin = 3; //Stop button 
int greenPin = 6;//green led 
int redPin = 7; //red led 
int motorPin = 9; //motor 
int startStatus = 0; //start status  
int stopStatus = 0; //stop status

void setup() { 
Serial.begin(9600);
pinMode(motorPin, OUTPUT); //sets motor as an output
pinMode(greenPin, OUTPUT); // sets led as output
pinMode(redPin, OUTPUT);
pinMode(startPin, INPUT); // sets the button as input
pinMode(stopPin, INPUT); 

} 

void loop() { //loop to check device status 
//Check on/off status
startStatus = digitalRead(startPin); 
stopStatus = digitalRead(stopPin);

if (startStatus == HIGH && stopStatus == LOW) { // if start button is pressed
digitalWrite(greenPin, HIGH); //turn the green led onn
digitalWrite(redPin, LOW); } //turn red led off
digitalWrite(motorPin, HIGH);// turn the motor on 
Serial.println("Device on"); // prints that device is on

if (startStatus == LOW && stopStatus == HIGH) { // if stop button pressed 
digitalWrite(greenPin, LOW); //turn the green led off
digitalWrite(redPin, HIGH); //turn the red led on
digitalWrite(motorPin, LOW); // turn the motor OFF 
Serial.println("Device off"); // prints that device is off
} 
}


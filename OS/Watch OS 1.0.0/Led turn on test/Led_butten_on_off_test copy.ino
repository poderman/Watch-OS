const int  buttonPin = 3;    // the pin that the pushbutton is attached to
const int ledPin = 1;       // the pin that the LED is attached to
// Variables will change:
int counter = 1;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}
void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // went from off to on:
      counter++;
      Serial.println(counter);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state for next time through the loop
  lastButtonState = buttonState;
  // turns on the LED after two button pushes
  if (counter >= 3) {
    digitalWrite(ledPin, HIGH);
    counter = 0;
  }
  // turns off the LED after one button pushes
  else if (counter == 1){
    digitalWrite(ledPin, LOW);
  }
}

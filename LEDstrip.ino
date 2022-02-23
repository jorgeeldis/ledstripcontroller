const int green = 13; //Green LED Strip
const int blue = 12; //Blue LED Strip
const int BLUEledPin =  11; //Blue LED Pin
const int REDledPin =  10; //Red LED Pin
const int GREENledPin =  9; //Green LED Pin
const int red = 8; //Red LED Strip
const int buttonPinRed = 7; // the number of the pushbutton pin
const int buttonPinBlue = 6; // the number of the pushbutton pin
const int buttonPinGreen = 5; // the number of the pushbutton pin

int buttonStateRed = 0; // variable for reading the pushbutton status
int buttonStateBlue = 0; // variable for reading the pushbutton status
int buttonStateGreen = 0; // variable for reading the pushbutton status
int color=0; //Initial State of Color

void setup() {
    // initialize the LED pin as an output:
  pinMode(BLUEledPin, OUTPUT);  
  pinMode(REDledPin, OUTPUT);
  pinMode(GREENledPin, OUTPUT);

    // initialize the LED pin as an output:
  pinMode(red, OUTPUT);  
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinRed, INPUT);     
  digitalWrite(buttonPinRed, HIGH); //Activate internal pull up for switch

   pinMode(buttonPinBlue, INPUT);     
  digitalWrite(buttonPinBlue, HIGH); //Activate internal pull up for switch

   pinMode(buttonPinGreen, INPUT);     
  digitalWrite(buttonPinGreen, HIGH); //Activate internal pull up for switch
}

void loop() {

   // read the state of the pushbutton value:
  buttonStateRed = digitalRead(buttonPinRed);
  buttonStateBlue = digitalRead(buttonPinBlue);
  buttonStateGreen = digitalRead(buttonPinGreen);

  if (buttonStateRed == LOW && buttonStateBlue == HIGH && buttonStateGreen == HIGH) {     
    SetColor(255, 0, 0);
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
  }
  if (buttonStateRed == LOW && buttonStateBlue == LOW && buttonStateGreen == HIGH) {     
    SetColor(255, 0, 255);
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
  }
  if (buttonStateRed == LOW && buttonStateBlue == LOW && buttonStateGreen == LOW) {     
    SetColor(255, 255, 255);
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
  }
  if (buttonStateRed == HIGH && buttonStateBlue == LOW && buttonStateGreen == LOW) {     
    SetColor(0, 255, 255);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }
  if (buttonStateRed == HIGH && buttonStateBlue == HIGH && buttonStateGreen == LOW) {     
    SetColor(0, 255, 0);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
  }
   if (buttonStateRed == HIGH && buttonStateBlue == HIGH && buttonStateGreen == HIGH) {     
    SetColor(0, 0, 0);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
  }
   if (buttonStateRed == HIGH && buttonStateBlue == LOW && buttonStateGreen == HIGH) {     
    SetColor(0, 0, 255);
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
  }
  if (buttonStateRed == LOW && buttonStateBlue == HIGH && buttonStateGreen == LOW) {     
    SetColor(255, 255, 0);
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
  }
}

void SetColor(char R,char G,char B)
{
  analogWrite(REDledPin,R);
  analogWrite(GREENledPin,G);
  analogWrite(BLUEledPin,B);  
}

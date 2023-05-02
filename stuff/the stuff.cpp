// constants won't change. They're used here to set pin numbers:
const int buttonPin = 3;  // the number of the pushbutton pin

// variables will change:
int buttonState;  // variable for reading the pushbutton status
long randNumber;

void setup() {
  pinMode(buttonPin, INPUT);  // initialize the pushbutton pin as an input
  Serial.begin(9600);
  Serial.println("Fortune Teller Program");

  // Seed the random number generator
  randomSeed(analogRead(0));
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    int fortune = random(8); // Generate a random number from 0 to 7
    switch (fortune) {
      case 0:
        Serial.println("You will have a great day tomorrow!");
        break;
      case 1:
        Serial.println("You will find a new opportunity soon!");
        break;
      case 2:
        Serial.println("You will make a new friend this week!");
        break;
      case 3:
        Serial.println("You will receive good news in the mail!");
        break;
      case 4:
        Serial.println("You will find a small amount of money!");
        break;
      case 5:
        Serial.println("You will learn something new today!");
        break;
      case 6:
        Serial.println("You will have a chance to help someone in need!");
        break;
      case 7:
        Serial.println("You will have a relaxing weekend!");
        break;
      default:
        Serial.println("Error: Invalid fortune number generated");
        break;
    }
  }
  delay(100); // Wait a short amount of time before checking the button again
}

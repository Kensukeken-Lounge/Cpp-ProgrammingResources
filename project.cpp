// Define constants and variables
const int POT_PIN = A0;
const int LED_PIN_1 = 2;
const int LED_PIN_2 = 3;
const int LED_PIN_3 = 4;
int accessCode = 1234;
int potValue;
float voltage;

void setup() {
  // Set up serial communication
  Serial.begin(9600);
  // Set up LED pins as outputs
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
}

void loop() {
  // Request access code from user
  Serial.print("Please enter the access code: ");
  while (Serial.available() == 0) {
    // Wait for user input
  }
  int input = Serial.parseInt();
  if (input != accessCode) {
    // Incorrect access code, lock user out
    Serial.println("Access denied");
    return;
  }
  // Read potentiometer value
  potValue = analogRead(POT_PIN);
  // Convert potentiometer value to voltage
  voltage = potValue * 5.0 / 1023.0;
  // Display potentiometer value and voltage on serial monitor
  Serial.print("Potentiometer value: ");
  Serial.print(potValue);
  Serial.print("  Voltage: ");
  Serial.println(voltage);
  // Turn off all LEDs if potentiometer value is zero
  if (voltage == 0.0) {
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    Serial.println("Off");
  }
  // Turn on one LED if potentiometer value is between 0 and 1
  else if (voltage > 0.0 && voltage <= 1.0) {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    Serial.println("Warming Up");
  }
  // Turn on two LEDs if potentiometer value is between 1 and 2
  else if (voltage > 1.0 && voltage <= 2.0) {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, LOW);
    Serial.println("Low");
  }
  // Turn on three LEDs if potentiometer value is between 2 and 3
  else if (voltage > 2.0 && voltage <= 3.0) {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    Serial.println("Medium");
  }
  // Turn on three LEDs if potentiometer value is between 3 and 4
  else if (voltage > 3.0 && voltage <= 4.0) {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    Serial.println("High");
  }
  // Potentiometer value is out of range
  else {
    Serial.println("Potentiometer value out of range");
  }
  // Wait for a short time before checking the potentiometer again
  delay(100);
}

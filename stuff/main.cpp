int const pot A0;
int analogIntValue;
float analogVoltsValue;
int pinNumber = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pinNumber, OUTPUT);
}

void loop() {
  // Read analog value and convert to volts
  analogIntValue = analogRead(pot A0);
  analogVoltsValue = analogIntValue * (5.0 / 1024.0);

  // Print analog value in volts
  Serial.print("0 to 5V VALUE = ");
  Serial.println(analogVoltsValue, 3);

  // Set pin to high and wait 1 second
  digitalWrite(pinNumber, HIGH);
  delay(1000);

  // Set pin to low and wait 1 second
  digitalWrite(pinNumber, LOW);
  delay(1000);

  // Read analog value again and use it to set the value of num
  analogIntValue = analogRead(pot A0);
  num = analogIntValue - 512;

  // Use num to determine what to print
  if (num == 0) {
    Serial.println("off");
  } else if (num > 0) {
    Serial.println("Warming Up");
  } else if (num < 0) {
    Serial.println("Low");
  }

  delay(1000);
}

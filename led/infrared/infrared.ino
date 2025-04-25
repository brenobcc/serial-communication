const int digitalPin = 8;
const int analogPin = A0;

void setup() {
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

int digitalValue, analogValue;

void loop() {
  digitalValue = digitalRead(digitalPin);
  analogValue = analogRead(analogPin);

  Serial.print("Digital (D0): ");
  Serial.print(digitalValue);
  Serial.print("  |  Analog (A0): ");
  Serial.println(analogValue);

  delay(1000);
}

// Definindo os pinos do sensor
const int trigPin = 8;
const int echoPin = 9;

char command;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

double getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  
  return duration * 0.0343 / 2;
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    if (command == 'D') {
      double distance = getDistance();
      Serial.println(distance);
    }
  }
}

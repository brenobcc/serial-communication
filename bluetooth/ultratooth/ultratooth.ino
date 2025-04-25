const int trigPin = 8;
const int echoPin = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  delay(1000);
  Serial.println("Aguardando comandos...");
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
  if (Serial.available()) {
    char command = Serial.read();

    // Ignora caracteres de quebra de linha ou retorno de carro
    if (command == '\n' || command == '\r') return;

    Serial.print("Comando recebido: ");
    Serial.println(command);

    if (command == 'L') {
      Serial.println("Ligando LED...");
      // digitalWrite(ledPin, HIGH);
    } else if (command == 'D') {
      double distance = getDistance();
      Serial.print(distance);
      Serial.print(" cm\n");
    }
  }
}

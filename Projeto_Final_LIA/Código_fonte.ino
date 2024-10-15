#include <Servo.h>

Servo meuServo;
const int trigPin = 8;
const int echoPin = 7;

void setup() {
  meuServo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duracao, distancia;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);
  distancia = (duracao * 0.034) / 2;

  if (distancia < 20) { // Distância em cm
    meuServo.write(90); // Abre o portão
    delay(2000); // Mantém aberto por 2 segundos
    meuServo.write(0); // Fecha o portão
  }

  delay(500);
}

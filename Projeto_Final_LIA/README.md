# README - Portão Automático com Arduino UNO e Servo Motor

## Descrição do Projeto

Este projeto consiste em um portão automático que utiliza um Arduino UNO e um servo motor para abrir e fechar de forma automatizada. É uma solução ideal para controle de acesso em residências e empresas, proporcionando segurança e comodidade.

## Objetivos

- Desenvolver um sistema de portão automático controlado por um Arduino.
- Aprender sobre o funcionamento de servo motores e sensores.
- Implementar um projeto prático de automação.

## Componentes Necessários

- 1 x Arduino UNO
- 1 x Servo motor (adequado para o peso e tamanho do portão)
- 1 x Fonte de alimentação para o servo motor
- 1 x Sensor de distância (ex: HC-SR04) ou botão de acionamento
- Fios de conexão
- Protoboard (opcional, para facilitar as conexões)
- Estrutura do portão (pode ser feita de madeira, metal ou outro material)

## Diagrama de Conexões

<img src="https://github.com/nicolasspezia/Nicolas/blob/main/Projeto_Final_LIA/Captura%20de%20tela%202024-10-15%20092759.png" alt="Descrição" style="transform: rotate(90deg);" width="400"/>

### Conexões

- **Sensor de Distância (HC-SR04)**:
  - VCC -> 5V no Arduino
  - GND -> GND no Arduino
  - Echo -> Pino digital (ex: 7)
  - Trigger -> Pino digital (ex: 8)

- **Servo Motor**:
  - VCC -> Fonte de alimentação (5-6V)
  - GND -> GND no Arduino e na fonte
  - Sinal -> Pino PWM no Arduino (ex: 9)

## Código Fonte

```cpp
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
```

## Instruções de Montagem

1. **Construção do Portão**: Monte a estrutura do portão com o material de sua escolha.
2. **Instalação do Servo**: Fixe o servo motor na parte do portão que irá realizar o movimento de abertura e fechamento.
3. **Realização das Conexões**: Siga o diagrama de conexões e conecte todos os componentes ao Arduino.
4. **Upload do Código**: Transfira o código acima para o Arduino utilizando a IDE do Arduino.

## Testes e Calibrações

- Verifique se o servo motor está corretamente fixado ao portão.
- Teste o sensor de distância para garantir que está funcionando e detectando a presença.
- Ajuste os ângulos no código conforme necessário para que o portão abra e feche corretamente.

## Conclusão

Este projeto demonstra a viabilidade de um portão automático simples e eficaz utilizando Arduino. Você pode expandir e modificar o projeto para incluir recursos adicionais, como controle remoto, conectividade Wi-Fi ou integração com sistemas de segurança.

## Licença

Este projeto é de código aberto. Sinta-se à vontade para usar, modificar e compartilhar conforme necessário. Agradecemos se você puder dar créditos ao autor original.

---


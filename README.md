# Nicolas
Projeto Arduino CEFET-MG

---
# Portão de Garagem Automático com Arduino Uno

## Descrição

Este projeto utiliza um Arduino Uno para controlar a abertura automática de um portão de garagem com base na proximidade de um veículo. O sistema é equipado com um sensor de proximidade que detecta quando um veículo se aproxima e aciona o portão para abrir. Um módulo buzzer emite um som de alerta quando a aproximação é detectada.

## Componentes Necessários

- **Arduino Uno**: Placa de microcontrolador para programação e controle do portão.
- **Servo Motor ou Motor de Passo**: Para abrir e fechar o portão.
- **Sensor de Proximidade (Ultrassônico ou Infravermelho)**: Para detectar a presença de um veículo.
- **Módulo Buzzer**: Para emitir um som de alerta.
- **Fonte de Alimentação**: Para fornecer energia ao Arduino e ao motor.
- **Transistor/MOSFET**: Para controlar o motor (se necessário).
- **Resistores, Diodos e Cabos**: Para circuitos e conexões.

## Esquema de Montagem

1. **Conecte o Motor ao Arduino**:
   - Para um servo motor, conecte o pino de controle ao pino de saída digital do Arduino. Para um motor de passo, utilize um driver apropriado e conecte ao Arduino via transistor ou MOSFET.

2. **Instale o Sensor de Proximidade**:
   - Conecte o sensor de proximidade ao pino de entrada digital do Arduino.

3. **Configure o Módulo Buzzer**:
   - Conecte o buzzer ao pino de saída digital do Arduino.

## Código Arduino

```cpp
// Definir pinos
const int motorPin = 9; // Pino para controle do servo motor ou motor de passo
const int buzzerPin = 8; // Pino para o buzzer
const int sensorPin = 7; // Pino para o sensor de proximidade

// Definir a distância mínima para abrir o portão (em cm)
const int aberturaDistancia = 20;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600); // Inicializa comunicação serial para debug
}

void loop() {
  // Ler o valor do sensor de proximidade
  int sensorValue = digitalRead(sensorPin);
  
  // Verificar se o sensor detecta a aproximação
  if (sensorValue == HIGH) {
    digitalWrite(motorPin, HIGH); // Ativa o motor para abrir o portão
    tone(buzzerPin, 1000); // Emite um som de 1000 Hz
  } else {
    digitalWrite(motorPin, LOW); // Desativa o motor quando não há proximidade
    noTone(buzzerPin); // Desliga o som
  }

  // Para fins de depuração, imprimir o valor do sensor
  Serial.println(sensorValue);
  delay(100); // Atraso para estabilização
}
```

## Instruções de Uso

1. **Montagem**: Conecte todos os componentes conforme o esquema de montagem. Assegure-se de que as conexões estejam corretas e seguras.
2. **Programação**: Carregue o código para o Arduino Uno usando a IDE Arduino.
3. **Ajustes do Sensor**: Configure o sensor de proximidade para que detecte a distância desejada para a abertura do portão. Certifique-se de que o sensor está posicionado de forma adequada para detectar a aproximação do veículo.
4. **Teste**: Teste o sistema para garantir que o portão abra corretamente quando o veículo se aproxima e que o buzzer emita o som conforme esperado.

## Notas

- **Segurança**: Garanta que todas as conexões elétricas estejam isoladas e seguras para evitar riscos de curto-circuito.
- **Calibração**: Ajuste o posicionamento do sensor de proximidade e a distância mínima de detecção para atender às suas necessidades específicas.
- **Manutenção**: Verifique periodicamente o funcionamento dos componentes e faça a manutenção quando necessário.

## Licença

Este projeto é fornecido sob a [Licença MIT](LICENSE).

---

Se precisar de mais informações ou ajustes adicionais, estou aqui para ajudar!

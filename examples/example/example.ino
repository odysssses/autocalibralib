#include <autocalibralib.h>
#include <EEPROM.h>

LineSensor sensorL(A3, 3);  // Sensor esquerdo com LED no pino 3
LineSensor sensorR(A1, 4); // Sensor direito com LED no pino 4

void setup() {
  Serial.begin(9600);
  
  Serial.println("Calibrando sensores...");
  Serial.println("Coloque o sensor ESQUERDO sobre a linha preta");
  delay(3000);
  sensorL.calibrate();
  
  Serial.println("Coloque o sensor DIREITO sobre a linha preta");
  delay(3000);
  sensorR.calibrate();
  
  Serial.println("Calibracao concluida!");

  EEPROM.write(0, sensorL.getThreshold());
  EEPROM.write(1, sensorR.getThreshold());
  
  Serial.print("Limiar esquerdo: "); Serial.println(sensorL.getThreshold());
  Serial.print("Limiar direito: "); Serial.println(sensorR.getThreshold());
}

void loop() {
  // Lê os sensores
  bool leftBlack = sensorL.isBlack();
  bool rightBlack = sensorR.isBlack();
  
  // Exibe os valores no monitor serial
  Serial.print("Esquerdo: ");
  Serial.print(leftBlack ? "PRETO" : "BRANCO");
  Serial.print(" (");
  Serial.print(sensorL.read());
  Serial.print(") | Direito: ");
  Serial.print(rightBlack ? "PRETO" : "BRANCO");
  Serial.print(" (");
  Serial.print(sensorR.read());
  Serial.println(")");
  
  delay(200); // Pequeno atraso para facilitar a leitura
}

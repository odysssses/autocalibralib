#include <autocalibralib.h>
#include <EEPROM2byte.h>

EEPROM2byte eeprom;

//Como o EEPROM, para armazenar valores maiores que 255, precisa de 2 bytes, os endereços tem de serem espaçados em ao menos 1
#define address1 1
#define address2 3
#define address3 5
#define address4 7

LineSensor sensE(A0, -1);
LineSensor sensD(A1, -1);
LineSensor sensE_ext(A2, -1);
LineSensor sensD_ext(A3, -1);

void setup() {
  Serial.begin(9600);
  
  Serial.println("Calibrando sensores...");
  
  Serial.println("Coloque o sensor ESQUERDO sobre a linha preta");
  delay(8000);
  sensE.setThreshold(sensE.read());
  
  Serial.println("Coloque o sensor DIREITO sobre a linha preta");
  delay(6000);
  sensD.setThreshold(sensD.read());

  Serial.println("Coloque o sensor ESQUERDO EXTERIOR sobre a linha preta");
  delay(6000);
  sensE_ext.setThreshold(sensE_ext.read());
  
  Serial.println("Coloque o sensor DIREITO EXTERIOR sobre a linha preta");
  delay(6000);
  sensD_ext.setThreshold(sensD_ext.read());
  
  Serial.println("Calibracao concluida!");

  eeprom.writeEEPROM(address1, sensE.getThreshold());
  eeprom.writeEEPROM(address2, sensD.getThreshold());
  eeprom.writeEEPROM(address3, sensE_ext.getThreshold());
  eeprom.writeEEPROM(address4, sensD_ext.getThreshold());
  
  Serial.print("Limiar esquerdo: "); Serial.println(eeprom.readEEPROM(address1));
  Serial.print("Limiar direito: "); Serial.println(eeprom.readEEPROM(address2));
  Serial.print("Limiar esquerdo externo: "); Serial.println(eeprom.readEEPROM(address3));
  Serial.print("Limiar direito externo: "); Serial.println(eeprom.readEEPROM(address4));
}

void loop() {
  bool leftBlack = sensE.isBlack();
  bool rightBlack = sensD.isBlack();
  bool leftBlack_ext = sensE_ext.isBlack();
  bool rightBlack_ext = sensD_ext.isBlack();
  
  Serial.print("Esquerdo: ");
  Serial.print(leftBlack ? "PRETO" : "BRANCO");
  Serial.print(" (");
  Serial.print(sensE.read());
  Serial.print(") | Direito: ");
  Serial.print(rightBlack ? "PRETO" : "BRANCO");
  Serial.print(" (");
  Serial.print(sensD.read());
  Serial.println(")");
  Serial.print("Esquerdo exterior: ");
  Serial.print(leftBlack_ext ? "PRETO" : "BRANCO");
  Serial.print(" (");
  Serial.print(sensE_ext.read());
  Serial.print(") | Direito exterior: ");
  Serial.print(rightBlack_ext ? "PRETO" : "BRANCO");
  Serial.print(" (");
  Serial.print(sensD_ext.read());
  Serial.println(")");
  
  delay(200); 
}

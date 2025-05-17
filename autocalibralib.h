#ifndef autocalibralib_h
#define autocalibralib_h

#include "Arduino.h"

class LineSensor {
  public:
    // Construtor: pin = pino analógico, ledPin = pino do LED de calibração (opcional)
    LineSensor(int pin, int ledPin = -1);
    
    // Calibra o sensor (deve ser chamado com o sensor sobre a linha preta)
    void calibrate();
    
    // Lê o sensor e retorna true se detectar preto
    bool isBlack();
    
    // Lê o valor bruto do sensor
    int read();
    
    // Define/obtém o limiar manualmente
    void setThreshold(int threshold);
    int getThreshold();
    
  private:
    int _pin;          // Pino do sensor
    int _ledPin;       // Pino do LED (opcional)
    int _threshold;    // Valor limiar para detecção de preto
    bool _hasLED;      // Indica se há LED configurado
    void _blinkLED(int times); // Pisca o LED
};

#endif

#include "autocalibralib.h"
#include "Arduino.h"

LineSensor::LineSensor(int pin, int ledPin) {
  _pin = pin;
  _ledPin = ledPin;
  _hasLED = (ledPin != -1);
  _threshold = 512; // Padrão
  
  pinMode(_pin, INPUT);
  if (_hasLED) {
    pinMode(_ledPin, OUTPUT);
    digitalWrite(_ledPin, LOW);
  }
}

void LineSensor::calibrate() {
  if (_hasLED) {
    _blinkLED(3); // Pisca 3 vezes para indicar início da calibração
  }
  
  // Lê o valor do sensor sobre a linha preta e o interpreta como limiar
  _threshold = analogRead(_pin);
  
  if (_hasLED) {
    _blinkLED(1); // Pisca 1 vez para indicar fim da calibração
    delay(500);
  }
}

bool LineSensor::isBlack() {
  int value = analogRead(_pin);
  // Considera uma margem de 70 unidades acima do limiar
  return (value >= _threshold - 70);
}

int LineSensor::read() {
  return analogRead(_pin);
}

void LineSensor::setThreshold(int threshold) {
  _threshold = threshold;
}

int LineSensor::getThreshold() {
  return _threshold;
}

void LineSensor::_blinkLED(int times) {
  if (!_hasLED) return;
  
  for (int i = 0; i < times; i++) {
    digitalWrite(_ledPin, HIGH);
    delay(200);
    digitalWrite(_ledPin, LOW);
    delay(200);
  }
}

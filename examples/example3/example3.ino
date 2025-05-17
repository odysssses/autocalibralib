#include <autocalibralib.h>

LineSensor sensor(A3, 3);  // Sensor esquerdo com LED no pino 3

void setup() {
  Serial.begin(9600);
  sensor.setThreshold(250);
}

void loop() {
  bool preto = sensor.isBlack();
  Serial.println("sensor:" + preto ? "PRETO" : "BRANCO");
}
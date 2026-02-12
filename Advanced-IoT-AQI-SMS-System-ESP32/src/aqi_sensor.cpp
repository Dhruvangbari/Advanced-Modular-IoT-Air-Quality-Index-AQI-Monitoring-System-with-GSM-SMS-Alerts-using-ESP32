
#include <Arduino.h>
#include "config.h"

void initSensor() {
  pinMode(AIR_SENSOR, INPUT);
}

int readAQI() {
  return analogRead(AIR_SENSOR);
}

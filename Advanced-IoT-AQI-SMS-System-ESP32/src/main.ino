
#include "config.h"
#include "aqi_sensor.h"
#include "gsm_module.h"

unsigned long lastAlert = 0;

void setup() {
  Serial.begin(9600);
  initSensor();
  initGSM();
}

void loop() {
  int airValue = readAQI();

  Serial.print("AQI Value: ");
  Serial.println(airValue);

  if (airValue > AQI_THRESHOLD && millis() - lastAlert > SMS_COOLDOWN) {
    sendSMS("ALERT! Poor Air Quality. AQI Value: " + String(airValue));
    lastAlert = millis();
  }

  delay(2000);
}

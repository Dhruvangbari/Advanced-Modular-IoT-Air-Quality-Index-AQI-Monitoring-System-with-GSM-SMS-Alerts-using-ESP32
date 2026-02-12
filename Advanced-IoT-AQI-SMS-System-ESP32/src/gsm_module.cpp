
#include <Arduino.h>
#include "config.h"

HardwareSerial sim800(2);

void initGSM() {
  sim800.begin(9600, SERIAL_8N1, RXD2, TXD2);
  delay(3000);
  sim800.println("AT");
  delay(1000);
  sim800.println("AT+CMGF=1");
  delay(1000);
}

void sendSMS(String message) {
  sim800.print("AT+CMGS=\"");
  sim800.print(PHONE_NUMBER);
  sim800.println("\"");
  delay(1000);
  sim800.print(message);
  delay(500);
  sim800.write(26);
  delay(5000);
}

#include <ESP8266WiFi.h>
#include "ControlCD.h"
#include <SPI.h>
#include <SD.h>

CCD::CCD(char* name) {  //конструктор класса
  nameFile = name;
}

void CCD::initializingCDcard(uint8_t pin) {  //функция проверки cd карты на её наличие
  bool statusCD = SD.begin(pin);
  Serial.println("connecting an SD card: " + String(statusCD));
}

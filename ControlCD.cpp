#include <ESP8266WiFi.h>
#include "ControlCD.h"
#include <SPI.h>
#include <SD.h>

bool CCD::initializingCDcard(uint8_t pin){
  //функция проверки cd карты на её наличие
   if (SD.begin(pin)) 
        return true;
}

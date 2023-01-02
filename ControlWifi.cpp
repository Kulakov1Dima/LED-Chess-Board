#include <ESP8266WiFi.h>

#include "ControlWifi.h"

CWIFI::CWIFI(char* network_name, char* network_password) {                //конструктор класса
  _network_name = network_name;                                           //имя сети(динамическое)
  _network_password = network_password;                                   //пароль сети
}

bool CWIFI::connectWiFi(int timeout, int led) {
  WiFi.begin(_network_name, _network_password);
  analogWrite(led, 0);
  // Функция подключения к wifi, пытается подключиться к сети timeout времени, при неуспешном подключении возвращает false иначе true
  //во время подключения мигает светодиодом
  //если функция вернула true светодиод останется включенным
  return true;
}


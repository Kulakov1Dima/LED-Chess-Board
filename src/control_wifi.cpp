#include "control_wifi.h"
#include <ESP8266WiFi.h>

bool CWIFI::connect_wifi(int timeout, uint8_t led) {
  WiFi.begin(_network_name, _network_password);

  while (WiFi.status() != WL_CONNECTED) {
    if (!(millis() % 70)) {
      analogWrite(led, map(analogRead(led), 0, 1023, 255, 0));
      delayMicroseconds(5);
    }
    if (!(millis() % timeout)) {
      analogWrite(led, 0);
      return false;
    }
  }
  analogWrite(led, 0);
  // Функция подключения к wifi, пытается подключиться к сети timeout времени,
  // при неуспешном подключении возвращает false иначе true
  // во время подключения мигает светодиодом
  // если функция вернула true светодиод останется включенным
  return true;
}

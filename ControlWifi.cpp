#include <ESP8266WiFi.h>
#include "Side_illumination.h"
#include "Configuration.h"
#include "ControlWifi.h"

CWIFI::CWIFI(String network_name, String network_password) {
  _network_name = network_name;
  _network_password = network_password;
}

bool CWIFI::connectWiFi() {

  SI side_illumination();

  WiFi.begin(_network_name, _network_password);
  while (WiFi.status() != WL_CONNECTED) {
    if (!(millis() % 70)) {
      analogWrite(INDICATOR_OF_NETWORK_STATUS,
                  map(analogRead(INDICATOR_OF_NETWORK_STATUS), 0, 1023, 255, 0));
      side_illumination.load();
      delayMicroseconds(ILLUMINATION_DELAY);
    }
    if (!(millis() % CONNECTION_TIME)) {
      analogWrite(INDICATOR_OF_NETWORK_STATUS, 0);
      return false;
    }
  }
  analogWrite(INDICATOR_OF_NETWORK_STATUS, 0);
  return true;
}
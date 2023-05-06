#include <ESP8266WiFi.h>
#include "LedChessBoardWifi.h"
#include "Configuration.h"
#include "SideIllumination.h"

SI ipanel;
int error_count = 0;

WIFI::WIFI() {
}

bool WIFI::connectingWiFi() {
  int count_connection = 0;
  WiFi.begin(APSSID1, APPSK1);
  while (WiFi.status() != WL_CONNECTED) {
    ipanel.loading_panel();
    //wifi_indicator_conection_status();
    DEBUG(".");
    if (!(millis() % CONNECTION_TIME)) {
      DEBUG("\n");
      count_connection++;
      if (count_connection == 2) WiFi.begin(APSSID2, APPSK2);
      if (count_connection == 3) WiFi.begin(APSSID3, APPSK3);
      if (count_connection > 3) {
        error_count++;
        if(error_count > 3){
          ipanel.error_panel();
          return false;
        }
        //analogWrite(INDICATOR_OF_NETWORK_STATUS, 1);
        //delay(CONNECTION_TIME);
        return connectingWiFi();
      }
    }
  }
  //analogWrite(INDICATOR_OF_NETWORK_STATUS, 255);
  ipanel.ok_panel();
  DEBUG("Connected, IP address: ");
  DEBUG(WiFi.localIP());
  return true;
}

void WIFI::wifi_indicator_conection_status() {
  if (!(millis() % INDICATOR_OF_NETWORK_STATUS_TIMEOUT)) {
    analogWrite(INDICATOR_OF_NETWORK_STATUS,
                map(analogRead(INDICATOR_OF_NETWORK_STATUS), 0, 1023, 255, 0));
  }
}
#include "Configuration.h"
#include "ControlWifi.h"

void setup() {
  CWIFI controlWifi(APSSID1, APPSK1);
  controlWifi.connectWiFi();
  updateFirmware();
}

void loop() {
  updateServer();
}

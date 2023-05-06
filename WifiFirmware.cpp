#include <ESP8266HTTPUpdateServer.h>
#include "Configuration.h"
#include "WifiFirmware.h"

#ifdef WIFI_FIRMWARE_ENABLE
ESP8266HTTPUpdateServer httpUpdater;
ESP8266WebServer HttpServer(SERVERPORT);
#endif

Firmware::Firmware() {
}

void Firmware::update_firmware() {
#ifdef WIFI_FIRMWARE_ENABLE
  httpUpdater.setup(&HttpServer, OTAPATH, OTAUSER, OTAPASSWORD);
  HttpServer.begin();
#endif
}

void Firmware::update_local_server() {
#ifdef WIFI_FIRMWARE_ENABLE
  HttpServer.handleClient();
#endif
}
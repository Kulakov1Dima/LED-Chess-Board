#include "Configuration.h"
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

ESP8266WebServer HttpServer(SERVERPORT);
ESP8266HTTPUpdateServer httpUpdater;

void updateFirmware() {
  httpUpdater.setup(&HttpServer, OTAPATH, OTAUSER, OTAPASSWORD);
  HttpServer.on("/", handleRoot);
  HttpServer.begin();
}

void updateServer() {
  HttpServer.handleClient();
}

void handleRoot() {
  HttpServer.send(400, "text/plain", "not found");
}


/*нужно переделать в класс который будет являться будущим локальным сервером для настройки светодиодной шахматной доски

Взято из старого репозитория:
https://github.com/interpreter-It/checkers/blob/main/LED%20chessboard%20firmware/checkers11/updateFirmwareWifi.ino
потому что у меня отвалился usb :)
*/
#include <WebSocketsClient.h>
#include "Configuration.h"
#include "LedChessBoardWifi.h"
#include "WifiFirmware.h"
#include "Screensaver.h"
#include "SideIllumination.h"
#include "Processing.h"
#include "Play.h"

WebSocketsClient webSocket;
Firmware wifi_firmware;
SI spanel;
Processing processing;
Play game;

void webSocketEvent(WStype_t type, uint8_t* payload, size_t length) {

  switch (type) {
    case WStype_DISCONNECTED:
      spanel.error_panel();
      break;
    case WStype_CONNECTED:
      spanel.ok_panel();
      webSocket.sendTXT("Connected");
      break;
    case WStype_TEXT:
      DEBUG((char*)payload);
      DEBUG("\n");
      String data = processing.parse_string((char*)payload);
      DEBUG(data);
      DEBUG("\n");
      if (data.length() == 0) spanel.error_panel();
      else if (data != "command") game.game(data);

      delay(1500);
      webSocket.sendTXT("message here");
      break;
  }
}

void setup() {
  print_version();
  enable_wifi_connection();
  enable_wifi_firmware();
  webSocket.begin("85.237.35.92", 80, "/relikt");
  webSocket.onEvent(webSocketEvent);
  webSocket.setReconnectInterval(5000);
  game.start();
}

void loop() {
#ifdef WIFI_FIRMWARE_ENABLE
  wifi_firmware.update_local_server();
#endif
  webSocket.loop();
}

void print_version() {
#ifdef DEBUG_ENABLE
  Serial.begin(DEBUG_SPEED);
#endif
  DEBUG("\nHello! This configuration for version: ");
  DEBUG(LED_CHESS_BOARD_VERSION);
  DEBUG("\n");
}

void enable_wifi_connection() {
  WIFI network;
  if (network.connectingWiFi()) {
    screensaver();
  }
}


void enable_wifi_firmware() {
#ifdef WIFI_FIRMWARE_ENABLE
  wifi_firmware.update_firmware();
#endif
}

void screensaver() {
  Screensaver screen;
  screen.start();
}

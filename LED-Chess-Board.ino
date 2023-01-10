#include "src/configuration.h"
#include "src/control_wifi.h"
#include "src/control_cd.h"
#include "src/backlight.h"

void setup() {
  initilization();   // Подготовка к запуску
  connecting_wifi();   // Подключение к wifi
  update_firmware();  // Запуск прошивки по wifi
}

void loop() {
  update_server();
}

void initilization() {
  CCD cdcard(CONFFILE);
  cdcard.initializingCDcard(CDPIN);
  Backlight().initBacklight();
}

void connecting_wifi() {
  CWIFI control_wifi(APSSID, APPSK);  // Пробуем подключиться к первой сети
  if (!control_wifi.connect_wifi(TIMEOUT, INDICATOR_OF_NETWORK_STATUS)) {
    CWIFI control_wifi(APSSID1, APPSK1);  // Пробуем подключиться ко второй сети
    if (!control_wifi.connect_wifi(TIMEOUT, INDICATOR_OF_NETWORK_STATUS)) {
      CWIFI control_wifi(APSSID2, APPSK2);  // Пробуем подключиться к третьей сети
      control_wifi.connect_wifi(TIMEOUT, INDICATOR_OF_NETWORK_STATUS);
    }
  }
  //костыль можно оптимизировать(много одинаковых операций)
}

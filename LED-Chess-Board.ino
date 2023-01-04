#include "Configuration.h"
#include "ControlWifi.h"
#include "ControlCD.h"
#include "Backlight.h"

/*
Эта ветка показывает структуру проекта!
*/

void setup() {
  initilization();
  connectedWifi();
  Backlight().initBacklight();
}

void loop() {
}

void initilization() {

  Serial.begin(9600);
  PRINT_VERSION;

  if (CCD().initializingCDcard(CDPIN)) {
    Serial.println("sd card is connected");
  } else {
    Serial.println("sd card isn't connected");
  }
  Serial.println(htmlFile);  // пример как достать содержимое файла html
}

void connectedWifi() {
  CWIFI controlWifi(APSSID1, APPSK1);  // создаём экземпляр класса отправляя имя и пароль в конструктор
  controlWifi.connectWiFi(TIMEOUT, INDICATOR_OF_NETWORK_STATUS);
  //функция подключения к нескольким сетям выполняет попытки подключения к APSSID1, APSSID2, APSSID
}

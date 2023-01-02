#include "Configuration.h"
#include "ControlWifi.h"
#include "ControlCD.h"

/*
Эта ветка показывает структуру проекта!
*/

  void setup() {
  Serial.begin(9600);
  PRINT_VERSION;
  if(CCD().checkCDcard()) {
    Serial.println("sd card is connected");
  }
  connectedWifi();
  Serial.println(htmlFile);  // пример как достать содержимое файла html
}

void loop() {
}

void connectedWifi() {
  CWIFI controlWifi(APSSID1, APPSK1);  // создаём экземпляр класса отправляя имя и пароль в конструктор
  controlWifi.connectWiFi(TIMEOUT, INDICATOR_OF_NETWORK_STATUS);
  //функция подключения к нескольким сетям выполняет попытки подключения к APSSID1, APSSID2, APSSID
}

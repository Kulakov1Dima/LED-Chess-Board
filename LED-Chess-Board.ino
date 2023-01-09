#include "Configuration.h"
#include "ControlWifi.h"
#include "ControlCD.h"
#include "Backlight.h"

/*
Эта ветка показывает структуру проекта!
*/

void setup() {
  print_version();
  initilization();
  connectedWifi();
  Backlight().initBacklight();
}

void loop() {
}

void print_version(){
  Serial.begin(COMPORTSPEED);
  Serial.println();
  Serial.println(PRINT_VERSION);
}

void initilization() {
  CCD cdcard("config.txt");
  cdcard.initializingCDcard(CDPIN);
  cdcard.CDConfig();
  Serial.println(htmlFile);  // пример как достать содержимое файла html
}

void connectedWifi() {
  CWIFI controlWifi(APSSID1, APPSK1);  // создаём экземпляр класса отправляя имя и пароль в конструктор
  controlWifi.connectWiFi(TIMEOUT, INDICATOR_OF_NETWORK_STATUS);
  //функция подключения к нескольким сетям выполняет попытки подключения к APSSID1, APSSID2, APSSID
}

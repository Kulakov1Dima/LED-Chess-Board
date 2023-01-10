#pragma once

/*
Файл настройки доски (указать все важные настройки и параментры используя
дерективы припроцессора)
*/

// TODO change all macros to const

/*..............................................................LOCAL................................................................*/
extern const char htmlFile[] PROGMEM;

#ifndef APSSID

#define APSSID "SHACMATIE"
#define APPSK "12345678"

#define APSSID1 ""
#define APPSK1 ""

#define APSSID2 "TP-Link_EFF4"
#define APPSK2 "13197421"

// Нужно реализовать подключение к нескольким сетям не подключился к одной за
// timeout  подключается к следеующей

#define TIMEOUT 5000
#define INDICATOR_OF_NETWORK_STATUS 2
#endif

#define matrixLed 5

/*............................................Update firmware into wifi
 * configuration...............................................*/

#define OTAUSER ""
#define OTAPASSWORD ""
#define OTAPATH "/firmware"
#define SUBFOLDERDATA "/data"
#define SERVERPORT 80

/*.............................................................sd
 * card...............................................................*/

#define CDPIN 4
#define CONFFILE "config.txt"
/*..........................................................time
 * settings............................................................*/

// ну и так далее...
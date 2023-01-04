#ifndef Configuration_h
#define Configuration_h

/*
Файл настройки доски (указать все важные настройки и параментры используя дерективы припроцессора)
*/

/*..............................................................LOCAL................................................................*/
extern const char htmlFile[] PROGMEM;

#define PRINT_VERSION                                                      Serial.println("\n2022012")

#ifndef APSSID

#define APSSID                                                             "SHACMATIE"
#define APPSK                                                              "12345678"

#define APSSID1                                                            "TP-Link_EFF4"
#define APPSK1                                                             "13197421"

#define APSSID2                                                            ""
#define APPSK2                                                             ""

//Нужно реализовать подключение к нескольким сетям не подключился к одной за timeout  подключается к следеующей

#define TIMEOUT                                                            2000
#define INDICATOR_OF_NETWORK_STATUS                                        2
#endif

#define matrixLed                                                          5                              

/*............................................Update firmware into wifi configuration...............................................*/

#define OTAUSER                                                           ""
#define OTAPASSWORD                                                       ""
#define OTAPATH                                                           "/firmware"
#define SUBFOLDERDATA                                                     "/data"
#define SERVERPORT                                                        80

/*.............................................................sd card...............................................................*/

#define CDPIN                                                             4
/*..........................................................time settings............................................................*/


//ну и так далее...

#endif

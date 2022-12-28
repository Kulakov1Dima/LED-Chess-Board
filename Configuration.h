#ifndef Configuration_h
#define Configuration_h

/*
Файл настройки доски (указать все важные настройки и параментры используя дерективы припроцессора)
*/

/*..............................................................LOCAL................................................................*/
extern const char htmlFile[] PROGMEM;

#define VERSION                                                           2022012

#ifndef APSSID
#define APSSID                                                            "SHACMATIE"
#define APPSK                                                             "12345678"
#endif

#define matrixLed                                                         13

/*............................................Update firmware into wifi configuration...............................................*/

#define OTAUSER                                                           ""
#define OTAPASSWORD                                                       ""
#define OTAPATH                                                           "/firmware"
#define SUBFOLDERDATA                                                     "/data"
#define SERVERPORT                                                        80

/*.............................................................sd card...............................................................*/





/*..........................................................time settings............................................................*/


//ну и так далее...

#endif


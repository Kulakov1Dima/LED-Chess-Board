/**
 * LED Chessboard Firmware
 * conceived in 2019
 * 
 * Based on a microcontroller NodeMCU 1.0(ESP-12E Module)
 * Kulakov Dmitry Alekseevich
 * 
 * This firmware is designed for the chess board microcontroller
 * The LED panel polls the web server,
 * receiving user commands,
 * that were given by voice to the skill of Yandex Alice
 * 
 * This is the 12 version of 2023
 */

#define CONFIGURATION_H_VERSION             2023012

//  backlight settings
#define matrixLed                           5
#define ILLUMINATION_DELAY                  1000
#define BRIGHTNESS                          50

//  network settings
// wifi 1
#define APSSID                              "SHACMATIE"
#define APPSK                               "12345678"
// wifi 2
#define APSSID1                             "Coworking"
#define APPSK1                              "Kvant1234"
// wifi 3
#define APSSID2                             "TP-Link_EFF4"
#define APPSK2                              "13197421"

/*
the device connects alternately to three Wi-Fi access points
*/

#define CONNECTION_TIME                     3000
#define INDICATOR_OF_NETWORK_STATUS         2

/*............................................Update firmware into wifi configuration...............................................*/

#define OTAUSER                                                           ""
#define OTAPASSWORD                                                       ""
#define OTAPATH                                                           "/firmware"
#define SUBFOLDERDATA                                                     "/data"
#define SERVERPORT                                                        80

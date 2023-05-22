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

/*........................................................Version settings..........................................................*/

#define LED_CHESS_BOARD_VERSION                                           "2023012"

//#define LED_CHESS_BOARD_VERSION                                           "2021011"                   // old desk 2019

//#define DESK_NAME                                                         "mockva"
//#define DESK_NAME                                                         "orel"
//#define DESK_NAME                                                         "anapa"
//#define DESK_NAME                                                         "mogayck"
//#define DESK_NAME                                                         "pckov"
#define DESK_NAME                                                         "cevactopol"
//#define DESK_NAME                                                         "tula"



/*.........................................................Debug settings...........................................................*/

#define DEBUG_ENABLE                                                                                  // enable debug output

#ifdef DEBUG_ENABLE

#define DEBUG_SPEED                                                       9600                      // serial com port speed

#define DEBUG(message) Serial.print(message)
#else
#define DEBUG(message)
#endif



/*.........................................................Wifi settings............................................................*/ 

#define APSSID1                                                           "Galaxy A678B7"             //  network 1
#define APPSK1                                                            "mahg5371"
#define APSSID2                                                           "Coworking"                 //  network 2
#define APPSK2                                                            "Kvant1234"
#define APSSID3                                                           "TP-Link_EFF4"              //  network 3
#define APPSK3                                                            "13197421"

#define CONNECTION_TIME                                                   3000                        // connection time one wifi network
#define INDICATOR_OF_NETWORK_STATUS                                       2                           // indicator of connection
#define INDICATOR_OF_NETWORK_STATUS_TIMEOUT                               100



/*............................................Update firmware into wifi configuration...............................................*/ 

#define WIFI_FIRMWARE_ENABLE                                                                          // enable the firmware via Wi-Fi

#ifdef WIFI_FIRMWARE_ENABLE
#define OTAUSER                                                           ""                          // login on local server
#define OTAPASSWORD                                                       ""                          // password on local server
#define OTAPATH                                                           "/firmware"                 // path to firmware
#define SUBFOLDERDATA                                                     "/data"                     // other path
#define SERVERPORT                                                        80                          // port for http server
#endif



/*.....................................................Backlight settings...........................................................*/ 

#define MATRIX_LED                                                         5
#define BRIGHTNESS                                                         50

#define AFFIRMATIVE_SIGNAL                                                 Color(0, 255, 0)           // the color of the sidebar for the successfully completed operation
#define ERROR_SIGNAL                                                       Color(255, 0, 0)           // the color of the sidebar for the error completed operation

#define DELAY_SCREENSAVER                                                  3000

#define COLOR_PLAYER_1                                                     Color(155, 100, 255)
#define COLOR_PLAYER_2                                                     Color(255, 213, 0)

#define COLOR_LADIES_1                                                     Color(2, 255, 255)
#define COLOR_LADIES_2                                                     Color(255, 100, 255)

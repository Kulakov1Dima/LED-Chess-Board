#include "ControlCD.h"
#include <SPI.h>

CCD::CCD(String name) {  //конструктор класса
  nameFile = name;
}

File myFile;

void CCD::CDConfig(bool* status) {  //функция проверки наличия config.txt
  if (*status) {
    myFile = SD.open(nameFile);
    *status *= bool(myFile);
  }
}

void CCD::initializingCDcard(uint8_t pin) {  //функция проверки cd карты на её наличие
  bool statusCD = SD.begin(pin);
  CDConfig(&statusCD); //отправляем в функцию указатель на переменную, что делает возможным изменения этой переменной внутри функции
}

//по итогу выполнения этих двух функций в statusCD будет информация о существовании старой конфигурации доски
#pragma once

#include <SD.h>
#include <string>

class CCD {
 public:
  CCD(std::string file_name) : file_name(file_name);
  void initializing_cdcard(uint8_t pin);

 private:
  void cd_config(bool* status);
  std::string file_name;
};
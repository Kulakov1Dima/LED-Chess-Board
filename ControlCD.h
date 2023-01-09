#include <SD.h>
class CCD {
public:
  CCD(String name);
  void initializingCDcard(uint8_t pin);
private:
  void CDConfig(bool* status);
  String nameFile;
};
class CCD {
public:
  CCD(char* name);
  void initializingCDcard(uint8_t pin);
private:
  char* nameFile;
};
class CWIFI {
public:
  CWIFI(char* network_name, char* network_password);
  bool connectWiFi(int timeout, int led);
private:
  char* _network_name;
  char* _network_password;
};
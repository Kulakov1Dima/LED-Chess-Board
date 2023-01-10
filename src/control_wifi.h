#pragma once

#include <string>

class CWIFI {
 public:
  CWIFI(String network_name, String network_password) : network_name(network_name), network_password(network_password);
  bool connect_wifi(int timeout, uint8_t led);

 private:
  std::string network_name;
  std::string network_password;
};

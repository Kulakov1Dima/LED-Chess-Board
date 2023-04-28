class CWIFI {
public:
  CWIFI(String network_name, String network_password);
  bool connectWiFi();
private:
  String _network_name;
  String _network_password;
};
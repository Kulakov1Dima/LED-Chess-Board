class Processing {
public:
  Processing();
  String parse_string(char* string);
private:
  String find_commands(String data);
};
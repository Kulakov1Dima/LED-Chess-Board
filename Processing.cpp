#include <Arduino_JSON.h>
#include "Processing.h"
#include "Configuration.h"

Processing::Processing() {
}

String Processing::parse_string(char* string) {
  JSONVar myObject = JSON.parse(string);
  if (JSON.typeof(myObject) == "undefined") {
    DEBUG("Parsing input failed!\n");
    return "";
  }
  if (myObject.hasOwnProperty(DESK_NAME)) {
    String data = myObject[DESK_NAME];
    data.replace(" ", "");
    data.toUpperCase();
    return find_commands(data);
  }
  return "";
}

String Processing::find_commands(String data) {
  String new_data = "";
  bool command = true;
  for (int i = 0; i < data.length(); i++) {
    for (char w = '1'; w < '9'; w++) {
      if (data.charAt(i) == w) {
        command = false;
        new_data += data.substring(i - 1, i + 1);
      }
    }
  }
  if (command) return "command";
  return new_data;
}
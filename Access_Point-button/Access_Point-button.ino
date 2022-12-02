#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "SHACMATIE"
#define APPSK  "12345678"
#endif

const char *APssid = APSSID;//Название точки доступа(выше)
const char *APpassword = APPSK;//Пароль от точки доступа(выше)
int n = 0;//смотреть в void setup()
String ssid;//Объявляем переменную названия WiFi-сети
String password;//Объявляем переменную пароля WiFi-сети

ESP8266WebServer server(80);

//Наш сайт
const String HtmlHtml = "<html><head><meta charset=\"utf-8\">"
"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /></head>";
const String HtmlButtons = "<form method=\"get\" action=\"/get\"><ul><li><input type=\"text\" name=\"ssid\" placeholder=\"Введите название WiFi-сети\"></li><li><input type=\"text\" name=\"password\" placeholder=\"Введите пароль\"></li><li><input type=\"submit\" value=\"Отправить\"></li></form>";
const String HtmlHtmlClose = "</html>";

//Класс для приема и отправки наших данных
void get() {
  ssid = server.arg("ssid");//Записываем в переменную
  password = server.arg("password");//Записываем в переменную
  //На это строчке данные отправляются на СД-карту
  Serial.println(ssid);//Отправляем наши введенные данные через Serial
  Serial.println(password);
  ESP.restart();//Ресет ЕСП
}

//Форма для заполнения
void response(){
  String htmlRes = HtmlHtml;
  htmlRes += HtmlButtons;
  htmlRes += HtmlHtmlClose; 
  server.send(200, "text/html", htmlRes);
}
 
void setup() {
    delay(1000); 
    //Пишите все, что надо для получения ssid и password
    //ssid = ;
    //password = ;
    Serial.begin(115200); 
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting..");
      n++;
      if(n==10){
        break;//Если больше 10 секунд не может подключиться
      }
    }
    if(n==10){
      WiFi.softAP(APssid, APpassword); 
      IPAddress apip = WiFi.softAPIP();  
      Serial.println(apip);  //К этому айпи подключаемся(у меня он всегда 192.168.4.1)
      server.on("/", response); //Форма для заполнения 
      server.on("/get", get); //Отправка информации
      server.begin();    
    }
    else{
      Serial.println(WiFi.localIP());
    }
}
 
void loop() {
  if(n==10){
    server.handleClient();//Чтобы сервер работал
  }
}

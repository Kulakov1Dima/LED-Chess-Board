#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#ifndef APSSID
#define APSSID "SHACMATIE"
#define APPSK  "12345678"
#endif

IPAddress local_ip(192,168,0,1);
IPAddress gateway(192,168,2,1);
IPAddress subnet(255,255,255,0);

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

void connectWiFi()  {
  Serial.println("Entering WiFi connection stage");

  WiFi.begin(ssid, password); 
  Serial.print("Connecting...");
  while( WiFi.status() != WL_CONNECTED )  {
    Serial.print(".");
    delay(1000);
    n++;
    if(n==10){
      connectAP;//Если больше 10 секунд не может подключиться
    }
  }
  Serial.println(WiFi.localIP());
}

void connectAP(){
  WiFi.softAP(APssid, APpassword); 
  apip = WiFi.softAPIP();  
  WiFi.softAPConfig(local_ip, gateway, subnet);
  server.on("/", response); //Форма для заполнения 
  server.on("/get", get); //Отправка информации
  server.begin();    
}

void setup() {
  delay(1000); 
  //Пишите все, что надо для получения ssid и password
  //ssid = ;
  //password = ;
  Serial.begin(115200); 
  connectWiFi;
}
 
void toLoop(){

}

void loop() {
  if(n==10){
    server.handleClient();//Чтобы сервер работал
  }
  else {
    toLoop;//хз, может так лучше, чтобы все функции основные писать без "else", чтобы он не мешал
  }
}

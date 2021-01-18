#include <WiFi.h>
//Informações da rede WIFI
const char* rede = "3b5ef6";
const char* senha = "265284045";

//Defini porta a ser acessada
WiFiServer server(3000);
String header;
unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 3500;
void setup() {
 Serial.begin(115200);
 Serial.print("Conectando-se com");
 Serial.println(rede);
 WiFi.begin(rede, senha);
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print("*");
 }
 //Printar infromações
 Serial.println("");
 Serial.println("Conexão Efetuada com sucesso à rede");
 Serial.println(rede);
 Serial.println("Endereço de IP: ");
 Serial.println(WiFi.localIP());
 server.begin();
}
void loop(){
 WiFiClient client = server.available();
 if (client) {
 previousTime = currentTime;
 Serial.println("New Client.");
 String currentLine = "";
 while (client.connected() && currentTime - previousTime <= timeoutTime) {

 currentTime = millis();
 if (client.available()) {
 char c = client.read();
 Serial.write(c);
 header += c;
 if (c == '\n') {


 if (currentLine.length() == 0) {
 client.println("HTTP/1.1 200 OK");
 client.println("Content-type:text/html");
 client.println("Connection: close");
 client.println();
 

 client.println("<!DOCTYPE html><html>");
 client.println("<head></head>");
 client.println("<body><h1>ESP32 Web Server</h1>");
 client.println("<h1>Projeto Trainee</h1>");

 client.println("</body></html>");

 client.println();
 break;
 } else {
 currentLine = "";
 }
 } else if (c != '\r') {
 currentLine += c;
 }
 }
 }
 header = "";

 client.stop();
 Serial.println("Conexão encerrada.");
 Serial.println("");
 }
}

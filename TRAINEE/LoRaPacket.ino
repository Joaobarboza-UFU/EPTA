#include <SPI.h>
#include <LoRa.h>
//define the pins used by the transceiver module
#define ss 5
#define rst 14
#define dio0 2
float pi = 3.14159;
void setup() {
 Serial.begin(115200);
 while (!Serial);
13
 Serial.println("Teste do Rádio LoRa");
 LoRa.setPins(ss, rst, dio0);

 //915E6 Indica a frequencia de operação. 915E6 é a frequencia da américa do
norte
 while (!LoRa.begin(915E6)) {
 Serial.println(".");
 delay(500);
 }
 //A palavre de sincronização é usada para sincronizar com apenas os recepto
res desejados
 LoRa.setSyncWord(0xA1);
 Serial.println("LoRa funcionando!");
}
void loop() {
 Serial.print("Pacote: ");
 Serial.println("O valor de pi continua sendo ");
 Serial.println(pi);
 //inicia o pacote de envio
 LoRa.beginPacket();
 LoRa.print("O valor de pi continua sendo ");
 LoRa.print(pi);
 //encerra o pacote de envio
 LoRa.endPacket();
 delay(1000);
}

#include <SD.h>
#include <SPI.h>
#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa mySensor;

#ifdef ESP32_HAL_I2C_H
#define SDA_PIN 21
#define SCL_PIN 22
#endif

void setup(){
  Serial.begin(115200);
  Serial.println("Iniciando SD...");
  if (!SD.begin()) {
    Serial.println("Erro, verifique se o cartão está inserido, reiniciando o sistema...");
    delay(5000);
    ESP.restart();
  }
  Serial.println("Conexão estabelecida.");
  #ifdef ESP32_HAL_I2C_H
  // for esp32
  Wire.begin(SDA_PIN, SCL_PIN); //sda, scl
  #else
  Wire.begin();
  #endif
   
  mySensor.setWire(&Wire);
  mySensor.beginAccel();
  mySensor.beginMag();
 
}
void loop() {
 
  File dataFile = SD.open("MPU.txt", FILE_WRITE);

  if (dataFile) {
    Serial.println("Arquivo aberto!");
 
      dataFile.print("Acelerometro: ");
      dataFile.print(" | ");
      dataFile.print("X" + String(mySensor.accelX())+ "Y" + String(mySensor.accelY())+ "Z" + String(mySensor.accelZ()));
      dataFile.print("Magnetómetro: ");
      dataFile.print(" | ");
      dataFile.print("X" + String(mySensor.magX())+ "Y" + String(mySensor.accelY())+ "Z" + String(mySensor.accelZ()));
      dataFile.println("");
      dataFile.close();
  }

  else {
    Serial.println("Erro. Arquivo não conseguiu ser aberto");
  }
 
  delay(2000);
 
}

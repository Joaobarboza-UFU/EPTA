#include <Arduino.h>
#include <MPU9250_asukiaaa.h>
#include <SPI.h> //Library used to Serial Peripheral Interface
#include <LoRa.h> //LoRa Library

#ifdef ESP32_HAL_I2C_H
#define SDA_PIN 21
#define SCL_PIN 22
#endif

MPU9250_asukiaaa mySensor;


#define ss 5
#define rst 14
#define dio0 2

void setup() {
while(!Serial);
Serial.begin(115200);
Serial.println("started");
LoRa.setPins(ss, rst, dio0);

while (!LoRa.begin(915E6)) {
  Serial.println(".");
  delay(500);
}


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
mySensor.accelUpdate();
mySensor.magUpdate();
LoRa.beginPacket();
LoRa.print("Aceleração X: " + String(mySensor.accelX()));
LoRa.print("Aceleração Y: " + String(mySensor.accelY()));
LoRa.print("Aceleração Z: " + String(mySensor.accelZ()));
LoRa.print("Magnitude X: " + String(mySensor.magX()));
LoRa.print("Magnitude Y: " + String(mySensor.magY()));
LoRa.print("Magnitude Z: " + String(mySensor.magZ()));
LoRa.endPacket();
delay(1000);
}

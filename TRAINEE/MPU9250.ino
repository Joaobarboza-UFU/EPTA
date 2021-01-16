#include <Arduino.h>
#include <MPU9250_asukiaaa.h>

#ifdef ESP32_HAL_I2C_H
#define SDA_PIN 21
#define SCL_PIN 22
#endif

MPU9250_asukiaaa mySensor;

String errorMsg;

void setup() {
while(!Serial);
 
Serial.begin(115200);
Serial.println("started");

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
Serial.println("print accel values");
Serial.println("Aceleração X: " + String(mySensor.accelX()));
Serial.println("Aceleração Y: " + String(mySensor.accelY()));
Serial.println("Aceleração Z: " + String(mySensor.accelZ()));
 
mySensor.magUpdate();
Serial.println("Valores de magnitude");
Serial.println("Magnitude X: " + String(mySensor.magX()));
Serial.println("Magnitude Y: " + String(mySensor.magY()));
Serial.println("Magnitude Z: " + String(mySensor.magZ()));
delay(500);
}

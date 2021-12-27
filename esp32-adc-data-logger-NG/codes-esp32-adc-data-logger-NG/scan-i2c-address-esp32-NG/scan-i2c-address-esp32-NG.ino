/** 
 * Main File
 * @file scan-i2c-address-esp32-NG.ino
 * @author Nandan Ghawate (nandan.ghawate@gmail.com)
 * @brief 
 * * This code is based on a i2c code by Nick Gammon http://www.gammon.com.au/i2c
 * * Code can be used to scan i2c connections on esp32 i2c bus
 * ! Tested on ESP-WROOM-32 Module only.
 * @version 1.1
 * @date 2021-12-27 
 */

#include <Wire.h>
#define esp32sda 21
#define esp32scl 22
void setup() {
  Serial.begin(115200);
  Serial.println("Scanning I2C on ESP32");
  Serial.println("Make Sure I2C device is connected on following Pins:");
  Serial.println("GPIO %d -> SDA", esp32sda);
  Serial.println("GPIO %d -> SCL", esp32scl);
  Serial.println("GROUND -> GROUND");
  Wire.begin (esp32sda, esp32scl);
}

void loop() {
  byte count = 0;
  for (byte i = 8; i < 120; i++) {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0) {
       //ack success
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
    }
  }
  Serial.print ("ESP32 found ");      
  Serial.print (count, DEC);
  if (count == 1) Serial.println("device");
  else Serial.println("devices");
  delay (100);
}

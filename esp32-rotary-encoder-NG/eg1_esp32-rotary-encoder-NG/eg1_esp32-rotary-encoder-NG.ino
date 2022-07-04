#include <MD_REncoder.h>
#define REncoderPinA 32 //Data Pin
#define REncoderPinB 25 //Clock Pin
MD_REncoder REncoder = MD_REncoder(REncoderPinA, REncoderPinB);

void setup() {
  Serial.begin(115200);
  REncoder.begin();
  Serial.print("Sketch Starts");
}

void loop() {
  uint8_t x = REncoder.read();
  if (x) {
    Serial.print(x == DIR_CW ? "\n+1" : "\n-1");
#if ENABLE_SPEED
    Serial.print("  ");
    Serial.print(REncoder.speed());
#endif
  }
}

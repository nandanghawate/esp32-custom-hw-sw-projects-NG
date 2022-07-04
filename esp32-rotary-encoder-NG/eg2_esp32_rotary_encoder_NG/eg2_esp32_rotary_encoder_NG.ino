#define REncoderPinA 32 //Data Pin
#define REncoderPinB 25 //Clock Pin
//Leave REncoderPinC open
#define REncoderPinD 10 //Push Pin
//Connect REncoderPinE to Ground

int Count = 0;
int clockCurrentStatus;
int clockLastStatus;
String Direction ="";
unsigned long lastButtonPress = 0;

void setup() {
  
  pinMode(REncoderPinB,INPUT_PULLUP);
  pinMode(REncoderPinA,INPUT_PULLUP);
  pinMode(REncoderPinD, INPUT_PULLUP);
  
  Serial.begin(115200);
  clockLastStatus = digitalRead(REncoderPinB);
}

void loop() {
  String Direction ="";
  clockCurrentStatus = digitalRead(REncoderPinB);
  if (clockCurrentStatus != clockLastStatus  && clockCurrentStatus == 1) {
    if (digitalRead(REncoderPinA) != clockCurrentStatus) {
      Count --;
      Direction ="Counter Clockwise";
    } 
    else { 
      Count ++;
      Direction ="Clockwise";
    }
    Serial.print("Direction: ");
    Serial.println(Direction);
    Serial.print("Count: ");
    Serial.println(Count);
  }

  clockLastStatus = clockCurrentStatus;
  
  int pushStatus = digitalRead(REncoderPinD);
  if (pushStatus == LOW) {
    if (millis() - lastButtonPress > 50) Serial.println("Push button pressed");
    lastButtonPress = millis();
  }
  delay(10);
}

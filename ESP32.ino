#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#define TXD 17
#define RXD 16

void setup() {
  Serial.begin(9600); // USB debug
  Serial2.begin(9600, SERIAL_8N1, RXD, TXD); // RX, TX for Arduino

  Dabble.begin("ESP32-Car");
}

void loop() {
  Dabble.processInput();

  int y = GamePad.getYaxisData();
  int x = GamePad.getXaxisData();

  if (y > 10) {
    Serial2.println("F");
  } else if (y < -10) {
    Serial2.println("B");
  } else if (x > 10) {
    Serial2.println("R");
  } else if (x < -10) {
    Serial2.println("L");
  } else {
    Serial2.println("S");
  }

  delay(100);
}

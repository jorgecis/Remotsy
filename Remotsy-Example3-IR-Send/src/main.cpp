#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

uint16_t Samsung_power_toggle[71] = {
    38000, 1, 1, 170, 170, 20, 63, 20, 63, 20, 63, 20, 20, 20, 20, 20, 20, 20,
    20, 20, 20, 20, 63, 20, 63, 20, 63, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
    20, 20, 20, 63, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 63, 20,
    20, 20, 63, 20, 63, 20, 63, 20, 63, 20, 63, 20, 63, 20, 1798};

IRsend irsend(4);  

void setup() {
  irsend.begin();
  Serial.begin(115200);
}

void loop() {
  Serial.println("Toggling power");
  irsend.sendGC(Samsung_power_toggle, 71);
  delay(10000);
}

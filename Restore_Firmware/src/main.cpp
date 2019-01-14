#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266httpUpdate.h>
#include <Adafruit_NeoPixel.h>
#include <Ticker.h>

#define BUILTIN_LED 14

// Change this to your WiFi credentials.
const char* ssid = "";
const char* password = "";
uint8_t deltabright = 8;
int8_t brightdir = 1;
Adafruit_NeoPixel LED = Adafruit_NeoPixel(1, BUILTIN_LED, NEO_GRB + NEO_KHZ800);
Ticker led_ticker;

void ICACHE_FLASH_ATTR glowing() {
  LED.setPixelColor(0, 0, deltabright, 0);
  LED.show();
  if ((deltabright >= 248) || (deltabright <= 0)) {
    brightdir = brightdir * -1;
  }
  deltabright =  deltabright + (brightdir * 8);
}


void ICACHE_FLASH_ATTR do_update() {
  char url[40];
  snprintf (url, sizeof(url), "/update?board=2.0&chipid=%08x", ESP.getChipId()); 
  auto ret = ESPhttpUpdate.update("remotsy.com", 80, url, "1.0");
    switch (ret) {
      case HTTP_UPDATE_FAILED:
      Serial.println("HTTP_UPDATE_FAILD Error");
      Serial.println(ESPhttpUpdate.getLastErrorString().c_str());
      ESP.restart();
      break;
      case HTTP_UPDATE_NO_UPDATES:
      Serial.println("[update] Update no Update.");
      break;
      case HTTP_UPDATE_OK:
      Serial.println("[update] Update ok.");
      break;
    }    
}


void setup() {
  Serial.begin(115200);
  LED.begin();
  LED.show();
  led_ticker.attach_ms(30, glowing);

  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.println("Begin Update");
  // The server will validate the chip id to flash only
  // remtorsy boards.
  do_update();
}
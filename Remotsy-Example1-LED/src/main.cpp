#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Ticker.h>


Adafruit_NeoPixel LED = Adafruit_NeoPixel(1, BUILTIN_LED, NEO_GRB + NEO_KHZ800);
Ticker led_ticker;

void tick()
{
  uint32_t color = LED.getPixelColor(0);
  if (color == 0) {
    LED.setPixelColor(0, 0x10CCFF);
  } else {
    LED.setPixelColor(0, 0);
  }
  LED.show();
}

void setup() {
  led_ticker.attach(500, tick);
}

void loop() {
}

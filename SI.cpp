#include <Adafruit_NeoPixel.h>

#include "Configuration.h"
#include "Side_illumination.h"

Adafruit_NeoPixel leds = Adafruit_NeoPixel(35, matrixLed, NEO_GRB + NEO_KHZ800);

bool blink;

SI::SI() {
  leds.setBrightness(BRIGHTNESS);
  leds.begin();
  blink = false;
}

void SI::load() {
    blink = !blink;
    if (blink) {
      for (int i = 0; i < 12; i++) {
        leds.setPixelColor(i, leds.Color(0, 71, 171));
        leds.show();
      }
    } else {
      for (int i = 0; i < 12; i++) {
        leds.setPixelColor(i, leds.Color(0, 0, 0));
        leds.show();
      }
    }
}
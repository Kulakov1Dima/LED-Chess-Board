#include <Adafruit_NeoPixel.h>
#include "Configuration.h"
#include "Screensaver.h"

Adafruit_NeoPixel panel = Adafruit_NeoPixel(67, MATRIX_LED, NEO_GRB + NEO_KHZ400);

Screensaver::Screensaver() {
  panel.begin();
  panel.setBrightness(BRIGHTNESS);
}

void Screensaver::start() {
  panel.setPixelColor(35, panel.Color(255, 255, 255));
  panel.setPixelColor(42, panel.Color(255, 255, 255));
  panel.setPixelColor(36, panel.Color(0, 0, 255));
  panel.setPixelColor(37, panel.Color(0, 0, 255));
  panel.setPixelColor(41, panel.Color(0, 0, 255));
  panel.setPixelColor(40, panel.Color(255, 0, 0));
  panel.setPixelColor(38, panel.Color(255, 0, 0));
  panel.setPixelColor(43, panel.Color(255, 255, 255));
  panel.setPixelColor(44, panel.Color(0, 0, 255));
  panel.setPixelColor(45, panel.Color(0, 0, 255));
  panel.setPixelColor(46, panel.Color(255, 0, 0));
  panel.setPixelColor(48, panel.Color(255, 0, 0));
  panel.setPixelColor(49, panel.Color(0, 0, 255));
  panel.setPixelColor(50, panel.Color(255, 255, 255));
  panel.setPixelColor(51, panel.Color(255, 255, 255));
  panel.setPixelColor(52, panel.Color(0, 0, 255));
  panel.setPixelColor(53, panel.Color(0, 0, 255));
  panel.setPixelColor(54, panel.Color(255, 0, 0));
  panel.setPixelColor(56, panel.Color(255, 0, 0));
  panel.setPixelColor(57, panel.Color(0, 0, 255));
  panel.setPixelColor(58, panel.Color(255, 255, 255));
  panel.setPixelColor(59, panel.Color(255, 255, 255));
  panel.setPixelColor(60, panel.Color(0, 0, 255));
  panel.setPixelColor(61, panel.Color(0, 0, 255));
  panel.setPixelColor(62, panel.Color(255, 0, 0));
  panel.setPixelColor(64, panel.Color(255, 0, 0));
  panel.setPixelColor(65, panel.Color(0, 0, 255));
  panel.setPixelColor(66, panel.Color(255, 255, 255));
  panel.show();
  delay(DELAY_SCREENSAVER);
}
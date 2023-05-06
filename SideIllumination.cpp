#include <Adafruit_NeoPixel.h>
#include "Configuration.h"
#include "SideIllumination.h"


Adafruit_NeoPixel i_panel = Adafruit_NeoPixel(35, MATRIX_LED, NEO_GRB + NEO_KHZ400);
int pixel;

SI::SI() {
  i_panel.begin();
  i_panel.setBrightness(BRIGHTNESS);
  pixel = 0;
}

void SI::loading_panel() {
  if (!(millis() % 100)) {
    i_panel.setBrightness(BRIGHTNESS - 50);
    i_panel.setPixelColor(pixel - 6, i_panel.Color(160, 50, 150));
    i_panel.setBrightness(BRIGHTNESS - 40);
    i_panel.setPixelColor(pixel - 5, i_panel.Color(170, 45, 149));
    i_panel.setBrightness(BRIGHTNESS - 30);
    i_panel.setPixelColor(pixel - 4, i_panel.Color(180, 40, 147));
    i_panel.setBrightness(BRIGHTNESS - 20);
    i_panel.setPixelColor(pixel - 3, i_panel.Color(190, 30, 145));
    i_panel.setBrightness(BRIGHTNESS - 5);
    i_panel.setPixelColor(pixel - 2, i_panel.Color(210, 20, 140));
    i_panel.setBrightness(BRIGHTNESS + 5);
    i_panel.setPixelColor(pixel - 1, i_panel.Color(230, 15, 130));
    i_panel.setBrightness(BRIGHTNESS + 20);
    i_panel.setPixelColor(pixel, i_panel.Color(250, 2, 140));
    pixel++;
    if (pixel < 36) i_panel.show();
    if (pixel > 40) pixel = 0;
  }
}

void SI::ok_panel() {
  i_panel.setBrightness(BRIGHTNESS);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.AFFIRMATIVE_SIGNAL);
  }
  i_panel.show();
  delay(200);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.Color(0, 0, 0));
  }
  i_panel.show();
  delay(70);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.AFFIRMATIVE_SIGNAL);
  }
  i_panel.show();
  delay(200);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.Color(0, 0, 0));
  }
  i_panel.show();
}

void SI::error_panel() {
  int p = pixel;
  i_panel.setBrightness(BRIGHTNESS);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.ERROR_SIGNAL);
  }
  i_panel.show();
  delay(100);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.Color(0, 0, 0));
  }
  i_panel.show();
  delay(40);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.ERROR_SIGNAL);
  }
  i_panel.show();
  delay(100);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.Color(0, 0, 0));
  }
  delay(10);
  for (pixel = 0; pixel < 36; pixel++) {
    i_panel.setPixelColor(pixel, i_panel.ERROR_SIGNAL);
  }
  i_panel.show();
  pixel = p;
}
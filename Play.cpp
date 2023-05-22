#include <Adafruit_NeoPixel.h>
#include <ESP_EEPROM.h>
#include "Configuration.h"
#include "Play.h"

Adafruit_NeoPixel matrix_game = Adafruit_NeoPixel(67, MATRIX_LED, NEO_GRB + NEO_KHZ400);
String last_step = "";
String one_square = "";
long one_square_time = 0;
uint32_t color_square;
int pix;

Play::Play() {
}

String checkersMatrix[] = { "A1", "A3", "A5", "A7", "B8", "B6", "B4", "B2",
                            "C1", "C3", "C5", "C7", "D8", "D6", "D4", "D2",
                            "E1", "E3", "E5", "E7", "F8", "F6", "F4", "F2",
                            "G1", "G3", "G5", "G7", "H8", "H6", "H4", "H2"
                          };

/*
  String checkersMatrix[] = { "H8", "H6", "H4", "H2", "G1", "G3", "G5", "G7",
                            "F8", "F6", "F4", "F2", "E1", "E3", "E5", "E7",
                            "D8", "D6", "D4", "D2", "C1", "C3", "C5", "C7",
                            "B8", "B6", "B4", "B2", "A1", "A3", "A5", "A7"
                          };*/

uint32_t matrix_color[] = { matrix_game.COLOR_PLAYER_1, matrix_game.COLOR_PLAYER_1, 0, matrix_game.COLOR_PLAYER_2, matrix_game.COLOR_PLAYER_2, matrix_game.COLOR_PLAYER_2, 0, matrix_game.COLOR_PLAYER_1,
                            matrix_game.COLOR_PLAYER_1, matrix_game.COLOR_PLAYER_1, 0, matrix_game.COLOR_PLAYER_2, matrix_game.COLOR_PLAYER_2, matrix_game.COLOR_PLAYER_2, 0, matrix_game.COLOR_PLAYER_1,
                            matrix_game.COLOR_PLAYER_1, matrix_game.COLOR_PLAYER_1, 0, matrix_game.COLOR_PLAYER_2, matrix_game.COLOR_PLAYER_2, matrix_game.COLOR_PLAYER_2, 0, matrix_game.COLOR_PLAYER_1,
                            matrix_game.COLOR_PLAYER_1, matrix_game.COLOR_PLAYER_1, 0, matrix_game.COLOR_PLAYER_2, matrix_game.COLOR_PLAYER_2, matrix_game.COLOR_PLAYER_2, 0, matrix_game.COLOR_PLAYER_1
                          };

void Play::start() {
  EEPROM.begin(32);
  //EEPROM.get(0, matrix_color);

  matrix_game.begin();
  matrix_game.setBrightness(BRIGHTNESS);
  for (int coord = 0; coord < 32; coord++) {
    matrix_game.setPixelColor(found_led(checkersMatrix[coord]), matrix_color[coord]);
  }
  matrix_game.show();
}

int Play::found_led(String coord) {
  for (int matrixLeds = 0; matrixLeds < 32; matrixLeds++) {
    if (checkersMatrix[matrixLeds] == coord) {
      if (LED_CHESS_BOARD_VERSION == "2023012") {
        return matrixLeds + 35;
      } else {
        return matrixLeds;
      }
    }
  }
  return -99;
}

void Play::game(String step) {

  if (step.length() == 2) {
    blink(step);
    if (one_square != step) {
      if (one_square != "") {
        pawn_move(one_square, step);
      }
      one_square = step;
    }
  } else {
    if (last_step != step) {
      for (int count_steps = 0; count_steps < step.length() / 2; count_steps += 2) {
        String steps = step.substring(0 + count_steps, 4 + count_steps);
        pawn_move(steps.substring(0, 2), steps.substring(2, 4));
        last_step = step;
      }
    }
  }
  EEPROM.put(0, matrix_color);
  boolean ok1 = EEPROM.commit();
  DEBUG((ok1) ? "First commit OK" : "Commit failed");
  DEBUG("\n");
}


void Play::pawn_move(String x, String y) {
  if (found_led(x) == -99) {
    error();
    return;
  }
  if (found_led(y) == -99) {
    error();
    return;
  }
  for (int coord = 0; coord < 32; coord++) {
    if (checkersMatrix[coord] == y) {
      if (matrix_color[coord] != 0) {
        error();
        return;
      }
      for (int coord1 = 0; coord1 < 32; coord1++) {
        if (checkersMatrix[coord1] == x) {
          if (matrix_color[coord1] == 0) {
            error();
            return;
          } else {
            if (checkGame(x, y)) {
              ok();
              matrix_color[coord] = matrix_color[coord1];
              matrix_color[coord1] = 0;
              ladies(x, y);
            }
          }
        }
      }
    }
  }
  for (int coord = 0; coord < 32; coord++) {
    matrix_game.setPixelColor(found_led(checkersMatrix[coord]), matrix_color[coord]);
  }
  matrix_game.show();
}

bool Play::checkGame(String x, String y) {
  bool permission_step = check_step(x, y);
  permission_step += check_kill(x, y);
  permission_step += step_ladies(x, y);
  if (!permission_step) {
    error();
  }
  return permission_step;
}

bool Play::check_kill(String x, String y) {
  String nulPozition = "";

  if (x.charAt(0) - 2 == y.charAt(0)) {
    nulPozition = char(x.charAt(0) - 1);
    int x1 = x.charAt(1) - 48;
    int y1 = y.charAt(1) - 48;
    if (x1 - 2 == y1) nulPozition = nulPozition + (y1 + 1);
    if (x1 + 2 == y1) nulPozition = nulPozition + (y1 - 1);
  }

  if (x.charAt(0) + 2 == y.charAt(0)) {
    int x1 = x.charAt(1) - 48;
    int y1 = y.charAt(1) - 48;
    nulPozition = char(x.charAt(0) + 1);
    if (x1 - 2 == y1) nulPozition = nulPozition + (y1 + 1);
    if (x1 + 2 == y1) nulPozition = nulPozition + (y1 - 1);
  }

  for (int coord = 0; coord < 32; coord++) {
    if (checkersMatrix[coord] == nulPozition) {
      for (int coord1 = 0; coord1 < 32; coord1++) {
        if (checkersMatrix[coord1] == x)
          if (matrix_color[coord] != matrix_color[coord1]) {
            if (matrix_color[coord] != 0) {
              matrix_color[coord] = 0;
              return true;
            }
          }
      }
    }
  }
  return false;
}

bool Play::check_step(String x, String y) {
  if (x.charAt(0) - 1 == y.charAt(0)) {

    for (int coord = 0; coord < 32; coord++) {
      if (checkersMatrix[coord] == x) {
        if (matrix_color[coord] == matrix_game.COLOR_PLAYER_2)
          if (x.charAt(1) - 1 == y.charAt(1)) return true;
      }
    }

    for (int coord = 0; coord < 32; coord++) {
      if (checkersMatrix[coord] == x) {
        if (matrix_color[coord] == matrix_game.COLOR_PLAYER_1)
          if (x.charAt(1) + 1 == y.charAt(1)) return true;
      }
    }
  }
  if (x.charAt(0) + 1 == y.charAt(0)) {

    for (int coord = 0; coord < 32; coord++) {
      if (checkersMatrix[coord] == x) {
        if (matrix_color[coord] == matrix_game.COLOR_PLAYER_2)
          if (x.charAt(1) - 1 == y.charAt(1)) return true;
      }
    }

    for (int coord = 0; coord < 32; coord++) {
      if (checkersMatrix[coord] == x) {
        if (matrix_color[coord] == matrix_game.COLOR_PLAYER_1)
          if (x.charAt(1) + 1 == y.charAt(1)) return true;
      }
    }
  }
  return false;
}


bool Play::step_ladies(String x, String y) {
  for (int coord = 0; coord < 32; coord++) {
    if (checkersMatrix[coord]  == y) {
      if (matrix_color[coord] == 0) {
        for (int coord1 = 0; coord1 < 32; coord1++) {
          if (checkersMatrix[coord1] == x) {
            if (matrix_color[coord1] == matrix_game.COLOR_LADIES_1 || matrix_color[coord1] == matrix_game.COLOR_LADIES_2) {
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}

String ladies_matrix1[] = { "A1", "C1", "E1", "G1"};
                         
String ladies_matrix2[] = { "B8", "D8", "F8", "H8"};

void Play::ladies(String x, String y) {
  for (int c = 0; c < 4; c++) {
    if (y == ladies_matrix1[c])
      for (int coord = 0; coord < 32; coord++) {
        if (checkersMatrix[coord] == y) {
          if (matrix_color[coord] == matrix_game.COLOR_PLAYER_2) matrix_color[coord] = matrix_game.COLOR_LADIES_2;
        }
      }
  }
    for (int c = 0; c < 4; c++) {
    if (y == ladies_matrix2[c])
      for (int coord = 0; coord < 32; coord++) {
        if (checkersMatrix[coord] == y) {
          if (matrix_color[coord] == matrix_game.COLOR_PLAYER_1) matrix_color[coord] = matrix_game.COLOR_LADIES_1;
        }
      }
  }
}

void Play::blink(String x) {
  if (millis() - one_square_time > 500) {
    one_square_time = millis();
    for (int coord = 0; coord < 32; coord++) {
      if (checkersMatrix[coord] == x) {
        color_square = matrix_color[coord];
      }
    }
    matrix_game.setPixelColor(found_led(x), matrix_game.Color(0, 0, 0));
    matrix_game.show();
    delay(200);
    matrix_game.setPixelColor(found_led(x), color_square);
    matrix_game.show();
  }
}

void Play::ok() {
  matrix_game.setBrightness(BRIGHTNESS);
  for (pix = 0; pix < 35; pix++) {
    matrix_game.setPixelColor(pix, matrix_game.AFFIRMATIVE_SIGNAL);
  }
  matrix_game.show();
  delay(200);
  for (pix = 0; pix < 35; pix++) {
    matrix_game.setPixelColor(pix, matrix_game.Color(0, 0, 0));
  }
  matrix_game.show();
  delay(70);
  for (pix = 0; pix < 35; pix++) {
    matrix_game.setPixelColor(pix, matrix_game.AFFIRMATIVE_SIGNAL);
  }
  matrix_game.show();
  delay(200);
  for (pix = 0; pix < 35; pix++) {
    matrix_game.setPixelColor(pix, matrix_game.Color(0, 0, 0));
  }
  matrix_game.show();
}

void Play::error() {
  int p = pix;
  matrix_game.setBrightness(BRIGHTNESS);
  for (pix = 0; pix < 35; pix++) {
    matrix_game.setPixelColor(pix, matrix_game.ERROR_SIGNAL);
  }
  matrix_game.show();
  delay(100);
  for (pix = 0; pix < 35; pix++) {
    matrix_game.setPixelColor(pix, matrix_game.Color(0, 0, 0));
  }
  matrix_game.show();
  delay(40);
  for (pix = 0; pix < 35; pix++) {
    matrix_game.setPixelColor(pix, matrix_game.ERROR_SIGNAL);
  }
  matrix_game.show();
  delay(100);
  for (pix = 0; pix < 35; pix++) {
    matrix_game.setPixelColor(pix, matrix_game.Color(0, 0, 0));
  }
  matrix_game.show();
  pix = p;
}

#ifndef GLOBALS_H
#define GLOBALS_H

#include <LiquidCrystal_I2C.h>

const int MAX_ROWS = 2;
const int MAX_CHARS = 16;
const int LCD_ADDRESS = 0x27;

const int PIN_BUZZER = 4;
const int PIN_BUTTON = 8;

const int PIN_PAD_1 = 13;
const int PIN_PAD_3 = 12;
const int PIN_PAD_5 = 11;
const int PIN_PAD_7 = 10;

extern LiquidCrystal_I2C lcd;

#endif

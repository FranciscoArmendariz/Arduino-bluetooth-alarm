#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include "LiquidCrystal_I2C.h"

// LCD constants
const int MAX_ROWS = 2;
const int MAX_CHARS = 16;
const int LCD_ADDRESS = 0x27;

extern LiquidCrystal_I2C lcd;

// pins fo I/O
const int PIN_BUZZER = 4;
const int PIN_BUTTON = 8;

const int PIN_PAD_1 = 13;
const int PIN_PAD_3 = 12;
const int PIN_PAD_5 = 11;
const int PIN_PAD_7 = 10;

const int INPUT_PINS[] = {PIN_BUTTON, PIN_PAD_1, PIN_PAD_3, PIN_PAD_5, PIN_PAD_7};

// set the current view and current view on the display
extern int currentView;
extern int currentDisplay;

// view IDs
const int CLOCK_VIEW = 0;
const int MENU_VIEW = 1;
const int ALARM_VIEW = 2;
const int ALARM_CONFIG_VIEW = 3;

#endif

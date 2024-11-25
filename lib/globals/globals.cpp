#include "globals.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, MAX_CHARS, MAX_ROWS);

int currentView = CLOCK_VIEW;
int currentDisplay = CLOCK_VIEW;

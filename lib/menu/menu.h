#ifndef MENU_H
#define MENU_H

#include <LiquidCrystal_I2C.h>

void showViewById(int viewId);

void showTime();
void showMenu();
void showAlarm();

extern int currentView;

const int TIME_VIEW = 0;
const int MENU_VIEW = 1;
const int ALARM_VIEW = 2;
const int SET_ALARM_VIEW = 3;

extern LiquidCrystal_I2C lcd;

#endif

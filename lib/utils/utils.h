#ifndef UTILS_H
#define UTILS_H

#include <RTClib.h>

String formatTime(const DateTime time, bool hasSeconds = true);
String formatTime(int hours, int minutes, int seconds = -1);
String formatDate(const DateTime date);

// we register when a button is pressed in so we cand do an action when pressing out
extern int pressedInButton;
void pressInListener();
bool pressOut(int pin);

#endif

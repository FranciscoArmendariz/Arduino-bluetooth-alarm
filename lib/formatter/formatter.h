#ifndef FORMATTER_H
#define FORMATTER_H

#include <Arduino.h>
#include <RTClib.h>

String formatTime(const DateTime time);
String formatDate(const DateTime date);

#endif

#ifndef ALARM_FUNCTIONS
#define ALARM_FUNCTIONS

#include <RTClib.h>

// VARIABLES
extern RTC_DS3231 rtc;

extern int alarmState;
const int ALARM_OFF = 0;
const int ALARM_RINGING = 1;

// FUNCTIONS
void startAlarm();
void stopAlarm();
void updateAlarm();

#endif

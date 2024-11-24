#ifndef ALARM_FUNCTIONS
#define ALARM_FUNCTIONS

#include <RTClib.h>

// VARIABLES
extern RTC_DS3231 rtc;
extern DateTime dateTime;
extern DateTime alarmTime;

extern int alarmState;
const int ALARM_OFF = 0;
const int ALARM_ON = 1;

extern bool alarmTriggered;

// FUNCTIONS
void startAlarm();
void stopAlarm();
void updateAlarm();
bool isAlarmTime();

#endif


#include "alarm.h"
#include "globals.h"

RTC_DS3231 rtc;
DateTime dateTime = DateTime();
DateTime prevDateTime = dateTime;
DateTime alarmTime = DateTime("2024/11/24", "18:54:0");

int alarmState = ALARM_OFF;

const long toneInterval = 75;
const long pauseInterval = 925;
long previousMillis = 0;
int toneStep = 0;

int previousView = CLOCK_VIEW;

bool alarmTriggered = false;
int alarmTriggeredHour = 0;
int alarmTriggeredMinute = 0;

bool isAlarmTime()
{
    if (alarmTriggered)
    {
        if (dateTime.hour() >= alarmTriggeredHour && dateTime.minute() >= alarmTriggeredMinute + 1)
        {
            alarmTriggered = false;
        };
        return false;
    }
    if (dateTime.hour() == alarmTime.hour() && dateTime.minute() == alarmTime.minute())
    {
        alarmTriggered = true;
        alarmTriggeredHour = alarmTime.hour();
        alarmTriggeredMinute = alarmTime.minute();
        return true;
    }
    return false;
}

void startAlarm()
{
    alarmState = ALARM_ON;
    previousView = currentView;
    currentView = ALARM_VIEW;
    toneStep = 0;
    previousMillis = millis(); // Initialize timer
}

void stopAlarm()
{
    alarmState = ALARM_OFF;
    currentView = previousView;
    noTone(PIN_BUZZER);
}

void updateAlarm()
{
    if (alarmState == ALARM_OFF)
    {
        if (isAlarmTime() && alarmState != ALARM_ON)
        {
            startAlarm();
        }
        return;
    }

    long currentMillis = millis();

    if (alarmState == ALARM_ON)
    {
        if (currentMillis - previousMillis >= toneInterval)
        {
            previousMillis = currentMillis;

            // Alternate between tone and silence
            if (toneStep < 8)
            {
                if (toneStep % 2 == 0)
                {
                    tone(PIN_BUZZER, 3000);
                }
                else
                {
                    noTone(PIN_BUZZER);
                }
                toneStep++;
            }
            else
            // when the loop end of 4 tones and 4 silences is reached the loop resets and a longer pause is made
            {
                noTone(PIN_BUZZER);
                toneStep++;
                previousMillis += pauseInterval - toneInterval;
                toneStep = 0;
            }
        }
    }
}


#include "alarm.h"
#include "globals.h"
#include "menu.h"

RTC_DS3231 rtc;
DateTime dateTime = DateTime();
DateTime alarmTime = DateTime("2024/11/24", "16:49:0");

int alarmState = ALARM_OFF;

const long toneInterval = 75;
const long pauseInterval = 925;
long previousMillis = 0;
int toneStep = 0;

int previousView = TIME_VIEW;

bool alarmTriggered = false;

bool isAlarmTime()
{
    if (alarmTriggered)
    {
        if (dateTime >= (alarmTime + TimeSpan(60)))
        {
            alarmTriggered = false;
        };
        return false;
    }
    if (dateTime.hour() == alarmTime.hour() && dateTime.minute() == alarmTime.minute())
    {
        alarmTriggered = true;
        return true;
    }
    return false;
}

void startAlarm()
{
    alarmState = ALARM_ON;
    previousView = currentView;
    showAlarm();
    toneStep = 0;
    previousMillis = millis(); // Initialize timer
}

void stopAlarm()
{
    alarmState = ALARM_OFF;
    showViewById(previousView);
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

    if (digitalRead(PIN_BUTTON) == LOW)
    {
        stopAlarm();
        return;
    }

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
            {
                noTone(PIN_BUZZER);
                toneStep++;
                previousMillis += pauseInterval - toneInterval;
                toneStep = 0;
            }
        }
    }
}

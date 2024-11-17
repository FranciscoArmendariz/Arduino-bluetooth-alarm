
#include "alarm.h"
#include "globals.h"

RTC_DS3231 rtc;
int alarmState = ALARM_OFF;

const long toneInterval = 75;   // 75ms for tone on/off
const long pauseInterval = 925; // 925ms pause between cycles
long previousMillis = 0;
int toneCycle = 0; // Keeps track of tone cycles

void startAlarm()
{
    alarmState = ALARM_RINGING;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  !!!ALARMA!!!  ");
    toneCycle = 0;
    previousMillis = millis(); // Initialize timer
}

void stopAlarm()
{
    alarmState = ALARM_OFF;
    lcd.clear();
    noTone(PIN_BUZZER);
}

void updateAlarm()
{
    if (alarmState == ALARM_OFF)
    {
        return;
    }

    long currentMillis = millis();

    if (digitalRead(PIN_BUTTON) == LOW)
    {
        stopAlarm();
        return;
    }

    if (alarmState == ALARM_RINGING)
    {
        if (currentMillis - previousMillis >= toneInterval)
        {
            previousMillis = currentMillis;

            // Alternate between tone and silence
            if (toneCycle < 8)
            {
                if (toneCycle % 2 == 0)
                {
                    tone(PIN_BUZZER, 3000);
                }
                else
                {
                    noTone(PIN_BUZZER);
                }
                toneCycle++;
            }
            else if (toneCycle == 8)
            {
                noTone(PIN_BUZZER);
                toneCycle++;
                previousMillis += pauseInterval - toneInterval; // Skip the pause duration
            }
            else
            {
                toneCycle = 0; // Reset cycle
            }
        }
    }
}

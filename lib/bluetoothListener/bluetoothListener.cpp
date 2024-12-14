#include <Arduino.h>
#include "utils.h"
#include "globals.h"
#include "alarm.h"
#include "bluetoothListener.h"

extern SoftwareSerial bluetooth(5, 6);

void handleSetDateCommand(String *messageParts)
{
    int year = messageParts[1].toInt();
    int month = messageParts[2].toInt();
    int day = messageParts[3].toInt();

    DateTime currentTime = rtc.now();
    DateTime newDate = DateTime(year, month, day, currentTime.hour(), currentTime.minute(), currentTime.second());
    rtc.adjust(newDate);
}

void handleSetTimeCommand(String *messageParts)
{
    int hour = messageParts[1].toInt();
    int minute = messageParts[2].toInt();
    int second = messageParts[3].toInt();

    DateTime currentDate = rtc.now();
    DateTime newTime = DateTime(currentDate.year(), currentDate.month(), currentDate.day(), hour, minute, second);
    rtc.adjust(newTime);
}

void handleSetAlarmCommand(String *messageParts)
{
    int hour = messageParts[1].toInt();
    int minute = messageParts[2].toInt();

    DateTime currentDate = rtc.now();
    alarmTime = DateTime(currentDate.year(), currentDate.month(), currentDate.day(), hour, minute, 0);
    alarmTriggered = false;
}

void listenBluetooth()
{
    if (bluetooth.available() > 0)
    {
        String message = "";
        message = bluetooth.readStringUntil(';');

        String messageParts[4];
        int partsCount = 0;

        while (message.length() > 0 && partsCount < 4)
        {
            int index = message.indexOf("-");
            if (index == -1)
            {
                messageParts[partsCount] = message;
                break;
            }
            else
            {
                messageParts[partsCount] = message.substring(0, index);
                partsCount++;
                message = message.substring(index + 1);
            }
        }
        String command = messageParts[0];

        if (command == DATE_COMMAND)
        {
            handleSetDateCommand(messageParts);
        }
        if (command == TIME_COMMAND)
        {
            handleSetTimeCommand(messageParts);
        }
        if (command == ALARM_COMMAND)
        {
            handleSetAlarmCommand(messageParts);
        }
    }
}


#include "utils.h"
#include "globals.h"

String formatDate(const DateTime date)
{
    String formattedDate = "";

    if (date.day() < 10)
    {
        formattedDate += "0";
    }
    formattedDate += String(date.day()) + "/";

    if (date.month() < 10)
    {
        formattedDate += "0";
    }
    formattedDate += String(date.month()) + "/";

    formattedDate += String(date.year());

    return formattedDate;
}

String formatTime(const DateTime time, bool hasSeconds)
{
    String formattedTime = "";

    if (time.hour() < 10)
    {
        formattedTime += "0";
    }
    formattedTime += String(time.hour()) + ":";

    if (time.minute() < 10)
    {
        formattedTime += "0";
    }
    formattedTime += String(time.minute());

    if (hasSeconds)
    {
        formattedTime += ":";
        if (time.second() < 10)
        {
            formattedTime += "0";
        }
        formattedTime += String(time.second());
    }

    return formattedTime;
}

String formatTime(int hours, int minutes, int seconds)
{
    String formattedTime = "";

    if (hours < 10)
    {
        formattedTime += "0";
    }
    formattedTime += String(hours) + ":";

    if (minutes < 10)
    {
        formattedTime += "0";
    }
    formattedTime += String(minutes);

    if (seconds >= 0)
    {
        formattedTime += ":";
        if (seconds < 10)
        {
            formattedTime += "0";
        }
        formattedTime += String(seconds);
    }

    return formattedTime;
}

int pressedInButton = -1;

void pressInListener()
{
    for (int pin : INPUT_PINS)
    {
        if (digitalRead(pin) == LOW)
        {
            pressedInButton = pin;
        }
    }
}

bool pressOut(int pin)
{
    if (pin == pressedInButton && digitalRead(pin) == HIGH)
    {
        pressedInButton = -1;
        return true;
    }
    return false;
}


#include "formatter.h"

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

String formatTime(const DateTime time)
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
    formattedTime += String(time.minute()) + ":";

    if (time.second() < 10)
    {
        formattedTime += "0";
    }
    formattedTime += String(time.second());

    return formattedTime;
}

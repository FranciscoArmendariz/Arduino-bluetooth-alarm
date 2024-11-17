
#include "formatter.h"

String formatDate(const DateTime date)
{
    String formattedDate = "";

    // Add leading zero for day if necessary
    if (date.day() < 10)
    {
        formattedDate += "0";
    }
    formattedDate += String(date.day()) + "/";

    // Add leading zero for month if necessary
    if (date.month() < 10)
    {
        formattedDate += "0";
    }
    formattedDate += String(date.month()) + "/";

    // Add year (no leading zero needed)
    formattedDate += String(date.year());

    return formattedDate;
}

String formatTime(const DateTime time)
{
    String formattedTime = "";

    // Add leading zero for hour if necessary
    if (time.hour() < 10)
    {
        formattedTime += "0";
    }
    formattedTime += String(time.hour()) + ":";

    // Add leading zero for minute if necessary
    if (time.minute() < 10)
    {
        formattedTime += "0";
    }
    formattedTime += String(time.minute()) + ":";

    // Add leading zero for second if necessary
    if (time.second() < 10)
    {
        formattedTime += "0";
    }
    formattedTime += String(time.second());

    return formattedTime;
}

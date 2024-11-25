#include "alarmView.h"
#include "globals.h"
#include "alarm.h"
#include "utils.h"

void setAlarmDisplay();
void handleAlarmInputs();

void alarmViewLoop()
{
    if (currentView != currentDisplay)
    {
        lcd.clear();
        setAlarmDisplay();
        currentDisplay = currentView;
    }
    handleAlarmInputs();
}
void setAlarmDisplay()
{
    currentView = ALARM_VIEW;
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.print("ALARMA!!!  ");
}

void handleAlarmInputs()
{
    if (pressOut(PIN_BUTTON))
    {
        stopAlarm();
    }
}

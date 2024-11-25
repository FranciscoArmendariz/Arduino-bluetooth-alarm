
#include "timeConfigView.h"
#include "globals.h"
#include "utils.h"
#include "alarm.h"

static bool changedValue = false;

static int hours = dateTime.hour();
static int minutes = dateTime.minute();

static void setTimeConfigDisplay();
static void updateDisplayTime();
static void handleTimeConfigInputs();

void timeConfigViewLoop()
{
    if (currentView != currentDisplay)
    {
        lcd.clear();
        hours = dateTime.hour();
        minutes = dateTime.minute();
        setTimeConfigDisplay();
        currentDisplay = currentView;
    }
    handleTimeConfigInputs();
    updateDisplayTime();
}
void setTimeConfigDisplay()
{
    lcd.setCursor(0, 0);
    lcd.print("7-");
    lcd.write(0);
    lcd.print("  5-Hrs 3-Min");
    lcd.setCursor(0, 1);
    String horaString = formatTime(hours, minutes, 0);
    lcd.print("[" + horaString + "]");
    lcd.setCursor(11, 1);
    lcd.print("1-OK");
}

void updateDisplayTime()
{
    if (changedValue)
    {
        lcd.setCursor(1, 1);
        changedValue = false;
        String horaString = formatTime(hours, minutes, 0);
        lcd.print(horaString);
    }
}

void handleTimeConfigInputs()
{
    if (pressOut(PIN_PAD_7))
    {
        currentView = MENU_VIEW;
    }
    if (pressOut(PIN_PAD_1))
    {
        dateTime = DateTime(dateTime.year(), dateTime.month(), dateTime.day(), hours, minutes, 0);
        rtc.adjust(dateTime);
        currentView = MENU_VIEW;
    }
    if (pressOut(PIN_PAD_5))
    {
        hours = (hours + 1) % 24;
        changedValue = true;
    }
    if (pressOut(PIN_PAD_3))
    {
        minutes = (minutes + 1) % 60;
        changedValue = true;
    }
};

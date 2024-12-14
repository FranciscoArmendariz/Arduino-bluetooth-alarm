#include "clockView.h"

#include "globals.h"
#include "alarm.h"
#include "utils.h"

bool backlightOn = true;

void setClockDisplay();
void handleClockInputs();

void clockViewLoop()
{
    if (currentView != currentDisplay)
    {
        lcd.clear();
        setClockDisplay();
        currentDisplay = currentView;
    }
    if (dateTime > prevDateTime)
    {
        setClockDisplay();
    }
    handleClockInputs();
}

void setClockDisplay()
{
    lcd.setCursor(0, 0);
    String fechaString = formatDate(dateTime);
    lcd.print(fechaString);
    lcd.setCursor(11, 0);
    lcd.print("5-lgt");
    lcd.setCursor(0, 1);
    String horaString = formatTime(dateTime);
    lcd.print(horaString);
    lcd.setCursor(10, 1);
    lcd.print("1-Menu");
}

void handleClockInputs()
{
    if (pressOut(PIN_PAD_1))
    {
        currentView = MENU_VIEW;
    }
    if (pressOut(PIN_PAD_5))
    {
        if (backlightOn)
        {
            lcd.noBacklight();
        }
        else
        {
            lcd.backlight();
        }
        backlightOn = !backlightOn;
    }
}

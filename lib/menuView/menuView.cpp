#include "menuView.h"
#include "globals.h"
#include "utils.h"

void setMenuDisplay();
void handleMenuInputs();

void menuViewLoop()
{
    if (currentView != currentDisplay)
    {
        lcd.clear();
        setMenuDisplay();
        currentDisplay = currentView;
    }
    handleMenuInputs();
}
void setMenuDisplay()
{
    lcd.setCursor(0, 0);
    lcd.print("7-");
    lcd.write(0);
    lcd.setCursor(8, 0);
    lcd.print("3-Fecha");
    lcd.setCursor(0, 1);
    lcd.print("5-Hora  1-Alarma");
}

void handleMenuInputs()
{
    if (pressOut(PIN_PAD_7))
    {
        currentView = CLOCK_VIEW;
    }
    if (pressOut(PIN_PAD_1))
    {
        currentView = ALARM_CONFIG_VIEW;
    }
    if (pressOut(PIN_PAD_5))
    {
        currentView = TIME_CONFIG_VIEW;
    }
}

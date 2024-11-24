#include "menu.h"
#include "alarm.h"
#include "globals.h"
#include "formatter.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, MAX_CHARS, MAX_ROWS);

int currentView = TIME_VIEW;

void showViewById(int viewId)
{
    switch (viewId)
    {
    case TIME_VIEW:
        showTime();
        break;
    case MENU_VIEW:
        showMenu();
        break;
    case ALARM_VIEW:
        showAlarm();
        break;
    default:
        showTime();
        break;
    }
}

void showTime()
{
    if (currentView != TIME_VIEW)
    {
        lcd.clear();
        currentView = TIME_VIEW;
    }

    lcd.setCursor(0, 0);
    String fechaString = formatDate(dateTime);
    lcd.print(fechaString);
    lcd.setCursor(0, 1);
    String horaString = formatTime(dateTime);
    lcd.print(horaString);
    lcd.setCursor(10, 1);
    lcd.print("1-Menu");
}
void showMenu()
{
    currentView = MENU_VIEW;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MENU  7-Volver");
    lcd.setCursor(0, 1);
    lcd.print("5-Hora  3-Alarma");
}

void showAlarm()
{
    currentView = ALARM_VIEW;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  !!!ALARMA!!!  ");
}

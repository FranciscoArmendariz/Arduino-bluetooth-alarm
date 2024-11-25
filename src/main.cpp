#include <SPI.h>
#include <Arduino.h>

#include "alarm.h"
#include "globals.h"
#include "clockView.h"
#include "menuView.h"
#include "alarmView.h"
#include "alarmConfigView.h"
#include "timeConfigView.h"
#include "utils.h"

byte backChar[] = {
    0x04,
    0x08,
    0x1F,
    0x09,
    0x05,
    0x01,
    0x0F,
    0x00};

byte openExclamationChar[] = {
    0x00,
    0x04,
    0x00,
    0x00,
    0x04,
    0x04,
    0x04,
    0x04};

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_BUZZER, OUTPUT);
  DDRB = B00000000;
  Wire.begin();
  Serial.begin(9600);
  lcd.init();
  lcd.createChar(0, backChar);
  lcd.createChar(1, openExclamationChar);
  lcd.backlight();

  if (!rtc.begin())
  {
    lcd.print("NO HAY RELOJ!");
    while (true)
    {
    }
  }
}

void loop()
{
  prevDateTime = dateTime;
  dateTime = rtc.now();
  updateAlarm();
  pressInListener();

  switch (currentView)
  {
  case CLOCK_VIEW:
    clockViewLoop();
    break;
  case MENU_VIEW:
    menuViewLoop();
    break;
  case ALARM_VIEW:
    alarmViewLoop();
    break;
  case ALARM_CONFIG_VIEW:
    alarmConfigViewLoop();
    break;
  case TIME_CONFIG_VIEW:
    timeConfigViewLoop();
    break;
  }
}

#include <SPI.h>
#include <Arduino.h>

#include "alarm.h"
#include "globals.h"
#include "menu.h"

DateTime prevTime;

void readInputs();

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  Wire.begin();
  lcd.init();
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
  prevTime = dateTime;
  dateTime = rtc.now();
  if (currentView == TIME_VIEW && dateTime > prevTime)
  {
    showTime();
    delay(250);
  }
  readInputs();
  updateAlarm();
}

void readInputs()
{
  switch (currentView)
  {
  case TIME_VIEW:
    if (digitalRead(PIN_PAD_1) == LOW)
    {
      showMenu();
    }
    break;

  case MENU_VIEW:
    if (digitalRead(PIN_PAD_7) == LOW)
    {
      showTime();
    }
    break;
  }
}

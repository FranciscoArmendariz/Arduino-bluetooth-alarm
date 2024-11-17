#include <SPI.h>
#include <Arduino.h>

#include "alarm.h"
#include "globals.h"
#include "formatter.h"

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
  DateTime dateTime = rtc.now();
  if (alarmState == ALARM_OFF)
  {
    lcd.setCursor(0, 0);
    String fechaString = formatDate(dateTime);
    lcd.print(fechaString);
    lcd.setCursor(0, 1);
    String horaString = formatTime(dateTime);
    lcd.print(horaString);
    delay(250);
  }
  if (dateTime.second() == 30 && alarmState != ALARM_RINGING)
  {
    startAlarm();
  }
  readInputs();
  updateAlarm();
}

void readInputs()
{
}

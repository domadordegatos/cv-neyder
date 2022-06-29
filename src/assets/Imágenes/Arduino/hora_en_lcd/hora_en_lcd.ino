#include <config.h>
#include <ds3231.h>
#include <RTClib.h>
#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;

#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4); 


 
String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };
 
void setup() {
  lcd.init();
  lcd.begin(20,4);
  lcd.backlight();


  
   Serial.begin(9600);
   delay(1000); 
 
   if (!rtc.begin()) {
      Serial.println(F("Couldn't find RTC"));
      while (1);
   }
 
   // Si se ha perdido la corriente, fijar fecha y hora
   if (rtc.lostPower()) {
      // Fijar a fecha y hora de compilacion
      rtc.adjust(DateTime(2018,4,12,8,3,0));
      
      // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
      // rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
   }
}
 
void printDate(DateTime date)
{
   Serial.print("AÑO ");  //
   Serial.print(date.year(), DEC);
   Serial.print('/');
   Serial.print("MES ");  //
   Serial.print(date.month(), DEC);
   Serial.print('/');
   Serial.print("DIA ");  //
   Serial.print(date.day(), DEC);
   Serial.print(" (");
   Serial.print(daysOfTheWeek[date.dayOfTheWeek()]);
   Serial.print(") ");
   Serial.print(date.hour(), DEC);
   Serial.print(':');
   Serial.print(date.minute(), DEC);
   Serial.print(':');
   Serial.print(date.second(), DEC);
   Serial.println();

   
   lcd.setCursor(0,0);
   lcd.print(date.hour());
      lcd.print(":");
   lcd.print(date.minute());
   lcd.print(":");
   lcd.print(date.second());
   lcd.print(" hora");
   
}
 
void loop() {
   // Obtener fecha actual y mostrar por Serial
   DateTime now = rtc.now();
   printDate(now);

 
   delay(1000);

 
}

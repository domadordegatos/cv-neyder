#include <Wire.h>
#include "RTClib.h"
int led1=6;
int led2=7;
int estado=0;
 
const int outputPin = LED_BUILTIN;
bool state = false;
 
// RTC_DS1307 rtc;
RTC_DS3231 rtc;
  
String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
   Serial.begin(9600);
   delay(1000);
 
   if (!rtc.begin()) {
      Serial.println(F("Couldn't find RTC"));
      while (1);
   }
 
   if (rtc.lostPower()) {
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   }
}void printDate(DateTime date){
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
}
 
// Comprobar si esta programado el encendido
bool isScheduledON(DateTime date)
{
   int weekDay = date.dayOfTheWeek();
   float hours = date.hour() + date.minute() / 60.0;
 
   // De 09:30 a 11:30 y de 21:00 a 23:00
   bool hourCondition = (hours >= 9.37 && hours <= 9.37) || (hours > 9.31 && hours < 9.32);

   if (hourCondition){
      estado='m';
   }
   estado='a';
}
 
void loop() {
   DateTime now = rtc.now();
 delay(1000);
   printDate(now);
   if (estado == 'm' )      // Apagado y debería estar encendido
   {
      digitalWrite(led1, HIGH);

      Serial.print("Activado");
   }
   else if (state == true && !isScheduledON(now))  // Encendido y deberia estar apagado
   {
      digitalWrite(led2, LOW);
      state = false;
      Serial.print("Desactivar");
   }

}



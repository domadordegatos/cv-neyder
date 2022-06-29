#include <Wire.h>
#include "RTClib.h"
 
const int outputPin = LED_BUILTIN;
bool state = false;
int led1=13;

String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };
 
// RTC_DS1307 rtc;
RTC_DS3231 rtc;
int hora=8;
int minuto=28; 
void setup() {
  pinMode(13,OUTPUT);
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
 
 bool isScheduledON(DateTime date){
   float hours = date.hour();
   float minutes = date.minute();
   bool hourCondition = (hours == '8' && minutes == '35');
   
   
 if (hourCondition){
      int state='m';
   }if(!hourCondition){
    state='a';
   }
 }
void loop() {
   DateTime now = rtc.now();
      printDate(now);
  if(state=='m'){
    digitalWrite(13,HIGH);
  }if(state=='a'){
    digitalWrite(13,LOW);
  }
}

#include <Wire.h>
#include <RTClib.h>

#include "RTClib.h"
 
// Declaramos un RTC DS3231
RTC_DS3231 rtc;
 
void setup () {
 Serial.begin(9600);
 
 delay(3000);
 
 // Comprobamos si tenemos el RTC conectado
 if (! rtc.begin()) {
 Serial.println("No hay un módulo RTC");
 while (1);
 }
 
 // Ponemos en hora, solo la primera vez, luego comentar y volver a cargar.
 // Ponemos en hora con los valores de la fecha y la hora en que el sketch ha sido compilado.
 // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
 
void loop () {
 DateTime now = rtc.now();
 Serial.print("DIA ");  //
 Serial.print(now.day());
 Serial.print('/');
 Serial.print("MES ");  //
 Serial.print(now.month());
 Serial.print('/');
 Serial.print("AÑO ");  //
 Serial.print(now.year());
 Serial.print(" ");
 Serial.print(now.hour());
 Serial.print(':');
 Serial.print(now.minute());
 Serial.print(':');
 Serial.print(now.second());
 Serial.println();
 delay(3000);
}



#include <Wire.h> 
#include "RTClib.h"

RTC_DS3231 RTC;
DateTime future = 0; // Variable para calcular cuando se debe desactivar la alarma

// CONFIGURACIÓN DE USUARIO
int seconds_alarm = 15; // Segundos alarma
int minutes_alarm = 6; // Minutos alarma
int hour_alarm = 9; // Horas alarma. Formato 24h
int day_alarm = 9; // Dia alarma
int month_alarm = 7; // Mes alarma
int year_alarm = 2014; // Año alarma
int weekday_alarm = 1; // Dia de la semana alarma. L(1), M(2), MX(3), J(4), V(5), S(6), D(7)
int alarm_duration = 10; // Tiempo activo de la alarma. Debe ser menor que la próxima alarma.

boolean all_seconds = false; // Alarma para todos los segundos
boolean all_minutes = false; // Alarma para todos los minutos
boolean all_hour = false; // Alarma para todas las horas
boolean all_weekday = true; // Alarma para todos los dias de la semana
boolean all_day = true; // Alarma para todos los dias
boolean all_month = true; // Alarma para todos los meses
boolean all_year = true; // Alarma para todos los años

int LedPin = 13;
// -------------

void setup () {
Wire.begin(); // Inicia el puerto I2C
RTC.begin(); // Inicia la comunicación con el RTC
//RTC.adjust(DateTime(__DATE__, __TIME__)); // Establece la fecha y hora (Comentar una vez establecida la hora)
pinMode(LedPin, OUTPUT);  // Establece el pin LedPin como salida 
Serial.begin(9600); // Establece la velocidad de datos del puerto serie
}

void loop(){
DateTime now = RTC.now(); // Obtiene la fecha y hora del RTC

Serial.print(now.year(), DEC); // Año
Serial.print('/');
Serial.print(now.month(), DEC); // Mes
Serial.print('/');
Serial.print(now.day(), DEC); // Dia
Serial.print(' ');
Serial.print(now.hour(), DEC); // Horas
Serial.print(':');
Serial.print(now.minute(), DEC); // Minutos
Serial.print(':');
Serial.print(now.second(), DEC); // Segundos
Serial.println();

if(now.hour() == hour_alarm && now.minute() == minutes_alarm && now.second() == seconds_alarm){
  digitalWrite(LedPin, HIGH);
  delay(5000);
  Serial.println("ACTIVIDADO");
}digitalWrite(LedPin, LOW);
}

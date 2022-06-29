#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 30
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);




String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo",  "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };
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





void setup() {
  Serial.begin(9600);
  dht.begin();

   lcd.init();
   lcd.begin(20,4);   
   lcd.backlight();




   
 



//sda blanco
//scl negro

//- negro
//+ blanco
// sda gris
//scl morado

   Serial.begin(9600);
   delay(1000); 
   if (!rtc.begin()) {
      Serial.println(F("Couldn't find RTC"));
      while (1);
   }
   // Si se ha perdido la corriente, fijar fecha y hora
   if (rtc.lostPower()) {
      // Fijar a fecha y hora de compilacion
     // rtc.adjust(DateTime(2018,6,9,11,4,0));
      
      // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
      // rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
   }
}
void printDate(DateTime date){
   lcd.setCursor(0,3);
   lcd.print(daysOfTheWeek[date.dayOfTheWeek()]);
   lcd.print(date.hour(), DEC);
   lcd.print(':');
   lcd.print(date.minute(), DEC);
   lcd.print(':');
   lcd.print(date.second(), DEC);
   lcd.println();

}
void loop() {

 delay(5000);
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahrenheit
  float f = dht.readTemperature(true);
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
  // Calcular el índice de calor en Fahrenheit
  float hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);

  lcd.setCursor(0,0);
  lcd.print("Hmd: ");
  lcd.print(h);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print("Tmp: ");
  lcd.print(t);
  lcd.print("C ");
  lcd.setCursor(0,2);
  lcd.print("Calor: ");
  lcd.print(hic);
  lcd.print("C ");

  DateTime now = rtc.now();
   printDate(now);
}



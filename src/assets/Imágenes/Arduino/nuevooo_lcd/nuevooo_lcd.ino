#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27

LiquidCrystal_I2C  lcd(0x27,16,2);
void setup()
   {
       lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
       lcd.setBacklightPin(3,HIGH);
       lcd.setBacklight(HIGH);

       lcd.home ();                   // go home
       lcd.print("Prometec.net");
       lcd.setCursor ( 0, 1 );        // go to the 2nd line
       lcd.print("Malpartida lib");
   }
void loop() 
   {}

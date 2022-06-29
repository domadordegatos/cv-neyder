#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup()
{  

  lcd.begin(16,2);
   lcd.backlight();
 

}
void loop()
{
 
   lcd.setCursor(0,1);
  lcd.println("HOLA COMO ESTAS");
  
  }
 
  
   



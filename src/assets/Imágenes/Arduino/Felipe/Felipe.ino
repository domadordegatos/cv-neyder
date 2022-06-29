#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20,4);

void setup(){
    lcd.init();
  lcd.begin(20,4);
  lcd.backlight();


}
void loop()
{
  lcd.setCursor(0,0);
lcd.println("Marianny es hermosa<3.");





}

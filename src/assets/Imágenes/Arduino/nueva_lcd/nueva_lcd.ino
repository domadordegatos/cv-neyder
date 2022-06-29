#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //Yes, if you put "" it will find in the same folder and will work!

LiquidCrystal_I2C lcd(0x3f,16,2);  // This is the correct way to initialize it!!

void setup()
{
  lcd.begin(16,2);                      //Why the author use init? This is the correct way.

  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
}

void loop()
{
}

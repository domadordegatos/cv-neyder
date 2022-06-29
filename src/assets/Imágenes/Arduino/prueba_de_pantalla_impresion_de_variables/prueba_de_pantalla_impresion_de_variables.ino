String v="hola";
String b="holaa";
String n="holaaa";
String m="holaaaa";
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4); 
void setup() {
Serial.begin(9600);
   lcd.init();
   lcd.begin(20,4);   
   lcd.backlight();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(v);
  lcd.setCursor(0,1);
  lcd.print(b);
  lcd.setCursor(0,2);
  lcd.print(n);
  lcd.setCursor(0,3);
  lcd.print(m);
while(1);
}

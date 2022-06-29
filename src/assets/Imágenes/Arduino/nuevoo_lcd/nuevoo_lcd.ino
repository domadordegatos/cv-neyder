#include <LiquidCrystal_I2C.h> // Debe descargar la Libreria que controla el I2C
#include<Wire.h>  

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Wire.begin(); 
  lcd.init();
  lcd.home();
  lcd.print("h");
  lcd.begin(16,2);
  lcd.clear();
 
  
}

void loop() { 

  int x=1;
  while(x==1){
     lcd.backlight();
     delay(500);
     lcd.noBacklight();
     delay(500);

  lcd.print("Dinastia Tecnologica....");
  lcd.print("Dinastia Tecnologica....");
  }
  }

#include <Wire.h>

#include <LiquidCrystal.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x3f,16,2);  //

void setup() {

lcd.begin(16,2);
for(int i=0;i<3;i++){
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
}
lcd.backlight();

lcd.setCursor(5,0);
lcd.print("hola neyder");
}

void loop() {
   // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
  lcd.setCursor(0, 1);
   // Escribimos el número de segundos trascurridos
  lcd.print(millis()/1000);
  lcd.print(" Segundos");
  delay(100);
}

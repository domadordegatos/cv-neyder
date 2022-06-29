#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x3F,20,4); 

String clave= "000";
char inicia_clave= '#';
String claves_validas []= {"426", "010","766"};
const byte filas =4;
int n=0;
const byte columnas=4;
byte pinsFilas[filas]= {29,28,27,26};
byte pinsColumnas[columnas]={25,24,23,22};
char
teclas[filas][columnas]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},
  
};
Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);

char tecla;
void setup() {
   lcd.init();
   lcd.begin(20,4);   
   lcd.backlight();
   lcd.setCursor (0,3);
   lcd.print ("Empezamos");

Serial.begin(9600);
}

void loop() {
tecla=teclado.getKey();
lcd.setCursor(0,0);
lcd.print (tecla);
if (tecla != 0){

  if (inicia_clave== tecla){
while (n<3){
  clave[n]=teclado.waitForKey();
  n=n+1;

}
lcd.setCursor(0,2);
lcd.println(clave);
for (int i=0; i <=2;i++){
  if (clave==claves_validas[i]){
  lcd.setCursor(0,1);
  lcd.println("clave invalida");
}else{
   lcd.setCursor(0,1);
  lcd.println(" clave valida");
}if (tecla=='D'){
  lcd.init();
   lcd.begin(20,4);   
   lcd.backlight();
   lcd.setCursor (0,3);
   lcd.print ("Empezamos");

}

}}}}

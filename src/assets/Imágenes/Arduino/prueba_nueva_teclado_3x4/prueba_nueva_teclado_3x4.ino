#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x3F,20,4); 

String clave= "000";
char inicia_clave= '#';
String claves_validas []= {"426", "010","766"};
const byte filas =4;
int n=0;
const byte columnas=3;
byte pinsFilas[filas]= {11,10,9,8};
byte pinsColumnas[columnas]={7,6,5};
char
teclas[filas][columnas]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
  
};
Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);

char tecla;
void setup() {
  
   Serial.print ("Empezamos");

Serial.begin(9600);
}

void loop() {
tecla=teclado.getKey();

Serial.print (tecla);
if (tecla != 0){

  if (inicia_clave== tecla){
while (n<3){
  clave[n]=teclado.waitForKey();
  n=n+1;

}

lcd.println(clave);
for (int i=0; i <=2;i++){
  if (clave==claves_validas[i]){

  Serial.println("clave invalida");
}else{
  
  Serial.println(" clave valida");
}if (tecla=='D'){

   Serial.print ("Empezamos");

}

}}}}

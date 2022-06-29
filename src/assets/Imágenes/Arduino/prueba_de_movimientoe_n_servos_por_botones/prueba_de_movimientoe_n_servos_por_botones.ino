#include <Servo.h>

Servo servito;


#include <Key.h>
#include <Keypad.h>

const byte Filas = 4;     //Cuatro filas
const byte Cols = 3;    //Cuatro columnas

byte Pins_Filas[] = {8, 7, 6, 5};  //Pines Arduino a los que contamos las filas.
byte Pins_Cols[] = { 4, 3, 2};   // Pines Arduino a los que contamos las columnas.
char Teclas [ Filas ][ Cols ] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};






//clave
char codigoSecreto[10] = {'3','0','0','2','5','7','7','1','7','0'};
int clave=0;
int posicion=0;
int cursor=5;

Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);

void setup(){   
  Serial.begin(9600) ; 
  servito.attach(9);
  Serial.print("Introduzca clave");
   servito.write(180);
}








  
void loop(){   
  char pulsacion = Teclado1.getKey() ; 
  if (pulsacion != 0){
    if (pulsacion != '#' && pulsacion != '*' && clave==0){     // Si el valor es 0 es que no se ha pulsado ninguna tecla
        Serial.print(pulsacion);
        cursor++;
if (pulsacion == codigoSecreto[posicion]){ 
      posicion ++;
}
if (posicion == 10){
      Serial.print(" Clave correcta");
      clave=1;
      servito.write(0);
      
}
if(cursor>15){
    cursor=5;
    posicion=0;

if(clave==0){
  Serial.println("clave incorrecta");
   servito.write(180);
     
}}}}
if (pulsacion == '*'){
      
      cursor=5;
      clave=0;
      Serial.println("Introduzca clave");
      posicion = 0;
       servito.write(180);
      
}}

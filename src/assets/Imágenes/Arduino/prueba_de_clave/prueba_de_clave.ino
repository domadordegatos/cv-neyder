
#include <Keypad.h>

const byte Filas = 4;     //Cuatro filas
const byte Cols = 3;    //Cuatro columnas

byte Pins_Filas[] = {8,7,6,5};   //Pines Arduino a los que contamos las filas.
byte Pins_Cols[] = {4,3,2};   // Pines Arduino a los que contamos las columnas.
//no utilizar los pines 1 y 0 para no interferir en Rx y Tx

char Teclas [ Filas ][ Cols ] = 
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
char codigoSecreto[4] = {'2','2','5','5'}; // Aqui va el codigo secreto
// Para cambiar el tamaño de la clave, solo hay que cambiar el tamaño del array
int luz=0;         // para el LCD
int cursor=5;      // posicion inicial de la clave en el LCD
int clave=0;       // para el LCD
int posicion=0; // necesaria para la clave
int ledVerde=11; // pin para el LED verde
int ledRojo=12;  // pin para el LED rojo

Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);

void setup(){
Serial.begin(9600) ;
pinMode (ledVerde,OUTPUT);
pinMode (ledRojo, OUTPUT);

Serial.print("Introduzca clave"); // escribimos en LCD
}

  
void loop(){
  
char pulsacion = Teclado1.getKey() ;  // leemos pulsacion
if (pulsacion != 0){  // Si el valor es 0 es que no se ha pulsado ninguna tecla

if (pulsacion != '#' && pulsacion != '*' && clave==0){  // descartamos almohadilla y asterisco
  
    Serial.print(pulsacion);  // imprimimos pulsacion
    cursor++;  // incrementamos el cursor
    
//--- Condicionales para comprobar la clave introducida -----------

if (pulsacion == codigoSecreto[posicion]){ // comparamos entrada con cada uno de los digitos, uno a uno
      posicion ++;  // aumentamos en uno el contador de posicion si es correcto el digito  

      }
      
if (posicion == 4){ // comprobamos que se han introducido los 4 correctamente
        
      digitalWrite (13,HIGH);  // encendemos LED
      Serial.print("Clave correcta  "); // escribimos en LCD
      
      }
//--- En el caso de que este incompleta o no hayamos acertado ----------   
    if(cursor>8){  // comprobamos que no pase de la cuarta posicion
      cursor=5;  // lo volvemos a colocar al inicio

    if(clave==0){           // comprobamos que no hemos acertado

      }
      }
    
    }
    }
//--- Condicionales para encender o apagar el LCD --------------

if (pulsacion == '#' && luz==0){ // comprobamos tecla y encendemos si esta apagado

    luz=1;  // indicamos que esta encendida
    pulsacion =0; // borramos el valor para poder leer el siguiente condicional
  }
if (pulsacion == '#' && luz==1){  //  comprobamos tecla y estado

    luz=0;  // indicamos que esta apagada
      }
//---------------------------------------------------------------

//--- Condicionales para resetear clave introducida -------------  

if (pulsacion == '*'){ // asterisco para resetear el contador
      posicion = 0;
      cursor = 5;
      clave=0;
     
      Serial.print("Introduzca clave\n"); // escribimos en LCD

      


     }
}


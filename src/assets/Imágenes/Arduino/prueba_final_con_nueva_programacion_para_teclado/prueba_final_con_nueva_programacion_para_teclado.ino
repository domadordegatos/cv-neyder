#include <Wire.h>

#include <Key.h>
#include <Keypad.h>


#include <Wire.h>
#include <Keypad.h>

const byte Filas = 4;  //Cuatro filas
const byte Cols = 3;   //Cuatro columnas
byte Pins_Filas[] = {11,10,9,8};//Pines Arduino a las filasbyte 
byte Pins_Cols[] = {7,6,5}; // Pines Arduino a las columnas.

char Teclas [ Filas ][ Cols ] =
 {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
 };

char codigoSecreto[4] = {'2','2','5','5'};

int posicion=0;    // necesaria para la clave
int cursor=5;      // posicion inicial de la clave en el LCD
int clave=0;       // para el LCD


Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);

void setup()
   {
      Serial.begin(9600) ;
     
      Serial.print("Introduzca clave"); 
      
    }

void loop()
   {
      char pulsacion = Teclado1.getKey() ; // leemos pulsacion
      if (pulsacion != 0)  {
          if (pulsacion != '#' && pulsacion != '*' && clave==0){ // para ir contando lo que digitamos 
            Serial.print(pulsacion); 
             cursor++;          
            
    
      if (pulsacion == codigoSecreto[posicion])
          posicion ++; // aumentamos posicion si es correcto el digito

      if (posicion == 4){ // comprobamos que se han introducido los 4 correctamente
 
         Serial.print("Clave correcta ");        

         clave=1; // 

     }
          }
      
     //--- En el caso de que este incompleta o no hayamos acertado ----------
     if(cursor>8){        // comprobamos que no pase de la cuarta posicion   cursor=5;     // lo volvemos a colocar al inicio
           posicion=0;           // borramos clave introducida
           
           Serial.print(" ");       // borramos la clave de la pantalla
 
           if(clave==0) {        // comprobamos que no hemos acertado
  
                Serial.print("clave incorrecta");
          
              }
        }
     }
   

//--- Condicionales para resetear clave introducida -------------
 if (pulsacion == '*'){ // asterisco para resetear el contador
       posicion = 0;
       cursor = 5;
       clave=0;
       posicion=0;
      
       Serial.print("Introduzca clave"); // escribimos en LCD

       Serial.print(" "); // borramos de la pantalla los numeros

  
    }
 }

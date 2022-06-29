const byte Filas = 4;     //Cuatro filas
const byte Cols = 4;    //Cuatro columnas

byte Pins_Filas[] = {29,28,27,26};  //Pines Arduino a los que contamos las filas. 
byte Pins_Cols[] = {25,24,23,22};   // Pines Arduino a los que contamos las columnas.                // programacion teclado
char Teclas [ Filas ][ Cols ] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);
pulsacion= 0;
//---------------------------------------------------------------------------------------------------------------------------------------------------
#define RELAY_ON 0
#define RELAY_OFF 1
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int campo1=5000;
int campo2=5500;
int campo3=6000;
int campo4=6500;
int campo5=7000;   // ingrese los porcentajes de agua para cada planta
int campo6=7500;   // revise la guia de trabajo.
int campo7=8000;
int campo8=8500;
int campo9=9000;
//---------------------------------------------------------------------------------------------------------------------------------------------------------
int pulsacion =0;
void setup() {
Serial.begin(9600);
pinMode (3,OUTPUT);
digitalWrite (3,RELAY_OFF);

}

void loop() {
char pulsacion = Teclado1.getKey() ; 
if (pulsacion != 0){     
      
   if(pulsacion=='1' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo1); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }

    if(pulsacion=='2' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo2); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }
    if(pulsacion=='3' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo3); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }
  if(pulsacion=='4' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo4); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }

    if(pulsacion=='5' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo5); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }
    if(pulsacion=='6' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo6); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }
    if(pulsacion=='7' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo7); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }
    if(pulsacion=='8' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo8); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }
    if(pulsacion=='9' ){ 
            digitalWrite (3,RELAY_ON);
            delay (campo9); 
            digitalWrite(3,RELAY_OFF);
            delay (1000);    
  }
}
}

#include <Servo.h>

Servo servo1;

int M=2; 
int estado = '0';   


void setup()  { 
  Serial.begin(9600);   
  servo1.attach(2,600,1500);
 
} 

void loop()  { 

  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if(estado=='B'){           // Boton desplazar al Frente
  servo1.write(90);           

  }
  
   if (estado== 'C'){
  servo1.write (1);
 }
    
    
    
    }
  

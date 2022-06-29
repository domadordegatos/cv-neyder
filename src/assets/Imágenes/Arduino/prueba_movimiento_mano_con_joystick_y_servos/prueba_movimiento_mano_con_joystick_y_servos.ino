#include <Servo.h>          // Incluir la librería Servo
Servo servo1;
Servo servo2;
// Crear un objeto tipo Servo llamado servo1
int angulo = 0 ;
int angulo2 = 0 ;
int Eje_X = A1 ;
int Eje_Y = A2 ;
int boton = 4  , LED = 13 ;

void setup()
    {
      Serial.begin(9600);
        servo1.attach(6) ;  // Conectar servo1 al pin 6
        servo2.attach(5) ;  // Conectar servo1 al pin 6
      
        pinMode( boton, INPUT_PULLUP) ;
    }

void loop()
    {

        guardado = analogRead(A1);
        angulo = map(guardado, 0, 1024, 0, 180);
///////////////////////////////////////////////////////////////////////
        angulo  = map( analogRead(A1), 0, 1024, 0, 180);


        
        angulo2  = map( analogRead(A2), 0, 1024, 0, 180);
        servo1.write(angulo);
        servo2.write(angulo2);
        if ( ! digitalRead(boton)){
          servo1.write(60);
          delay(250);
          servo1.write(120);
          delay(250);
          
             
    }else{
    }     
    

    
          Serial.print("angulo 1: ");
          Serial.print(angulo);
          Serial.print("  ");
          Serial.print("angulo 2: ");
          Serial.println(angulo2);  

            
        delay(250) ;
           }

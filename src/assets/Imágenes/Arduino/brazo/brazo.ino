#include <Servo.h>  
Servo servo2;   
int ma1 = 9; 
int ma11 = 8; 
int ma2 = 7; 
int ma22 = 6;
int mat1 = 5; 
int mat11 = 4; 
int mat2 = 3; 
int mat22 = 2;
int vel= 255;
 
int estado = '0';   
int estado2 = '0';

void setup()  { 
  Serial.begin(9600);   
  servo2.attach(10,600,1500);
  pinMode(ma1, OUTPUT);
  pinMode(ma11, OUTPUT);
  pinMode(ma2, OUTPUT);
  pinMode(ma22, OUTPUT);
  pinMode(mat1, OUTPUT);
  pinMode(mat11, OUTPUT);
  pinMode(mat2, OUTPUT);
  pinMode(mat22, OUTPUT);
} 

void loop()  { 

  if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  if(estado=='A'){           // Boton desplazar al Frente
    servo2.write(100);
    analogWrite(ma11, 0);     
    analogWrite(ma22, 0);
    analogWrite(mat11, 0);     
    analogWrite(mat22, 0); 
    analogWrite(ma1, vel);  
    analogWrite(ma2, vel);
    analogWrite(mat1, vel);  
    analogWrite(mat2, vel);
           
  }
  if(estado=='D'){          // Boton IZQ 
    servo2.write(60);
    analogWrite(ma11, 0);     
    analogWrite(ma22, 0);
    analogWrite(mat11, 0);     
    analogWrite(mat22, 0); 
    analogWrite(ma1, vel);  
    analogWrite(ma2, 0);
    analogWrite(mat1, vel);  
    analogWrite(mat2, 0);     
  }
  if(estado=='E'){         // Boton Parar
    analogWrite(ma11, 0);     
    analogWrite(ma22, 0);
    analogWrite(mat11, 0);     
    analogWrite(mat22, 0); 
    analogWrite(ma1, 0);  
    analogWrite(ma2, 0);
    analogWrite(mat1, 0);  
    analogWrite(mat2, 0);
  }
  if(estado=='C'){          // Boton DER
    servo2.write(140);
    analogWrite(ma11, 0);     
    analogWrite(ma22, 0);
    analogWrite(mat11, 0);     
    analogWrite(mat22, 0); 
    analogWrite(ma1, 0);  
    analogWrite(ma2, vel);
    analogWrite(mat1, 0);  
    analogWrite(mat2, vel); 
  } 

  if(estado=='B'){          // Boton Reversa
    servo2.write(100);
    analogWrite(ma11, vel);     
    analogWrite(ma22, vel);
    analogWrite(mat11, vel);     
    analogWrite(mat22, vel); 
    analogWrite(ma1, 0);  
    analogWrite(ma2, 0);
    analogWrite(mat1, 0);  
    analogWrite(mat2, 0);   
  }
  }

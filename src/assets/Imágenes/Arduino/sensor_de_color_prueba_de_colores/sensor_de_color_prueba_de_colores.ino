#include <Servo.h>
Servo ss1;
const int s0 = A1;  
const int s1 = A2;  
const int s2 = A3;  
const int s3 = A4;  
const int out = 4;    
int rojo = 0;  
int verde = 0;  
int azul = 0;  

void setup(){  
  Serial.begin(9600); 
  pinMode(s0,OUTPUT);  
  pinMode(s1,OUTPUT);  
  pinMode(s2,OUTPUT);  
  pinMode(s3,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH);
  digitalWrite(s2,HIGH);  
  digitalWrite(s3,HIGH);  
  ss1.attach(7,800,1500);
  ss1.write(180);
}  

   
void loop(){  
  color(); 
  Serial.print("   ");  
  Serial.print(rojo, DEC);  
  Serial.print("   ");  
  Serial.print(verde, DEC);  
  Serial.print("   ");  
  Serial.print(azul, DEC);  

   //     if(rojo >= 5 && rojo <= 8 && verde >= 8 && verde <=12 && azul >= 9 && azul <=13){  
   //Serial.println("   azul");    
  if(rojo >= 8 && rojo <= 12 && verde >= 4 && verde <=9 && azul >= 2 && azul <=5){
   Serial.println("   amarillo");   
   ss1.write(127);
   
  }else if(rojo >= 5 && rojo <= 7 && verde >= 7 && verde <=8 && azul >= 6 && azul <=7){
   Serial.println("   blanco");   
  }
  else{
  Serial.println("  ");  
  ss1.write(180);
  }
  delay(500);     
  }  
    
void color(){    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}


#include <Ultrasonic.h>//Incluimos la libreria para el control del sensor HC-SR04.
Ultrasonic ultrasonic(5,6); // (Trig PIN,Echo PIN, microsegundos max "distancia máxima") 30000us = 5 metros.
int m1ad=8;
int m1at=9;
int m2ad=10;
int m2at=11;
int vel=250;
int velm=255;
int tiempodemedida=5;//Variable para ajustar la velocidad de medida del sensor.
int distance;
int control=2;
int aleatorio=0;//Variable para guardar un valor aleatorio. 

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT); 
Serial.begin(9600);//Iniciamos el puerto serie
 pinMode(control,OUTPUT);
digitalWrite(control,HIGH);
    delay(5000);
    digitalWrite(control,LOW);
    delay(5000);
 
} 
 
void loop() { 
  analogWrite(m1ad,vel);
  analogWrite(m1at,0);
  analogWrite(m2ad,velm);
  analogWrite(m2at,0);
  
 distance = ultrasonic.read();
  delay(tiempodemedida);
 
 Serial.print("No obstaculo ");
 Serial.print(distance);
 Serial.print(" aleatorio ");
 Serial.println(aleatorio);

 aleatorio=random (2);
  
  
  while(distance<30){//Mientras la distancia sea menor que 30 se mantiene en este bucler
  
  analogWrite(m1ad,0);
  analogWrite(m1at,0);
  analogWrite(m2ad,0);
  analogWrite(m2at,0);
  delay(1000);                
  distance = ultrasonic.read();
  delay(1000);
  if(aleatorio==0){//Si la variable aleatorio vale 0 entra en este bucle.
 Serial.print("dentro 0");
 Serial.println(distance);
 Serial.print("aleatorio ");
 Serial.println(aleatorio);
 
  analogWrite(m1ad,0);
  analogWrite(m1at,0);
  analogWrite(m2ad,velm);
  analogWrite(m2at,0);
  delay(2000);
  }
  if (aleatorio==1){
 Serial.print("dentro 1");
 Serial.println(distance);
 Serial.print("aleatorio ");
 Serial.println(aleatorio);
 
  analogWrite(m1ad,velm);
  analogWrite(m1at,0);
  analogWrite(m2ad,0);
  analogWrite(m2at,0);
  delay(2000);
  }
 
  }
} 

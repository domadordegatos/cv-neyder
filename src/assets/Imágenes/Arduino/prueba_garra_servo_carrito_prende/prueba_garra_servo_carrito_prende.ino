#include <Servo.h>
Servo s1;
Servo s2;

int estado=0;

void setup(){
   s1.attach(12,800,1500);
   s2.attach(7,800,1500);
   
  //s2.attach(8);
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  
  
}

void loop(){
// if(Serial.available()>0){
// estado = Serial.read();
//s2.write(estado);
s1.write(25);
s2.write(130);





  
 }
//}

#include <SoftwareSerial.h> 
int bTx = 12; 
int bRx = 13;
SoftwareSerial bluetooth(bTx, bRx);
int mad1=6; 
int mat1=5;
int mad2=10; 
int mat2=11;

int velM=255;
int velm=200;
int veln=0;


void setup(){
  bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
}

void loop(){
 if(bluetooth.available()>= 2 ){
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int estado = (servopos1 *256) + servopos;
    Serial.println(estado);
 
 if (estado == 4002){
   analogWrite(mad1,veln);
   analogWrite(mat1,veln);
   analogWrite(mad2,veln);//STOP
   analogWrite(mat2,veln);
  }
if(estado== 4000){
   analogWrite(mad1,velM);
   analogWrite(mat1,veln);//ADELANTE
   analogWrite(mad2,velM);
   analogWrite(mat2,veln);
}
   if (estado == 4004){
   analogWrite(mad1,veln);
   analogWrite(mat1,velM);//ATRAS
   analogWrite(mad2,veln);
   analogWrite(mat2,velM);
  }
if(estado== 4001){
   analogWrite(mad1,velM);
   analogWrite(mat1,veln);//DERECHA
   analogWrite(mad2,veln);
   analogWrite(mat2,veln);
}
if(estado== 4003){
   analogWrite(mad1,veln);
   analogWrite(mat1,veln);
   analogWrite(mad2,velM);//IQUIERDA
   analogWrite(mat2,veln);
}
}
}

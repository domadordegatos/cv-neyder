#include <Servo.h>
Servo s1;
Servo s2;
int m1ad=A0;
int m1at=A1;
int m2ad=A2;
int m2at=A3;
int estado=0;

//direccion servos
int s1r=110;
int s2r=104;
int s1de=125;
int s1iz=93;
int s1cude=121;
int s2cude=93;
int s1cuiz=98;
int s2cuiz=115;

void setup() {
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  s1.attach(13);
  s2.attach(12);
  Serial.begin(9600);
    s1.write(s1r);
    s2.write(s2r);
}
void loop() {
 if(Serial.available()>0){
  estado=Serial.read();
  if(estado == 'B'){
    digitalWrite(m1ad,HIGH);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,HIGH);//adelante 2 servos 90
    digitalWrite(m2at,LOW);
    s1.write(s1r);
    s2.write(s2r);
  }if(estado == 'D'){
    digitalWrite(m1ad,HIGH);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,HIGH);//izquierda 1 servo girado
    digitalWrite(m2at,LOW);
    s1.write(s1iz);
    s2.write(s2r);
  }if(estado == 'E'){
    digitalWrite(m1ad,LOW);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,LOW);//stop 2 servo 90
    digitalWrite(m2at,LOW);
    s1.write(s1r);
    s2.write(s2r);
  }if(estado == 'F'){
    digitalWrite(m1ad,HIGH);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,HIGH);//DERECHO 1 servo girado
    digitalWrite(m2at,LOW);
    s1.write(s1de);
    s2.write(s2r);
  }if(estado == 'H'){
    digitalWrite(m1ad,LOW);
    digitalWrite(m1at,HIGH);
    digitalWrite(m2ad,LOW);//ATRAS 2 servS 90
    digitalWrite(m2at,HIGH);
    s1.write(s1r);
    s2.write(s2r);
  }if(estado == 'A'){
    digitalWrite(m1ad,HIGH);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,HIGH);//IZQUIERDA ADELANTE 2 servo girado
    digitalWrite(m2at,LOW);
    s1.write(s1cuiz);
    s2.write(s2cuiz);
  }if(estado == 'C'){
    digitalWrite(m1ad,HIGH);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,HIGH);//DERECHO ADELANTE 2 servo girado
    digitalWrite(m2at,LOW);
    s1.write(s1cude);
    s2.write(s2cude);
  }if(estado == 'G'){
    digitalWrite(m1ad,LOW);
    digitalWrite(m1at,HIGH);
    digitalWrite(m2ad,LOW);//IZQUIERDA ATRAS 2 servOS GIRADOS
    digitalWrite(m2at,HIGH);
    s1.write(s1cuiz);
    s2.write(s2cuiz);
  }if(estado == 'I'){
    digitalWrite(m1ad,LOW);
    digitalWrite(m1at,HIGH);
    digitalWrite(m2ad,LOW);//DERECHA ATRAS 2 servS GIRADOS
    digitalWrite(m2at,HIGH);
    s1.write(s1cude);
    s2.write(s2cude);
  }
 }
}

#include <Ultrasonic.h>
int control=2;
int m1ad=A1;
int m1at=A2;
int m2ad=A3;
int m2at=A4;
int vel=150;
int velm=255;
int estado=0;
#include <Ultrasonic.h>

Ultrasonic ultrasonic(8, 9);
int distance;
void setup() {
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  Serial.begin(9600);
  pinMode(control,OUTPUT);
digitalWrite(control,HIGH);
    delay(5000);
    digitalWrite(control,LOW);
    delay(5000);
}

void loop() {
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  if(Serial.available()>0){
    estado=Serial.read();
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  if(estado=='a'){
    analogWrite(m1ad,vel);
    analogWrite(m1at,0);
    analogWrite(m2ad,vel);
    analogWrite(m2at,0);
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(200);
  if(distance<=20){
    analogWrite(m1ad,0);
    analogWrite(m1at,0);
    analogWrite(m2ad,0);
    analogWrite(m2at,0); 
  }
  }  if(estado=='b'){
    analogWrite(m1ad,0);
    analogWrite(m1at,vel);
    analogWrite(m2ad,0);
    analogWrite(m2at,vel);
  }  if(estado=='c'){
    analogWrite(m1ad,0);
    analogWrite(m1at,0);
    analogWrite(m2ad,0);
    analogWrite(m2at,0);
  }  if(estado=='d'){
    analogWrite(m1ad,vel);
    analogWrite(m1at,0);
    analogWrite(m2ad,0);
    analogWrite(m2at,0);
  }  if(estado=='e'){
    analogWrite(m1ad,0);
    analogWrite(m1at,0);
    analogWrite(m2ad,vel);
    analogWrite(m2at,0);
    
  }
  }

  }

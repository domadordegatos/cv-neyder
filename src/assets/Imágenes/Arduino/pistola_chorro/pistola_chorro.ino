#include <Servo.h>
Servo s1,s2;
int pos1;
int pos2;
int state;
void setup() {
Serial.begin(9600);
s1.attach(5);
s2.attach(4);
pinMode(7,INPUT);
pinMode(6,OUTPUT);
digitalWrite(6,LOW);
}

void loop() {
  pos1=map(analogRead(A0),0,1023,0,180);
  pos2=map(analogRead(A1),0,1023,0,180);
  state=analogRead(A3);
 s1.write(pos2);
 s2.write(pos1);
 Serial.print(pos1);
 Serial.print(" ");
 Serial.print(pos2);
 Serial.print(" ");
 Serial.println(state);
 if(state==0){
  Serial.print("presionado");
  digitalWrite(6,HIGH);
 }else{
  digitalWrite(6,LOW);
 }
 
}

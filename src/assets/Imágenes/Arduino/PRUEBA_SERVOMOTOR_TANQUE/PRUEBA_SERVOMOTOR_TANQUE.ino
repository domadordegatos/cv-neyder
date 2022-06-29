#include <Servo.h> 
int led= 52;
Servo servo1;
int c=0;

void setup() {
pinMode (led,OUTPUT);
Serial.begin (9600);
servo1.attach (53,500,1800);
}

void loop() {

 for(c=0;c<=180;c+5){
  c=c+5;
  servo1.write(c);
  delay(200);
 }
 for(c=180;c>=0;c-5){
  c=c-5;
  servo1.write(c);
  delay(200);
 }
}

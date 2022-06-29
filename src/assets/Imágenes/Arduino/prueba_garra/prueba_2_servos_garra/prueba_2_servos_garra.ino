#include <Servo.h>
Servo hola;
Servo hola2;
int m=0;

void setup() {
  // put your setup code here, to run once:
hola.attach(8,500,1800);
hola2.attach(9,500,1800);
}

void loop() {
  // put your main code here, to run repeatedly:

hola2.write(70);
delay(1000);
hola.write(150);
delay(1000);
vel = 90;
   .write(vel);              
   delay(1500);    



}

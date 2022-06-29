#include <Servo.h>
Servo hola;
int m=0;

void setup() {
  // put your setup code here, to run once:
hola.attach(9,500,1800);
}

void loop() {
  // put your main code here, to run repeatedly:
for(m=0;m<=180;m+5){
  m=m+5;
  hola.write(m);
  delay(200);
}
for(m=180;m>=0;m-5){
  m=m-5;
  hola.write(m);
  delay(200);
}
}

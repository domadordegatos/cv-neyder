#include <Servo.h>
Servo s1;
Servo s2;
int position;
int a=0;
int p=A0;
int casa=0;
void setup() {
  // put your setup code here, to run once:
  s1.attach(10,800,1500);
  s2.attach(11,800,1500);
  
}

void loop() {
  // put your main code here, to run repeatedly:
a=analogRead(p);
position=map(a,0,1023,0,180);
casa=180-position;
s1.write(position);
s2.write(casa);
}

#include <Servo.h>
Servo s1;
Servo s2;
Servo s3;
int pos1;
int pos2;
int pos3;

void setup() {
 s1.attach(5);
 s2.attach(6);
 s3.attach(7,800,1500);
 Serial.begin(9600);

}

void loop() {
  pos1=map(analogRead(A1),0,1023,0,180);
  pos2=map(analogRead(A2),0,1023,0,180);
  pos3=map(analogRead(A3),0,1023,0,180);
   s1.write(pos1);
   s2.write(pos2);
   s3.write(pos3);
   Serial.print(pos1);
   Serial.print(" ");
   Serial.print(pos2);
   Serial.print(" ");
   Serial.println(pos3);
   
}

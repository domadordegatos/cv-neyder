#include <Servo.h>
 
Servo myservo;  // crea el objeto servo
 
int vel = 0;    // velocidad del servo
 
void setup() {
   myservo.attach(9);  // vincula el servo al pin digital 9
}
 
void loop() {
 myservo.write(0);
 delay(1000);
 myservo.write(180);
 delay(1000);
 
}

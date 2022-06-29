#include <Servo.h>
Servo s1;

void setup() {
s1.attach (10,800,1500);
Serial.begin (9600);
}

void loop() {
  
 s1.write (55);
 delay (1000);
  s1.write (180);
 delay (1000);
}

#include <Servo.h>

Servo servo1;
void setup() {
  // put your setup code here, to run once:
servo1.attach(24,800,1500);
}

void loop() {
for(int m=1;m<=180;m+5){
  m=m+5;
  delay(100);
  servo1.write(m);
}
for(int m=180;m>=1;m-5){
  m=m-5;
  delay(100);
  servo1.write(m);
}
}

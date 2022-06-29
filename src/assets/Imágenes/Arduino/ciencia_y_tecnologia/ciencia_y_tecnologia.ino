#include <AFMotor.h>
#include <Servo.h>              // Add library
Servo servo;               // Define any servo name

int m=0;

void setup() {
  
servo.attach(10);          // Define the servo signal pins

}

void loop() {
for(m=0;m<=90;m+5){
  m=m+5;
  servo.write(m);
  delay(100);
}
for(m=90;m>=0;m-5){
  m=m-5;
  servo.write(m);
  delay(100);
}
}



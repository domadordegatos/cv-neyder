#include <Servo.h>

Servo myservo;  // create servo object to control a servo 
 
void setup() {
  Serial.begin(9600);
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  myservo.write(0);
  delay(500);

  
  Serial.println("Stop");
  myservo.write(90);
  delay(500);

    myservo.write(180);
  delay(500);
}

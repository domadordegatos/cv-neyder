#include <AFMotor.h>

AF_DCMotor motorA(3);

void setup() 
{
  Serial.begin(9600);
  Serial.begin(9600);
  motorA.setSpeed(255);
}

void loop() 
{
 if (Serial.available()>0){
  int letra=Serial.read();

}
  
  motorA.setSpeed(255);
  motorA.run(FORWARD);
  delay(3000);
}

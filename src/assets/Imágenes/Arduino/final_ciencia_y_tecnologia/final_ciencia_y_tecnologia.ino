#include <Servo.h>
#include <AFMotor.h>
Servo servo5;
Servo servo4;
Servo servo3;
Servo servo2;
Servo servo1;
AF_DCMotor motorA(3);
AF_DCMotor motorB(4);
int l=A8;
int g=0;
int pos;
int m=0;
void setup() {
servo5.attach(32,800,1500);
servo4.attach(30,800,1500);
servo3.attach(28,800,1500);
servo2.attach(26,800,1500);
servo1.attach(24,800,1500);
  motorA.setSpeed(255);
  motorB.setSpeed(255);
Serial.begin(9600);
}

void loop() {
  pos=map(analogRead(A8),0,1023,0,255);
  Serial.print("pos: ");
  Serial.println(pos);
  motorA.setSpeed(pos);
  motorB.setSpeed(pos);
  motorA.run(FORWARD);
for(m=20; m<=140; m+3){
  servo5.write(m);
  servo4.write(m);
  servo3.write(m);
  servo2.write(m);
  servo1.write(m);
  m=m+3;
  delay(100);
  pos=map(analogRead(A8),0,1023,0,255);
  Serial.print("pos: ");
  Serial.println(pos);
  motorA.setSpeed(pos);
  motorB.setSpeed(pos);
  motorA.run(FORWARD);
  motorB.run(FORWARD);
}
for(m=140; m>=20; m-3){
  servo5.write(m);
  servo4.write(m);
  servo3.write(m);
  servo2.write(m);
  servo1.write(m);
  m=m-3;
  delay(100);
  pos=map(analogRead(A8),0,1023,0,255);
  Serial.print("pos: ");
  Serial.println(pos);
  motorA.setSpeed(pos);
  motorB.setSpeed(pos);
  motorA.run(FORWARD);
  motorB.run(FORWARD);
  
}
}

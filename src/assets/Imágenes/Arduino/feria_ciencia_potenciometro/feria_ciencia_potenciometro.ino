#include <AFMotor.h>

int position;
int g=0;
int l=A8;

AF_DCMotor motorA(3);
void setup() {
Serial.begin(9600);
}

void loop() {
g=analogRead(l);
position=map(g,0,1023,0,255);
Serial.println(position);

  motorA.setSpeed(position);
  motorA.run(FORWARD);
}

#include <Servo.h>

int led=8;
#define RELAY_ON 0    
#define RELAY_OFF 1
int letra=0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
digitalWrite (8, RELAY_OFF);
pinMode(8,OUTPUT);
}

void loop() {
  if(Serial.available()>0){
 letra=Serial.read();
 if(letra=='a'){
  digitalWrite(8, RELAY_ON);
 } if(letra=='b'){
  digitalWrite(8, RELAY_OFF);
 }

  }
}

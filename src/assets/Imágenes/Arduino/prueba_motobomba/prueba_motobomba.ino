#include <Servo.h>
#define RELAY_ON 0
#define RELAY_OFF 1
int letra=0;



void setup() {
Serial.begin (9600);
digitalWrite (3,RELAY_OFF);
pinMode (3,OUTPUT); 

}

void loop() {

digitalWrite(3,RELAY_ON);
delay (8000);
digitalWrite(3,RELAY_OFF);
delay (8000);

 }

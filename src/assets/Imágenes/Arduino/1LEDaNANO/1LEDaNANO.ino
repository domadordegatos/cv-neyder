#include <Servo.h>


int led=2;
int dato=0;
Servo servitobaby;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  servitobaby.attach(4,800,1500);

}

void loop() {
  if(Serial.available()>0){
    dato=Serial.read();
    
  }if(dato=='A'){
     digitalWrite(led,HIGH);
  }if(dato=='B'){
    digitalWrite(led,LOW);
  }if (dato=='C'){
    servitobaby.write(0);
  }if (dato=='D'){
    servitobaby.write(180);
  }
  
 

}

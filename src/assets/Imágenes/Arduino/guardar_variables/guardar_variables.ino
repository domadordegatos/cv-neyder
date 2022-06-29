#include <Servo.h>
Servo servito;
char letra=0;
int m=0; int n=0;
void setup() {
Serial.begin(9600);
servito.attach(7,800,1500); 
}

void loop() {
  if(Serial.available()>0){
 letra=Serial.read();

if(letra=='a' && n==0 && m==0){  ///punto antes de borrar

  
  for(m=0;m<=178;m+5){
    m=m+5;
    Serial.println(m);
    servito.write(m);
    delay(200);
  }
 letra='0';
}/////////////////////// fin del if
if(letra=='a' && n==0 && m==180){
 letra='0';
}

 if(letra=='b'){
  m=0;
  for(n=180;n>=1;n-5){
    n=n-5;
    Serial.println(n);
    servito.write(n);
    delay(200);
  }
  letra='0';
}

return;
}
}

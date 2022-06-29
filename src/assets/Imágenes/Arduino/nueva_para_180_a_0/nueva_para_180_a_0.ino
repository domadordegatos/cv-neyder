#include <Servo.h>
Servo servito;
char letra=0;
int m=0; int n=0;
void setup() {
Serial.begin(9600);
servito.attach(22,800,1500); 
Serial.println(" presione a para ir a 180");
Serial.println(" presione b para ir a 0");

}

void loop() {
  if(Serial.available()>0){
 letra=Serial.read();
if(letra=='a' && m==0){  ///punto antes de borrar  
  for(m=0;m<=178;m+5){
    m=m+5;
    Serial.println(m);
    servito.write(m);
    delay(200);
  }
 letra='0';
 m=180;
}
 if(letra=='b' && m==180){
  for(m=180;m>=1;m-5){
    m=m-5;
    Serial.println(m);
    servito.write(m);
    delay(200);
  }
  letra='0';
  m=0;
}if(letra=='a' && m==180){
  letra='0';
  m=180;
  Serial.println("ya esta en el 180 no puede volver a ir");
}if(letra=='b' && m==0){
  letra='0';
  m=0;
    Serial.println("ya esta en el 0 no puede volver a ir");
}

return;
}
}

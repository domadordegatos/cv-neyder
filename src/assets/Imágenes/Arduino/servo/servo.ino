#include <Servo.h>                // Incluye la libreria Servo
 
Servo servo1;
Servo servo2;// subir



void setup() 
{ 
  servo1.attach(10,800,1500);
  servo2.attach(11,800,1500);
  
}                               
  
void loop() 
{   
  servo1.write(170);
  delay(1000);
    servo2.write(145);
    delay(2000);
    servo1.write(130);
    delay(1000);
    servo2.write(100);
   
  
  
   
   

  } 

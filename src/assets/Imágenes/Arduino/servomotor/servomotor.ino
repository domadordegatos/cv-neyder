
#include <Servo.h>                
 
Servo servo1;                    

void setup() 
{ 
  servo1.attach(8,600,1500);    
}                               
  
void loop() 
{                       
    servo1.write(95);                 
    delay(100);
    servo1.write(90);                 
    delay(100);                       
    servo1.write(85);                 
    delay(100);  
    servo1.write(80);                 
    delay(100); 
     
    servo1.write(75);               
    delay(100);
    servo1.write(80);                 
    delay(100); 
    servo1.write(85);                 
    delay(100); 
    servo1.write(90);                 
    delay(100);      
                      
    servo1.write(95);           
    delay(100);
    servo1.write(100);                 
    delay(100);
    servo1.write(105);                 
    delay(100);  
    servo1.write(110);                 
    delay(100);    
    servo1.write(115);                 
    delay(100);  
    
    servo1.write(120);           
    delay(100);
    servo1.write(115);                 
    delay(100);  
    servo1.write(110);                 
    delay(100);  
    servo1.write(105);                 
    delay(100);  
    servo1.write(100);                 
    delay(100);  
    
                          
  } 

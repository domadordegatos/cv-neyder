#include <AFMotor.h>
AF_DCMotor ejeY(1);
AF_DCMotor ejeX1(2);
AF_DCMotor ejeX2(3);


void setup() {
  ejeY.setSpeed(255);  //Velocidad estándar de 250, máxima velocidad posible 255
  ejeX1.setSpeed(255);//ANTIGUOS
  ejeX2.setSpeed(255);// NUEVOS 

}

void loop() {
  ejeY.run(BACKWARD);
 delay(29000);
 ejeY.run(RELEASE); 
 delay (1000);

  ejeY.run(FORWARD);
 delay(58000);
 ejeY.run(RELEASE); 
 delay (1000);

  ejeY.run(BACKWARD);// SE DEVUELVE
 delay(29000);
 ejeY.run(RELEASE); 
 delay (1000);

 

  ejeX1.run(BACKWARD);   // SUBE
   ejeX2.run(BACKWARD); 
   delay (100000); 
 ejeX1.run(RELEASE); 
ejeX2.run(RELEASE); 
delay (1000);

  ejeY.run(BACKWARD);
 delay(29000);
 ejeY.run(RELEASE); 
 delay (1000);

  ejeY.run(FORWARD);
 delay(58000);
 ejeY.run(RELEASE); 
 delay (1000);

  ejeY.run(BACKWARD);// SE DEVUELVE
 delay(29000);
 ejeY.run(RELEASE); 
 delay (1000);

 

  ejeX1.run(BACKWARD);   //SUBE
   ejeX2.run(BACKWARD); 
   delay (100000); 
 ejeX1.run(RELEASE); 
ejeX2.run(RELEASE); 
delay (1000);

  ejeY.run(BACKWARD);
 delay(29000);
 ejeY.run(RELEASE); 
 delay (1000);

  ejeY.run(FORWARD);
 delay(58000);
 ejeY.run(RELEASE); 
 delay (1000);

  ejeY.run(BACKWARD);// SE DEVUELVE
 delay(29000);
 ejeY.run(RELEASE); 
 delay (1000);

 

 

}


 

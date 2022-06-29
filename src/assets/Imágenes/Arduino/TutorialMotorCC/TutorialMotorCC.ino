#include <AFMotor.h>
AF_DCMotor motor1(4);
AF_DCMotor motor2(1);
AF_DCMotor motor3(3);


void setup() 
{
  motor2.setSpeed(255);  //Velocidad estándar de 250, máxima velocidad posible 255
  motor3.setSpeed(255);  //Velocidad estándar de 250, máxima velocidad posible 255
  
}

void loop() 
{
  motor3.run(FORWARD);   //Recuerda (FORWARD = ADELANTE) – (BACKWARD = ATRAS) – (RELEASE = DETENER)
  motor2.run(FORWARD);
}

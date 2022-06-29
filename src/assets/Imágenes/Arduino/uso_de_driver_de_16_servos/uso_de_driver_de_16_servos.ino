#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

void setup() {
  servos.begin();  
  servos.setPWMFreq(40); //Frecuecia PWM de 60Hz o T=16,66ms
}
void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  
}
void loop() {
  

 servos.setPWM(8, 0, duty);
 delay(1000);
 servos.setPWM(8, 180, duty);
 delay(1000);
 
   
 
 
 
}

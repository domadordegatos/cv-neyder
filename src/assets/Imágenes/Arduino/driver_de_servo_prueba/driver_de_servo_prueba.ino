#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

void setup() {
  servos.begin();  
  servos.setPWMFreq(40); //Frecuecia PWM de 60Hz o T=16,66ms
}


void loop() {
  
  for (int duty = pos0; duty < pos180; duty=duty+10) {

      servos.setPWM(8,0,duty);
    
  }
  delay(1000);
  for (int duty = pos180; duty > pos0; duty=duty-10) {
 
      servos.setPWM(8,0,duty);
     
  }
  delay(1000);
}

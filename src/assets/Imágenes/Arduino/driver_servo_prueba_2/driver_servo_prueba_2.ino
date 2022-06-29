 
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
 
void setup() 
{
   pwm.begin();
 
   // Ajustamos la frecuencia al máximo (1600Hz)
   pwm.setPWMFreq(1600); 
}
 
void loop() 
{
   for (uint16_t duty = 0; duty < 4096; duty += 8)
   {
      for (uint8_t pwmNum = 0; pwmNum < 16; pwmNum++)
      {
         // Ajustar PWM con ON en tick=0 y OFF en tick=duty
         pwm.setPWM(pwmNum, 0, duty);
      }
   }
}

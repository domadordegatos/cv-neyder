#include <Servo.h>       //libreria para señales del servomotor
Servo servitobebe;       //declaracion del servo
void setup() {
servitobebe.attach(pin,800,1500);  // pin a usar y rangos de señal
}
void loop() {
servitobebe.write(0);            // servo va a un grado en el plano
delay(1000);                     //tiempo que dura ahi
servitobebe.write(180);          // servo va al grado 180
delay(1000);
}                                //programacion secuencial



#include <Servo.h>
Servo adelante;
Servo atras;

void setup() {
  // put your setup code here, to run once:
adelante.attach(11,800,1500);
atras.attach(10,800,1500);

}

void loop() {
  adelante.write(85);
  atras.write(92);
  
}

#include <Servo.h>
Servo servito;
Servo servito2;
int pote = A1;
int almacen;
int position;

void setup() {
  servito.attach(3,800,1500);

}

void loop() {
  
almacen= analogRead (pote);
position = map (almacen, 0, 1023, 1, 180);

servito.write (position);

Serial.println (position);

}


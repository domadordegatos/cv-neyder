#include <Servo.h>
Servo laura;
int lectura=A5;
int almacen;
int position;
void setup() {
  laura.attach(3,800,1500);
  Serial.begin(9600);
}

   void loop() {
   
  
  almacen=analogRead(lectura);
  position=map(almacen, 0, 1023, 0, 180);
  laura.write(position);

 
  
}


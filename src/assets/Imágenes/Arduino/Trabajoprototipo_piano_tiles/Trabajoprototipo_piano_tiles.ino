#include <Servo.h>

int foto1=A4;
int foto2=A3;
int foto3=A2;
int foto4=A1;

int almacen1=0;
int almacen2=0;
int almacen3=0;
int almacen4=0;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
Serial.begin(9600);
servo1.attach(5,800,1500);
servo2.attach(6,800,1500);
servo3.attach(9,800,1500);
servo4.attach(10,800,1500);

}

void loop() {
almacen1=analogRead(foto1);
almacen2=analogRead(foto2);
almacen3=analogRead(foto3);
almacen4=analogRead(foto4);

Serial.print("FOTO1: ");
Serial.print(almacen1);
Serial.print(" ");
Serial.print("FOTO2: ");
Serial.print(almacen2);
Serial.print(" ");
Serial.print("FOTO3: ");
Serial.print(almacen3);
Serial.print(" ");
Serial.print("FOTO4: ");
Serial.print(almacen4);
Serial.println(" ");


if(almacen1<=600){
  servo1.write(30);
}if(almacen1>600){
  servo1.write(0);

  
}if(almacen2<=600){
  servo2.write(30);
}if(almacen2>600){
  servo2.write(0);

  
}if(almacen3<=600){
  servo3.write(0);
}if(almacen3>600){
  servo3.write(30);

  
}if(almacen4<=600){
  servo4.write(0);
}if(almacen4>600){
  servo4.write(30);
}
}

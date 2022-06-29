#include <Servo.h>
Servo s1;
#define sensor A3
#define sensor2 A0

 
void setup(){
  pinMode(sensor, INPUT);
  pinMode(sensor2, INPUT);
  Serial.begin(9600);
}
 
void loop(){
  
  int HumedadTierraDerecha= map(analogRead(sensor), 0, 1023, 100, 0);
  int HumedadTierraIzquierda= map(analogRead(sensor2), 0, 1023, 100, 0);
  
  Serial.print("HumedadTierraDerecha: ");
  Serial.print(HumedadTierraDerecha);
  Serial.print("%");
  Serial.print("  ");
  Serial.print("HumedadTierraIzquierda:");
  Serial.print(HumedadTierraIzquierda);
  Serial.println("%");

  delay(100);



}

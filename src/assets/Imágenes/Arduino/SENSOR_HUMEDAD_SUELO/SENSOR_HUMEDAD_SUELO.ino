#include <Servo.h>
Servo s1;
#define sensor A0
#define sensor2 A3
#define RELAY_ON 0    
#define RELAY_OFF 1

 
void setup(){
  pinMode(sensor, INPUT);
  s1.attach (10);
   pinMode(9,OUTPUT);
  Serial.begin(9600);
}
 
void loop(){
  
  //Se hace la lectura analoga del pin A0 (sensor) y se pasa por la funcion
  //map() para ajustar los valores leidos a los porcentajes que queremos utilizar   
  int valorHumedad = map(analogRead(sensor), 0, 1023, 100, 0);
    int valorHumedad2 = map(analogRead(sensor2), 0, 1023, 100, 0);
  
  Serial.print("Humedad: ");
  Serial.print(valorHumedad);
  Serial.print("%");
    Serial.print("  ");
  Serial.print("Humedad2: ");
  Serial.print(valorHumedad2);
  Serial.println("%");

  delay(100);

s1.write (0);

if (valorHumedad <= 20){
  Serial.print ("ALERTA");
    digitalWrite(9, RELAY_ON);
    delay(1000);

}else {
  Serial.print( "ESTADO NORMAL");
      digitalWrite(9, RELAY_OFF);
    delay(1000);
}
s1.write (120);

if (valorHumedad2 <= 20){
  Serial.print ("   ALERTA2  ");
    digitalWrite(9, RELAY_ON);
    delay(1000);
}else {
  Serial.print( "   ESTADO NORMAL2 ");
    digitalWrite(9, RELAY_OFF);
    delay(1000);
}


}

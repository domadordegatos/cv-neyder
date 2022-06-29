
int pinReceptor = A0;
int pinReceptor2 = A1;
int sensorVal; //Declaramos una variable para almacenar el valor de la lectura
int sensorVal2; 
void setup(){
Serial.begin(9600); // Abrimos comunicación Serial
}
 
void loop(){
sensorVal = analogRead(pinReceptor);
sensorVal2 = analogRead(pinReceptor2);
Serial.println(); //Sacamos la lectura por serial
delay(500);  //Pequeña pausa de medio segundo
if (sensorVal <= 15){
  Serial.println("negro1");
}else{
  Serial.println("blanco1");
}if(sensorVal2 <= 15){
  Serial.println("negro2");
}else{
  Serial.println("blanco2");
}
}

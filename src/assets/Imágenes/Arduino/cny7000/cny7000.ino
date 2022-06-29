
int pinReceptor = 7; //Establecemos el pin a leer
int sensorVal; //Declaramos una variable para almacenar el valor de la lectura
void setup(){
Serial.begin(9600); // Abrimos comunicación Serial
}
 
void loop(){
sensorVal = digitalRead(pinReceptor); //Guardamos la lectura del pin Analógico
delay(500);  //Pequeña pausa de medio segundo
Serial.println(sensorVal);
if(sensorVal==0){
  Serial.println("blanco");
}else{
  Serial.println("negro");
}
}

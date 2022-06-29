void setup() { 
//pin 2,3,4,5,6 como salidas digitales 
pinMode(2, OUTPUT); 
pinMode(3, OUTPUT); 
pinMode(4, OUTPUT); 
pinMode(5, OUTPUT); 
pinMode(6, OUTPUT); 

Serial.begin(9600); //velocidad del puerto serial 
} 

// 
void loop() { 
int sensorValue = analogRead(A0); // lee la entrada analógica 0 
//-----compara el valor del pin analógico y si está dentro del rango enciende el led, si no lo apaga---- 
if (sensorValue>=360 && sensorValue<=400){ 
Serial.println("Es color es azul" ); 
digitalWrite(2, HIGH); 
} 
else{ 
digitalWrite(2, LOW); 
} 
//-----compara el valor del pin analógico y si está dentro del rango enciende el led, si no lo apaga---- 
if (sensorValue>=36 && sensorValue<=42){ 
Serial.println("Es color es amarillo" ); 
digitalWrite(3, HIGH); 
} 
else{ 
digitalWrite(3, LOW); 
} 
//-----compara el valor del pin analógico y si está dentro del rango enciende el led, si no lo apaga---- 
if (sensorValue>=28 && sensorValue<=30){ 
Serial.println("Es color es rojo" ); 
digitalWrite(4, HIGH); 
} 
else{ 
digitalWrite(4, LOW); 
} 
//-----compara el valor del pin analógico y si está dentro del rango enciende el led, si no lo apaga---- 
if (sensorValue>=31 && sensorValue<=34){ 
Serial.println("Es color es blanco" ); 
digitalWrite(5, HIGH); 
} 
else{ 
digitalWrite(5, LOW); 
} 
//-----compara el valor del pin analógico y si está dentro del rango enciende el led, si no lo apaga---- 
if (sensorValue>=650 && sensorValue<=750){ 
Serial.println("Es color es verde" ); 
digitalWrite(6, HIGH); 
} 
else{ 
digitalWrite(6, LOW); 
} 
//-----compara el valor del pin analógico y si está dentro del rango enciende el led, si no lo apaga---- 
// Muestra el valor del pin analógico 0 
Serial.println(sensorValue); 
delay(1000); // Retardo entre lecturas 
}

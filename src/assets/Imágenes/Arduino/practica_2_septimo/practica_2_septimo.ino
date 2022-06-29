int guardar=0;
void setup() {
Serial.begin(9600);//iniciar el puerto Serial->9600->velocidad de transmicion
pinMode(8,INPUT);
}

void loop() {
guardar=digitalRead(8);//leer el estado del pin (presionado o no presionado)
if(guardar==HIGH){
  Serial.print("El estado es encendido: ");//para mensajes estaticos
  Serial.println(guardar);//para variable----> ln para salto de linea
}else{
  Serial.print("El estado es apagado: ");
  Serial.println(guardar);
}
}

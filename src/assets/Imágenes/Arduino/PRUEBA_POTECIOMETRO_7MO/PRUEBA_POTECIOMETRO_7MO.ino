int posicion_encargado=0;
void setup() {
 Serial.begin(9600);//inicializar el puerto serial
}

void loop() {
 posicion_encargado=map(analogRead(A2),0,1023,0,50);
 Serial.print("La posicion de la tumba es: ");
 Serial.println(posicion_encargado);
}

int lecpo = A8; // pin para leer el estado del potenciometro
int almacen=0; //variable que almacena la lectura analógica
int position; //posicion del potenciometro
void setup() {
  Serial.begin(9600);
}
void loop() {
almacen = analogRead(lecpo); // lectura de la posicion
position = map(almacen, 0, 1023, 0, 100); // rangos de posicion
 // tiempo de actualizacion
Serial.println(position);
}




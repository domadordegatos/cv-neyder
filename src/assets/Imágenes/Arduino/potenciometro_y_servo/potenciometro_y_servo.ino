int lectura = A0;    //entrada analogica para lectura del pin
int almacen;         // variable para almacenamiento de datos
int position;        //posicion en el mapa establecido
void setup() {
  Serial.begin(9600); 
}
void loop() {
almacen = analogRead(lectura); // almacenamos los datos leidos
position = map(almacen, 0, 1023, 0, 190); // establecemos el rango en el mapa
Serial.println(position);
}




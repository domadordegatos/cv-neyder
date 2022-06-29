int analogPin = A0;
int motor=9;
int value; //variable que almacena la lectura analógica raw
int position; //posicion del potenciometro en tanto por ciento
void setup() {
  Serial.begin(9600);
}
void loop() {
value = analogRead(analogPin); // realizar la lectura analógica raw
position = map(value, 0, 1023, 0, 255); // convertir a porcentaje
//...hacer lo que se quiera, con el valor de posición medido
Serial.println(position);
delay(30);
analogWrite(motor, value);

}

int valor_foto=0;
void setup() {
Serial.begin(9600);
}
void loop() {
  valor_foto=analogRead(A3);
  Serial.println(valor_foto);
}

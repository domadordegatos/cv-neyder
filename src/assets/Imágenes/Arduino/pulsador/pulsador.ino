int pulsador = A5; 
int almacen = 0; 
void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
} void loop(){
  almacen = digitalRead(pulsador);
  if (almacen == HIGH) {
      Serial.println("Encendido");
  }else {
      Serial.println("Apagado");
  }
  delay(200);
}

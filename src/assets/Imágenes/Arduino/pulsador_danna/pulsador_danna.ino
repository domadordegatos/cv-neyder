int pulsador = A5;
int almacen1 = 0;
int rtyu = 7;
void setup() {
  Serial.begin(9600);
  pinMode(rtyu, OUTPUT);
  pinMode(pulsador, OUTPUT); 
} 

void loop() {
  almacen1 = digitalRead(pulsador);
  if ( almacen1 == HIGH ){
    Serial.println("encendido");
    digitalWrite(rtyu, HIGH);
  }else {
    Serial.println("apagado");
    digitalWrite(rtyu, LOW);
  }
  delay(200);
}

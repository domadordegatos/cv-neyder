#define RELAY_ON 0   //señal o para activar
#define RELAY_OFF 1  //señal 1 para desactivar

void setup() {
  pinMode(4,OUTPUT);  // se habilita el puerto como salida

}
void loop() {
    digitalWrite(9, RELAY_ON);
    delay(1000);
    digitalWrite(9, RELAY_OFF);
    delay(1000);
    //proceso de encender y apagar el rele cada 1 segundo
}

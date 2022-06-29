int led1 = 13;            //declaramos que usaremos el pin 13
void setup() {            //parte inicial de la configuracion de pines
pinMode(led1, OUTPUT);    // configuramos el pin 13 como pin de salida
}                         //fin de la configuracion
void loop() {             //inicio de la programacion ciclica
digitalWrite(led1, HIGH); //funcion de encendido del led
delay(1000);              //durante un tiempo de un segundo
digitalWrite(led1, LOW);  //funcion de apagado del led
delay(1000);              // durante un segundo
}

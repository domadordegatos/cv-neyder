int adelante=31; //derecha
int atras=33;    //izquierda
int letra=0;
void setup() {
 Serial.begin(9600);
pinMode(31,OUTPUT);
pinMode(33,OUTPUT);
Serial.println("digite letra: ");
}

void loop() {

  
    digitalWrite(33,HIGH);
    digitalWrite(31,LOW);
delay(1350); // tiempo de movienmiento entre posiciones del eje x



  
   digitalWrite(31,LOW);
    digitalWrite(33,LOW);
delay(100000);

}

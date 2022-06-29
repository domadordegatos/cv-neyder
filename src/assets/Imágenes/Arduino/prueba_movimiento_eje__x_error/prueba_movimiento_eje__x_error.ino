int adelante=37; //atrás 
int atras=35;    //adelnate
int letra=0;
void setup() {
 Serial.begin(9600);
pinMode(37,OUTPUT);
pinMode(35,OUTPUT);
Serial.println("digite letra: ");
}

void loop() {

  
    digitalWrite(37,HIGH);
    digitalWrite(35,LOW);
delay(11000); // tiempo de movienmiento entre posiciones del eje y



  
   digitalWrite(37,LOW);
    digitalWrite(35,LOW);
delay(100000);

}

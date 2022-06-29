int adelante=37; //derecha
int atras=35;    //izquierda
int letra=0;
void setup() {
 Serial.begin(9600);
pinMode(35,OUTPUT);
pinMode(37,OUTPUT);
pinMode(31,OUTPUT);
pinMode(33,OUTPUT);

Serial.println("digite letra: ");
}

void loop() {
if(Serial.available()>0){
  letra=Serial.read();

  if(letra=='1'){
    digitalWrite(37,HIGH);
    digitalWrite(35,LOW); /// ATRAS
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
  }if(letra=='2'){
    digitalWrite(37,LOW);
    digitalWrite(35,HIGH);///ADELANTE
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
  }if(letra=='3'){
    digitalWrite(37,LOW);
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
  }if(letra=='4'){
    digitalWrite(37,LOW);
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);///DERECHA
    digitalWrite(33,LOW);
  }if(letra=='5'){
    digitalWrite(37,LOW);
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);///IZQUIERDA
    digitalWrite(33,HIGH);
  }if(letra=='6'){
    digitalWrite(37,LOW);
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);///MOVIMIENTO CON TIEMPO
    digitalWrite(33,HIGH); /// tiempo hallado 650del centro de cafe a la cruz 
    delay(650);
    digitalWrite(37,LOW);
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
  }if(letra=='7'){
    digitalWrite(37,LOW);
    digitalWrite(35,HIGH);
    digitalWrite(31,LOW);///MOVIMIENTO CON TIEMPO EN BAJADA
    digitalWrite(33,LOW);
    delay(9500);
    digitalWrite(37,LOW);
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
  }
}
}

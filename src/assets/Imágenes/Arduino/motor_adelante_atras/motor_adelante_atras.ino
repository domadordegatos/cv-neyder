int estado=0;
int ad=7;
int at=6;

void setup() {
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);

}

void loop() {
  if(Serial.available()>0){
    estado=Serial.read();

    if(estado=='A'){
      digitalWrite(7,HIGH);
      digitalWrite(6,LOW);
   }if(estado=='B'){
      digitalWrite(7,LOW);
      digitalWrite(6,HIGH);
   }if(estado=='C'){
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
   }
  }
}

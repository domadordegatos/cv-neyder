
int letra=0;
void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  

}

void loop() {
  if(Serial.available()>0){
 letra=Serial.read();
  if(letra=='A'){
   Serial.println("hola1");
   digitalWrite(8,HIGH);
  }
 if(letra=='B'){
   Serial.println("hola2");
   for(int i=1;i<10;i++){
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
      delay(50);
      digitalWrite(9,LOW);
      digitalWrite(8,HIGH);
      delay(50);
   }
  } if(letra=='C'){
   Serial.println("hola3");
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      
  } if(letra=='D'){
   Serial.println("hola4");
  } if(letra=='E'){
   Serial.println("hola5");
  }
}
}

int adl1=22;
int adl2=23;
int atr1=24;
int atr2=25;
int guardar=0;
void setup() {
  // put your setup code here, to run once:
pinMode (22,OUTPUT),
pinMode (23,OUTPUT);
pinMode (24,OUTPUT),
pinMode (25,OUTPUT);
Serial.begin (9600);
 digitalWrite(22,LOW);
  digitalWrite(23,LOW); 
  digitalWrite(24,LOW);
  digitalWrite(25,LOW); 
  Serial.println("digite letra: ");
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0){
 guardar=Serial.read();

if (guardar=='B'){
  digitalWrite(22,HIGH);
  digitalWrite(23,HIGH); 
  digitalWrite(24,LOW);
  digitalWrite(25,LOW); 
}
 if (guardar=='A'){
  digitalWrite(22,LOW);
  digitalWrite(23,LOW); 
  digitalWrite(24,HIGH);
  digitalWrite(25,HIGH); 
 }
 if (guardar=='C'){
   digitalWrite(22,LOW);
  digitalWrite(23,LOW); 
  digitalWrite(24,LOW);
  digitalWrite(25,LOW); 
 }
}
}

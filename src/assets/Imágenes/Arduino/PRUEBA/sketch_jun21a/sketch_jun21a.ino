//primera parte declaracion variables
//1 paso - declarar variables
int led = 4;  
void setup() {
//segunda parte estado de los elementos
pinMode(4,OUTPUT);
Serial.begin(9600);
Serial.print("Digite A=ENCENDER Y B APAGAR");
}

void loop() {
//tercera parte los procesos a realizar 
if(Serial.available()>0){
  int guardar=Serial.read();

  if(guardar=='A'){
    digitalWrite(4,HIGH);
  }if(guardar=='B'){
    digitalWrite(4,LOW);
  }
}

}

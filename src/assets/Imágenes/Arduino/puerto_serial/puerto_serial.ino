
int letra=0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0){
 letra=Serial.read();
 if(letra=='B'){
   Serial.println("hola");
  }
}
}

int x=0;
int y=0;
void setup() {
//los pines analogicos no se declaran como entrada
}

void loop() {
  x=map(analogWrite(A0),0,1023,50,100);
  y=map(analogWrite(A1),0,1023,50,100);

  Serial.print("");
  

}

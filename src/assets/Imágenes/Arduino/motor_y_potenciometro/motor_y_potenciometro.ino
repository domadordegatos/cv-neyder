void setup(){
Serial.begin(9600);
}
void loop(){
float niv=analogRead(A0)/4;
analogWrite(3, niv);
Serial.println (niv);
delay(1000);
}

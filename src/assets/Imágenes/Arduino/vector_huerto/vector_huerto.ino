int agua[9];
char nombre[9];
int m;
void setup() {

}

void loop() {
for(m=0;m<=9;m++){
  nombre[m]=Serial.read();
  delay(100);
  agua[m]=Serial.read();
  delay(100);
}
}

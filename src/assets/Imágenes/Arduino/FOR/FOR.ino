int i;
int f;
void setup() {
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
}

void loop() {
for(i=2;i<=7;i++){
  digitalWrite(i, HIGH);
  delay(25);
}
for(f=2;f<=7;f++){
  digitalWrite(f, LOW);
  delay(25);
}

}

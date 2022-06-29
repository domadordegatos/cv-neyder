int m=0;
void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}

void loop() {
  for(m=1;m<=12;m+1){
    digitalWrite(m,LOW);
    m=m+1;
    digitalWrite(m,HIGH);
    delay(150);
  }
  for(m=12;m>=2;m+1){
    digitalWrite(m,HIGH);
    m=m-1;
    digitalWrite(m,LOW);
    delay(150);
  }
}

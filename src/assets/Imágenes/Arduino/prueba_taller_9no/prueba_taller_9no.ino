int a=0; int b=0; int c=0;
void setup() {
  // put your setup code here, to run once:
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
}

void loop() {
 for(a=2;a<=11;a++){

  digitalWrite(a,HIGH);
  a=a+1;
  digitalWrite(a,HIGH);
  delay(150);
    for(c=0;c<=11;c++){
      digitalWrite(c,LOW);
      c=c+1;
      digitalWrite(c,LOW);
  }
 }
 for(a=11;a>=2;a--){

  digitalWrite(a,HIGH);
  a=a-1;
  digitalWrite(a,HIGH);
  delay(150);
    for(c=11;c>=0;c--){
      digitalWrite(c,LOW);
      c=c-1;
      digitalWrite(c,LOW);
  }
 }



























 

}

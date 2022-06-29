int pu1=2;
int g1=0;
int motor1=3;
void setup() {
pinMode(2,INPUT);
pinMode(3,OUTPUT);
Serial.begin(9600);
}

void loop() {
g1=digitalRead(2);
if(g1==HIGH){
  for(int a=0;a<=10;a++){
    analogWrite(3,255);
    delay(1000);
    a=a+1;
    Serial.println(a);
  }
  for (int m=255;m>=0;m--){
    analogWrite(3,m);
    delay(100);
    m=m-1;
    Serial.println(m);
  }
}
}

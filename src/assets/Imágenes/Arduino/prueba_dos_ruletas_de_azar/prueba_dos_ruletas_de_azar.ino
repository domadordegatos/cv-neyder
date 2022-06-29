int pu1=2;
int pu2=3;
int g1=0;
int g2=0;
int motor1=6;
int motor2=7;
void setup() {
pinMode(2,INPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
Serial.begin(9600);
}

void loop() {
g1=digitalRead(2);
g2=digitalRead(3);
if(g1==HIGH){
  for(int a=0;a<=10;a++){
    analogWrite(6,255);
    delay(1000);
    a=a+1;
    Serial.println(a);
  }
  for (int m=255;m>=0;m--){
    analogWrite(6,m);
    delay(100);
    m=m-1;
    Serial.println(m);
  }
}
if(g2==HIGH){
  for(int aa=0;aa<=10;aa++){
    analogWrite(5,255);
    delay(1000);
    aa=aa+1;
    Serial.println(aa);
  }
  for (int mm=255;mm>=0;mm--){
    analogWrite(5,mm);
    delay(100);
    mm=mm-1;
    Serial.println(mm);
  }
}
}

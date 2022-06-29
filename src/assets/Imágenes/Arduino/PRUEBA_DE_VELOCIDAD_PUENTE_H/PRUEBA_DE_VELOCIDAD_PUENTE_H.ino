int IN1=22;
int IN2=24;
int ENA=8;
int a=A0;
int g=0;
int p=0;

void setup() {
  Serial.begin(9600);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(ENA,OUTPUT);

  
}

void loop() {
  g=analogRead(A0);
  p=map(g,0,1023,0,255);
 digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW); 
  analogWrite(ENA,p);
  Serial.println(p);

}

int pu1=2;
int g1=0;
int motor1=5;
int motor2=6;
int motor3=7;
void setup() {
pinMode(2,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
Serial.begin(9600);
}

void loop() {
g1=digitalRead(2);
if(g1==HIGH){
  for(int a=0;a<=10;a++){
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
        delay(1000);
    Serial.println(a);
    a=a+1;

  }
    for(int a=0;a<=10;a++){
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
        delay(1000);
    Serial.println(a);
        a=a+1;

  }
    for(int a=0;a<=10;a++){
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
        delay(1000);
    Serial.println(a);
        a=a+1;
    delay(1000);
  }
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
 }
}

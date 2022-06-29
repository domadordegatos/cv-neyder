int pu1=2;
int g1=0;
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
if(g1==HIGH){
  for(int a=0;a<=25
  ;a++){
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    delay(1000);
    a=a+1;
    Serial.println(a);
  }
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    delay(250);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    delay(50);
  }

}

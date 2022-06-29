int m1ad=2;
int m1at=3;
int m2ad=4;
int m2at=5;
int estado= 0;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  Serial.begin(9600);
}

void loop() {
   if(Serial.available()>0){
  estado=Serial.read();
  if(estado == 'B'){
    digitalWrite(m1ad,HIGH);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,LOW);//adelante 2 servos 90
    digitalWrite(m2at,LOW);

  }
  if(estado == 'C'){
    digitalWrite(m1ad,LOW);
    digitalWrite(m1at,HIGH);
    digitalWrite(m2ad,LOW);//adelante 2 servos 90
    digitalWrite(m2at,LOW);

  }
  if(estado == 'D'){
    digitalWrite(m1ad,LOW);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,HIGH);//adelante 2 servos 90
    digitalWrite(m2at,LOW);

  }
  if(estado == 'E'){
    digitalWrite(m1ad,LOW);
    digitalWrite(m1at,LOW);
    digitalWrite(m2ad,LOW);//adelante 2 servos 90
    digitalWrite(m2at,HIGH);

  }}}

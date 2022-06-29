int a=7;
int b=6;
int c=5;
int g1=0;
int g2=0;
int g3=0;
void setup() {
  // put your setup code here, to run once:
pinMode(7, INPUT);
pinMode(6, INPUT);
pinMode(5, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
g1=digitalRead(7);
g2=digitalRead(6);
g3=digitalRead(5);
if(g1==HIGH){
  Serial.println("ENCENDIDO1");
}
if(g2==HIGH){
  Serial.println("ENCENDIDO2");
}
if(g3==HIGH){
  Serial.println("ENCENDIDO3");
}
}

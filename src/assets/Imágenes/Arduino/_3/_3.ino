int l1=2;
int l2=3;
int l3=4;
int l4=5;
int l5=6;
int l6=7;
int l7=8;
int l8=9;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//Inicializar la comunicación serial 
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
  pinMode(l8, OUTPUT);
}

void loop() {
 digitalWrite(l1, HIGH);
 digitalWrite(l2, HIGH);
 digitalWrite(l3, LOW);
 digitalWrite(l4, LOW);
 digitalWrite(l5, HIGH);
 digitalWrite(l6, HIGH);
 digitalWrite(l7, LOW);
 digitalWrite(l8, LOW);
 delay(100);
 digitalWrite(l1, LOW);
 digitalWrite(l2, HIGH);
 digitalWrite(l3, HIGH);
 digitalWrite(l4, LOW);
 digitalWrite(l5, LOW);
 digitalWrite(l6, HIGH);
 digitalWrite(l7, HIGH);
 digitalWrite(l8, LOW);
 delay(100);
 digitalWrite(l1, LOW);
 digitalWrite(l2, LOW);
 digitalWrite(l3, HIGH);
 digitalWrite(l4, HIGH);
 digitalWrite(l5, LOW);
 digitalWrite(l6, LOW);
 digitalWrite(l7, HIGH);
 digitalWrite(l8, HIGH);
 delay(100);
 digitalWrite(l1, HIGH);
 digitalWrite(l2, LOW);
 digitalWrite(l3, LOW);
 digitalWrite(l4, HIGH);
 digitalWrite(l5, HIGH);
 digitalWrite(l6, LOW);
 digitalWrite(l7, LOW);
 digitalWrite(l8, HIGH);
 delay(100);

}

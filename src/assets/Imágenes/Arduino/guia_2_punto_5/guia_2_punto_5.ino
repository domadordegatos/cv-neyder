int pulsador = A5; 
int almacen;
int l1 = 7;
int l2 = 8;
int l3 = 9;
int l4 = 10;
int l5 = 11;
int l6 = 12;
int l7 = 13; 
void setup() {
  Serial.begin(9600);
  pinMode(pulsador, INPUT);
   pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(l6, OUTPUT);
  pinMode(l7, OUTPUT);
} void loop(){
  almacen = analogRead(pulsador);
  if (almacen == LOW) {
     digitalWrite(l1, HIGH);
  digitalWrite(l2, HIGH);
  digitalWrite(l3, HIGH);
  digitalWrite(l4, HIGH);
  digitalWrite(l5, HIGH);
  digitalWrite(l6, HIGH);
  digitalWrite(l7, HIGH);
  }else {
      digitalWrite(l1,LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
  digitalWrite(l6, LOW);
  digitalWrite(l7, LOW);
  }
}

int n1=7;
int nose=4;
int hi=2;
void setup() {
 pinMode(n1, OUTPUT);
pinMode(nose, OUTPUT);
pinMode(hi, OUTPUT);
}

void loop() {
 digitalWrite(n1, HIGH);
 digitalWrite(nose, LOW);
 digitalWrite(hi, LOW);
 delay(500);

 digitalWrite(n1, LOW);
 digitalWrite(nose, HIGH);
 digitalWrite(hi, LOW);
 delay(500);

 digitalWrite(n1, LOW); 
  digitalWrite(nose, LOW);
digitalWrite(hi, HIGH);
 delay(500);

digitalWrite(n1, LOW);
digitalWrite(nose, HIGH);
digitalWrite(hi, LOW);
delay(500);
}

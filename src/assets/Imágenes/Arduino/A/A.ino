
int n1=7;
int nose=2;
int hi=4;
void setup(){
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
  digitalWrite(hi, HIGH);
  delay(500);
  
 digitalWrite(n1, HIGH);
  digitalWrite(nose, LOW);
  digitalWrite(hi, HIGH);
}  

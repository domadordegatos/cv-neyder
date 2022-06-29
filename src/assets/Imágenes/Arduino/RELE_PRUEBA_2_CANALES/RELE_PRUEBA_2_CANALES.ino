void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
 digitalWrite(7,LOW);
 digitalWrite(6,HIGH);
 delay(1000);
 digitalWrite(7,HIGH);
 digitalWrite(6,LOW);
 delay(1000);
 
}

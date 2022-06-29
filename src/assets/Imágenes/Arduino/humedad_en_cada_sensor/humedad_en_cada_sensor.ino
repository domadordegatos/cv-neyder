int s=0;
int sensor=A4;
 
void setup() {
Serial.begin(9600);
}
 
void loop() {
 s=map(analogRead(A4),0,1023,175,0);
Serial.println(s);
}

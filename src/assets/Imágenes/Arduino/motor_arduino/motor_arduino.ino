int control = 7 ;
void setup(){
  pinMode(control, OUTPUT) ; 
  Serial.begin(9600);
  }
void loop(){
for ( int n = 0 ; n < 255 ; n++){
analogWrite (control, n) ;
delay(500);
Serial.println(n);
}
}

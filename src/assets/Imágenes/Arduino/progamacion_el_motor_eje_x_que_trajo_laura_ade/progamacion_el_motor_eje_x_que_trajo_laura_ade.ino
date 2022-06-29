int adelante= 31;
int atras = 33;


void setup() {
 pinMode (31,OUTPUT);
 pinMode (33,OUTPUT);
 digitalWrite (31,LOW);
digitalWrite (33,LOW);
}

void loop() {
   digitalWrite (31,LOW);
digitalWrite (33,LOW);
delay (3000);
digitalWrite (33,HIGH);
digitalWrite (31,LOW);
delay (1500);
   digitalWrite (31,LOW);
digitalWrite (33,LOW);
delay (30000000);
}

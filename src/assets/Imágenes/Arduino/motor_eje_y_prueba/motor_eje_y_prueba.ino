int adelante= 31;
int atras = 33;
int a=35;
int b=37;



void setup() {
 pinMode (31,OUTPUT);
 pinMode (33,OUTPUT);
 pinMode (35,OUTPUT);
 pinMode (37,OUTPUT);
 digitalWrite (35,LOW);
digitalWrite (37,LOW);
}

void loop() {
digitalWrite (37,HIGH);
digitalWrite (35,LOW);
delay (23000);
digitalWrite (31,LOW);
digitalWrite (33,LOW);
delay (30000000);
}

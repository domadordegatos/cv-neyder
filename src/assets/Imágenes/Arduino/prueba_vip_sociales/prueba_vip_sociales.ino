int a=8; int b=10;int c=12;
int aa=7;int bb=6;int cc=5;
int g1=0;int g2=0;int g3=0;
const int pinBuzzer = 9;

#define RELAY_ON 0    
#define RELAY_OFF 1
const int tonos[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
const int countTonos = 10;

void setup() {
Serial.begin(9600);
digitalWrite (7, RELAY_OFF);
digitalWrite (6, RELAY_OFF);
digitalWrite (5, RELAY_OFF);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(8, INPUT);
pinMode(10, INPUT);
pinMode(12, INPUT);

}

void loop() {
  
g1=digitalRead(8);
g2=digitalRead(10);
g3=digitalRead(12);
Serial.print("b1: ");
Serial.print(g1);
Serial.print("  b2: ");
Serial.print(g2);
Serial.print("  b3: ");
Serial.println(g3);

 if(g1==HIGH && g2==LOW && g3==LOW){
  Serial.println("gana el 1");
  digitalWrite (7, RELAY_ON);
   tone(pinBuzzer, 494);
   delay(250);
   exit(0);
}if(g1==LOW && g2==HIGH && g3==LOW){
   Serial.println("gana el 2");
    digitalWrite (6, RELAY_ON);
    tone(pinBuzzer, 494);
   delay(250);
   exit(0);
}if(g1==LOW && g2==LOW && g3==HIGH){
   Serial.println("gana el 3");
    digitalWrite (5, RELAY_ON);
    tone(pinBuzzer, 494);
   delay(250);
   exit(0);
}
}

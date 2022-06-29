const int pinBuzzer = 9;
 
const int tonos[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
const int countTonos = 10;
   int a=1;
void setup()
{ 
}
 
void loop(){
   tone(pinBuzzer, 440);
   delay(500);
   exit(0);
}

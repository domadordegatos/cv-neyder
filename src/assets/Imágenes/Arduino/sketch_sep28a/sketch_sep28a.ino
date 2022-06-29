int position ;
int l = A1 ;
int motor = 3;



void setup() {
 pinMode (3, OUTPUT);
 Serial.begin (9600);
 // put your setup code here, to run once:

}

void loop() {
 position = map (analogRead (A1), 0, 1023, 0, 255); // put your main code here, to run repeatedly:
analogWrite (3, position);
Serial.println (position);
}

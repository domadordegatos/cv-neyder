#include <Servo.h>
Servo hola;
void setup() {
 
hola.attach(8);
}

void loop() {
for(int m=0;m<=180;m++){
  hola.write(m);
  delay(30);
}for(int m=180;m>=0;m--){
  hola.write(m);
  delay(30);
}

}

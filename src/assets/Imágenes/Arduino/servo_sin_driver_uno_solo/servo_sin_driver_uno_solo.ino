#include <Servo.h>
Servo s1;
void setup() {
  // put your setup code here, to run once:
s1.attach(9);
}

void loop() {
  
s1.write(98);

}

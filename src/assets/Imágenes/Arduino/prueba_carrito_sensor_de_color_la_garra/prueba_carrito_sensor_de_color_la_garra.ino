#include <Servo.h>
Servo s1;
void setup() {
s1.attach(7,800,1500);

}

void loop() {
  s1.write(1);
}

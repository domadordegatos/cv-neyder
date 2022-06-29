#include <Ultrasonic.h>

Ultrasonic ultrasonic(8, 9);
Ultrasonic ultrasonic2(6, 7);
int distance;
int distance2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();
    distance2 = ultrasonic2.read();
  
  Serial.print("Distance in CM: ");
  Serial.print(distance);
    Serial.print("Distance2 in CM: ");
  Serial.println(distance2);
  delay(200);
}

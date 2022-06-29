   #include <Ultrasonic.h>

int m1ad=11;
int m1at=10;
int m2ad=6;
int m2at=5;
int velm=150;
int vel=255;
int estado=0;
#include <Ultrasonic.h>

Ultrasonic ultrasonic(8, 9);
int distance;
void setup() {
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(200);

    analogWrite(m1ad,vel);
    analogWrite(m1at,0);
    analogWrite(m2ad,vel);
    analogWrite(m2at,0);
}

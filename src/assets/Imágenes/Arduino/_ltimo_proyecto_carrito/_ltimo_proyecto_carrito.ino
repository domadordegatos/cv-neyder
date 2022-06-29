#include <SoftwareSerial.h> // TX RX software library for bluetooth
 #include <Servo.h> // servo library 

int bluetoothTx = 8; // bluetooth tx to 10 pin
int bluetoothRx = 9; // bluetooth rx to 11 pin
 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
Servo s1, s2;
int m1ad=11;
int m1at=10;
int m2ad=6;
int m2at=5;
int velm=150;
int vel=255;
void setup() {
  s1.attach(7,800,1500);
  s2.attach(12,800,1500);
  bluetooth.begin(9600);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
s1.write(180);
s2.write(0);
}

void loop() {
    
    
    if(bluetooth.available()>= 2 ) {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    Serial.println(realservo);

  if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      s1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
      }
       if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      s2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
      }
       if (realservo >= 3000 && realservo <3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      int dato= 180;
      int grado= dato- servo3;
      s1.write(servo3);
      s2.write(grado); 
      
      Serial.println("Servo 3 ON");
      delay(10);
      }
     if (realservo == 4000) {
         analogWrite(m1ad,vel);
    analogWrite(m1at,0);
    analogWrite(m2ad,vel); //Adelante
    analogWrite(m2at,0);
     }
 
         if (realservo == 4004) {
    analogWrite(m1ad,0);
    analogWrite(m1at,vel);
    analogWrite(m2ad,0); // Atrás
    analogWrite(m2at,vel);
         }

              if (realservo == 4002) {
     analogWrite(m1ad,0);
    analogWrite(m1at,0);
    analogWrite(m2ad,0); // Para
    analogWrite(m2at,0);
              }

         if (realservo == 4001) {
    analogWrite(m1ad,vel);
    analogWrite(m1at,0);
    analogWrite(m2ad,0); // Gira hacia algún lado 
    analogWrite(m2at,0);
         }
        if (realservo == 4003) {
    analogWrite(m1ad,0);
    analogWrite(m1at,0);
    analogWrite(m2ad,vel); // Gira hacia el otro
    analogWrite(m2at,0);
        }

    if (realservo == 4005) {
    s1.write(100);
    s2.write(25);
         }

    if (realservo == 4006) {
    s1.write(130);
    s2.write(50);
         }
         
    if (realservo == 4007) {
    s1.write(130);
    s2.write(25);
         }

    if (realservo == 4008) {
    s1.write(105);
    s2.write(45);
         }

    if (realservo == 4009) {
    s1.write(180);
      s2.write(0); 
    }
    }
}
  

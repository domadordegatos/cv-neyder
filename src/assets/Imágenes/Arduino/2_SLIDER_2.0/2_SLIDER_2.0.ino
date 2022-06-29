#include <SoftwareSerial.h> 
int bTx = 10; 
int bRx = 11;
 
SoftwareSerial bluetooth(bTx, bRx);
 
void setup()
{
  myservo1.attach(4,800,1500); // attach servo signal wire to pin 9
  myservo2.attach(5,800,1500);
  //Setup usb serial connection to computer
  Serial.begin(9600);
 
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}
 
void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servopos = bluetooth.read();
    unsigned int servopos1 = bluetooth.read();
    unsigned int realservo = (servopos1 *256) + servopos;
    Serial.println(realservo);
 
    if (realservo >= 1000 && realservo <1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      myservo1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
    if (realservo >= 2000 && realservo <2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      myservo2.write(servo2);
      Serial.println("Servo 2 ON");
      delay(10);
    }
  }
}

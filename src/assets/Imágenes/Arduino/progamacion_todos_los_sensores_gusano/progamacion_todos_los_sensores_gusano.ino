#include <Servo.h>
#include <Ultrasonic.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#define sensor A0
#define sensor2 A3
#define RELAY_ON 0    
#define RELAY_OFF 1
DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ultrasonic(8, 9);
Ultrasonic ultrasonic2(10, 11);
Servo s1;
Servo s2;
int m1ad=2;
int m1at=3;
int m2ad=4;
int m2at=5;
int distance;
int distance2;




void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(sensor2,INPUT);
  Serial.begin(9600);
  s1.attach(6);
  s2.attach(7);

}

void loop() {
 distance = ultrasonic.read();
  distance2 = ultrasonic2.read();
  
  Serial.print("Distance in CM: ");
  Serial.print(distance);
  Serial.print("   Distance2 in CM: ");
  Serial.println(distance2);
  delay(200);
  delay(5000);
////////////////////SENSOR DISTANCIA/////////////////////////////////////////////////////////////////////////////////
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
  Serial.println("Error obteniendo los datos del sensor DHT11");
  return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.print(" *F");

///////////////////////////SENSOR AIRE HUMEDAD////////////////////////////////////////////77
 int valorHumedad = map(analogRead(sensor), 0, 1023, 100, 0);
 int valorHumedad2 = map(analogRead(sensor2), 0, 1023, 100, 0);
  
  Serial.print("Humedad: ");
  Serial.print(valorHumedad);
  Serial.print("%");
  Serial.print("  ");
  Serial.print("Humedad2: ");
  Serial.print(valorHumedad2);
  Serial.println("%");
  delay(100);




}

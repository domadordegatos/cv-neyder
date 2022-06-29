#define PIN_OUT 3  
#define PIN_OE  5  
#define PIN_S0  2 
#define PIN_S1  4  
#define PIN_S2  7  
#define PIN_S3  8  
 #define TIEMPO_ENTRE_LECTURAS 1000 
 unsigned long cronometro_lecturas=0;
unsigned long duracion_ciclo;

void setup() {
 pinMode(PIN_S0,OUTPUT);
  digitalWrite(PIN_S0,LOW);  
  pinMode(PIN_S1,OUTPUT);
  digitalWrite(PIN_S1,HIGH); 
  pinMode(PIN_S2,OUTPUT);
  digitalWrite(PIN_S2,HIGH); 
  pinMode(PIN_S3,OUTPUT);
  digitalWrite(PIN_S3,LOW);  
  pinMode(PIN_OE,OUTPUT);
  digitalWrite(PIN_OE,LOW);  
  pinMode(PIN_OUT,INPUT);
  Serial.begin(9600);
 
}

void loop() {

if((unsigned long)(millis()-cronometro_lecturas)>TIEMPO_ENTRE_LECTURAS)
  
    cronometro_lecturas=millis();
    pulseIn(PIN_OUT,LOW); 
    duracion_ciclo=pulseIn(PIN_OUT,HIGH); 
    duracion_ciclo+=pulseIn(PIN_OUT,LOW); 
    Serial.print("Frecuencia ");
    Serial.print(1000.0/duracion_ciclo); 
    Serial.println(" KHz");

 
}

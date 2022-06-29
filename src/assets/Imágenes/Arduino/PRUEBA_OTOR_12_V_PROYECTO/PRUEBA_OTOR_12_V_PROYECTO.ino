int adelante = 31;  // cajas  
int atras = 33; // adelante= izquiera atras = derecha
int velocidad = 2;
void setup() {
pinMode (adelante,OUTPUT);
pinMode (atras,OUTPUT);
pinMode (velocidad,OUTPUT);
}

void loop() {

  digitalWrite (adelante,LOW);
  digitalWrite (atras,HIGH);
  analogWrite (velocidad,120);
  delay (1000);
  
}


#define PIN_OE  5  // Número de pin para activar el TCS3200 (se activa a nivel bajo) Para que siempre esté activo se puede conectar a GND
#define PIN_S0  1  // Número de pin de Arduino que conecta a S0 del TCS3200 (escala de frecuencia)
#define PIN_S1  2  // Número de pin de Arduino que conecta a S1 del TCS3200 (escala de frecuencia)
#define PIN_S2  3  // Número de pin de Arduino que conecta a S2 del TCS3200 (filtro de color)
#define PIN_S3  4  // Número de pin de Arduino que conecta a S3 del TCS3200 (filtro de color)
#define TOTAL_FILTROS 4
#define TIEMPO_ENTRE_RESULTADOS 1000 // Esperar 1 segundo para mostrar el estado actual de máximo y mínimo
 
unsigned long cronometro_resultado=0;
unsigned char contador_filtro; // Contador global del número de filtro que se está procesando
float tiempo_pulso;
unsigned long minimo[TOTAL_FILTROS]={-1,-1,-1,-1};
unsigned long maximo[TOTAL_FILTROS]={0,0,0,0};
bool s2[TOTAL_FILTROS]={LOW,HIGH,LOW,HIGH}; // Valor del pin S2 para conseguir el rojo (0), verde (1) azul (2) y la luminosidad (3)
bool s3[TOTAL_FILTROS]={LOW,HIGH,HIGH,LOW}; // Valor del pin S3 para conseguir el rojo (0), verde (1) azul (2) y la luminosidad (3)
String nombre[TOTAL_FILTROS]={"Rojo","Verde","Azul","Blanco"};


void setup() {

  pinMode(PIN_OUT,INPUT);
  pinMode(PIN_OE,OUTPUT);
  pinMode(PIN_S0,OUTPUT);
  pinMode(PIN_S1,OUTPUT);
  pinMode(PIN_S2,OUTPUT);
  pinMode(PIN_S3,OUTPUT);
  digitalWrite(PIN_S0,LOW);  // Modo de baja frecuencia (2%) 12 KHz máximo (con pulseIn la frecuencia máxima es de 50 KHz, tiempo mínimo 10 µs)
  digitalWrite(PIN_S1,HIGH); // Modo de baja frecuencia (2%) 12 KHz máximo (con pulseIn la frecuencia máxima es de 50 KHz, tiempo mínimo 10 µs)
  digitalWrite(PIN_OE,LOW);  // Activar el TCS3200 estableciendo un nivel bajo en OE
  Serial.begin(9600);
}
 

void loop() {
  {
  for(contador_filtro=0;contador_filtro<TOTAL_FILTROS;contador_filtro++)
  {
    digitalWrite(PIN_S2,s2[contador_filtro]);
    digitalWrite(PIN_S3,s3[contador_filtro]);
    pulseIn(PIN_OUT,LOW); // Esperar a que cambie el estado a bajo
    tiempo_pulso=pulseIn(PIN_OUT,HIGH); // Tiempo transcurrido hasta que cambia el estado (medio ciclo)
    tiempo_pulso+=pulseIn(PIN_OUT,LOW); // Volver a medir para completar y ciclo y disminuir un poco el error
    if(tiempo_pulso>maximo[contador_filtro])
    {
      maximo[contador_filtro]=tiempo_pulso;
    }
    if(tiempo_pulso<minimo[contador_filtro])
    {
      minimo[contador_filtro]=tiempo_pulso;
    }
  }
  if((unsigned long)(millis()-cronometro_resultado)>TIEMPO_ENTRE_RESULTADOS)
  {
    cronometro_resultado=millis();
    for(contador_filtro=0;contador_filtro<TOTAL_FILTROS;contador_filtro++)
    {
      Serial.println(nombre[contador_filtro]);
      Serial.print("Tiempo máximo ");
      Serial.print(maximo[contador_filtro]);
      Serial.println(" µs");
      Serial.print("Tiempo mínimo ");
      Serial.print(minimo[contador_filtro]);
      Serial.println(" µs");
      Serial.print("\n"); // Una línea en blanco como separador
      // Cambiar el máximo y el mínimo para ver el comportamiento en cada lectura
      /*
      minimo[contador_filtro]=-1;
      maximo[contador_filtro]=0;
      */
    }
    Serial.print("\n"); // Una línea en blanco como separador
      }

}

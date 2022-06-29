
#include <Time.h>
#include <TimeAlarms.h>
#include <DS1307RTC.h>
 
void setup() {
  // Preparar la interfaz serial
  Serial.begin(9600);
 
  // Configurar los pines de salida de relevadores desactivados al inicio
  // recordamos que los modulos de reles se activan con un estado bajo
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  pinMode(4,HIGH);
  digitalWrite(4, HIGH);
 
  // Cargar la hora actual desde el RTC e indicar que esto suceda de forma automática durante loop()
  // Utilizamos el método RTC.get() de la libreria DS1307RTC. El RTC debe estar conectado como se
  // indica en el texto y debe tener la fecha y hora correctas
  setSyncProvider(RTC.get);
  if (timeStatus() != timeSet)
    Serial.println("Fallo de RTC");
  else
    Serial.println("Sincronizado con RTC");
 
  // Crear las alarmas y configurar las funciones correspondientes a cada una
  Alarm.alarmRepeat(18, 0, 0, EventoEnciendeLuz);  // Evento a las 18:00 diario (enciende luz)
  Alarm.alarmRepeat(7, 0, 0, EventoApagaLuz);  // Evento a las 7:05 diario (apaga luz)
}
 
void loop() {
  // Mostrar el reloj en el monitor serial
  digitalClockDisplay();
 
  // Esperar 1 segundo y procesar las Alarmas mientras tanto...
  // El metodo Alarm.delay() procesa en el fondo las alarmas y llamara a las funciones indicadas
  Alarm.delay(1000);
}
 
/**
   Funcion callback que activa el relevador en el pin 3 (enciende la luz)
*/
void EventoEnciendeLuz()
{
  Serial.println("Encendiendo Luz!!!");
  digitalWrite(3, LOW);
}
 
/**
   Funcion callback que desactiva el relevador en el pin 3 (apaga la luz)
*/
void EventoApagaLuz()
{
  Serial.println("Apagando Luz!!!");
  digitalWrite(3, HIGH);
}
 
/**
   Funciones para la impresion del reloj al monitor serial de arduino
*/
void digitalClockDisplay() {
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}
 
void printDigits(int digits) {
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

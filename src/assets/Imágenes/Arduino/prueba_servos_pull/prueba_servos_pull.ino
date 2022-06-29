#include <Servo.h>
Servo primera;
char guardado=0;
int c=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
primera.attach(22,800,1500);
Serial.println(" presione D para ir a 0");
Serial.println(" presione E para ir a 90");
Serial.println(" presione F para ir a 180");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
 guardado = Serial.read();
 
                                  
  if(guardado=='D' && c==0){ // la parte dificil es establecer tres movimientos para el brazo y poder realizarlos sin que se repita,
   for(c=0;c<=90;c+5){   // estructura for para que vaya a  
   c=c+5;                // los grados se pueden modificar para establecer un punto para sujetar las cosas
   primera.write(c);     // se mueve segun va incrementando la letra c   
   delay(200);           // se mueve cada 200 
   } // fin del for
   guardado='0';     //guardado vuelve a ser igual a cero para poder seguir leyendo letras   
   c=90;             // c toma el valor al que llego para evitar inconvenientes al momento de reutilizar el for
  }if(guardado=='D' && c==90){
    guardado='0';          // esta condicion es para que cuando se lee una letra y ya se encuentra en ese grado no realice nada
    c=90;
  }if(guardado=='D' && c==180){
   for(c=180;c>=90;c-5){
    c=c-5;                  //cuando lee la letra d y se encuentra en 180 el se encarga de ir a 90 grado, se debe tener presente que la letra indicada el grado para el que funciona el servo en este caso D es para 90 grados en ese servo
    primera.write(c);
    delay(200);
   }
   guardado='0';
   c=90;
  }


                                  
  if(guardado=='E' && c==0){    // la letra es es para que este mismo servo vaya al grado 0  por lo cual si ya esta en cero y lee la letra E entonces no hace nada
   guardado='0';    
   c=0;             
  }if(guardado=='E' && c==90){  // si esta en 90
    for(c=90;c>=0;c-5){
      c=c-5;
      primera.write(c);
      delay(200);
    }
    guardado='0';         
    c=0;
  }if(guardado=='E' && c==180){
   for(c=180;c>=0;c-5){
    c=c-5;                 
    primera.write(c);
    delay(200);
   }
   guardado='0';
   c=0;
  }



  if(guardado=='F' && c==0){    // la letra F es es para que este mismo servo vaya al grado 180  por lo cual si ya esta en cero y lee la letra E entonces no hace nada
   for(c=0;c<=180;c+5){
    c=c+5;
    primera.write(c);
    delay(200);
   }
   guardado='0';    
   c=180;             
  }if(guardado=='F' && c==90){  // si esta en 90
    for(c=90;c<=180;c+5){
      c=c+5;
      primera.write(c);
      delay(200);
    }
    guardado='0';         
    c=180;
  }if(guardado=='F' && c==180){
   guardado='0';
   c=0;
  } 
  return;
  }
}
   

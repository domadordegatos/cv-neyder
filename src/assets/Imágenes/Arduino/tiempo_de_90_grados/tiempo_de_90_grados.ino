/* 
ARDUINO   L293D(Puente H)        
  5          10
  6          15
  9          7
  10         2
  5V         1, 9, 16
  GND        4, 5, 12, 13  
 m 1 se conecta a los pines 3 y 6 del Puente H
 m 2 se conecta a los pines 11 y 14 del Puente H
  
  La fuente de alimentacion de los Motores se conecta a tierra y
  el positivo al pin 8 del puennte H. 
*/
int izqA = 5; //pines de puente h
int izqB = 6; //pines de puente h
int derA = 9; //pines de puente h
int derB = 10;  //pines de puente h
int bra1 = 19;  // brazos por asignar
int bra2 = 20;  // brazos por asignar 
int bra11 = 22;  // brazos por asignar
int bra22 = 23;  // brazos por asignar 

int vel = 255; //velocidad de rodaje
int vel2 = 150; //velocidad de basura        
int estado = 'g';     
void setup()  { 
  Serial.begin(9600);  
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  pinMode(bra1, OUTPUT); // brazos por asignar
  pinMode(bra2, OUTPUT); // brazos por asignar
  pinMode(bra11, OUTPUT);
  pinMode(bra22, OUTPUT);
 } 
 
void loop()  { 
  
  if(Serial.available()>0){       
      estado = Serial.read();
  }
  if(estado=='A'){           //adelante
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, vel);  
      analogWrite(izqA, vel);
      
  }
  if(estado=='B'){          // izquierda 
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);  
      analogWrite(izqA, vel);
      delay(140);
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);  
      analogWrite(izqA, 0);
      delay(3000);      
  }
  if(estado=='E'){         // alto
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, 0);    
      analogWrite(izqA, 0); 
  }
  if(estado=='C'){          // derecha
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, 0);
       analogWrite(derA, vel); 
       delay(140); 
       analogWrite(derB, 0);     
       analogWrite(izqB, 0); 
       analogWrite(derA, 0);  
       analogWrite(izqA, 0);
       delay(3000);  
  } 
  
  if(estado=='D'){          // atras
       analogWrite(derA, 0);    
       analogWrite(izqA, 0);
       analogWrite(derB, vel);  
       analogWrite(izqB, vel);      
  }
  if(estado=='2'){          // obstaculo a la derecha //el cero falta por asignar al boton de la aplicacion
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, 0);
       analogWrite(derA, vel);
       delay(3000);
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel);
       analogWrite(derA, vel);
       delay(3000);
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel);
       analogWrite(derA, 0);
       delay(3000);
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel);
       analogWrite(derA, vel); //permanente hacia adelante

      }
  if(estado=='1'){          // obstaculo a la izquierda //el cero falta por asignar al boton de la aplicacion
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel);
       analogWrite(derA, 0);
       delay(3000);             // segundos por establecer
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel);
       analogWrite(derA, vel);
       delay(3000);
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, 0);
       analogWrite(derA, vel);
       delay(3000);
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel);
       analogWrite(derA, vel); //permanente hacia adelante
        }
  if(estado=='4'){          // levantar brazossssssssssssssssssssssssssssssssss para recoger basura  // estado 0 aun por asignar
       analogWrite(derB, 0); // motores apagados    
       analogWrite(izqB, 0); // motores apagados
       analogWrite(izqA, 0); // motores apagados
       analogWrite(derA, 0); // motores apagados
       analogWrite(bra11, 0);
       analogWrite(bra22, 0);
       analogWrite(bra1, vel2); // brazos a 90 grados arriba     
       analogWrite(bra2, vel2); // brazos a 90 grados arriba
       delay(5000);  // tiempo por definir hasta que esten arriba
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel2);
       analogWrite(derA, vel2);  // va hacia adelante recogiendo basura con velocidad mas lenta que esta establecida en variables 150
       delay(3000);             // segundos po establecer
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, 0);
       analogWrite(derA, 0);
       analogWrite(bra1, 0);
       analogWrite(bra2, 0);
       analogWrite(bra11, vel2); // bajan los brazos nivel de los brazos por definir
       analogWrite(bra22, vel2); // bajan los brazos nivel de los brazos por definir
       delay(3000);  // tiempo por definir segun nivel de los brazos
       analogWrite(bra1, 0);
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);
       analogWrite(bra22, 0);
       analogWrite(derB, 0);     
       analogWrite(izqB, 0);
       analogWrite(izqA, vel);
       analogWrite(derA, vel); //permanente hacia adelante
       } 
  
  if(estado=='3'){          // walle buscando basura  //estado 0 por asignar  //brazos giran opuestamente y motores van en sigsag
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);
       analogWrite(derA, 0);  
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora giro d 45 grados hacia el otro lado
       analogWrite(derA, vel);   
       analogWrite(izqA, 0);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos  
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);
       analogWrite(derA, 0);  
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora giro d 45 grados hacia el otro lado
       analogWrite(derA, vel);   
       analogWrite(izqA, 0);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos  
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);
       analogWrite(derA, 0);  
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora giro d 45 grados hacia el otro lado
       analogWrite(derA, vel);   
       analogWrite(izqA, 0);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos  
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);
       analogWrite(derA, 0);  
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora giro d 45 grados hacia el otro lado
       analogWrite(derA, vel);   
       analogWrite(izqA, 0);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos  
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);
       analogWrite(derA, 0);  
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora giro d 45 grados hacia el otro lado
       analogWrite(derA, vel);   
       analogWrite(izqA, 0);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(1000);  // giro de 45 grados    // tiempo tambien por definir dependiendo de los grados del giro
       analogWrite(derB, 0);    
       analogWrite(izqB, 0);   // ahora derecho unos segundos con los brazos aun en movimiento
       analogWrite(derA, vel);   
       analogWrite(izqA, vel);
       analogWrite(bra1, vel); //gira opuestamente al otro brazo    
       analogWrite(bra2, 0);
       analogWrite(bra11, 0);  
       analogWrite(bra22, vel); //gira opuestamente al otro brazo
       delay(6000);  // derecho 6 segundos  
  }
   if (estado == '5'){   // levante brazo izquierdo
    analogWrite(derB, 0); // motores apagados    
       analogWrite(izqB, 0); // motores apagados
       analogWrite(izqA, 0); // motores apagados
       analogWrite(derA, 0); // motores apagados
       analogWrite(bra11, 0);
       analogWrite(bra22, 0);
       analogWrite(bra1, vel); // brazos a 90 grados arriba     
       analogWrite(bra2, vel); // brazos a 90 grados arriba
       delay(5000);  // tiempo por definir hasta que esten arriba    
   }

   if (estado =='6'){ //levante brazo derecho
    analogWrite(derB, 0); // motores apagados    
       analogWrite(izqB, 0); // motores apagados
       analogWrite(izqA, 0); // motores apagados
       analogWrite(derA, 0); // motores apagados
       analogWrite(bra11, 0);
       analogWrite(bra22, 0);
       analogWrite(bra1, vel); // brazos a 90 grados arriba     
       analogWrite(bra2, vel); // brazos a 90 grados arriba
       delay(5000);  // tiempo por definir hasta que esten arriba
   }
   
   if (estado =='8'){ //baje brazo izquierdo
    analogWrite(derB, 0); // motores apagados    
       analogWrite(izqB, 0); // motores apagados
       analogWrite(izqA, 0); // motores apagados
       analogWrite(derA, 0); // motores apagados
       analogWrite(bra11, vel); // brazos a 90 grados arriba
       analogWrite(bra22, vel); // brazos a 90 grados arriba
       analogWrite(bra1, 0);   
       analogWrite(bra2, 0); 
       delay(5000);  // tiempo por definir hasta que esten abajo
   }


      if (estado =='9'){ //baje brazo derecho
    analogWrite(derB, 0); // motores apagados    
       analogWrite(izqB, 0); // motores apagados
       analogWrite(izqA, 0); // motores apagados
       analogWrite(derA, 0); // motores apagados
       analogWrite(bra11, vel); // brazos a 90 grados arriba
       analogWrite(bra22, vel); // brazos a 90 grados arriba
       analogWrite(bra1, 0);
       analogWrite(bra2, 0);
       delay(5000);  // tiempo por definir hasta que esten abajo
   }
  }
           

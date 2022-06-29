#include <Ultrasonic.h> //libreria ultrasonico
#include <AFMotor.h>  //libreria motores
#include <Servo.h>    //libreria servos

                //variables para el for //las letras son la variable que se ocupa en el for para poder moverse entre grados sin que haya fallos al repetir la variable para el for
Servo direccion;    //a         //direccion del carro
Servo girogarra;    //b         //gira la garra para agarrar y soltar
Servo primera;      //c         //primer grado de movimiento 
Servo segunda;      //d         //segundo grado de movimiento levanta la garra
Servo garra;        //e         // abre y cierra la garra
Servo separador;    //

AF_DCMotor motor1(1);  //declaracion de variables por motor del motor shield
AF_DCMotor motor2(2);

Ultrasonic ultrasonic(9,8);  // estos pines del ultrasonico hay que cambiarlos porque ya se estan usando por el motor shields
Ultrasonic ultrasonic2(9,8);  // hay que cambiar estos pines porque ademas de que se repiten son pines que ya estan en uso


int a=0;  //direccion
int b=0;  //giro de la garra
int c=0;  //primer servo de 11kg
int d=0;  //segundo servo futaba arriba del de 11kg
int e=0;  //abrir y cerrar garra

 //variables for para el automatico
 int f=0; //primera
 int g=0; // segunda
 int h=0; //garra


                    // hay que cambiar los pines del sensor de color porque estos ya los estamos usando
const int s0 = 8;  //cambiar
const int s1 = 9;  //cambiar
const int s2 = 12;  //cambiar
const int s3 = 11;  //cambiar
const int out = 10; //cambiar
byte countRed = 0;   variable para color
byte countGreen = 0;
byte countBlue = 0;



int guardado=0;   //variable para guardar datos de aplicacion

void setup() {

   pinMode(s0, OUTPUT);   //pines para los leds blancos, como salida porque es una luz
   pinMode(s1, OUTPUT);
   pinMode(s2, OUTPUT);
   pinMode(s3, OUTPUT);
   pinMode(out, INPUT);    //entrada de señal
   digitalWrite(s0, HIGH);
   digitalWrite(s1, HIGH);

motor1.setSpeed(255); // se establece la velocidad en maximo
motor2.setSpeed(255);
  
  Serial.begin(9600); // comunicacion con el puerto serial y velocidad de comunicacion
direccion.attach(22,500,1800);
girogarra.attach(23,500,1800);
primera.attach(24,500,1800);  //pines a usar para los servos. se pueden cambiar
segunda.attach(25,500,1800);
garra.attach(26,500,1800);


primera.write(90);  //se pone en el void setup para que inicialmente este en 90 grados el servo
segunda.write(90);  //se pone en el void setup para que inicialmente este en 90 grados el servo
direccion.write(grado centrado);  //cambiar valor
garra.write(grado abierta);  //cambiar valor
girogarra.write(grado al frente, estado apagada);  //cambiar valor

}

void loop() {

  Serial.print("distacia1: ");   // sensor uno
  Serial.print(ultrasonic.Ranging(CM)); // segun los calculos de la libreria da un valor en centimetros
  Serial.print(" cm     " );  // da un valor en centimetros con repeticiones casi instantaneas para que sea mas exacta la distancia
  delay(50);


 Serial.print("distacia2: ");         // deteccion en centimetros del segundo ultrasonico
 Serial.print(ultrasonic2.Ranging(CM));
 Serial.print(" cm     " );
 delay(50);

 
  getColor();             // esta programacion es para encender el sensor de color y poder determinar tres colores, lo usaremos para dos nada mas
   Serial.print("Red: ");
   Serial.print(countRed, DEC);
   Serial.print("Green: ");
   Serial.print(countGreen, DEC);
   Serial.print("Blue: ");
   Serial.print(countBlue, DEC);
 
   if (countRed < countBlue && countGreen > 100 && countRed < 80){
      Serial.println(" - Red");
   }
   else if (countBlue < countRed && countBlue < countGreen){
      Serial.println(" - Blue");
   }
   else if (countGreen < countRed && countGreen < countBlue)
   {
      Serial.println(" - Green");
   }
   else {
      Serial.println("-");
   }
   delay(300);
}
 
void getColor()
{
   digitalWrite(s2, LOW);
   digitalWrite(s3, LOW);
   countRed = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   digitalWrite(s3, HIGH);
   countBlue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
   digitalWrite(s2, HIGH);
   countGreen = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
  






  if(Serial.available()>0){   // si el puerto seriale sta disponible y tiene una variable de entrada 
    guardado=Serial.read(); // sera almacenado todo lo que se lea en el puerto serial en la variable guardado



   if(guardado=='A'){ // este para que el carro gire a la derecha
    direccion.write(grado de giro derecha);
  }if(guardado=='B'){ // giro a la izquierda                                    // no es necesario usar un for en esta ya que se complica mas todo y es mejor que el servo use un giro
    direccion.write(grado de giro izquierda);                                   // fuerte para poder establecer la direccion
  }if(guardado=='C'){// en este la direccion estara apuntando hacia el frente
    direccion.write(grado de direccion centrada);    
  }




                          // PARA LA PRIMER PARTE DE LA GARRA SERVO DE 11 KG
 
                            // con la letra D va a 90 grados
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
  }                       // ESTAS TRES PRIMERAS PARTES SEPARADAS SON PARA UN SOLO SERVOMOTOR CON SUS 9 POSIBILIDADES DE COMBINACIONES TENIENDO EN CUENTA QUE SI SE QUIEREN HACER 4 O 5 O N PUNTOS DE MOVIMIENTO SE TIENEN QUE HACER MUCHAS MAS CONDICIONALES.
                          // POR LO CUAL ESTAS TRES PARTES NOS SIRVEN PARA LOS OTROS SERVOS CAMBIANDO NADA MAS LAS LETRAS DE LLEGADA Y EL TIPO DE VARIABLE PARA EL FOR. EN ESTE CASO LA VARIABLE DE CADA FOR ESTA EN LAS INCIIALES DECLARADAS
                          // DE AQUI HACIA ABAJO NO ESPECIFICO NADA DE LAS PARTES YA QUE ES LO MISMO DE ESTAS TRES PRIMERAS SOLO QUE CON OTRO SERVOMOTOR




if(guardado=='G' && d==0){          // PARA LA SEGUNDA PARTE DE LA GARRA EL SEGUNDO SERVO FUTABA
   for(d=0;d<=90;d+5){              // hay que revisar que no se me haya olvidado cambiar una variable como una c por d o en otros casos o que no le haya cambiado el nombre al servo
   d=d+5;                
   segunda.write(d);     
   delay(200);          
   } 
   guardado='0';    
   d=90;            
  }if(guardado=='G' && d==90){
    guardado='0';    
    d=90;
  }if(guardado=='G' && d==180){
   for(d=180;d>=90;d-5){
    d=d-5;            
    segunda.write(d);
    delay(200);
   }
   guardado='0';
   d=90;
  }


 
  if(guardado=='H' && d==0){   
   guardado='0';    
   d=0;             
  }if(guardado=='H' && d==90){  
    for(d=90;d>=0;d-5){
      d=d-5;
      segunda.write(d);
      delay(200);
    }
    guardado='0';         
    d=0;
  }if(guardado=='H' && d==180){
   for(d=180;d>=0;d-5){
    d=d-5;                 
    segunda.write(d);
    delay(200);
   }
   guardado='0';
   d=0;
  }



  if(guardado=='I' && d==0){    
   for(d=0;d<=180;d+5){
    d=d+5;
    segunda.write(d);
    delay(200);
   }
   guardado='0';    
   d=180;             
  }if(guardado=='I' && d==90){  
    for(d=90;d<=180;d+5){
      d=d+5;
      segunda.write(d);
      delay(200);
    }
    guardado='0';         
    d=180;
  }if(guardado=='I' && d==180){
   guardado='0';
   d=0;
  }





 if(guardado=='J' && e==0){          // PARA LA GARRA, se puede dejar en abrir y cerrar sin tres opciones pero se pued edejar asi para objetos grandes y pequeños
   for(e=0;e<=90;e+5){              // hay que revisar que no se me haya olvidado cambiar una variable como una c por d o en otros casos o que no le haya cambiado el nombre al servo
   e=e+5;                
   garra.write(e);     
   delay(200);          
   } 
   guardado='0';    
   e=90;            
  }if(guardado=='J' && e==90){
    guardado='0';    
    e=90;
  }if(guardado=='J' && e==180){
   for(e=180;e>=90;e-5){
    e=e-5;            
    garra.write(e);
    delay(200);
   }
   guardado='0';
   e=90;
  }


 
  if(guardado=='K' && e==0){   
   guardado='0';    
   e=0;             
  }if(guardado=='K' && e==90){  
    for(e=90;e>=0;e-5){
      e=e-5;
      garra.write(e);
      delay(200);
    }
    guardado='0';         
    e=0;
  }if(guardado=='K' && e==180){
   for(e=180;e>=0;e-5){
    e=e-5;                 
    garra.write(e);
    delay(200);
   }
   guardado='0';
   e=0;
  }



  if(guardado=='L' && e==0){    
   for(e=0;e<=180;e+5){
    e=e+5;
    garra.write(e);
    delay(200);
   }
   guardado='0';    
   e=180;             
  }if(guardado=='L' && e==90){  
    for(e=90;e<=180;e+5){
      e=e+5;
      garra.write(e);
      delay(200);
    }
    guardado='0';         
    e=180;
  }if(guardado=='L' && e==180){
   guardado='0';
   e=0;
  }




 if(guardado=='M' && b==0){    //  GIRO DE LA GARRA
   girogarra.write(0); // gira hacia un direccion en este caso el tiempo tiene que ser calculado con la garra montada para saber cuanto tarda en girar y ese tiempo se pone en el delay
   delay(tiempo de giro); // giro a 0 grados 
 }
 guardado='0';    
   b=180;             
  if(guardado=='M' && b==180){  
    }
    guardado='0';         
    b=0;            // si el giro no se da bien hay que cambiar estos valores de 0 por 180
  }



  if(guardado=='O' && b==0){    
    girogarra.write(180);
    delay(tiempo de giro en la otra direccion);
   }
   guardado='0';    
   b=180;             
  }if(guardado=='O' && b==180){  
    }
    guardado='0';         
    b=0;



if(guardado=='P'){  // boton extra para parar el giro de la garra en caso de un error
  girogarra.write(90); 
guardado='0';
}guardado='0';


if(guardado=='Q'){  //CARRO HACIA ADELANTE       // TODAS ESTAS OPCIONES SON PARA LA DIRECCION DEL CARRO EN TODAS LAS DIRECCIONES POSIBLES, TIENEN QUE PONER LOS GRADOS DE MOVIMIENTO DE LA DIRECCION
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  direccion.write(grado centrado);
}
if(guardado=='R'){  //va a la derecha
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  direccion.write(grado derecha);
}
if(guardado=='S'){  //va a la izquierda
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  direccion.write(grado izquierda);
} 
if(guardado=='T'){  //va HACIA ATRAS
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  direccion.write(GRADO CENTRADO);
}if(guardado=='U'){  //va HACIA ATRAS A LA DERECHA
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  direccion.write(GRADO IZQUIERDA);
}if(guardado=='V'){  //va HACIA ATRAS A LA IZQUIERDA
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  direccion.write(GRADO DERECHA);
}if(guardado=='W'){ //STOP en este caso el carro solo se detiene y se mantiene la direccion son muchos los botones de la aplicacion hayq ue agregar un boton para parar y establecer que el carro va hacia adelante pero parado. solo para si alguien quiere que el se detenga y luego de parar vaya en la direccion centrada
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}if(guardado=='W'){ // ENTONCES ESTA ES PARA PARAR Y QUE EL CARRO APUNTE HACIA ADELANTE
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  direccion.write(grado centrado);
}








 // si esta es la programacion para agarrar y separar en automatico por ahora no vamos a agregar los interruptores, lo que haremos es busca en internet el duro proe garcia y buscamos la programacion para un carro en automatico con sensor de distancia y la aplicamos a los que ya tenemos

                      // la funcion en automatico de la garra se hace en un paso a paso movimiendo los grados de forma que se haga algo en secuencia, primero tiene que estar el servo 360 mirando hacia el frente 
                                         // la condicion hace que se ejecute todo el proceso de agarrado del objeto si detecta algo a 5 cm, hay que trabajar con los valores a prueba y error, y se puede cambiar la distancia, en este caso son dos sensores de distancia. osea que todo lo de abajo hay que copiarlo y pegarlo, yo les dejare declarados los dos sensores de distancia y sus calculos  ustedes solo tienen que agregar otra condicion y cambiar el proceso de seleccion y agarrado del objeto
       if(ultrasonic.Ranging(CM)=='5'){  // osea tiene que ser una distancia en la que la garra pueda alcanzar el objeto en este caso la pelota
       motor1.run(RELEASE);
       motor2.run(RELEASE);   //LOS MOTORES PARAN PARA PODER OBTENER EL OBJETO CON LOS SERVOS
       girogarra.write(frente);
       delay(tiempo de espera);
       girogarra.write(90); // detiene el giro de la garra
       for(f=90;f<=110;f+5){  // movimiento del primer servo hasta 110 grados osea inclinado sobre la parte del frente
       f=f+5; 
       primera.write(f);
       delay(200);
       }
       for(g=90;g<=110;g+5){ // segundo servo baja la garra hasta casi el suelo, los grados se pueden modificar y pueden probar esta parte en otro codigo para la realizacion de prueba y luego si ponerla aqui
       g=g+5;
       segunda.write(g);
       delay(200);
       }
       for(h=90;h<=100;h+5){ // abrir y cerrar garra, esta aparte puede estar mal segun como este puesto el servo, asi que pueden cambiar los datos por unos mayores o menos o incluso el for no puede estar sumanos sino restando
       h=h+5;
       garra.write(h);
       delay(200);
       }
       for(g=110;g>=90;g-5){ //subir segunda garra al grado inicial, puede cambiar el valor del grado
       g=g-5;
       segunda.write(g);
       delay(200);
       }
       for(f=110;f>=90;f-5){// primer servo de 11kg sube  lo que recogio
       f=f-5;
       primera.write(f);
       delay(200);
       }
       girogarra.write(atras);
       delay(tiempo de espera);
       girogarra.write(90); // detiene la garra estando atras
       if (countRed < countBlue && countGreen > 100 && countRed < 80){ /// esta condicional hay que cambiarla por la funciones del sensor de color // corrijo ya  no hay que cambiarla se supone que detecta el rojo y el azul
       separador.write(grado de giro hacia un lado);
       }else if (countBlue < countRed && countBlue < countGreen){   // esto es para separar entre dos colores
       separador.write(grado de giro hacua otro lado);
       }
       for(h=100;h>=90;h-5){ // abre la garra para soltar el objeto en el separador
       h=h-5;
       garra.write(h);
       delay(200);
       }
       }// fin de la condicion de distancia
       else{ // si no se detecta algo a una distancia n se tiene que seguir moviendo el carro en modo automatico con la programacion que desconozco 
       
}



// hay que revisar que los corchetes estan completos o si faltan o si estan mal., creo que faltan
// suerte muchachas, perdon por todo.

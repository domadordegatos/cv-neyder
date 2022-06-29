int xat=37;  //atrás 
int xad=35;  //adelnate
int yad=31;  //derecha
int yat=33;  //izquieda
int letra=0;
int posx='1'; int posy='1';
void setup() {
 Serial.begin(9600);
pinMode(37,OUTPUT);
pinMode(35,OUTPUT);
pinMode(31,OUTPUT);
pinMode(33,OUTPUT);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);
Serial.println("digite letra: ");
}

void loop() {
if(Serial.available()>0){
  letra=Serial.read();

if(letra=='1' && posx=='1' && posy=='1'){     // esto en 1 y quiero ir a 1
Serial.println("ya estoy en esta posicion");
posx='1';
posy='1';
}
if(letra=='2' && posx=='1' && posy=='1'){ 
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 2
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='1';
}
if(letra=='3' && posx=='1' && posy=='1'){ 
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 3
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='1';
}
if(letra=='4' && posx=='1' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 4
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='2';
}
if(letra=='5' && posx=='1' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 5
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 5
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='2';
}
if(letra=='6' && posx=='1' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 6
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 6
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='2';
}
if(letra=='7' && posx=='1' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 7
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='3';
}
if(letra=='8' && posx=='1' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 8
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 8
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='3';
}
if(letra=='9' && posx=='1' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 9
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                          // estoy en 1 y quiero ir a la 9
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 1 ///////////////////////////////////////////////////////////////////
if(letra=='1' && posx=='2' && posy=='1'){     
digitalWrite(31,LOW);
digitalWrite(33,HIGH);
digitalWrite(35,LOW);
digitalWrite(37,LOW);   // ESTOY EN LA POSICION 2 VOY A LA 1
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);
posx='1';
posy='1';
}
if(letra=='2' && posx=='2' && posy=='1'){ 
Serial.println("estoy en esa posicion");


posx='2';
posy='1';
}
if(letra=='3' && posx=='2' && posy=='1'){ 

digitalWrite(31,HIGH);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);  // EN LA POSICION 2 VOY A 3
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='1';
}
if(letra=='4' && posx=='2' && posy=='1'){ 

digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOY EN 2 VOY A 4
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(1100);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='2';
}
if(letra=='5' && posx=='2' && posy=='1'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='2';
}
if(letra=='6' && posx=='2' && posy=='1'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(1100);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);  // ESTOT EN 2 VOY A 6
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='2';
}
if(letra=='7' && posx=='2' && posy=='1'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOT EN 2 VOY A 7
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='3';
}
if(letra=='8' && posx=='2' && posy=='1'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='3';
}
if(letra=='9' && posx=='2' && posy=='1'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);  // ESTOT EN 2 VOY A 9
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 2 ///////////////////////////////////////////////////////////////////
if(letra=='1' && posx=='3' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                          // estoy en 3 y quiero ir a la 1
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='1';
}
if(letra=='2' && posx=='3' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                          // estoy en 3 y quiero ir a la 2
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='1';
}
if(letra=='3' && posx=='3' && posy=='1'){ 
Serial.println("ya estoy en esta posicion");                         // estoy en 3 y quiero ir a la 3

posx='3';
posy='1';
}
if(letra=='4' && posx=='3' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                          // estoy en 3 y quiero ir a la 4
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 3 y quiero ir a la 4
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='2';
}
if(letra=='5' && posx=='3' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 3 y quiero ir a la 5
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 3 y quiero ir a la 5
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='2';
}
if(letra=='6' && posx=='3' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 3 y quiero ir a la 6
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='2';
}
if(letra=='7' && posx=='3' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 3 y quiero ir a la 7
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 3 y quiero ir a la 7
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='3';
}
if(letra=='8' && posx=='3' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 3 y quiero ir a la 8
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 3 y quiero ir a la 8
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='3';
}
if(letra=='9' && posx=='3' && posy=='1'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                          // estoy en 3 y quiero ir a la 9
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 3 ///////////////////////////////////////////////////////////////////
if(letra=='1' && posx=='1' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);  // ESTOT EN 4 VOY A 1
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='1';
}
if(letra=='2' && posx=='1' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);  // ESTOT EN 4 VOY A 2
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);  // 
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='1';
}
if(letra=='3' && posx=='1' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);  // ESTOT EN 4 VOY A 3
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);  // 
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='1';
}
if(letra=='4' && posx=='1' && posy=='2'){ 
Serial.println("estoy en esa posicion");   // ESTOY EN 4 VOY 4

posx='1';
posy='2';
}
if(letra=='5' && posx=='1' && posy=='2'){ 

digitalWrite(31,HIGH);
digitalWrite(33,LOW);  // ESTOT EN 4 VOY A 5
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='2';
}
if(letra=='6' && posx=='1' && posy=='2'){ 

digitalWrite(31,HIGH);
digitalWrite(33,LOW);  // ESTOT EN 4 VOY A 6
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='2';
}
if(letra=='7' && posx=='1' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);  // ESTOT EN 4 VOY A 7
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='3';
}
if(letra=='8' && posx=='1' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);  // ESTOT EN 4 VOY A 8
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='3';
}
if(letra=='9' && posx=='1' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);  // ESTOT EN 4 VOY A 9
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 4 ///////////////////////////////////////////////////////////////////
if(letra=='1' && posx=='2' && posy=='2'){ 
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                          // estoy en 5 y quiero ir a la 1
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 1
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='1';
}
if(letra=='2' && posx=='2' && posy=='2'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 2
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='1';
}
if(letra=='3' && posx=='2' && posy=='2'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 3
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 3
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='1';
}
if(letra=='4' && posx=='2' && posy=='2'){ 
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 5 y quiero ir a la 4
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='2';
}
if(letra=='5' && posx=='2' && posy=='2'){ 
Serial.println("ya estoy en esta posicion");  // estoy en 5 y quiero ir a 5

posx='2';
posy='2';
}
if(letra=='6' && posx=='2' && posy=='2'){ 
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 6
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='2';
}
if(letra=='7' && posx=='2' && posy=='2'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 7
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 5 y quiero ir a la 7
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='3';
}
if(letra=='8' && posx=='2' && posy=='2'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 8
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='3';
}
if(letra=='9' && posx=='2' && posy=='2'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 9
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 5 y quiero ir a la 9
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 5 ///////////////////////////////////////////////////////////////////
if(letra=='1' && posx=='3' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOT EN 6 A 1
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='1';
}
if(letra=='2' && posx=='3' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOT EN 6 A 2
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='1';
}
if(letra=='3' && posx=='3' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);  // ESTOT EN 6 A 3
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='1';
}
if(letra=='4' && posx=='3' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOT EN 6 A 4
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='2';
}
if(letra=='5' && posx=='3' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOT EN 6 A 5
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='2';
}
if(letra=='6' && posx=='3' && posy=='2'){ 
Serial.println("estoy en esa posicion");   // ESTOY EN 6VOY 6


posx='3';
posy='2';
}
if(letra=='7' && posx=='3' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOT EN 6 A 7
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);  
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='3';
}
if(letra=='8' && posx=='3' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOT EN 6 A 8
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);  
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='3';
}
if(letra=='9' && posx=='3' && posy=='2'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);  // ESTOT EN 6 A 9
digitalWrite(35,HIGH);
digitalWrite(37,LOW);
delay(11000);



digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 6 ///////////////////////////////////////////////////////////////////
if(letra=='1' && posx=='1' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 1
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='1';
}
if(letra=='2' && posx=='1' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 2
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 2
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='1';
}
if(letra=='3' && posx=='1' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 3
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 3
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='1';
}
if(letra=='4' && posx=='1' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 4
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='2';
}
if(letra=='5' && posx=='1' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 5
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 5
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='2';
}
if(letra=='6' && posx=='1' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 6
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 6
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='2';
}
if(letra=='7' && posx=='1' && posy=='3'){ 

Serial.println("ya estoy en esta posicion");     // estoy en 7 y quiero ir a la 7

posx='1';
posy='3';
}
if(letra=='8' && posx=='1' && posy=='3'){ 
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 8
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='3';
}
if(letra=='9' && posx=='1' && posy=='3'){ 
digitalWrite(31,HIGH);
digitalWrite(33,LOW);                           // estoy en 7 y quiero ir a la 9
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 7 ///////////////////////////////////////////////////////////////////
if(letra=='1' && posx=='2' && posy=='3'){ 

digitalWrite(31,LOW);
digitalWrite(33,HIGH);  // ESTOT EN 8 A 1
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);  
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);



digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='1';
}
if(letra=='2' && posx=='2' && posy=='3'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);    // ESTOY EN 8 VOY A 2
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);



digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='1';
}
if(letra=='3' && posx=='2' && posy=='3'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);    // ESTOY EN 8 VOY A 3
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);   
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='1';
}
if(letra=='4' && posx=='2' && posy=='3'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);    // ESTOY EN 8 VOY A 4
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);   
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);

digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='2';
}
if(letra=='5' && posx=='2' && posy=='3'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);    // ESTOY EN 8 VOY A 5
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);



digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='2';
}
if(letra=='6' && posx=='2' && posy=='3'){ 

digitalWrite(31,LOW);
digitalWrite(33,LOW);    // ESTOY EN 8 VOY A 6
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,HIGH);
digitalWrite(33,LOW);   
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='2';
}
if(letra=='7' && posx=='2' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,HIGH);   // ESTOY EN 8 VOY 7
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='3';
}
if(letra=='8' && posx=='2' && posy=='3'){ 
Serial.println("estoy en esa posicion");

posx='2';
posy='3';
}
if(letra=='9' && posx=='2' && posy=='3'){ 


digitalWrite(31,HIGH);
digitalWrite(33,LOW);   // ESTOY EN 8 VOY 9
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);


digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 8 ///////////////////////////////////////////////////////////////////
if(letra=='1' && posx=='3' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 9 y quiero ir a la 1
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 9 y quiero ir a la 1
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='1';
}
if(letra=='2' && posx=='3' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 9 y quiero ir a la 2
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 9 y quiero ir a la 2
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='1';
}
if(letra=='3' && posx=='3' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 9 y quiero ir a la 3
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(22000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='1';
}
if(letra=='4' && posx=='3' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 9 y quiero ir a la 4
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 9 y quiero ir a la 4
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='2';
}
if(letra=='5' && posx=='3' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 9 y quiero ir a la 5
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 9 y quiero ir a la 5
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='2';
}
if(letra=='6' && posx=='3' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,LOW);                           // estoy en 9 y quiero ir a la 6
digitalWrite(35,LOW);
digitalWrite(37,HIGH);
delay(11000);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='3';
posy='2';
}
if(letra=='7' && posx=='3' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 9 y quiero ir a la 7
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(2700);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='1';
posy='3';
}
if(letra=='8' && posx=='3' && posy=='3'){ 
digitalWrite(31,LOW);
digitalWrite(33,HIGH);                           // estoy en 9 y quiero ir a la 8
digitalWrite(35,LOW);
digitalWrite(37,LOW);
delay(1350);
digitalWrite(31,LOW);
digitalWrite(33,LOW);
digitalWrite(35,LOW);
digitalWrite(37,LOW);

posx='2';
posy='3';
}
if(letra=='9' && posx=='3' && posy=='3'){         //estoy en 9 y quiero ir a la 9
Serial.println("ya estoy en esta posicion");

posx='3';
posy='3';
}
//////////////////////////////////////////////////////////////////////////////////////////////final movimiento 9 ///////////////////////////////////////////////////////////////////
if (letra == 'A') {                          /// demostrativo, movimiento encima de cada una de las plantas sin regado, inicia en x1y1 y termine en x1y1
 digitalWrite(37,LOW);  // PASO A 2
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);
    digitalWrite(33,LOW);
    delay(1350);

    digitalWrite(37,LOW);   // PARO EN 2
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);   // PASO A 3
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);
    digitalWrite(33,LOW);
    delay(1350);

    digitalWrite(37,LOW);  // PARO EN  3
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);  // PASO A  6
    digitalWrite(35,HIGH);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(11000);

    digitalWrite(37,LOW);  // PARO EN  6
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);  // PASO A 5
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,HIGH);
    delay(1350);

    digitalWrite(37,LOW);  // PARO EN 5
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);  // PASO A  4
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,HIGH);
    delay(1350);

    digitalWrite(37,LOW);  // PARO EN 4
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);  // PASO A 7
    digitalWrite(35,HIGH);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(11000);

    digitalWrite(37,LOW);  // PARO EN 7
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);  // PASO A 8
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);
    digitalWrite(33,LOW);
    delay(1350);

    digitalWrite(37,LOW);  // PARO EN 8
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);  // PASO A 9
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);
    digitalWrite(33,LOW);
    delay(1350);

    digitalWrite(37,LOW);  // PARO EN 9
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);  // PASA DE 9 AL 7
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,HIGH);
    delay(2700);

    digitalWrite(37,LOW);  // PARO EN 7
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,HIGH);  // PASA DE 7 AL 1
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(22000);

    


    digitalWrite(31,LOW);  // FIN DE LA SECUENCIA 
    digitalWrite(33,LOW);
    digitalWrite(37,LOW);
    digitalWrite(35,LOW);
posx='1';
posy='1';
}
}
}


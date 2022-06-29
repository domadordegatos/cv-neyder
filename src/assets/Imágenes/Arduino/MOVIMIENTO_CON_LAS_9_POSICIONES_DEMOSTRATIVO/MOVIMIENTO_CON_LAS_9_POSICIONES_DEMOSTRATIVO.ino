void setup() {
  // put your setup code here, to run once:

}

void loop() {
   digitalWrite(37,LOW);  // PASO A 2
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);
    digitalWrite(33,LOW);
     delay(tiempox);
    digitalWrite(37,LOW);   // PARO EN 2
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000); 

    digitalWrite(37,LOW);   // PASO A 3
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);
    digitalWrite(33,LOW);
    delay(tiempox);
    digitalWrite(37,LOW);  // PARO EN  3
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,LOW);  // PASO A  6
    digitalWrite(35,HIGH);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(tiempoy);
    digitalWrite(37,LOW);  // PARO EN  6
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);


    
    digitalWrite(37,LOW);  // PASO A 5
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,HIGH);
    delay(tiempox);
    digitalWrite(37,LOW);  // PARO EN 5
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

   
    digitalWrite(37,LOW);  // PASO A  4
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,HIGH);
    delay(tiempox);
    digitalWrite(37,LOW);  // PARO EN 4
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);    


    
    digitalWrite(37,LOW);  // PASO A 7
    digitalWrite(35,HIGH);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(tiempoy);
    digitalWrite(37,LOW);  // PARO EN 7
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);



 
    digitalWrite(37,LOW);  // PASO A 8
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);
    digitalWrite(33,LOW);
    delay(tiempox);
    digitalWrite(37,LOW);  // PARO EN 8
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

        
    digitalWrite(37,LOW);  // PASO A 9
    digitalWrite(35,LOW);
    digitalWrite(31,HIGH);
    digitalWrite(33,LOW);
    delay(tiempox);
    digitalWrite(37,LOW);  // PARO EN 9
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);
 
    
    digitalWrite(37,LOW);  // PASA DE 9 AL 7
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,HIGH);
    delay(tiempoxx);

    digitalWrite(37,LOW);  // PARO EN 7
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(2000);

    digitalWrite(37,HIGH);  // PASA DE 7 AL 1
    digitalWrite(35,LOW);
    digitalWrite(31,LOW);
    digitalWrite(33,LOW);
    delay(tiempoyy);

    digitalWrite(31,LOW);  // FIN DE LA SECUENCIA 
    digitalWrite(33,LOW);
    digitalWrite(37,LOW);
    digitalWrite(35,LOW);

}

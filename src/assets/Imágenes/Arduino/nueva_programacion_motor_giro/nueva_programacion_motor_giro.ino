int led2=2; // Habitación 1.
int led3=3; // Habitación 2.
int led4=4; // Habitación 3.
int led6=6; // Baño.
int led7=7; // Sala.
int led8=8; // Ventilador.
int led9=9; // Pasillo.
int led10=10; // Cocina.
int led11=11; // Garaje.
int led12=12; // Ático. 
int velocidad = map(255);
int estado=0;

void setup(){
  Serial.begin(9600);
}

void loop(){
 if(Serial.available()>0){
  
 }
 if (estado =='1'){
   digitalWrite(led2,LOW);
  }
if(estado=='2'){
   digitalWrite(led2,HIGH);
  }

 if (estado =='3'){
   digitalWrite(led3,LOW);
  }
if(estado=='4'){
   digitalWrite(led3,HIGH);
  }

 if (estado =='5'){
   digitalWrite(led4,LOW);
  }
if(estado=='6'){
   digitalWrite(led4,HIGH);
  }

 if (estado =='9'){
   digitalWrite(led6,HIGH);
  }
if(estado=='G'){
   digitalWrite(led6,LOW);
  }

 if (estado =='A'){
   digitalWrite(led7,HIGH);
  }
if(estado=='B'){
   digitalWrite(led7,LOW);
  }

 if (estado =='C'){
   digitalWrite(led8,LOW);
  }
if(estado=='D'){
   digitalWrite(motor,velocidad);
   digitalWrite(led8,HIGH);
  }

 if (estado =='E'){
   digitalWrite(led9,HIGH);
  }
if(estado=='F'){
   digitalWrite(led9,LOW);
  }

 if (estado =='H'){
   digitalWrite(led10,LOW);
  }
if(estado=='I'){
   digitalWrite(led10,HIGH);
  }

 if (estado =='J'){
   digitalWrite(led11,LOW);
  }
if(estado=='K'){
   digitalWrite(led11,HIGH);
  }

 if (estado =='L'){
   digitalWrite(led12,HIGH);
  }  
if(estado=='M'){
   digitalWrite(led12,LOW);
  }


}  



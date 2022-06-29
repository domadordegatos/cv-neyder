const int s0 = A1;  
const int s1 = A2;  
const int s2 = A3;  
const int s3 = A4;  
const int out = 4;    
int rojo = 0;  
int verde = 0;  
int azul = 0;  

void setup(){  
  Serial.begin(9600); 
  pinMode(A1,OUTPUT);  
  pinMode(A2,OUTPUT);  
  pinMode(A3,OUTPUT);  
  pinMode(A4,OUTPUT);  
  pinMode(out,INPUT);   
  digitalWrite(s0,HIGH);  
  digitalWrite(s1,HIGH);  
}  

   
void loop(){  
  color(); 
  Serial.print("   ");  
  Serial.print(rojo, DEC);  
  Serial.print("   ");  
  Serial.print(verde, DEC);  
  Serial.print("   ");  
  Serial.print(azul, DEC);  

  if (rojo <= 23 && rojo >= 22 && verde >= 15 && verde <= 16 && azul <= 5 && azul >= 4) {  
   Serial.println("   Rojo");    
  }   
  else if (azul < rojo && azul < verde && verde < rojo)  
  {  
   Serial.println("   Azul");        
  }  

  else if (rojo > verde && azul > verde )  
  {  
   Serial.println("   Verde");       
  }  
  else{
  Serial.println("  ");  
  }
  delay(900);     
  }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);   
  rojo = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);   
  azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);    
  verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}


int izqA = 5; 
int izqB = 6; 
int derA = 9; 
int derB = 10;   

int vel = 255; //velocidad de rodaje
    


void setup()  { 
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  
 } 
 
void loop()  { 
 
      analogWrite(derB, 0);     
      analogWrite(izqB, 0); 
      analogWrite(derA, vel);  
      analogWrite(izqA, vel);
         
   }


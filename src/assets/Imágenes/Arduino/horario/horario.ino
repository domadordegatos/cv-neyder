#include <Time.h>

void setup(){
  Serial.begin(115200);
      setTime(00,00,00,1,1,2018); // Las 19:58:00 del dia 6 de Nov de 2014
  }
void loop(){ 
  time_t t = now();

      Serial.print(day(t));
      Serial.print(+ "/") ;
      Serial.print(month(t));
      Serial.print(+ "/") ;
      Serial.print(year(t)); 
      Serial.print( " ") ;
      Serial.print(hour(t));  
      Serial.print(+ ":") ;
      Serial.print(minute(t));
      Serial.print(":") ;
      Serial.println(second(t));
      delay(1000);
  }

int vel1 = 255;              //variable para maxima velocidad
int vel2 = 0;                //variable para velocidad 0 apagado
int m1 = 9;                  //pin pwm para motor
void setup() {
pinMode(m1, OUTPUT);         //tipo de elemento a usar "de salida"
}
void loop() {
 analogWrite(m1, vel1);      //motor enciende segun la velocidad establecida 
}



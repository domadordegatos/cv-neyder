#include <Keypad.h>
String clave= "000";
char inicia_clave= '#';
String claves_validas []= {"426", "010","766"};
const byte Filas = 4;
const byte Colum = 4;
char teclas [Filas][Colum]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinFilas [Filas]= (9,8,7,6);
byte pinColum [Colum]= (5,4,3,2,);
Keypad Teclado= Keypad( makeKeymap (teclas), pinFilas, pinColum, Filas, Colum);



void setup() {
Serial.begin (9600);
Serial.println  ("Empezamos"); 


}

void loop() {
int n=0;
char tecla= Teclado.getKey ();
if (tecla != 0){

  if (inicia_clave== tecla){
while (n<3){
  clave[n]=Teclado.waitForKey();
  n=n+1;

}
Serial.println(clave);
for (int i=0; i <=2;i++){
  if (clave==claves_validas[i])Serial.println("Esta clave es valida");
}
}
}
}


}

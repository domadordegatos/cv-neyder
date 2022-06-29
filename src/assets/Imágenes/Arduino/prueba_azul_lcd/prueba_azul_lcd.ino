  #include <Wire.h> // Librería comunicación I2C
  #include <LiquidCrystal_I2C.h> // Librería LCD I2C
  LiquidCrystal_I2C lcd(0x3f,16,2);
 
  void setup()
  {
    Serial.begin(9600);  // Configura la velocidad de la comunicación serie
    lcd.begin(16,2);   // Inicializa el LCD para 16x2
   
 
  // Realiza 3 parpadeos del LED (backlight)
    for(int i = 0; i< 3; i++)
    {
      lcd.backlight();
      delay(250);
      lcd.noBacklight();
      delay(250);
    }
   lcd.backlight(); // Finaliza con el LED encendido (backlight)
 
  // Escribe el texto en el LCD
  // NOTA: La posición del cursor del LCD (Carácter, línea) comienza en (0,0)
    lcd.setCursor(0,0);
    lcd.write("Hola, Usuario!"); // Podemos poner tanto write como print
    delay(1000);
    lcd.setCursor(0,1);
    lcd.write("Bienvenido");
    delay(2000);  
 
  // Espera a que se conecte el monitor serie y envía los caracteres al LCD
  // Configurar el monitor serie en el modo "Sin final de línea"
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Monitor serie...");
    lcd.setCursor(0,1);
    lcd.print(">Pulsa una tecla");
  }
 
 
  void loop()
  {
      char ch;
      // Si se recibe un carácter por el puerto serie...
      if (Serial.available())
      {
        // Retardo para que pueda recibir el caracter
        delay(100);
        // Borra la pantalla
        lcd.clear();    
        lcd.print("Recibiendo>>> ");
        lcd.setCursor(14,0);
         
        // Si lo recibido es mayor que 0...
        while (Serial.available() > 0)
        {
          // Lee el carácter que llega
          ch = Serial.read();
          // Muestra el carácter a través del LCD
          lcd.write(ch);
          // Muestra por terminal virtual el carácter enviado al LCD
          Serial.write(ch);
        }
      }
  }

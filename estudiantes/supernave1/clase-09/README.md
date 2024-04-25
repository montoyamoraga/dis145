# clase-09

## Codigo inicial
Con este código buscamos hacer que el servomotor se mueva en un rango de 180 grados, rango el cual permite tener a un máximo de 3 jugadores, ya que en un futuro va a hacer paradas en el rango, bajo un mínimo de 60 grados de recorrido.
￼

#include <Servo.h> // Incluye la biblioteca del Servo en el codigo
int pos = 0; // Damos posicion inicial del servo

Servo servo; // Nombramos sero al servomotor

int pausa = 100; //

void setup()
{
  Serial.begin(9600);
  servo.attach(9, 500, 2500); // servo en el pin digital 9, 500 y 2500 son el ancho
}

void loop()
{
  
  for (pos = 0; pos <= 180; pos += 1) { // hace que el servo se mueva desde la posición 0 grados hasta 180 grados
    
    servo.write(pos);
   
    delay(pausa);
    Serial.print("subiendo: ");
    Serial.println(pos);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // hace que vuelva de 180 a 0, ya que cada uno vez iba sumando uno
    servo.write(pos);
    delay(pausa);
    Serial.print("bajando: ");// hace que vuelva de 180 a 0
    Serial.println(pos);
  }
}




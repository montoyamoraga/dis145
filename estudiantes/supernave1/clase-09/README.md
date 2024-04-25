# clase-09

## Codigo inicial
Con este código buscamos hacer que el servomotor se mueva en un rango de 180 grados, rango el cual permite tener a un máximo de 3 jugadores, ya que en un futuro va a hacer paradas en el rango, bajo un mínimo de 60 grados de recorrido.
￼

#include <Servo.h> // Incluye la biblioteca del Servo en el código

int pos = 0; // Damos posición inicial del servo
Servo servo; // Nombramos servo al servomotor
int pausa = 100; // Duración de pausa en milisegundos

void setup()
{
  Serial.begin(9600);
  servo.attach(9, 500, 2500); // Servo en el pin digital 9, 500 y 2500 son los límites de ancho de pulso
}

void loop()
{
  for (pos = 0; pos <= 180; pos += 1) { // Hace que el servo se mueva desde la posición 0 grados hasta 180 grados
    servo.write(pos);
    delay(pausa);
    Serial.print("Subiendo: ");
    Serial.println(pos);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // Hace que vuelva de 180 a 0 grados
    servo.write(pos);
    delay(pausa);
    Serial.print("Bajando: ");
    Serial.println(pos);
  }
}




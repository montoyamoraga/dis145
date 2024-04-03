// 2024-04-02
// psegunda sesión DIS
// queremos un código en el que se pueda emular un mouse con Arduino UNO
// por thiagv, Sr.Yuyo, MarcialLeaplaza
// hecho con: Arduino UNO R3

#include <Mouse.h>

// Definición de pines para potenciómetros y botones
const int pinPotX = A0;
const int pinPotY = A1;
const int pinBotonIzquierdo = 2;
const int pinBotonDerecho = 3;
const int pinBotonInicio = 4;

bool controlRatonActivado = false; // Variable para indicar si el control del ratón está activado o no
// Es importante tenerlo porque se puede perder el control del puntero en el computador

void setup() {
  pinMode(pinPotX, INPUT);
  pinMode(pinPotY, INPUT);
  pinMode(pinBotonIzquierdo, INPUT_PULLUP);
  pinMode(pinBotonDerecho, INPUT_PULLUP);
  pinMode(pinBotonInicio, INPUT_PULLUP);
  Mouse.begin(); // Inicialización del control del ratón
}

void loop() {
  // Verificar si se ha presionado el botón de inicio
  if (digitalRead(pinBotonInicio) == LOW) {
    controlRatonActivado = true; // Activar el control del ratón
    while(digitalRead(pinBotonInicio) == LOW); // Esperar hasta que se suelte el botón de inicio
  }

  // Si el control del ratón está activado
  if (controlRatonActivado) {
    // Leer los valores de los potenciómetros y mapearlos al rango de movimiento del ratón
    int valorX = map(analogRead(pinPotX), 0, 1023, -10, 10);// Rangos respecto al potenciometro
    int valorY = map(analogRead(pinPotY), 0, 1023, -10, 10);
    // Mover el cursor del ratón
    Mouse.move(valorX, valorY);

    // Verificar si se ha presionado el botón izquierdo del ratón
    if (digitalRead(pinBotonIzquierdo) == LOW) {
      Mouse.press(MOUSE_LEFT); // Simular clic izquierdo del ratón
      delay(100); // Pequeño retraso para evitar clics múltiples
      Mouse.release(MOUSE_LEFT); // Liberar el clic izquierdo del ratón
    }

    // Verificar si se ha presionado el botón derecho del ratón
    if (digitalRead(pinBotonDerecho) == LOW) {
      Mouse.press(MOUSE_RIGHT); // Simular clic derecho del ratón
      delay(100); // Pequeño retraso para evitar clics múltiples
      Mouse.release(MOUSE_RIGHT); // Liberar el clic derecho del ratón
    }
  }

  delay(10); // Pequeño retraso entre cada iteración del bucle para evitar rebotes
}

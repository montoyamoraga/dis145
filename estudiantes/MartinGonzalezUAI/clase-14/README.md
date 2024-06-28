```cpp

//Codigo creado por Martin Gonzalez Marin
//24/06/2024
//Codigo que activa un motor paso a paso en función de un potenciómetro

//Agregamos libreria del motor paso a paso 
#include <Stepper.h>
 
//Definimos número de pasos por una revolución  completa
const int pasoRev = 200;

//Asignamos pin de control de velocidad con potenciómetro
const int pinControlVel = A0;

//Decretamos número de pasos por revolución y conectamos controlador de motor al arduino
Stepper motor(pasoRev, 1, 2, 3, 4);
 
void setup() {
}
 
void loop() {

  //Leemos la velocidad del potenciómetro
  int valVel = analogRead(pinControlVel);
  
  //Modificamos el rango de valores
  int velMotor = map(valVel, 0, 1023, 0, 100);
  
  //Establecemos velocidad del motor
  if (velMotor > 0) {
    motor.setSpeed(velMotor);
    
    // Hacemos que el motor avance en función a los pasos
    motor.step(pasoRev / 100);
  }
}

```

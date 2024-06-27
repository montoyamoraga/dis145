```cpp

//Codigo creado por Martin Gonzalez Marin
//24/06/2024
//Codigo que activa un motor paso a paso en función de un potenciómetro

//Agregamos libreria del motor paso a paso 
#include <Stepper.h>
 
//Definimos número de pasos por rotación
const int pasoRev = 200;

//Asignamos pin de control de velocidad
const int pinControlVel = A0;

//Definimos motor y conectamos controlador de motor
Stepper motor(pasoRev, 1, 2, 3, 4);
 
void setup() {
}
 
void loop() {

  //Leemos la velocidad
  int valVel = analogRead(pinControlVel);
  
  //Modificamos el rango de valores
  int velMotor = map(valVel, 0, 1023, 0, 100);
  
  //Configuramos velocidad del motor
  if (velMotor > 0) {
    motor.setSpeed(velMotor);
    
    // Hacemos el paso a revolución
    motor.step(pasoRev / 100);
  }
}

```

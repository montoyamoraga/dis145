# clase-11

Simulación Código definitivo LDR & ServoMotor

https://github.com/josefinasanchezr/dis145/assets/164403301/dacb009c-9ac1-4289-b083-5e8045f943be

```cpp
// 2024-27-06
// Código que activa movimiento de motor servo con el valor del sensor de luz LDR
// por josefinasanchezr
// hecho con Arduino IDE 1.8.19
// para Arduino UNO R3

// Incluye la librería Servo.h para controlar el servo motor
#include <Servo.h>  

// Declaración de constantes y variables

// Pin analógico al que está conectado el LDR
const int ldrPin = A0; 
// Pin digital al que está conectado el servo
const int servoPin = 9; 
// Umbral de luz para activar el servo 
const int umbralLuz = 950; 

// Crea un objeto de tipo Servo
Servo miServo; 


void setup() {

// Inicia la comunicación serial a 9600 bps
  Serial.begin(9600); 
// Adjunta el servo al pin especificado
  miServo.attach(servoPin); 
// Inicializa el servo en la posición 0 grados
  miServo.write(0); 
}

void loop() {
// Lee el valor del LDR (0 a 1023), cuando se cumple el valor luzActiva(500) se mueve el motor
  int nivelLuz = analogRead(ldrPin); 
  Serial.print("Nivel Luz: ");
// Imprime el nivel de luz leído
  Serial.println(nivelLuz); 

// Si el nivel de luz supera el umbral (luzActiva(500))
  if (nivelLuz > umbralLuz) { 
// Gira el servo a 180 grados
    miServo.write(180); 
  } else {
// Vuelve el servo a la posición 0 grados
    miServo.write(0); 
  }

// Espera 100 ms antes de la siguiente lectura
  delay(100); 
}

```

Los valores del LDR son: 
 0 = oscuridad
 1023 = máxima luz

El umbral de luz dentro de la sala es entre 0 y 900 aproximadamente
El umbral de luz cuando la linterna esta a menos de 5 cm del sensor es entre 950 y 1023




Simulación Física con código y prueba de nmeros para el umbral

https://github.com/josefinasanchezr/dis145/assets/164403301/3eb8ba45-73b0-41d7-930f-3d6d600e15ce


Cambio en el codigo para que el ServoMotor se mueva en 180 grados y la compuerta funcione...

Simulacion Prototipo Compuerta en 180 grados

https://github.com/josefinasanchezr/dis145/assets/164403301/e05ee1bf-31f7-47ba-9394-df2ed1c4f59e




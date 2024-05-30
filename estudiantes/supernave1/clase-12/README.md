# clase-12

## Prototipo rueda lanzadora de cartas

Le puse una tapa con un elastico para que tenga agarre y pueda lanzar las cartas. Con un hoyo y pegamento la unimos al motor, quedo algo así:

![IMG_1499 Chico](https://github.com/supernave1/dis145/assets/164402810/2bcca39e-af14-49d9-ae7d-57e9a87123f2)

Luego, conecte todo al circuito, y la puse a prueba:


https://github.com/supernave1/dis145/assets/164402810/e55057ca-04f3-4fb3-8391-80530da9ceb6

No muy contento con el resultado, pensaba que las cartas saldrian disparadas facilmente, vamos a hacer mas pruebas.

Descubri que hay que poner la rueda al final de las cartas ya que ahi tiene mas recorrido para lanzar de mejor manera y mas separada.


https://github.com/supernave1/dis145/assets/164402810/673ca700-f6fd-4b16-8a62-37fd355ce254



Feliz con el resultado :), se logro que vaya tirando cartas ahora hay que lograr hacer que lanze una carta solamente, se me ocurre bajar la potencia de giro, o hacer que gire en intervalos de tiempo cortos. Pero eso lo vamos a dejar para despues, ya que voy a trabajar en la base del proyecto, la cual se va a encargar de girar las cartas para que las lanze en distintas direcciones.

## Rotacion de las cartas
Con un servo motor S3003, buscaremos hacer que la base gire una cierta cantidad de grados, frene, espere un tiempo, y gire la misma cantidad de grados, para despues repetir el proceso. 

Buscando en internet, logre girar el servo en 180 grados repetidamente, lo que me alegra mucho. Para esto se necesita:
* Servo motor
* Condensador 100 µF
* Cables
* Arduino


https://github.com/supernave1/dis145/assets/164402810/b8dd882b-6131-4f90-95c8-8aabced60d90

Aca va el codigo el cual permite hacer esto:

```cpp
#include <Servo.h>

Servo myservo;  // Darle nombre al Servo

int pos = 0;    // Variable para darle posición inicial al Servo

void setup() {
  myservo.attach(9);  // Ataja el servo al Pin 9
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // Va de 0 a 180 grados
    // in steps of 1 degree
    myservo.write(pos);              // le dice al servo que vaya a posicion 'pos'
    delay(15);                       // espera 15ms para alcanzar la posicion
  }
  for (pos = 180; pos >= 0; pos -= 1) { // va de 180 a 0 grados
    myservo.write(pos);              // le dice al servo que vaya a posicion 'pos'
    delay(15);                       // espera 15ms para alcanzar la posicion
  }
}
```

Haciendole un par  de variaciones al código, logre hacer que haga el mismo recorrido de 180 grados, solo que ahora hace paradas cada 60 grados con duracion de dos segundos, tiempo suficiente para que la rueda lanze una carta (cuando logre hacer que lanze solamente una carta, voy a hacer que las paradas del servo sean lo mas cortas posibles). 

Aca hay un video del servo con sus paradas. 

https://github.com/supernave1/dis145/assets/164402810/3d0fd952-331d-40c0-bb56-e5e51f1f9174

Aca va el codigo el cual permite hacer esto:

```cpp
#include <Servo.h>

Servo myservo;  // Darle nombre al Servo

int pos = 0;    // Variable para darle posición inicial al Servo

void setup() {
  myservo.attach(9);  // Ataja el servo al Pin 9
}

void loop() {
  // Mover de 0 a 180 grados parando dos segundos cada 60 grados
  for (pos = 0; pos <= 180; pos += 60) {
    myservo.write(pos);  // mueve el servo a la posición 'pos'
    delay(2000);         // espera 2 segundos
  }

  // Volver directamente de 180 a 0 grados
  myservo.write(0);  // mueve el servo a la posición 0 grados
     // espera 2 segundos
}
```

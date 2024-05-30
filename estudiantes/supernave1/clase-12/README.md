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




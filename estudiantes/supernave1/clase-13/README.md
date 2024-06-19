# clase-13

## Avances para esta clase

Esta clase vamos a modelar todo el sistema del Card Dealer, ya que es fundamental para poder hacer pruebas concisas del funcionamiento.

El sistema tiene que cumplir con: 
* La base tiene que ser capaz de girar con las cartas encima.
* La rueda tiene que quedar apoyada sobre las cartas.
* La rueda tiene que estar en el extremo superior mas cercano a la dirección que se lanzan las cartas.
* La rueda tiene que ser movible para poder volver a colocar las cartas.
* Cuando la rueda gire sea capaz por cuenta propia de lanzar las cartas una a una.

Vuelvo a subir foto de la logica del sistema.

![331406187-7a6b98bc-db20-439e-9126-46a245a368c0](https://github.com/supernave1/dis145/assets/164402810/2f3eb232-d28b-4310-a2ef-143a7e10ed2d)

## Modelo 3d

Primero modele la base para las cartas, con un extremo sin cara por el cual saldran las cartas.

<img width="830" alt="Captura de Pantalla 2024-06-06 a la(s) 17 59 06" src="https://github.com/supernave1/dis145/assets/164402810/317fd4a5-de14-4554-8c44-a0fb8f29f71a">

Despues modele el brazo el cual conecta el motor con la rueda a la base de las cartas.

<img width="830" alt="Captura de Pantalla 2024-06-06 a la(s) 18 58 34" src="https://github.com/supernave1/dis145/assets/164402810/fa24c0db-ffa2-48e8-bf6a-b744a8022404">

Le agregue el motor con su rueda, unido al brazo y además le hice un enganche el cual permite al brazo subir y bajar por un eje, el cual no topa, por lo que el brazo va a ser capaz de bajar hasta la ultima carta.

<img width="830" alt="Captura de Pantalla 2024-06-06 a la(s) 18 43 06" src="https://github.com/supernave1/dis145/assets/164402810/12147043-d669-45de-b52b-00ea8ed191dc">

Todo unido quedaría así:

<img width="830" alt="Captura de Pantalla 2024-06-06 a la(s) 18 35 06" src="https://github.com/supernave1/dis145/assets/164402810/1e0f6725-9aed-40ba-95c0-5d1ca4efb12d">

## Impresión 3d

Con el modelo ya terminado, queda hacer el archivo de corte para imprimir, el cual se exporta como STl desde rhino, para flashprint, el cual procesa el archivo y te entrega un archivo gx, este mediante un pendrive va directo a la impresora.

<img width="1147" alt="Captura de Pantalla 2024-06-17 a la(s) 18 31 00" src="https://github.com/supernave1/dis145/assets/164402810/3ba3ee41-8a19-470e-9a41-3cfc8444b3dc">

Con una impresora Aventurer 3, mi archivo se demora 8 horas y 39 minutos en imprimirse, y en total se ocupan 54 gramos de filamento.

Este archivo lo guarde en un pendrive y lo descargue en la impresora, esperemos que salga bien!! 

https://github.com/supernave1/dis145/assets/164402810/49fa39c2-6523-4c69-8a71-b8af9b583772



## Proxima clase

Para la proxima clase traere todo esto impreso en 3d, lo que me permitira ver si realmente funciona, y poder configurar el motor para que vaya lanzando una por una las cartas.

Desarrollare una base con espacio para esconder el hardware utilizado en el proyecto, la cual dara espacio al servo motor para girar lo ya modelado.

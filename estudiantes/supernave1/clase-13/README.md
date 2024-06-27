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


# clase-14

Fui a buscar las impresiones, las cuales una de ellas fallo. La base para las cartas no se imprimio hasta arriba, por lo que no se imprimeron los soportes para el brazo. De suerte habia otra impresora  disponible, por lo que pude mandar el archivo a impirmir nuevamente. Espero que esta vez pueda salir bien.

![Photoroom_20240622_55613 p  m](https://github.com/supernave1/dis145/assets/164402810/3ac7db0a-0a07-4ac4-8bd3-3de815fcc84e)


https://github.com/supernave1/dis145/assets/164402810/ef08a14c-8ad8-4117-b62e-3834c9416e2d


El brazo para el motor, salio perfecto, lo unico es que me equivoque en las medidas del diametro, por lo que en un principio no cabia, por lo que corte el brazo en un punto para que se pueda abrir, queda muy bien fijado el motor ya instalado.


![Photoroom_20240622_60433 p  m](https://github.com/supernave1/dis145/assets/164402810/05f2dbbb-d1f8-48f7-a42a-c9afccaba8b3)


![Photoroom_20240622_55558 p  m](https://github.com/supernave1/dis145/assets/164402810/059436b9-ba68-4e80-bf88-ac031e168b8c)


Una vez en mi casa, arme todo, y con la base mal impresa busque solucionar de forma casera el problema. Le pegue con silicona caliente una llave allen lo suficientemente pequeña para que pase por el hoyito del brazo y funcione como eje. Quedo muy practico, lo que me va a permitir poder hacer las pruebas neceserias para ver si realmente funciona mi proyecto.

![Photoroom_20240622_21309 p  m](https://github.com/supernave1/dis145/assets/164402810/cbd3ad5a-e51b-4f8a-b074-66b9e3ed31d3)

Este video muestra como el brazo tiene la libertad para moverse para arriba o para abajo.


https://github.com/supernave1/dis145/assets/164402810/63796b4e-6623-4962-9c2d-7c2e64389f1e

Bastante feliz con como va agarrando forma el proyecto, me gusto el funcionamiento, ahora veremos si tiene algun problema el motor bajo este sistema.

## Pruebas

Lamentablemente,con todo el sistema armado, descubri un problema bien grande. El motor no tiene la suficiente fuerza para lograr girar cuando la rueda esta apoyada en las cartas, es decir, no es capaz de girar apoyado en su propio peso, lo que es grave ya que en eso consiste el sistema para tirar cada carta.


https://github.com/supernave1/dis145/assets/164402810/1262fa51-34c9-459a-b636-45ed64313352

Para comprobar esto, le voy a sacar el elastico a la rueda a ver si sin el roce que provoca el elastico, es capaz de girar.


https://github.com/supernave1/dis145/assets/164402810/cf092965-ae95-4417-b5ad-3edbee3abd5c

El motor con la rueda sin elastico si es capaz de girar sopportando su propio peso, pero con el roce que le hace el elastico no es capaz. :(

Le pondre unas tiras de silicona caliente a la rueda de un lado al otro, para que asi tenga mas espacio para girar que con el elastico, quizas que con esto, el motor logre agarrar la suficiente fuerza para que siga girando y logre empujar las cartas.


![Photoroom_20240622_52708 p  m](https://github.com/supernave1/dis145/assets/164402810/b4c91c6e-0541-4665-84e0-5ddc47e61985)

Esperemos que funcione!!

https://github.com/supernave1/dis145/assets/164402810/d016ed0e-1410-401c-8b1b-9cf70a2b1b54

Aunque mejora un poco, sigue siendo inutil para lo que queremos lograr. Voy a investigar sobre motores mas pequeños y quizas proporcionalmente mas fuertes, que sean capaces de girar soportando su propio peso.

## Investigación

Encontre un video que es muy parecido a lo que quiero hacer, solo que cambia la forma en que gira la base, haciendola sin un servo motor. Se puede ver que ocupa un motor mas chico el cual si es capaz de girar apoyandose en su propio peso, lo cual da esperanzas. Incluso se puede ver que le pone un elastico para darle mas presion lo que muestra que aguanta mas de su peso.

https://www.youtube.com/watch?v=dx9-wwSQbUE&ab_channel=MrInnovative

Encontre el mismo motor, solo que no he logrado encontrar un lugar en Chile que lo venda, solo por lugares de exportacion, como Temu y Aliexpress. Parece que la tienda Hubot lo tiene, asique mañana llamare para ver si lo tienen disponible y con entrega inmediata.

https://www.youtube.com/watch?v=ZZ8EuwA4-gs&ab_channel=JOAQUINARDILA


## Cambios

Al no tener los materiales necesarios, hare pruebas con lo que tengo a mano. Intentare cambiar el motor dc por un servo, el cual tiene mas torque pero no la velocidad. 

Primero hare rotar el servo en 180°

https://github.com/supernave1/dis145/assets/164402810/8d3a6d69-8c2d-4d1a-9662-693411853711

Me da esperanzas de que puede funcionar, ahora lo pondre en el brazo para verlo en su posicion real, quizas funicona!!

![IMG_1937 Chico](https://github.com/supernave1/dis145/assets/164402810/0a19aca0-b677-4e50-9900-4892a86e03ea)

Se ve bien conectado, combina con el azul del brazo jaja, espero que fucnione. Voy a hacer la primera prueba, con una rotacion de 180°.

https://github.com/supernave1/dis145/assets/164402810/81e4d9fd-df02-41b1-af67-a46ec8f854b3

Estuvo muy cerca de lanzar la carta, le falta mas rotacion, voy a intentar hacer que gire mas de 180°, ya que ahi si alcanzaria, algo bueno del servo, es que vuelve a la posicion inicial, lo cual hara que la carta debajo de la lanzada quede en buena posicion y no bote mas de una.

Me consegui un servo capaz de rotar de manera continua, es decir en 360°, lo cual para mi proyecto puede ser util, ya que debiese ser capaz de lanzar las cartas. Vamos a ponerlo a prueba.


https://github.com/supernave1/dis145/assets/164402810/5bd0b118-feba-4417-afd1-cc4bb1c0ff3d

Feliz por que si gira en 360°, nos volvimos a ilucionar. Ahora lo pondre en la rueda, y vere si es capaz de lanzar las cartas.


https://github.com/supernave1/dis145/assets/164402810/6e1b47dd-81c0-4146-b847-3c7e8a1a1000

Si las lanza, y apoyado sobre su propio peso, cosa que hasta este punto no había logrado! Eso si, antes de que lanze una carta, alcanza a agarrar la que viene, lo que no es bueno. Pensare en formas para evitar esto.

Volviendo atras en mi readme, vi que le habia puesto tiras de silicona, las cuales hacen que no tenga friccion con la carta todo el rato, por lo que probare con ese metodo.

Para esto, provare con 1, 2 y 3 tiras, para ver cual funciona mejor. 

# Prueba con 1 tira

https://github.com/supernave1/dis145/assets/164402810/ff8e8ade-e0ba-4582-9288-469c09595e11

Se puede ver que funciona muy bien, es capaz de lanzar una a una las cartas, nose si es tan eficiente, ya que tiene que dar 4 vueltas para recien lanzar una carta.

# Prueba con 2 tiras

https://github.com/supernave1/dis145/assets/164402810/f0c2167f-9db5-4aa8-be27-4e34c3d7094d

A mi gusto, funciona mejor que con una tira, ya que cumple la misma funcion, pero lo hace el doble de rapido, por ahora me quedo con esta, veremos con 3 tiras como queda.

# Prueba con 3 tiras

https://github.com/supernave1/dis145/assets/164402810/3c85b3f2-5bd1-4f23-b451-111e1fccf3db

Sigue funcinando y con mas velocidad, pero hay mas riesgos que en las otras ya que a veces agarraba dos cartas, lo que para este proyecto no sirve.

En conclusion, la rueda con dos tiras de silicona es la que mejor funciona, en tanto a velocidad como eficacia. 




















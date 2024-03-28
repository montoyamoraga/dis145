# clase-04

Durante esta clase estaremos trabajando con Arduino Uno R3,
Dado que no traje mi arduino, me desarrollaré en la aplicación Tinkercat la cual simula un arduino.

Buscamos comenzar desde algo simple hacia algo un poco mas complicado por lo que el primer acercamiento con arduino fue prender una luz Led y apagarla.

Para esto utilizamos cables (negros para ground y rojos para poder), una resistencia de 1K(om), ardiuno, y una Led.

En este caso utilizamos los puertos 13 (conectado al led) y ground (desde la resistencia).

![circuito1ledmalo](./circuito1ledmalo.png)

creamos el circuito y su codigo en el cual se define el LED como pinledamarillo en output y definimos tambien desde donde sale (puerto 13)
luego, en el codigo escribimos el "void loop (la acción) en donde se describe cuando se prende la luz y cuando se apaga (high y low con sus respectivos tiempos cada uno)

![codigo1led](./codigo1led.png)


# Clase 15

Empece con el codigo, para hacerlo mas facil, lo hice mediante Tinkercad, para que cada prueba se haga mas facil. El codigo es simple, consiste en dos servos, uno para la base, y otro para la rueda. El de la base hace un movimiento costante de 60°, y cuando termina ese movimiento, se da una pausa de 2 segundos, destinada para que el servo 2 logre lanzar las cartas.
Hace 4 paradas en total y vuelve a su inicio.

Aca hay un video que muestra graficamente estos movimientos.

https://github.com/supernave1/dis145/assets/164402810/ab0cbf3f-2c02-4578-8048-6d6f563da4d7

Se puede ver que funciona y se respeta un movimiento para hacer el otro, lo que es gratificante. Lo unico, es que el servo2, no es de rotacion continua, por lo que pienso que cuando ponga el codigo con el servo de rotacion continua, no va a funcionar de igual manera.

## Construccion

Ya con parte del codigo avanzado, decidi darle el toque final a lo fiscico, y de una vez juntar todas las piezas.

Parti haciendo la base, la cual esta hecha de MDF, y pensada para almacenar las cosas debajo y que no queden a la vista. Despues a esta misma caja, le hice un corte ene el centro con las medidas del servo1, para que quede fijo ahi.


![Photoroom_20240627_30345 p  m](https://github.com/supernave1/dis145/assets/164402810/7c4ff509-e25c-4479-93bb-aee5f58d6114)

Me gusta como a quedando, ya quiero verlo todo ensamblado!!

Luego le pegue una base al servo, para que tenga mayor superficie, y quede fijo, para cuando este todo ensamblado soporte el peso facilmente.

![Photoroom_20240627_30957 p  m](https://github.com/supernave1/dis145/assets/164402810/1388c533-47dd-44d3-a122-e22c6dc9869b)

Para ver como serian los movimientos, puse todo lo ensablado a prueba, quedo asi!


https://github.com/supernave1/dis145/assets/164402810/5be19cb9-170b-4f01-ac02-14b1bd221c63

Muy feliz porque ya va tomando forma!, ahora le pondre la base con las cartas y veremos si soporta el peso, y si es capaz de girar.


https://github.com/supernave1/dis145/assets/164402810/2668c1ab-c1f0-4a47-bb69-8e31c593078b

Se ve muy buenooo!!! Solamente faltaria ver si se sincronizan los servos y ver como quedaria todo funcionando al mismo tiempo, por lo que subiremos el codigo y haremos las pruebas.


https://github.com/supernave1/dis145/assets/164402810/35b0ba38-e25d-4f56-9acf-ee72a3834444

Funciona!!! la base es capaz de girar, mientras que la rueda es capaz de la lanzar las cartas, asi que estoy muy contento con mis avances!!!

Si bien no lanza las cartas una a una, y no esta del todo sincronizado, funciona. Faltarian afinar un par de detalles pero muy feliz con los resultados.


## Codigo

El codigo es bien sencillo, se explicara a continuacion, pero como se dijo anteriormente, el codigo busca sincornizar los movimientos de los servos, para que cuando llegue a una posicion, el otro bote las cartas.












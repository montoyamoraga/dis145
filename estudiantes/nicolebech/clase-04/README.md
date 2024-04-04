# clase-04

Soy en grupo con @isigoycoolea y @Samillanc. Para los encargos de la clase 3 y 4 que se encuentran subidos.




Resposteado desde @Samillanc.



# Resolución encargo grupal clase 04.
*Jueves 28 de marzo de 2024.*

## Miembros del Grupo:
- ***Isidora Goycoolea.***
- ***Nicole Bechan.***
- ***Sebastián Millán.***

  ## [Iteración número 1 - Intento fallido](https://www.youtube.com/watch?v=0qsdvkh5eXc)
Para la realización de nuestra primera iteración de la realización del mouse con la placa Arduino R3 procedimos a utilizar la placa arduino R3 conectada a dos sensores de botones junto a resistencias de 10k

![primer circuito](./IMG_20240328_173424.jpg)

## [Iteración número 2 - Funcionalidad extra lograda](https://www.hackster.io/prabeenr2/joystick-pc-mouse-18552b)
Para la realización de nuestra segunda iteración de la realización del mouse con la placa Arduino R3 procedimos a utilizar la placa arduino R3 conectada a un sensor de joystick para lograr la funcionalidad extra.

[código Arduino IDE](./c_digo_mouse-1.ino)

![circuito tinkercad](./circuit.png)

![esquemático](./schematic.png)

![segunda iteración](./IMG_20240328_173503.jpg)

![resultados consola](./IMG-20240328-WA0028.jpg)
 
## [Iteración número 3 - Funcionalidades CORE logradas]
Para la realización de nuestra tercera iteración de la realización del mouse con la placa Arduino UNO R3 procedimos a conectar solo un boton a la protoboard y la placa, también implementamos cambios en el código con respecto a la iteración número 1. Como resultado de este ejercicio podemos recalcar que logramos un testeo documentado exitoso para las funcionalidades de reconocer el click derecho, el click mantenido y también el doble click.

[código Arduino IDE](./codigo_botones.ino)

![tercer circuito](./IMG_20240328_191639.jpg)

![resultados consola](./VID-20240328-WA0031.mp4)

## Discusión sobre el encargo

***Problema 1:*** Malfuncionalidad del código Arduino IDE de la iteración número 3, que ocurre al marcar un click doble; actualmente la consola marca la presencia del click doble pero a continuación también marca la presencia de el click derecho.

***Problema 2:*** Conflictos para reproducir en archivo README.md el video de pruebas sobre el funcionamiento de los resultados esperados para la tercera iteración, que incluyen una muestra del circuito electrónico y los resultados de consola para las variables programadas.

- [ ] **Solución propuesta 1:** Crear una restricción para el display en consola del click derecho cuando se cumpla la condicionalidad de hacer el doble click al botón en el tiempo estipulado para ello según el código IDE.
- [x] **Solución propuesta 2:** Importar el archivos en la carpeta de la clase-04 con formato MP4 para descarga y luego visualización. [Descarga aquí](https://github.com/Samillanc/dis145/blob/main/estudiantes/Samillanc/clase-04/VID-20240328-WA0031.mp4)

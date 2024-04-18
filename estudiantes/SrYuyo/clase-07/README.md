# clase-07
18/04/2024

Tener en cuenta los cables boost, los cuales permiten una conexión entre procesing y arduino.

El proyecto es libre. Entre todos se deben ayudar, pero cada uno debe hacer su parte individual con respecto al proyecto. Se puede trabajar en base a algo, pero debe estar referenciado. El codigo las cosas formales importan.

**Proyecto Janis**
Interacción entre arduinos y botones, simulación del juego Simón dice. Bajar nota por no bloque de comentarios y no depurar. Debe existir tanto un readme como un comentario en el codigo. Pobrecita :c

Aprenderemos a ordenar nuestros proyecto, a pesar de ser complejos. 

Es importante tener las bibliotecas, para así poder tener procesos empaquetados, además de que se puede retomar proyectos pasados.

Open sours es mostrarte el codigo y la receta en cierta forma.

```cpp
const int ledPin = 13; // Pin del LED

void setup() {
  pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida
}

void loop() {
  parpadearLED(500); // Llama a la función parpadearLED con un intervalo de 500 milisegundos
}

void parpadearLED(int intervalo) {
  digitalWrite(ledPin, HIGH); // Enciende el LED
  delay(intervalo); // Espera el intervalo especificado
  digitalWrite(ledPin, LOW); // Apaga el LED
  delay(intervalo); // Espera el intervalo especificado nuevamente
}

```


"La programación orientada a objetos es un modelo de programación en el que el diseño de software se organiza alrededor de datos u objetos, en vez de usar funciones y lógica. Se enfoca en los objetos que los programadores necesitan manipular, en lugar de centrarse en la lógica necesaria para esa manipulación." Universidad Europea.

El archivo h sirve para declar las variables. Si no declaramos no pueden ejecutar en el codigo.
Recordar que hay una diferencia entre una variable y la función por los parentesisi.

#include "auto.h" permite que todo lo que esta en archivo .h funciona en cpp. Permitiendome crear clases y atributos, para poder iterar, además del constructor.  

"auto::auto" dentro de la clase auto constructor. Esto signiificia.Las condiciones iniciales del constructor, por la cantidad de veces que lo use.

Ahora podremos leer codigos más complejos en su sintxis.

Gracias a adafruit podemos tener la base a algunos proyectos y sus respectivas librerias.

Referencias:
<https://arduino.cl/como-hacer-matematica-en-programas-de-arduino-operadores-matematicos/>
<https://arduino.cl/operadores-aritmeticos-en-arduino/>
<https://universidadeuropea.com/blog/programacion-orientada-objetos/#:~:text=La%20programaci%C3%B3n%20orientada%20a%20objetos%20es%20un%20modelo%20de%20programaci%C3%B3n,l%C3%B3gica%20necesaria%20para%20esa%20manipulaci%C3%B3n.>
<https://learn.adafruit.com/>

-------------------------------------------------------------------------






# clase-05

jueves 04 de abril 2024

partimos esta clase con feedback sobre el proyecto de marzo sobre crear un ratón con Arduino y documentarlo en GitHub usando lenguaje Markdown.

estudiamos la importancia de las unidades de tiempo en un microcontrolador Arduino.

estudiamos la función `millis()`, que retorna un número entero, que es siempre no-negativo por lo que usamos `unsigned long` para declarar la variable que lo almacena.

estudiamos cómo usar `millis()` para medir el tiempo que ha pasado desde que el programa comenzó a correr, y cómo usar esa información para medir intervalos de tiempo, evitando el uso de `delay()`.

vimos estrategias para que nuestros proyectos no solamente lean un dato desde un sensor, y con eso directamente envién una señal a un actuador, sino que procesen esos datos, los filtren, los promedien, ignoren repeticiones, los interpreten, y con eso eventualmente declaren estados.

recomiendo revisar también los apuntes de @josefinasanchezr, donde usamos estrategias de imprimir datos en consola para entender mejor los estados internos del programa.

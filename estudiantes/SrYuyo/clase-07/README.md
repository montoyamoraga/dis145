# Clase-07
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
Hold the line- Toto

# Propuesta trabajo DIS145

En la contemporaneidad, la problemática del desperdicio de alimentos constituye un desafío de envergadura global, con impactos significativos tanto ambientales como económicos. Datos proporcionados por la Organización de las Naciones Unidas para la Agricultura y la Alimentación (FAO) revelan que alrededor de un tercio de la producción mundial de alimentos destinados al consumo humano se pierden o desperdician anualmente. En este contexto, la mayoría de estas pérdidas tienen origen en los hogares, lo que subraya la imperiosa necesidad de desarrollar soluciones innovadoras para atenuar este fenómeno.

Una posible solución que emerge como respuesta a este desafío es un sistema inteligente de monitoreo del estado de los alimentos, que emplea sensores, para determinar la idoneidad de los alimentos para el consumo, su urgencia de consumo y su estado de descomposición. Este dispositivo, al proveer información en tiempo real sobre la condición de los alimentos, habilita a los usuarios para tomar decisiones fundamentadas acerca de su consumo, con el potencial de reducir significativamente el desperdicio de alimentos. 

**Sensores Utilizados:**

  - Sensor MQ2 (Sensor de Gas): Este dispositivo se utiliza para detectar la presencia de gases nocivos en el ambiente, tales como amoníaco, metano y compuestos orgánicos volátiles, aún así tales gases pueden ser liberados por alimentos en descomposición (metano , amoniaco, dióxido de carbono, entre otros). Mediante la detección de estos gases, el sistema es capaz de discernir si los alimentos han alcanzado un estado no seguro para el consumo. Cabe destacar que algunos alimentos deben fermentarse, por lo cual se deberían de tener aparte o bien sellados.

  - Sensor DHT11 (Sensor de Humedad y Temperatura): Este sensor mide la humedad y temperatura del entorno. Variaciones inusuales en estos parámetros pueden indicar un proceso de descomposición en curso. Al monitorear estos indicadores, el dispositivo alerta a los usuarios sobre la posible degradación de los alimentos y la necesidad de su consumo inmediato.

**Beneficios y Aplicaciones:**

  - Reducción del desperdicio de alimentos: Al proporcionar información precisa sobre la condición de los alimentos, el dispositivo contribuye a prevenir la pérdida innecesaria de alimentos, permitiendo su consumo antes de que se tornen inapropiados para su ingesta.

 - Fomento de la Economía Circular: El sistema puede integrarse con aplicaciones móviles que faciliten la donación de alimentos no consumidos a personas necesitadas, de manera similar a plataformas como "Olio" o "Good Meal". Esto no solo reduce el desperdicio de alimentos, sino que también promueve la solidaridad comunitaria.

  - Estímulo al compostaje: Los alimentos que ya no son aptos para el consumo pueden destinarse al compostaje. El dispositivo puede estar vinculado a una aplicación que facilite la recolección de residuos orgánicos y su posterior compostaje, fomentando así la generación de abono orgánico y la reducción de residuos.

**Aplicaciones Conectadas:**

  - Aplicación Similar a "Olio": Esta aplicación permite a los usuarios compartir alimentos que no serán consumidos y donarlos a aquellos que estén interesados en su consumo. Facilita la gestión de alimentos excedentes y fomenta la solidaridad comunitaria.

  - Aplicación para compostaje: Esta aplicación ofrece una plataforma para la recolección de residuos orgánicos y su posterior compostaje. Ayuda a dar un uso adecuado a los alimentos no aptos para el consumo y promueve prácticas más sostenibles de gestión de residuos.

Ahora bien al momento de fijar un objetivo es el de poder concretar el dispositivo de una forma que sea pulcro en temas de codigo y de funcionalidad. Con esto tambien se debe de tener en cuenta el funcionamiento simultaneo de ambas aplicaciones, las cuales no se concretaron previamente en el proyecto.


**Referencias:**  
<https://ovie.life/>  
<https://www.fsis.usda.gov/wps/portal/fsis/newsroom/news-releases-statements-transcripts/news-release-archives-by-year/archive/2017/pha-071717-01>  
<https://www.cdc.gov/foodsafety/communication/ecoli-and-food-safety.html>  
<https://www.ncbi.nlm.nih.gov/books/NBK209612/>  
<https://www.cdc.gov/foodsafety/foodborne-germs.html>  
<https://www.fao.org/platform-food-loss-waste/es/>  
<https://olioapp.com/en/>  
<https://www.goodmeal.app/>  


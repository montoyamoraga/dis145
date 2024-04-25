# clase-06

## Clases de comunicaciones
Interés en intervenciones de audio con distintos medios audiovisuales

En el código de impresión en un monitor serial (Serial.begin(9600)), el número 9600 se refiere a un *baud* que implica cuántos símbolos por segundo se pueden enviar.
Este tipo de impresión no es ni muy rápida, ni muy lenta. Tiene una velocidad decente.

_**processing.org**_ (Janis está con ellos <3)
*pensamientos del momento:* Me llamó la atención la interacción que se puede tener con la interfaz en general, la página.
1. Fue creada *Design system international*
[Página de Design Systems] (https://designsystems.international/)

Processing y p5 está creado por las mismas personas, poseen paradigmas parecidas, pero la diferencia es que *processing* es anterior a *p5*, ya que la última está pensada para correr páginas en sistemas web, mientras que la primera en el computador propio; por decirlo de alguna forma. De hecho, *processing* se maneja con **_java_** y *p5* con **_javaScript_**.

### Contexto turbio de la historia de Arduino
Los profesores de Hernando Barragán creó en su tesis Wiring que posteriormente sería pseudo robado, empaquetado y patentado con el nombre de Arduino. Debido a que uno de los mentores de Hernando fue quien creó *processing*, Arduino tiene una interfaz similar que responde a *processing*.

### Más sobre _**processing**_
Si yo le doy un solo valor entre 0 y 255 entregará una escala de grises, siendo 0 negro y 255 blanco.
Si se le da tres valores (x, y, z) abrirá la escala de color completa.

El color se maneja de esa forma por el hecho de los bytes que contienen 8 bits. Si se hace la conversión de 2^8 = 256 y como en programación se comienza a contar desde el cero, se llega a 255.

### Lenguaje MIDI
Se almacenan en tres los bytes. Con tal de hacer que los instrumentos puedan comunicarse entre distintos.
Más sobre el tema:
Se vio que se había comenzado a perder la creación de música de manera análoga; ya que se genera una interacción distinta a trabajar con un computador. 

El bus es un "río" que tiene la característica de ser bidimensional.
virtual MIDI para Windows de Tobias Erichsen (driver) 
midi SDK: un software development kit

### Explicación del código descargado de Aarón
notaMidi = notaMidi % 128 se crea para limitar el contador hasta la capacidad que tiene midi que es de 0-127.

### Ejercicio realizado en clases
Se realizó un botón, tanto en Arduino como en Processing.
Este permitió que si se apretara un botón con su respectivo código en Arduino, se dibujara un Canva en Processing con distintos colores.

```
/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  printArray(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.read();         // read it and store it in val
  }
  background(255);             // Set background to white
  if (val == 0) {              // If the serial value is 0,
    fill(0);                   // set fill to black
  } 
  else {                       // If the serial value is not 0,
    fill(204);                 // set fill to light gray
  }
  rect(50, 50, 100, 100);
}
```

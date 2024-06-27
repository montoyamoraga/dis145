# Clase-10 

**Loverboy - Working for the Weekend**

# Visualización de datos en Processing

A continuación, se detallan los conceptos básicos del código en Processing que pude recopilar, las funciones clave y como establecer una posible conexión con Arduino para recibir datos a través del puerto serie. Esto es una extensión de la clase que perdí por el no guardado del archivo .md. 🤡

# Establecer Conexión con Arduino

Para establecer una conexión con Arduino, es necesario utilizar la biblioteca `Serial` de Processing, que permite la comunicación a través del puerto serie. La configuración se realiza en la función `setup()`, donde se especifica el puerto serie y la velocidad de comunicación (baud rate). En este caso, utilizamos `Serial.list()[0]` para seleccionar el primer puerto serie disponible y una velocidad de 9600 baudios.

# Conceptos Básicos de Processing

Un programa básico en Processing consta de dos funciones principales: `setup()` y `draw()`. La función `setup()` se ejecuta una vez al inicio, mientras que `draw()` se ejecuta continuamente para crear animaciones y gráficos. Ambos son ciclos en cierta forma.

```java
void setup() {
  size(800, 600); // Tamaño de la ventana
  background(255); // Color de fondo (blanco), depende del codigo rgb 3 variables. No considera transparencia.
}

void draw() {
  ellipse(mouseX, mouseY, 50, 50); // Dibuja un círculo en la posición del mouse
}
```

# Variables y Tipos de Datos

Processing soporta varios tipos de datos estándar, como enteros (`int`), números de punto flotante (`float`), cadenas de texto (`String`) y booleanos (`boolean`). Las variables se utilizan para almacenar y manipular datos.

```java
int xPosition = 100;
float ySpeed = 2.5;
String message = "Hello world!"; //Clasico de la programación.
boolean isActive = true;
```

# Dibujo y Formas

Processing ofrece funciones integradas para dibujar formas básicas como líneas, rectángulos, elipses y más. Además, es posible personalizar colores y estilos de línea.

```java
void setup() {
  size(400, 400); //lienzo de 400 x 400 pixeles
}

void draw() {
  background(200); // Fondo gris claro

  stroke(0); // Color de la línea (negro)
  strokeWeight(2); // Grosor de la línea
  fill(255, 0, 0); // Color de relleno (rojo)
  rect(100, 100, 50, 50); // Dibuja un rectángulo

  noFill(); // Sin relleno
  ellipse(300, 200, 80, 80); // Dibuja una elipse
}
```

# Condicionales y Bucles

Para controlar el flujo de ejecución, Processing utiliza condicionales (`if`, `else`) y bucles (`for`, `while`). Al igual que otros lenguajes.

```java
int circleSize = 50;

void draw() {
  background(255); // Fondo blanco

  if (mousePressed) {
    fill(0, 0, 255); // Relleno azul
  } else {
    fill(255); // Relleno blanco
  }

  ellipse(mouseX, mouseY, circleSize, circleSize); // Círculo interactivo

  // Actualiza el tamaño del círculo con la rueda del mouse
  circleSize += int(map(mouseY, 0, height, -5, 5));
}
```

# Funciones

Las funciones permiten organizar el código en bloques reutilizables. Esto facilita la división del programa en partes más pequeñas y comprensibles y mejorando la legibilidad.

```java
void setup() {
  size(400, 400);
}

void draw() {
  background(200);
  drawRect(100, 100, 50, 50); // Llama a la función drawRect, dibuja un rectangulo.
}

void drawRect(int x, int y, int w, int h) {
  rect(x, y, w, h);
}
```

# Entrada y Eventos del Usuario

Processing permite interactuar con eventos del mouse (`mousePressed`, `mouseClicked`, `mouseMoved`, etc.) y del teclado (`keyPressed`, `keyReleased`, `keyTyped`). Estos eventos pueden utilizarse para crear interacciones dinámicas y controlar la aplicación basada en la entrada del posible usuario. 

```java
void setup() {
  size(400, 400);
}

void draw() {
  background(255);

  if (mousePressed) {
    fill(0); // Relleno negro
  } else {
    fill(255); // Relleno blanco
  }

  ellipse(mouseX, mouseY, 50, 50); // Dibuja un círculo interactivo
}
```

# Integración de librerías externas

Processing admite la importación de librerías externas para ampliar sus funcionalidades. Esto permite agregar capacidades adicionales, como gráficos avanzados, sonido, redes y más por lo que pude estudiar.

```java
import processing.sound.*;

SoundFile sound;

void setup() {
  size(400, 400);
  
  sound = new SoundFile(this, "sound.wav"); // Carga un archivo de sonido. Los archivos WAV proporcionan la mayor calidad de sonido posible
  sound.play(); // Reproduce el sonido
}
```

# Referencias

- [Processing.org](https://processing.org)
- [Processing Reference](https://processing.org/reference/)
- [Libraries in Processing](https://processing.org/reference/libraries/)

<https://openprocessing.org/>
<https://es.khanacademy.org/computing/computer-programming/pjs-documentation>


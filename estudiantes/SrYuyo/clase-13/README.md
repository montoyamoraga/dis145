# Clase-13

Stay With Me - Miki Matsubara


## Tareas para hacer 06/06

1. Bloque 2

  -Hacer un dibujo para tener un aproximado de como sera el objeto.
  
  -Proponer un modelo en cierta forma compacto que contenga el objeto.
  
  -Revisar la impresión de deste modelo 3d.

2. Bloque 3

  -Establecer una primera conexión entre arduino con processing.
  
  -Iterar distintos códigos (simples o ejemplos basicos).
  
  -Establecer una conexión entre el codigo de arduino con uno simple de processing.
  
  -Proponer mejoras en la interfaz de processing o observar errores.

## Bloque 2
No se pudo hacer un modelo en 3d, pues el programa de rhino no es apto para poder 

## Bloque 3

```java 
import processing.serial.*;

Serial myPort;
String dataString = "";
float humidity = 0;
float temperature = 0;
int gas = 0;

void setup() {
  size(400, 300);
  println(Serial.list()); // Listar los puertos seriales disponibles
  myPort = new Serial(this, Serial.list()[0], 9600); // Ajustar el índice según el puerto usado
  myPort.bufferUntil('\n'); // Lectura hasta el fin de línea
}

void draw() {
  background(255);
  fill(0);
  textSize(20);
  textAlign(CENTER);

  // Mostrar los valores de los sensores
  text("Lecturas de los Sensores", width/2, 40);
  text("Humedad: " + nf(humidity, 1, 2) + "%", width/2, 100);
  text("Temperatura: " + nf(temperature, 1, 2) + "°C", width/2, 140);
  text("Concentración de Gas: " + gas + " ppm", width/2, 180);
}

void serialEvent(Serial myPort) {
  dataString = myPort.readStringUntil('\n');
  dataString = trim(dataString);

  // Separar la cadena de datos recibidos
  String[] data = split(dataString, ' ');

  if (data.length == 3) {
    humidity = float(data[0]);
    temperature = float(data[1]);
    gas = int(data[2]);
  }
}

```


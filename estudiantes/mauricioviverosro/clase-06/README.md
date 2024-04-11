# clase-06
Durante esta clase trabajé con Valentina Tiznado y Martin Gonzalez, probamos el código que mostraré a continuación obtenido de la librería de Processing, del cual extrajimos una parte para colocarla en el programa de Arduino. Posteriormente, cargamos y subimos el código desde el Software de arduino a Arduino Uno, una vez que pudimos conectar correctamente la placa (nos demoramos ya que está con problemas, no funciona correctamente) y cargar el archivo en ella, cerramos el programa de Arduino, sin desconectar la placa y la volvimos a cagar en Processing, la cuál respondió al programa. (Al conectarse la placa en Processing, luego de haberle subido y cargado el código en Arduino, pudimos cambiar el color de la ventana de negro a gris.

//Código de processing
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
  String portName = Serial.list()[1];
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



/*

// Wiring / Arduino Code
// Code for sensing a switch status and writing the value to the serial port.

int switchPin = 4;                       // Switch connected to pin 4

void setup() {
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.write(1);               // send 1 to Processing
  } else {                               // If the switch is not ON,
    Serial.write(0);               // send 0 to Processing
  }
  delay(100);                            // Wait 100 milliseconds
}

*/


//Código de arduino
// Wiring / Arduino Code
// Code for sensing a switch status and writing the value to the serial port.

int switchPin = 4;                       // Switch connected to pin 4

void setup() {
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.write(1);               // send 1 to Processing
  } else {                               // If the switch is not ON,
    Serial.write(0);               // send 0 to Processing
  }
  delay(100);                            // Wait 100 milliseconds
}

Posteriormente, descargamos el código de MidiBus desde la Clase 06 del repositório del profesor con el fin de copiarla en Processing. Antes de cargarla en el programa, instalamos MidiBus por medio del mismo programa.

Analizamos diferentes controles Midi y también tuvimos la oportunidad de ver uno en clases que tenia el profesor.

''Bus'' una manera de interpretarlo es que es una especie de cable (a modo de ejemplo) por donde pasa información de forma unidireccional.

Por MIDI pueden transistar muchos mensajes pero por canales distintos; toda la informacion llega de manera simúltanea pero se selecciona al inicio del código con '' int Entrada = y '' e '' int Salida = x ''.

Nota máxima de MIDI = 7 bits.



# Clase 06 (11/04/2024)

## Processing.org

Con mis compañeros Valentina Tiznado y Mauricio Viveros utilizamos un codigo de los ejemplos de processing que nos permite cambiar el color de negro a gris de un cuadrado mostrado en la pantalla a traves de un boton que esta conectado a una placa arduino.

Codigo de processing:

```cpp

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

```

Codigo de arduino: 

```cpp

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

```

bus: cable bidireccional
-1: la entrada da lo mismo

Tambien usamos el codigo entregado por el profe para enviar y recibir qie sirven para emitir sonidos a traves del computador.

```cpp

// ej_34_midi_enviar
// por montoyamoraga
// para Academia Sinestesia
// Programa de Medios Interactivos 2023
// v0.0.2 mayo 2023
// hecho con Processing 4.2.0
// ejemplo traducido y basado
// de The MidiBus => Basic

// importar biblioteca
import themidibus.*;

// crear instancia de MidiBus
MidiBus bus;

int entradaMIDI = -1;
int salidaMIDI = 2;

int canalMIDI = 0;
int notaMIDI = 0;
int velocidadMIDI = 20;

void setup() {

  size(200, 200);

  frameRate(100);

  // listar todos las midibus
  MidiBus.list();

  bus = new MidiBus(new java.lang.Object(), entradaMIDI, salidaMIDI);

  textAlign(CENTER, CENTER);
  fill(0);
}

void draw() {

  background(255, 255, 0);
  text("Enviar", width/2, height/2);

  // enviar nota MIDI
  bus.sendNoteOn(canalMIDI, notaMIDI, velocidadMIDI);
  
  // actualizar nota MIDI
  notaMIDI = notaMIDI + 1;
  
  notaMIDI = notaMIDI % 128;
}

```

Tambien descargamos Virtual Midi de Tobias Eerichsen y creamos un bus por donde transita MIDI, es un cable interno en mi computador.

# Traspaso del código de Arduino a Processing
Se comenzó a buscar formas en que Processing pudiese leer los datos enviados desde Arduino para que se pueda mostrar la interfaz creada.
Este paso se dio, ya que se había logrado que las frecuencias del Buzzer dependiesen de los valores entregados por el primer potenciómetro.

## Código en Arduino
El siguiente código permite que se lean los valores de ambos potenciómetros en el puerto serial de Arduino con una coma que los separara de la siguiente forma:

``` C++
/* 20 de junio, 2024
clase 14
thiare gonzalez
versión 1
leer valores de dos potenciometros y enviarlos por serial
*/

// primer Potenciometro
int pinPotUno = A0;
// valor de lectura
int valorPotUno;

// segundo Potenciometro
int pinPotDos = A1;
// valor de lectura
int valorPotDos;

void setup() {
  // los valores de los potenciometros se ingresan como entrada
  pinMode(pinPotUno, INPUT);
  pinMode(pinPotDos, INPUT);
  // comunicación serial
  Serial.begin(9600);
}

void loop() {
  // leer y refrescar valor actual
  valorPotUno = analogRead(pinPotUno);
  valorPotDos = analogRead(pinPotDos);

  // imprimir valores en el comunicador serial de forma que se ingrese como "uno"
  Serial.print(valorPotLED);
  Serial.print(",");
  Serial.println(valorPotBUZ);

  delay(100); // tiempo de espera
}
```
## Código en Processing
El primer código que se realizó buscaba emular exactamente lo que hacía el Led RGB, presentar seis colores según los valores del potenciómetro: rojo, amarillo, verde, cyan, azul y magenta. Cada color tenía asignado, a su vez, distintas variaciones de frecuencia para emitir un ruido que emulara el sonido de un Buzzer y permitiera darle intensidad a la emoción.

```C++
/* thiare gonzalez
processing
sintetizador de emociones, parte uno
semana del 20 de junio */

// permite conectar Processing y a Arduino, usando los datos del monitor serial del último
import processing.serial.*;

// biblioteca que permite generar sonidos a través de ondas y sus variaciones
import ddf.minim.*;
import ddf.minim.ugens.*;


Serial myPort; // nombre del puerto donde estará conectado arduino
int val1, val2; // variables de lectura de los valores de arduino llamadas pinPotUno y pinPotDos
Minim minim; // nombre biblioteca
AudioOutput out; 
Oscil osc1, osc2; // parametros de las ondas 

void setup() {
  size(600, 400); // tamaño de la ventana abierta en processing
  String portName = Serial.list()[1]; // seleccion del puerto al que se conecta el arduino
  myPort = new Serial(this, portName, 9600); // inicia la comunicación serial
  myPort.bufferUntil('\n'); // permite que el codigo haga lectura hasta encontrar un vacío

  minim = new Minim(this);
  out = minim.getLineOut();
  osc1 = new Oscil(440, 0.5, Waves.SINE); // parámetros para la creación de la primera onda
  osc2 = new Oscil(440, 0.5, Waves.TRIANGLE); // segunda onda con distinta forma, esta es triangular
  osc1.patch(out); // conecta la primera onda a AudioOutput
  osc2.patch(out); // Conecta la segunda onda a AudioOutput
}

void draw() {
  background(0); // fondo blanco de forma inicial

  // simulación de parametros de led RGB, estado inicial
  int ledRojo = 0;
  int ledVerde = 0;
  int ledAzul = 0;

  // valor inicial de la frecuencia del sonido emitido, según valores del segundo potenciómetro
  float frecuencia1 = 0;
  float frecuencia2 = 0;

  // si el primer potenciometro da un valor, se activan los segundos parámetros
  if (val1 < 1 * 1023 / 6) { // rojo (rabia)
    ledRojo = 255;
    frecuencia1 = map(val2, 0, 1023, 400, 480); // 400-480 Hz
    frecuencia2 = map(val2, 0, 1023, 120, 960); // 800-960 Hz
    osc2.setWaveform(Waves.TRIANGLE);
  } else if (val1 < 2 * 1023 / 6) { // amarillo (alegría)
    redValue = 255;
    greenValue = 255;
    frequency1 = map(val2, 0, 1023, 1000, 2000); // 500-600 Hz
    frequency2 = map(val2, 0, 1023, 1000, 1200); // 1000-1200 Hz
    osc2.setWaveform(Waves.TRIANGLE);
  } else if (val1 < 3 * 1023 / 6) { // verde (nervios)
    greenValue = 255;
    frequency1 = map(val2, 0, 1023, 600, 700); // 600-700 Hz
    frequency2 = map(val2, 0, 1023, 1200, 1400); // 1200-1400 Hz
    osc2.setWaveform(Waves.TRIANGLE);
  } else if (val1 < 4 * 1023 / 6) { // cyan (tranquilidad)
    greenValue = 255;
    blueValue = 255;
    frequency1 = map(val2, 0, 1023, 110, 130); // 350-450 Hz
    // frequency2 = map(val2, 0, 1023, 700, 900); // 700-900 Hz
    osc2.setWaveform(Waves.SINE);
  } else if (val1 < 5 * 1023 / 6) { // azul (tristeza)
    blueValue = 255;
    frequency1 = map(val2, 0, 1023, 200, 400); // 300-400 Hz
    frequency2 = map(val2, 0, 1023, 800, 1000); // 600-800 Hz
    osc2.setWaveform(Waves.SINE);
  } else { // magenta (amor)
    redValue = 255;
    blueValue = 255;
    frequency1 = map(val2, 0, 1023, 120, 220); // 450-550 Hz
    //frequency2 = map(val2, 0, 1023, 400, 600); // 900-1100 Hz
    osc2.setWaveform(Waves.SINE);
  }

  fill(redValue, greenValue, blueValue);
  rect(0, 0, width, height);

  osc1.setFrequency(frequency1); // Ajusta la frecuencia del primer oscilador
  osc2.setFrequency(frequency2); // Ajusta la frecuencia del segundo oscilador
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n'); // Lee la línea completa hasta el carácter de nueva línea
  if (inString != null) {
    inString = trim(inString); // Elimina los espacios en blanco
    int[] vals = int(split(inString, ',')); // Divide la cadena en dos valores
    if (vals.length == 2) {
      val1 = vals[0];
      val2 = vals[1];
    }
  }
}

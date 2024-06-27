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
creacion código en processing
*/

// importar las bibliotecas para que se comunique el arduino con processing a través del monitor serial
import processing.serial.*;

// biblioteca para crear sonidos a través de ondas
import ddf.minim.*;
import ddf.minim.ugens.*;

// puerto que se utilizará 
Serial myPort;

// variables que darán los resultados de las variables en arduino
int val1, val2;
Minim minim;
AudioOutput out;

// variable para la creación de ondas con el comando de minim
Oscil osc1, osc2;

void setup() {
  size(600, 400); // tamaño de la ventana
  String portName = Serial.list()[1]; // puerto donde se conectará el arduino
  myPort = new Serial(this, portName, 9600); // comunicación serial
  myPort.bufferUntil('\n'); // lee el código hasta que encuentre un espacio, no lo transmite eternamente

  minim = new Minim(this);
  out = minim.getLineOut();
  osc1 = new Oscil(440, 0.5, Waves.SINE); // parametros para la primera onda
  osc2 = new Oscil(440, 0.5, Waves.TRIANGLE); // parametros para la segunda onda
  osc1.patch(out); // conecta la primera onda al AudioOutput
  osc2.patch(out); // conecta la segunda onda al AudioOutput
}

void draw() {
  background(0); // Fondo blanco

  // emulacion de led RGB en processing y los estados iniciales de cada color
  int ledRojo = 0;
  int ledVerde = 0;
  int ledAzul = 0;

  // frecuencia inicial de las ondas
  float frecuencia1 = 0;
  float frecuencia2 = 0;

  if (val1 < 1 * 1023 / 6) { // rojo (rabia)
    ledRojo = 255;
    frecuencia1 = map(val2, 0, 1023, 400, 480); // 400-480 Hz; primeros parametros de onda uno
    frecuencia2 = map(val2, 0, 1023, 120, 960); // 800-960 Hz; segundos parametros de onda dos
    osc2.setWaveform(Waves.TRIANGLE);

  } else if (val1 < 2 * 1023 / 6) { // amarillo (alegría)
    ledRojo = 255;
    ledVerde = 255;
    frecuencia1 = map(val2, 0, 1023, 1000, 2000); // 500-600 Hz
    frecuencia2 = map(val2, 0, 1023, 1000, 1200); // 1000-1200 Hz
    osc2.setWaveform(Waves.TRIANGLE);

  } else if (val1 < 3 * 1023 / 6) { // verde (nervios)
    ledVerde = 255;
    frecuencia1 = map(val2, 0, 1023, 600, 700); // 600-700 Hz
    frecuencia2 = map(val2, 0, 1023, 1200, 1400); // 1200-1400 Hz
    osc2.setWaveform(Waves.TRIANGLE);

  } else if (val1 < 4 * 1023 / 6) { // cyan (tranquilidad)
    ledVerde = 255;
    ledAzul = 255;
    frecuencia1 = map(val2, 0, 1023, 110, 130); // 350-450 Hz
    // frecuencia2 = map(val2, 0, 1023, 700, 900); // 700-900 Hz; se cambio para no interseccionar dos ondas
    osc2.setWaveform(Waves.SINE); // cambio de forma de onda

  } else if (val1 < 5 * 1023 / 6) { // azul (tristeza)
    ledAzul = 255;
    frecuencia1 = map(val2, 0, 1023, 200, 400); // 300-400 Hz
    frecuencia2 = map(val2, 0, 1023, 800, 1000); // 600-800 Hz
    osc2.setWaveform(Waves.SINE);

  } else { // magenta (amor)
    ledRojo = 255;
    ledAzul = 255;
    frecuencia1 = map(val2, 0, 1023, 120, 220); // 450-550 Hz
    //frecuencia12 = map(val2, 0, 1023, 400, 600); // 900-1100 Hz
    osc2.setWaveform(Waves.SINE);
  }

  fill(ledRojo, ledVerde, ledAzul); // cambio de fondo blanco a los colores emitidos, segun parámetros del led RGB simulado
  rect(0, 0, width, height); // llenar todo el cuadrado

  osc1.setFrequency(frecuencia1); // actualiza la frecuencia de la primera onda
  osc2.setFrequency(frecuencia2); // actualiza la frecuencia de la primera onda
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n'); // lee la línea completa hasta el nuevo parámetro en línea
  if (inString != null) {
    inString = trim(inString); // eliminar espacios en blancos que generen interferencia
    int[] vals = int(split(inString, ',')); // dividir las variables de puerto serial de arduino en dos
    if (vals.length == 2) {
      val1 = vals[0];
      val2 = vals[1];
    }
  }
}
```

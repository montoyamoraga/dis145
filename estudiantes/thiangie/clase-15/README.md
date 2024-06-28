# Entrega final
## Definición de proyecto
Sintetizador de emociones, a través de controlar potenciómetros para definir la emoción que se siente y con qué intensidad.

![imagen](https://github.com/thiangie/dis145/assets/100184098/71a068c1-9b7a-4333-a726-9a829de8eb61)

La idea surge de los sintetizadores de perrilla que permite controlar diversos parámetros por medio de potenciómetros.
Además, nace a raíz de la consola de emociones que se encuentra en la película *Intensamente* de *Pixar*

https://github.com/thiangie/dis145/assets/100184098/6ecdd891-018d-4401-945d-d48b00136d1d
*Trailer Intensamente en Studios LA*

# Línea temporal del proyecto
## Sintetizador de emociones
Este proyecto parte desde una problemática personal, como la gestión de emociones.

## Inicio del proceso del proyecto

### Semana 10
En la semana 10 se comenzó a trabajar con un sintetizador de emociones netamente en processing, donde se empezó a buscar códigos de ayuda para animar letras y mostrar las distintas emociones.
Para esto se creó un código y una clase.

#### Clase creada
```C++
class Caracter {
  char valor;
  float x, y;
  
  // hogar en x e y para el string, estado "normal"
  float homeX, homeY;
  float velocidad = 0.05;

  Caracter(char valor, float x, float y) {
    // posiciones de cada caracter
    this.valor = valor;
    this.x = x;
    this.y = y;
    this.homeX = x;
    this.homeY = y;
  }

  void display() {
    text(valor, x, y);
  }

  void shake() {
    // determina cuánto se va a mover
    x += random(-10, 10);
    y += random(-10, 10);
  }

  void returnHome() {
    
    // el lerp suaviza la llegada al hogar
    // x indica en dónde está y homeX a donde quiere llegar
    x = lerp(x, homeX, velocidad);
    y = lerp(y, homeY, velocidad);
  }
}
```
#### Código completo
Se generó uno de los Happy Accidents

```C++
import ddf.minim.*;
import ddf.minim.ugens.*;

String mensaje = "R A B I   A";

ArrayList<Caracter> caracteres = new ArrayList<Caracter>();
float kerling = 20;

Minim minim;
AudioOutput out;
Oscil fm;

void setup() {
  // dibujar pantalla que proyecta la visualizacion de los elementos
  size(750, 500, P3D);
  background(255, 0, 0);
  
  // iniciar los objetos que responden a las variables minim y out
  minim = new Minim(this);
  out = minim.getLineOut();
  Oscil rojo = new Oscil(400, 0.8, Waves.TRIANGLE);
  
  // onda 2
  fm = new Oscil(15, 5, Waves.SINE);
  fm.offset.setLastValue(200);
  fm.patch(rojo.frequency);
  rojo.patch(out);
  
  PFont fuente;
  fuente = loadFont("HelveticaNeue-Bold-48.vlw");
  textFont(fuente, 150);
  fill(255, 0, 0);
  textAlign(CENTER, CENTER);
  float x = width/3;  
  float y = height/2;
  
  for (int i = 0; i < mensaje.length(); i++) {
    char c = mensaje.charAt(i);
    Caracter caracter = new Caracter(c, x, y);
    caracteres.add(caracter);
    x -= kerling;
    x += textWidth(c);
  }
  
}

void draw() {
  background(0);
  stroke( 0 );
  for (int i = 0; i < out.bufferSize() - 1; i++)
  {
    float x1 = map( i, 0, out.bufferSize(), 0, width);
    float x2 = map(i+1, 0, out.bufferSize(), 0, width);

    line( x1, 50 + out.left.get(i)*50, x2, 150 + out.right.get(i+1)*50);
    line( x2, 150 + out.left.get(i)*50, x2, 150 + out.right.get(i+1)*50);
  }
  text( "Modulation frequency: " + fm.frequency.getLastValue(), 5, 15 );
  text( "Modulation amplitude: " + fm.amplitude.getLastValue(), 5, 30 );
}

void mouseMoved() {
  float modulateAmount = map( mouseY, 0, height, 220, 1 );
  float modulateFrequency = map( mouseX, 0, width, 0.1, 100 );

  fm.setFrequency( modulateFrequency );
  fm.setAmplitude( modulateAmount );
  
  for (Caracter c : caracteres) {
    c.display();
    
    if (mousePressed) {
      c.shake();
      fill(180, 0, 0);
      
    } else {
      c.returnHome();
      fill(255, 0, 0);
    }
  }
}
```
https://github.com/thiangie/dis145/assets/100184098/9f90d314-0ce1-4aac-ba13-41356fedb5ea

### Semana 11
Se comenzó a trabajar en la transmisión de datos de Arduino a Processing, ya que se decidió controlar parámetros de processing con parámetros
#### Códigos en Arduino para comenzar a emitir lectura de valores de un potenciometro

```C++
// variable donde se almacenarán los datos del potenciometro
int valor;

// variable de conversion de la variable numerica a un string
String valorString;
 
void setup() {
  //Inicializamos la comunicación serial
  Serial.begin(9600);
  
  //Escribimos por el monitor serie mensaje de inicio
  Serial.println("Valores del potenciometro");
 
}
 
void loop() {
  // leemos del pin A0 valor
  valor = analogRead(A0);

  // conversion de valor numerico a string
  valorString = String(valor);
  Serial.println(valorString);

  // delay de tiempo para no emitir el mensaje muy rapido
  delay(1000);
}
```
#### Código en processing para lectura en monitor serial
```C++
import processing.serial.*;

Serial myPort;
String val;

void setup() {
  String portName = Serial.list() [1];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if (myPort.available() > 0) {
    val = myPort.readStringUntil('\n');
  }
  
  println(val);
}
```
Este código dio pie a buscar cómo lograr que en Arduino se ingresaran dos valores para que entren como uno en Processing y Processng los pudiese separar posteriormente.

### Semana 12
Se llevó lo que se pretendía a hacer en Processing a formato físico por frustraciones personales
Este proyecto permite cambiar los colores de un led RGB y que imprima el valor del potenciometro.

```C++
/* 30 de mayo, 2024
clase 12
thiare gonzalez
versión 1
conectar led rgb a un arduino uno
*/

// definir los leds asociado a cada pin en el arduino
#define ledRojo 11
#define ledVerde 10
#define ledAzul 9

// patita del potenciometro
int pinPot = A0;
// valor de lectura el potenciómetro
long valorPot;

int valorMin = 0;
int valorMax = 1023;

int divisiones = 6;
int tamanoDivision;

int estadoActual;
int estadoAnterior;

int tiempoPausa = 500;


void setup() {
  // registrar los leds del led rgb como salida
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  // registrar el potenciómetor como entrada
  pinMode(valorPot, INPUT);
  Serial.begin(9600);

  // revisar map(valor, 0, 1023, 0, 5);
  tamanoDivision = 1023 / (divisiones - 1);
}

void loop() {

  // leer y refrescar valor actual
  valorPot = analogRead(pinPot);

  // antes de refrescar el estadoActual
  // tomamos su valor y lo almacenamos
  // en estadoAnterior
  estadoAnterior = estadoActual;

  if (valorPot < 1 * valorMax / divisiones) {
    // color rojo
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
    delay(tiempoPausa);
    estadoActual = 0;
  } else if (valorPot < 2 * valorMax / divisiones) {
    // color amarillo
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
    delay(tiempoPausa);
    estadoActual = 1;
  } else if (valorPot < 3 * valorMax / divisiones) {
    // color verde
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
    delay(tiempoPausa);
    estadoActual = 2;
  } else if (valorPot < 4 * valorMax / divisiones) {
    // color cyan
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, HIGH);
    delay(tiempoPausa);
    estadoActual = 3;
  } else if (valorPot < 5 * valorMax / divisiones) {
    // color azul
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
    delay(tiempoPausa);
    estadoActual = 4;
  } else {
    // color magenta
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
    delay(tiempoPausa);
    estadoActual = 5;
  }

  // ahora podemos comparar estadoActual y estadoAnterior

  if (estadoAnterior != estadoActual) {
    Serial.print("nuevo estado: ");
    Serial.println(estadoActual);
  }
}
```
#### Video de cómo se ve
https://github.com/thiangie/dis145/assets/100184098/35074195-5898-4d95-8c18-4512b9b27ddb

#### Semana 13
Se agregó un segundo potenciómetro conectado a un buzzer para ver cómo se podría llevar hacer que los valores de un potenciometro dependiesen de uno principal.
```C++


/* 06 de junio, 2024
clase 12
thiare gonzalez
versión 1
conectar led rgb a un arduino uno
*/



// definir los leds asociado a cada pin en el arduino
#define ledRojo 11
#define ledVerde 10
#define ledAzul 9

// patita del potenciometro de LED
int pinPotLED = A0;
// valor de lectura el potenciómetro
long valorPotLED;

// valores maximos y minimos de potenciometro LED
int valorMin = 0;
int valorMax = 1023;

int divisiones = 6;
int tamanoDivision;

int estadoActual;
int estadoAnterior;

int tiempoPausa = 500;


// definir el pin del buzzer en el arduino
//#define pinBuzzer 2
const int pinBuzzer=2;

// patita potenciometro buzzer
int pinPotBUZ = A1;
// valor lectura potenciometro buzzer
int valorPotBUZ;

// intervalos de valores para cada color
// color rojo
int valorMinROJO = 400;
int valorMaxROJO = 484;
// color amarillo
int valorMinAMA = 508;
int valorMaxAMA = 526;
// color verde
int valorMinVER = 527;
int valorMaxVER = 606;
// color cyan
int valorMinCYAN = 607;
int valorMaxCYAN = 630;
// color azul
int valorMinAZUL = 631;
int valorMaxAZUL = 668;
// color magenta
int valorMinMAG = 669;
int valorMaxMAG = 789;


void setup() {
  // registrar los leds del led rgb como salida
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  // registrar el buzz como salida
  pinMode(pinBuzzer, OUTPUT);
  // registrar los potenciometros como entrada
  pinMode(valorPotLED, INPUT);
  pinMode(valorPotBUZ, INPUT);
  Serial.begin(9600);

  // revisar map(valor, 0, 1023, 0, 5);
  tamanoDivision = 1023 / (divisiones - 1);
}

void loop() {

  // leer y refrescar valor actual
  valorPotLED = analogRead(pinPotLED);
  // leer los valores del potenciometro del buzzer
  valorPotBUZ = analogRead(pinPotBUZ);

  // antes de refrescar el estadoActual
  // tomamos su valor y lo almacenamos
  // en estadoAnterior
  estadoAnterior = estadoActual;

  if (valorPotLED < 1 * valorMax / divisiones) {
    // color rojo
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
    delay(tiempoPausa);
    estadoActual = 0;
  } else if (valorPotLED < 2 * valorMax / divisiones) {
    // color amarillo
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
    delay(tiempoPausa);
    estadoActual = 1;
  } else if (valorPotLED < 3 * valorMax / divisiones) {
    // color verde
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
    delay(tiempoPausa);
    estadoActual = 2;
  } else if (valorPotLED < 4 * valorMax / divisiones) {
    // color cyan
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, HIGH);
    delay(tiempoPausa);
    estadoActual = 3;
  } else if (valorPotLED < 5 * valorMax / divisiones) {
    // color azul
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
    delay(tiempoPausa);
    estadoActual = 4;
  } else {
    // color magenta
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
    delay(tiempoPausa);
    estadoActual = 5;
  }

  // ahora podemos comparar estadoActual y estadoAnterior

  if (estadoAnterior != estadoActual) {
    Serial.print("nuevo estado: ");
    Serial.println(estadoActual);
  }

  // lectura de los valores de potenciometro
  if (estadoActual == 0) {
    //int frecuencia = map(valorPotBUZ, 0, 1023, valorMinROJO, valorMaxROJO);
    tone(pinBuzzer, 1000);
    delay(500);
  }

  if (estadoActual == 1) {
    //int frecuencia = map(valorPotBUZ, 0, 1023, valorMinAMA, valorMaxAMA);
    tone(pinBuzzer, 1500);
    delay(500);
  }

  if (estadoActual == 2) {
    //int frecuencia = map(valorPotBUZ, 0, 1023, valorMinVER, valorMaxVER);
    digitalWrite(pinBuzzer, HIGH);
    tone(pinBuzzer, 2000);
    delay(500);
  }

  if (estadoActual == 3) {
    long frecuencia = map(valorPotBUZ, 0, 1023, valorMinCYAN, valorMaxCYAN);
    tone(pinBuzzer, frecuencia);
    delay(500);
  }

  if (estadoActual == 4) {
    long frecuencia = map(valorPotBUZ, 0, 1023, valorMinAZUL, valorMaxAZUL);
    tone(pinBuzzer, frecuencia);
    delay(500);
  }

  if (estadoActual == 5) {
    long frecuencia = map(valorPotBUZ, 0, 1023, valorMinMAG, valorMaxMAG);
    tone(pinBuzzer, frecuencia);
    delay(500);
  }
  

}
```


## Traspaso del código de Arduino a Processing

### Primera instancia
Se comenzó a buscar formas en que Processing pudiese leer los datos enviados desde Arduino para que se pueda mostrar la interfaz creada.
Este paso se dio, ya que se había logrado que las frecuencias del Buzzer dependiesen de los valores entregados por el primer potenciómetro.

#### Código en Arduino
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
  Serial.print(valorPotUno);
  Serial.print(",");
  Serial.println(valorPotDos);

  delay(100); // tiempo de espera para lectura
}
```
#### Código en Processing
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
#### Video funcionamiento

https://github.com/thiangie/dis145/assets/100184098/23438ae9-6347-4688-9dce-5e453d1c521d

### Segunda instancia, agregar animaciones para cada emocion
En esta instancia, debido a que no se pudieron encontrar sonidos más melódicos para las emociones más suaves, como la felicidad, tranquilidad y amor, se pensaron en qué emociones proyectaba cada frecuencia, terminado siendo negativas.

El código de arduino se mantiene, ya que ahora lo que hay que editar es cómo se proyecta en processing.

#### Nuevo código en processing
Nuevos parámetros para cada animación

```C++
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

// parámetros para el gradiente para hacer el display de la emoción RABIA
float amplitude = 70;
float fillGap = 50;

// parámetros para crear la geometría de ANSIEDAD
int x;
int y;
float outsideRadius = 175;
float insideRadius = 100;

// parámetros para los círculos de DISOCIACIÓN
float diameter;
float angle = 0;

// parámetros para la sensación de VACÍO
float yoff = 0.0;
```
Set up 

```C++
void setup() {
  size(600, 400, P3D); // tamaño de la ventana
  String portName = Serial.list()[1]; // selección del puerto que se utilizará
  myPort = new Serial(this, portName, 9600); // inicio de comunicación serial
  myPort.bufferUntil('\n'); // definir el término de lectura

  minim = new Minim(this);
  out = minim.getLineOut();
  osc1 = new Oscil(440, 0.5, Waves.SINE); // primera onda, sinusoidal
  osc2 = new Oscil(440, 0.5, Waves.TRIANGLE); // segunda onda, triangular
  osc1.patch(out); // conecta la primera onda al AudioOutput
  osc2.patch(out); // conecta la segunda onda al AudioOutput
  
  // geometría que representa a la ansiedad con parametros de ancho, x, y alto, y
  x = width/2;
  y = height/2;
  
  // hacer que las figuras geométricas no tengan línea de contorno
  noStroke();
  
  // parámetros de los círculos de la emoción DISOCIACIÓN
  diameter = height - 10;
  noStroke();
  fill(0, 255, 255); // color magenta
}
```
Código de lo que se proyectará en pantalla del computador

``` C++
void draw() {

  float frecuencia1 = 0;
  float frecuencia2 = 0;

  if (val1 < 1 * 1023 / 6) { // rojo (rabia)
    frecuencia1 = map(val2, 0, 1023, 400, 480); // 400-480 Hz; mapeo los valores de frecuencia de la onda
    frecuencia2 = map(val2, 0, 1023, 120, 960); // 120-960 Hz
    osc2.setWaveform(Waves.SINE);
    osc1.setWaveform(Waves.TRIANGLE);
    drawGradientRojo();
    
  } else if (val1 < 2 * 1023 / 6) { // amarillo (ansiedad)
    background(255, 255, 0);
    frequency1 = map(val2, 0, 1023, 1000, 2000); // 1000-2000 Hz
    frequency2 = map(val2, 0, 1023, 1000, 1200); // 1000-1200 Hz
    background(255, 255, 0); // Fondo amarillo
    osc2.setWaveform(Waves.SINE);
    osc1.setWaveform(Waves.TRIANGLE);
    drawAnxiety();
    
  } else if (val1 < 3 * 1023 / 6) { // verde (estrés)
    background(0, 255, 0);
    frequency1 = map(val2, 0, 1023, 600, 700); // 600-700 Hz
    frequency2 = map(val2, 0, 1023, 1200, 1400); // 1200-1400 Hz
    background(0, 255, 0); // Fondo verde
    drawStress();
    
  } else if (val1 < 4 * 1023 / 6) { // cyan (disociación)
    background(0, 255, 255);
    frequency1 = map(val2, 0, 1023, 110, 130); // 110-130 Hz
    // frequency2 = map(val2, 0, 1023, 700, 900); // 700-900 Hz
    background(0, 255, 255); // Fondo cyan
    osc2.setWaveform(Waves.SINE);
    drawDisociacion();
    
  } else if (val1 < 5 * 1023 / 6) { // azul (sobrepensar)
    background(0, 0, 255);
    frequency1 = map(val2, 0, 1023, 200, 400); // 200-400 Hz
    frequency2 = map(val2, 0, 1023, 800, 1000); // 800-1000 Hz
    background(0, 0, 255); // Fondo azul
    drawOverthink();
    
  } else { // magenta (vacio)
    frequency1 = map(val2, 0, 1023, 120, 220); // 120-220 Hz
    // frequency2 = map(val2, 0, 1023, 400, 600); // 400-600 Hz
    background(255, 0, 255); // Fondo magenta
    osc2.setWaveform(Waves.SINE);
    drawEmpty();
  }

  osc1.setFrequency(frecuencia1); // ajusta la frecuencia de la primera onda
  osc2.setFrequency(freceuncia2); // ajusta frecuencia de la segunda onda
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n'); // lee la línea hasta su término para pasar a la siguiente
  if (inString != null) {
    inString = trim(inString); // eliminar espacios en blanco
    int[] vals = int(split(inString, ',')); // divide el string entregado por arduino por dos, para considerar los valores de ambos potenciometros
// esto permite que el código sepa el orden de los valores entregados
    if (vals.length == 2) { 
      val1 = vals[0];
      val2 = vals[1];
    }
  }
}
```

Creación de las animaciones de cada emoción, basadas en los ejemplos de processing y editados para que funcionen con los parámetros entregados según el valor del segundo potenciometro, ya que este regula la intensidad de cada emoción.

#### Emoción de rabia
Basado en el ejemplo de Gradiente de Processing
```C++
void drawGradientRojo() {
  PImage gradient = createImage(width, height, RGB);
  float frequency = 0;

  for (int i = -50; i < height + 100; i++) {
    float angle = 0;
    frequency += 0.002;
    for (float j = 0; j < width + 75; j++) {
      float py = i + sin(radians(angle)) * amplitude;
      angle += frequency;
      color c = color(abs(py - i) * 255 / amplitude, 0 - abs(py - i) * 255 / amplitude, j * (0.0 / (width + 50)));
      for (int filler = 0; filler < fillGap; filler++) {
        gradient.set(int(j - filler), int(py) - filler, c);
        gradient.set(int(j), int(py), c);
        gradient.set(int(j + filler), int(py) + filler, c);
      }
    }
  }
  set(0, 0, gradient);
}
```
En esta emoción, el segundo potenciométro controla la variación de la frecuencia del sonido.
Se adaptaron los valores para que el fondo concordara.

#### Emoción de ansiedad
Basado en el ejemplo *Triangle strip* de processing

```C++
void drawAnxiety() {
  int numPoints = int(map(val2, 0, 1023, 1, 60)); // los valores del segundo potenciometro dejan que crezca la geometría
  float angle = 0;
  float angleStep = 180.0/numPoints;
  
  fill(0);
  stroke(255,255,0);
    
  beginShape(TRIANGLE_STRIP); 
  for (int i = 0; i <= numPoints; i++) {
    float px = x + cos(radians(angle)) * outsideRadius;
    float py = y + sin(radians(angle)) * outsideRadius;
    angle += angleStep;
    vertex(px, py);
    px = x + cos(radians(angle)) * insideRadius;
    py = y + sin(radians(angle)) * insideRadius;
    vertex(px, py); 
    angle += angleStep;
  }
  endShape();
}
```
Este código permite demostrar qué tan ansiosa una persona se siente, incrementando ruido y la visual.

#### Sensación de estrés
Basado en el ejmplo *Random Gaussian* de processing
```C++
void drawStress() {
  background(0);
  float val = randomGaussian();
  float sd = 60;                  // definir una desviación estandar
  float mean = val2/2;           // definir un valor promedio
  float x = ( val * sd ) + mean;  // escalar en número gaussiano segun la desviación estandar

  noStroke(); // quitar contorno
  fill(0, 255, 0); // rellenar el color verde
  ellipse(x, val2/2, 32, 32); // mapeo del valor y movimiento de la elipse con 
}
```

#### Sensación de estar disociando
Basado en el ejemplo *Sine* de processing
``` C++
void drawDisociacion() {
  background(0);
  float d1 = 10 + (sin(angle)* val2/2) + diameter/2;
  float d2 = 10 + (sin(angle + PI/2) * val2/2) + diameter/2;
  float d3 = 10 + (sin(angle + PI) * val2/2) + diameter/2;
  
  ellipse(0, height/2, d1, d1);
  ellipse(width/2, height/2, d2, d2);
  ellipse(width, height/2, d3, d3);
  
  angle += 0.02;
}
```

#### Sensación de estar sobrepensando
Basado en el ejmplo *Mixture Grid* de processing

``` C++
void drawOverthink() {
  defineLights();
  background(0);
  
  for (int x = 0; x <= width; x += 60) {
    for (int y = 0; y <= height; y += 60) {
      pushMatrix();
      translate(x, y);
      rotateY(map(val2, 0, width, 0, PI));
      rotateX(map(val2, 0, height, 0, PI));
      box(90);
      popMatrix();
    }
  }
}

// las luces que llegan a las figuras
void defineLights(){
  pointLight(10, 100, 200,   // color
             200, -150, 0); // posicion

  // luz celeste desde el costado
  directionalLight(0, 102, 255, // color
                   1, 0, 0);    // The x-, y-, z-axis direction

  // luz azul desde el frente
  spotLight(10, 19, 109,  // color
            0, 40, 200,     // posicion
            0, -0.5, -0.5,  // direccion
            PI / 2, 2);   
}
```

#### Sensación de vacío
Basado en el ejemplo *Noise wave* de processing
```C++
void drawEmpty() {
  background(40); 
  fill(75);
  
  beginShape();
  float xoff = 0;
  for (float x = 0; x <= width; x += 10) {
    // mapear los valores del ruido
    float y = map(noise(xoff, yoff), 0, 1, 200,val2/2); // ruido 2D
    // float y = map(noise(xoff), 0, 1, 200,300);    // ruido 1D
    
    // setear el vertice
    vertex(x, y); 
    // incrementar la dimension x de la onda de ruino
    xoff += 0.05;
  }
  // dimension y de la onda de ruido
  yoff += 0.01;
  vertex(width, height);
  vertex(0, height);
  endShape(CLOSE);
  
}
```
### Código completo
```C++
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

// parámetros para el gradiente para hacer el display de la emoción RABIA
float amplitude = 70;
float fillGap = 50;

// parámetros para crear la geometría de ANSIEDAD
int x;
int y;
float outsideRadius = 175;
float insideRadius = 100;

// parámetros para los círculos de DISOCIACIÓN
float diameter;
float angle = 0;

// parámetros para la sensación de VACÍO
float yoff = 0.0;

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

// parámetros para el gradiente para hacer el display de la emoción RABIA
float amplitude = 70;
float fillGap = 50;

// parámetros para crear la geometría de ANSIEDAD
int x;
int y;
float outsideRadius = 175;
float insideRadius = 100;

// parámetros para los círculos de DISOCIACIÓN
float diameter;
float angle = 0;

// parámetros para la sensación de VACÍO
float yoff = 0.0;

void setup() {
  size(600, 400, P3D); // tamaño de la ventana
  String portName = Serial.list()[1]; // selección del puerto que se utilizará
  myPort = new Serial(this, portName, 9600); // inicio de comunicación serial
  myPort.bufferUntil('\n'); // definir el término de lectura

  minim = new Minim(this);
  out = minim.getLineOut();
  osc1 = new Oscil(440, 0.5, Waves.SINE); // primera onda, sinusoidal
  osc2 = new Oscil(440, 0.5, Waves.TRIANGLE); // segunda onda, triangular
  osc1.patch(out); // conecta la primera onda al AudioOutput
  osc2.patch(out); // conecta la segunda onda al AudioOutput
  
  // geometría que representa a la ansiedad con parametros de ancho, x, y alto, y
  x = width/2;
  y = height/2;
  
  // hacer que las figuras geométricas no tengan línea de contorno
  noStroke();
  
  // parámetros de los círculos de la emoción DISOCIACIÓN
  diameter = height - 10;
  noStroke();
  fill(0, 255, 255); // color magenta
}

void draw() {

  float frecuencia1 = 0;
  float frecuencia2 = 0;

  if (val1 < 1 * 1023 / 6) { // rojo (rabia)
    frecuencia1 = map(val2, 0, 1023, 400, 480); // 400-480 Hz; mapeo los valores de frecuencia de la onda
    frecuencia2 = map(val2, 0, 1023, 120, 960); // 120-960 Hz
    osc2.setWaveform(Waves.SINE);
    osc1.setWaveform(Waves.TRIANGLE);
    drawGradientRojo();
    
  } else if (val1 < 2 * 1023 / 6) { // amarillo (ansiedad)
    background(255, 255, 0);
    frequency1 = map(val2, 0, 1023, 1000, 2000); // 1000-2000 Hz
    frequency2 = map(val2, 0, 1023, 1000, 1200); // 1000-1200 Hz
    background(255, 255, 0); // Fondo amarillo
    osc2.setWaveform(Waves.SINE);
    osc1.setWaveform(Waves.TRIANGLE);
    drawAnxiety();
    
  } else if (val1 < 3 * 1023 / 6) { // verde (estrés)
    background(0, 255, 0);
    frequency1 = map(val2, 0, 1023, 600, 700); // 600-700 Hz
    frequency2 = map(val2, 0, 1023, 1200, 1400); // 1200-1400 Hz
    background(0, 255, 0); // Fondo verde
    drawStress();
    
  } else if (val1 < 4 * 1023 / 6) { // cyan (disociación)
    background(0, 255, 255);
    frequency1 = map(val2, 0, 1023, 110, 130); // 110-130 Hz
    // frequency2 = map(val2, 0, 1023, 700, 900); // 700-900 Hz
    background(0, 255, 255); // Fondo cyan
    osc2.setWaveform(Waves.SINE);
    drawDisociacion();
    
  } else if (val1 < 5 * 1023 / 6) { // azul (sobrepensar)
    background(0, 0, 255);
    frequency1 = map(val2, 0, 1023, 200, 400); // 200-400 Hz
    frequency2 = map(val2, 0, 1023, 800, 1000); // 800-1000 Hz
    background(0, 0, 255); // Fondo azul
    drawOverthink();
    
  } else { // magenta (vacio)
    frequency1 = map(val2, 0, 1023, 120, 220); // 120-220 Hz
    // frequency2 = map(val2, 0, 1023, 400, 600); // 400-600 Hz
    background(255, 0, 255); // Fondo magenta
    osc2.setWaveform(Waves.SINE);
    drawEmpty();
  }

  osc1.setFrequency(frecuencia1); // ajusta la frecuencia de la primera onda
  osc2.setFrequency(freceuncia2); // ajusta frecuencia de la segunda onda
}

void serialEvent(Serial myPort) {
  String inString = myPort.readStringUntil('\n'); // lee la línea hasta su término para pasar a la siguiente
  if (inString != null) {
    inString = trim(inString); // eliminar espacios en blanco
    int[] vals = int(split(inString, ',')); // divide el string entregado por arduino por dos, para considerar los valores de ambos potenciometros
// esto permite que el código sepa el orden de los valores entregados
    if (vals.length == 2) { 
      val1 = vals[0];
      val2 = vals[1];
    }
  }
}

void drawGradientRojo() {
  PImage gradient = createImage(width, height, RGB);
  float frequency = 0;

  for (int i = -50; i < height + 100; i++) {
    float angle = 0;
    frequency += 0.002;
    for (float j = 0; j < width + 75; j++) {
      float py = i + sin(radians(angle)) * amplitude;
      angle += frequency;
      color c = color(abs(py - i) * 255 / amplitude, 0 - abs(py - i) * 255 / amplitude, j * (0.0 / (width + 50)));
      for (int filler = 0; filler < fillGap; filler++) {
        gradient.set(int(j - filler), int(py) - filler, c);
        gradient.set(int(j), int(py), c);
        gradient.set(int(j + filler), int(py) + filler, c);
      }
    }
  }
  set(0, 0, gradient);
}

void drawAnxiety() {
  int numPoints = int(map(val2, 0, 1023, 1, 60)); // los valores del segundo potenciometro dejan que crezca la geometría
  float angle = 0;
  float angleStep = 180.0/numPoints;
  
  fill(0);
  stroke(255,255,0);
    
  beginShape(TRIANGLE_STRIP); 
  for (int i = 0; i <= numPoints; i++) {
    float px = x + cos(radians(angle)) * outsideRadius;
    float py = y + sin(radians(angle)) * outsideRadius;
    angle += angleStep;
    vertex(px, py);
    px = x + cos(radians(angle)) * insideRadius;
    py = y + sin(radians(angle)) * insideRadius;
    vertex(px, py); 
    angle += angleStep;
  }
  endShape();
}

void drawStress() {
  background(0);
  float val = randomGaussian();
  float sd = 60;                  // definir una desviación estandar
  float mean = val2/2;           // definir un valor promedio
  float x = ( val * sd ) + mean;  // escalar en número gaussiano segun la desviación estandar

  noStroke(); // quitar contorno
  fill(0, 255, 0); // rellenar el color verde
  ellipse(x, val2/2, 32, 32); // mapeo del valor y movimiento de la elipse con 
}

void drawDisociacion() {
  background(0);
  float d1 = 10 + (sin(angle)* val2/2) + diameter/2;
  float d2 = 10 + (sin(angle + PI/2) * val2/2) + diameter/2;
  float d3 = 10 + (sin(angle + PI) * val2/2) + diameter/2;
  
  ellipse(0, height/2, d1, d1);
  ellipse(width/2, height/2, d2, d2);
  ellipse(width, height/2, d3, d3);
  
  angle += 0.02;
}

void drawOverthink() {
  defineLights();
  background(0);
  
  for (int x = 0; x <= width; x += 60) {
    for (int y = 0; y <= height; y += 60) {
      pushMatrix();
      translate(x, y);
      rotateY(map(val2, 0, width, 0, PI));
      rotateX(map(val2, 0, height, 0, PI));
      box(90);
      popMatrix();
    }
  }
}

// las luces que llegan a las figuras
void defineLights(){
  pointLight(10, 100, 200,   // color
             200, -150, 0); // posicion

  // luz celeste desde el costado
  directionalLight(0, 102, 255, // color
                   1, 0, 0);    // The x-, y-, z-axis direction

  // luz azul desde el frente
  spotLight(10, 19, 109,  // color
            0, 40, 200,     // posicion
            0, -0.5, -0.5,  // direccion
            PI / 2, 2);   
}

void drawEmpty() {
  background(40); 
  fill(75);
  
  beginShape();
  float xoff = 0;
  for (float x = 0; x <= width; x += 10) {
    // mapear los valores del ruido
    float y = map(noise(xoff, yoff), 0, 1, 200,val2/2); // ruido 2D
    // float y = map(noise(xoff), 0, 1, 200,300);    // ruido 1D
    
    // setear el vertice
    vertex(x, y); 
    // incrementar la dimension x de la onda de ruino
    xoff += 0.05;
  }
  // dimension y de la onda de ruido
  yoff += 0.01;
  vertex(width, height);
  vertex(0, height);
  endShape(CLOSE);
  
}
```
# Link video final de resultado
https://youtu.be/Z7cs1x-Pwvo

### Citas y videos utilizados
1. Manipular texto, video de referencia utilizado:
   https://www.youtube.com/watch?v=VeTNV1On34w&list=PLtyMmy0eKyqFsLPesmz7y4EznkZFJrGuu&index=138&ab_channel=AirRoom

2. Manipular caracteres:
   https://www.youtube.com/watch?v=96HVTZa4-PA&list=PLtyMmy0eKyqFsLPesmz7y4EznkZFJrGuu&index=139&ab_channel=AirRoom

3. Ejemplos de Processing:
   https://processing.org/examples/arrayobjects.html

4. Video para entender cómo traspasar datos de Arduino a Processing:
   https://www.youtube.com/watch?v=2-WI2BtO-V0&ab_channel=SergioRomeroLozano

5. Cómo utilizar Biblioteca de Minim
   https://www.youtube.com/watch?v=Jq2N8Y9NgMM&t=318s&pp=ygUfc29uaWRvcyBlbiBwcm9jZXNzaW5nIGNvbiBtaW5pbQ%3D%3D

### Futuras proyecciones
Ingresar texto para diferenciar las emociones

### Conclusiones
La idea de este proyecto es ayudar a personas a demostrar cómo se sienten, en especial con emociones negativas.
Ojala se pueda llevar a algo más grande y que ayude a las personas a gestionar sus emociones, traspasarlo a un espectro más grande.
Faltaron realizar los textos para decir textualmente qué emoción es la que se está proyectando en el momento. Esto, idealmente, se podría hacer con una interfaz física que indique en qué estado está el Potenciómetro para las emociones y su caos.
Tengo dudas de cómo seguir implementando más potenciómetros.
Falta averiguar cómo realizar mis propias animaciones para diseño más personalizado.






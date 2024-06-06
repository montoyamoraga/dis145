# Clase 13

## Tareas del día de hoy
1. Hacer que el segundo potenciómetro limite los parámetros del buzzer/zumbador para que responda a los parámetros del primer potenciometro.
2. Trasladar el código si se logra lo anterior

``` C++


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
    tone(2, 1000);
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

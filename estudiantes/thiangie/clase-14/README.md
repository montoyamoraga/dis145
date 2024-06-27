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

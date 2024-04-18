**APUNTES**: (18/abril)

**Función Aritmetica (ejemplo clases):**

float absolutFloat (float x0) {
  if (x0 < 0)
  return -x0:
} else (
  return x0;
)
)
int absolutInt (int x0)
  if (x0 < 0){
  return -x0;
  } else (

**Función Aritmetica (mio):**

SUMA:
  int suma (int v, int g){
  return v+g;
  }

RESTA:
  int resta (int v, int j){
  return v-j
  }

  Vemos que en este caso la palabra suma se puede reemplazar por cualquier frase o palabra, y en este caso al estar prigramando nosotros explicamos la funcion que queremos realizar.
cuando se trabaja en arduino se tiende a no usar palabras, sino numeros, ya que las palabras puden tener un numero de caracteres variables.
  
**Investigación de sensor (AdaFruit):** Ultrasonic Distance Sensor - 3V or 5V - HC-SR04 compatible - RCWL-1601

Programas compatibles: Arduino, CircuiPython y MakeCode
Uso: Este sensor es un dispositivo que emite ondas sonoras de alta frecuencia (ultrasonido), detectanado asi el eco que refleja un objeto, de esta forma podemos medir la distancia de objetos, detectar obstaculos, etc.

Codigo de prueba: 

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

void setup() {
Serial.begin (9600);
modo pin (trigPin, SALIDA);
pinMode(echoPin, INPUT);
modo pin (led, SALIDA);
modo de pin (led2, SALIDA);
}

void loop() {
larga duración, distancia;
digitalWrite(trigPin, LOW); // Se ha añadido esta línea
delayMicroseconds(2); // Se ha añadido esta línea
digitalWrite(trigPin, HIGH);
// delayMicroseconds(1000); - Se ha eliminado esta línea
delayMicroseconds(10); // Se ha añadido esta línea
digitalWrite(trigPin, LOW);
duración = pulseIn(echoPin, ALTO);
distancia = (duración/2) / 29.1;
if (distancia < 4) { // Aquí es donde se enciende/apaga el LED
digitalWrite(led,HIGH); // Cuando se cumpla con la condición de rojo, el LED verde debe apagarse
digitalWrite(led2,LOW);
}
de lo contrario {
digitalWrite(led,LOW);
digitalWrite(led2,HIGH);
}
if (distancia >= 200 || distancia <= 0){
Serial.println("Fuera de rango");
}
de lo contrario {
Serial.print (distancia);
Serial.println(" cm");
}
retraso (500);
}

**Investigación de sensor (AdaFruit):** Piezoelectric Ribbon Sensor - 2 feet / 600mm long

Uso: Un piezoeléctrico es un dispositivo que genera un voltaje cuando se toca o desforma, es decir por ejemplo: al doblarlo, o mediante una vibración, onda sonora o tensión mecanica, igualmente podemos crear un tono mediante este mismo, y se puede usar para reproducir tonos o para detectar tonos. 
El boceto lee la salida piezoeléctrica utilizando el comando analogRead, codificando el rango de voltaje de 0 a 5 voltios a un rango numérico de 0 a 1023 en un proceso conocido como conversión analógica a digital, o ADC.

Codigo:  los datos piezoeléctricos entrantes se comparan con un valor de umbral establecido por el usuario. Intente aumentar o bajar este valor para aumentar la sensibilidad general de su sensor.

/*
  Knock Sensor

  This sketch reads a piezo element to detect a knocking sound.
  It reads an analog pin and compares the result to a set threshold.
  If the result is greater than the threshold, it writes "knock" to the serial
  port, and toggles the LED on pin 13.

  The circuit:
	- positive connection of the piezo attached to analog in 0
	- negative connection of the piezo attached to ground
	- 1 megohm resistor attached from analog in 0 to ground


// these constants won't change:
const int ledPin = 13;       // LED connected to digital pin 13
const int knockSensor = A0;  // the piezo is connected to analog pin 0
const int threshold = 100;   // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;  // variable to store the value read from the sensor pin
int ledState = LOW;     // variable used to store the last LED status, to toggle the light

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);

  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock!");
  }
  delay(100);  // delay to avoid overloading the serial port buffer
}

**Investigación de sensor (AdaFruit):** VCNL4010 Proximity/Light sensor

Programas compatibles: Arduino y CircuiPython
Uso: Sensor de proximidad de distancias cortas (en el caso de distancias largas se recomienda usar sensor de distancia SHARP IR,). Sensor facil de usar con un microcontrolador que tenga capacidad de i2c (que un sensor tenga capacidad de i2c siginifica que  significa que puede comunicarse utilizando el protocolo de comunicación I2C (Inter-Integrated Circuit). I2C es un protocolo de comunicación serial que permite la comunicación entre varios dispositivos conectados en un bus de dos cables, uno para la transmisión de datos (SDA) y otro para la señal de reloj (SCL))

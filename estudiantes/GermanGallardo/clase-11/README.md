# clase-11
Para ocompletar mi proyecto necesitar ese dos componentes escensiales el cual será el Sensor HC-SR04 y El moto vibratorio .
el Sensor HC-SR04 es detectar la distancia que estara el componente de el cuello y asi si se supera de la distancia establecida vibrara el motor

Logre conseguir mi sensor de movimiento (Sensor HC-SR04) ahora estoy investigando como ocupar correctamente el codigo 
DistanciaSerial: Obtiene la distancia en centímetros y lo envía por el hardware serial (puede visualizar las mediciones desde el monitor serial del IDE Arduino)
Proximidad: Sensor HC-SR04 como un sensor discreto, a partir de una distancia como umbral definimos si existe presencia o no de un objeto cercano, dependiendo si la distancia es mayor o menor al umbral, activamos o apagamos una salida digital(LED)
## Imagen
  ![image](https://github.com/GermanGallardo/dis145/assets/164402341/67713a81-cd58-4f9d-9d26-d463b97063ad)
 ## codigo
 ```cpp
const int trigPin = 9;  // Pin de señal del sensor de proximidad (Trig)
const int echoPin = 10; // Pin de señal del sensor de proximidad (Echo)
const int motorPin = 6; // Pin del motor vibrador


long duration; // Variable
int distance; // Variables
void setup() {
  // Inicialización de los pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);


  Serial.begin(9600);   // Inicialización de la comunicación serial 
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);




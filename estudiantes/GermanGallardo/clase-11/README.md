# clase-11

const int trigPin = 9;  // Pin de señal del sensor de proximidad (Trig)
const int echoPin = 10; // Pin de señal del sensor de proximidad (Echo)
const int motorPin = 6; // Pin del motor vibrador

// Variables para medición de distancia
long duration;
int distance;

void setup() {
  // Inicialización de los pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);

  // Inicialización de la comunicación serial para depuración
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  ![image](https://github.com/GermanGallardo/dis145/assets/164402341/67713a81-cd58-4f9d-9d26-d463b97063ad)


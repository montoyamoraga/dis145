# clase-12

 ```cpp


// Define los pines del sensor de ultrasonidos
const int trigPin = 9;
const int echoPin = 10;

// Define el pin del motor vibrador
const int motorPin = 3;

// Define la distancia límite en cm
const int distanciaLimite = 3;

// Variables de tiempo
unsigned long previousMillis = 0;
const long interval = 100; // Intervalo de tiempo en milisegundos

void setup() {
    // Configura los pines del sensor y del motor
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(motorPin, OUTPUT);
    
    // Inicia la comunicación serie para depuración
    Serial.begin(9600);
}

void loop() {
    // Obtiene el tiempo actual
    unsigned long currentMillis = millis();
    
    // Verifica si ha pasado el intervalo de tiempo
    if (currentMillis - previousMillis >= interval) {
        // Guarda el tiempo actual
        previousMillis = currentMillis;
        
        // Variables para medir la duración y la distancia
        long duracion;
        int distancia;
        
        // Genera un pulso de 10us en el pin Trig
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        
        // Lee el pulso del pin Echo
        duracion = pulseIn(echoPin, HIGH);
        
        // Calcula la distancia en cm
        distancia = duracion * 0.034 / 2;
        
        // Imprime la distancia 
        Serial.print("Distancia: ");
        Serial.print(distancia);
        Serial.println(" cm");
        
        // Si la distancia es menor que la distancia límite, activa el motor vibrador
        if (distancia > distanciaLimite) {
            digitalWrite(motorPin, HIGH); // Activa el motor
        } else {
            digitalWrite(motorPin, LOW); // Desactiva el motor
        }
    }

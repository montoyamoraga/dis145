# Clase 4 
## Metas para hoy

1. Investigar el buzzer y sus funciones.
1. Aprender como  prenderlo y apagarlo con sensor infrarojo
1. Escribir codigo
1. Empezar a probar cambios en el codígo
1. Replantearse Objetivo de proyecto
## Avances
El Código planeado en las clases pasadas logro funcionar, eso si el motor vibrados fue remplazado por buzzer, solo debí reemplazar el buzzer por lo del motor en el Código y logro funcionar, está tomando forma el proyecto, ahora ya teniendo el Código casi listo debo tomar decisiones de la meterialidad para el funcionamiento, se me ocurre una cajita hecha a 3d que sea instalable en las sillas en vez de ser un weable quieron poner dos luces led una verde y una roja, ambas luces significaran que esta prendido el dispositivo la verde signifcaras que estas bien sentado y la roja que no, se logro el objetivo anterior y ahora pasare a pensar que en que añadir y en mi proyecto final
## Prototipo 1
Se logro lo de poner las luces, verde cuando estas cerca y no suena y rojo cuando estas lejos y suena
![image](https://github.com/GermanGallardo/dis145/assets/164402341/f372f517-3cf1-4ea0-8473-c15d3e85bf29)
## Video 


https://github.com/GermanGallardo/dis145/assets/164402341/433da728-f60a-4bec-9b7e-55a1c5660fe7
## Idea
![image](https://github.com/GermanGallardo/dis145/assets/164402341/82e029db-dcf3-455c-b487-87e88e76d913)

## Codigo
 ```cpp

// Define los pines del sensor de ultrasonidos
const int trigPin = 9;
const int echoPin = 10;

// Define el pin del buzzer
const int buzzerPin = 5;
// Define el pin del led


// Define la distancia límite en cm
const int distanciaLimite = 5;

// Variables de tiempo
unsigned long previousMillis = 0;
const long interval = 100; // Intervalo de tiempo en milisegundos

void setup() {
    // Configura los pines del sensor y del motor
      pinMode(2, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    
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
        
        // Si la distancia es menor que la distancia límite, activa el buzzer
        if (distancia > distanciaLimite) {
            digitalWrite(buzzerPin, HIGH); // Activa el buzzer
              digitalWrite (2,0); // Apaga led verde
              digitalWrite (3,1); //  prende led rojo
            
        } else {
            digitalWrite(buzzerPin, LOW); // Desactiva el buzzer
             digitalWrite (2,1); // Prende led verde
             digitalWrite (3,0); // Apaga led rojo
        }
    }
}

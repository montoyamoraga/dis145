Exámen Diseño y construcción de Interfaces
Universidad Adolfo Ibañez
S1-2024
Docente: Aaron Montoya
Ayudante: Janis Sepulveda

# ¿Qué es el proyecto?
Es un dispositivo fabricado para sillas de oficina que ayuda al usuario a mantener una postura erguida 
el dispositivo está instalado entre el cabezal y el respaldo de la silla(como se mostrara en la imagen 1), el dispositivo funciona mediante un sensor de proximidad El sensor detecta la distancia entre la espalda del usuario y el respaldo de la silla.
El dispositivos tiene dos modos:


•	Corrección de Postura: Si el usuario adopta una posición encorvada y se aleja del dispositivo, este activa un buzzer que emite un sonido molesto y enciende un LED rojo, alertando al usuario para que corrija su postura.


•	Postura Correcta: Cuando el usuario mantiene una postura correcta, la luz verde del dispositivo se enciende y el buzzer permanece en silencio, proporcionando una señal visual de que la postura es adecuada.


El dispositivo está diseñado para ayudar a los usuarios a desarrollar y mantener el hábito de una buena postura. 


## Lista de Materiales

1. Sensor hc-sr04
1. Led
2. Cables
3. Arduino R3
4.  Buzzer
5.  Resistencia 


## Imagen 1
![OBJECTOINS](https://github.com/GermanGallardo/dis145/assets/164402341/8e1ad860-4736-48a2-acbb-e493a8d31507)


## Imagen 2
![IMAGEN SILLA](https://github.com/GermanGallardo/dis145/assets/164402341/5d40c139-f70e-4d6a-9ebe-c85ce8f6e5ff)


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
```
# Proceso de fabricación 
## Linea temporal 
1. En la clase 8 comenzamos el proyecto definiendo que seria nuestro proyecto, definiendo en una frase este, cual sería nuestros materiales a conseguir y viendo referentes para nuestra idea en mi caso me faltaba un motor vibrador y el sensor. 
1. las clases 9 y 10 no asistí (o no anote) a clases sin embargo esos días me logre conseguir el sensor y el motor
1. En la clase 11 ya con mis materiales empecé a conocer el sensor y a jugar con el en tinkercad ya que descubrí que mi Arduino dejo de funcionar (yo pensaba que era mi computador  lo logre hacer funcionar pero no como yo quería, cabe destacar que en este punto mi proyecto era otro sin embargo muy similar a este ya que seria un wearable que iría pegado en la espalda 
  1. Clase 12  en esta clase pense en pedir un arduino al fablab pero lamentablemnte no tenian  asi que decidi avanzar con el codigo aprendi más como fuuncionaba el sensor como calculaba la distancia este y viendo videos de como poder entenderlo mejor esto me ayudo bastante a que la clase siguiente pudiera avanzar muy bien.
En esta clase le comente al profesor mi situación y me hizo trabajar con josefina, en su proyecto donde compartimos ideas y soluciones a ciertos problemas.
. Aparte en esta clase empecé a pensar que tal si esto era un dispositivo que se ocupaba en una silla.


1. Clase 13 Finalmente con todos mis materiales opte por cambiar la finalidad de mi proyecto 
Cambie el motor vibrador por el buzzer y empezar a probar en físico lo trabajado en clases anteriores y empezando a jugar con la distancia de sensor y el buzzer el código funciono bien, quería añadir algo final así que me decidí por led(si bien en el proyecto no resaltan mi idea es que en el proyecto final estas fueran luces más potentes cosa de que pudieran ver la luz en la pared) en esta clase estuve ayudando a Thiare con el buzzer también y empiece a imaginar como seria) haciendo un modelo 3d básico



## Fuentes Y citas
https://github.com/naylampmechatronics/Examples_HC-SR04/tree/master
https://naylampmechatronics.com/blog/10_tutorial-de-arduino-y-sensor-ultrasonico-hc-sr04.html
https://mecabot-ula.org/tutoriales/arduino/practica-30-encender-y-apagar-varios-led-dependiendo-de-la-distancia-que-mida-un-sensor-de-ultrasonido-hc-sr04/
## Conclusiones de la investigación

En conclusión el trabajo 

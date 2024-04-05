// 2024-03-28
// psegunda sesión DIS
// queremos un código en el que se pueda emular un mouse con Arduino UNO
// por thiagv, Sr.Yuyo, MarcialLeaplaza
// hecho con: Arduino UNO R3

// establecer variables

// potenciometro
const int potDer = 3;
const int potIzq = 4;

// botones
const int botDer = 8;
const int botIzq = 7;

// tiempos, se guarda para que mantenga los valores positivos
unsigned long umbralIntervalo = 500; // intervalo entre los clicks
unsigned long momentoClick = 0;

// detectores de doble click
bool unClick = false;
bool dobleClick = false;
unsigned long tiempoRebote = 0;
unsigned long delayRebote = 50;


void setup() {

  // establacer las variables como inputs

  // comenzar el lector del monitor
  Serial.begin(9600);

  // declarar potenciometro como input
  pinMode(potDer, INPUT);
  pinMode(potIzq, INPUT);

  // declarar botones como input
  pinMode(botDer, INPUT);
  pinMode(botIzq, INPUT);
}

void loop() {
  // esto es para leer si el botón está presionado o no
  int estadobotDer = digitalRead(botDer);
  int estadobotIzq = digitalRead(botIzq);

  // en el caso de que el botón derecho esté presionado se muestra en el monitor serial
  if (estadobotDer == HIGH) {
    Serial.println("Click derecho pulsado");

  }

  // si el botón izquierdo ha sido presionado
  if (estadobotIzq == HIGH) {
    tiempoRebote = millis() // se comienza a tomar el tiempo
  }

  if (millis() - tiempoRebote > delayRebote) {
    if ()
  }
  
}

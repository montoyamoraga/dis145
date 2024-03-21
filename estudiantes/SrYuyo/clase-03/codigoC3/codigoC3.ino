// Definición del pin del botón y del pin del LED
const int botonPin = 2;       

// Variable para almacenar el estado del botón
int estadoBoton;
// Variable para almacenar el estado anterior del botón
int estadoBotonAnterior = LOW;

void setup() {
  // Inicializar el pin del botón como entrada
  pinMode(botonPin, INPUT);
  // Inicializar la comunicación serial a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Leer el estado actual del botón
  estadoBoton = digitalRead(botonPin);

  // Si el botón ha sido presionado
  if (estadoBoton == HIGH && estadoBotonAnterior == LOW) {
    // Mostrar mensaje en el monitor serial
    Serial.println("boton presionado");
  }

  // Actualizar el estado anterior del botón
  estadoBotonAnterior = estadoBoton;
}


// 2024-03-21
// segunda sesión
// se quiere lograr que un botón al encenderlo que muestre por el monitor si hay click
// por thiagv y SrYuyo
// hecho con: Arduino UNO R3 (parche: 2.3.2)


// definición del pin del boton y del pin del LED
const int botonPin = 2;       

// variable para almacenar el estado del boton
int estadoBoton;
// variable para almacenar el estado anterior del boton
int estadoBotonAnterior = LOW;

void setup() {
  // inicializar el pin del boton como entrada
  pinMode(botonPin, INPUT);
  // inicializar la comunicación serial a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // leer el estado actual del boton
  estadoBoton = digitalRead(botonPin);

  // si el botón ha sido presionado
  if (estadoBoton == HIGH && estadoBotonAnterior == LOW) {
    // mostrar mensaje en el monitor serial
    Serial.println("boton presionado");
  }

  // actualizar el estado anterior del boton
  estadoBotonAnterior = estadoBoton;
}


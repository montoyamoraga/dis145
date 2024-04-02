// 2024-03-28
// codigo click derecho click izquierdo
// queremos que este código distinga entre click derecho y click izquierdo imprimiendo en la consola según corresponde la respuesta de la accion.
// por josefinasanchezr
// hecho con Arduino IDE 1.8.19
// para Arduino UNO R3

// Definimos los pines que vamos a utilizar

// Pin donde está conectado el botón izquierdo
const int pinBotonIzq = 2; 
// Pin donde está conectado el botón izquierdo
const int pinBotonDer = 4; 


void setup() {
  // Configuramos el pin del botón como entrada
  pinMode(pinBotonIzq, INPUT);
  // Inicializamos la comunicación serial para imprimir en la consola
  Serial.begin(9600);
}

void loop() {
  // Leemos el estado del botón izquierdo
  int estadoBotonIzq = digitalRead(pinBotonIzq);

  // Si el botón izquierdo está presionado
  if (estadoBotonIzq == HIGH) {
    // Imprimimos en la consola
    Serial.println("Click Izquierdo");
    // Se imprime "Click Izquierdo" cada vez que apretamos el boton siempre y cuando pasen 500 milisegundos antes
    delay(500);
  } else {
    
  }
  // Leemos el estado del botón izquierdo
  int estadoBotonDer = digitalRead(pinBotonDer);

  // Si el botón izquierdo está presionado
  if (estadoBotonDer == HIGH) {
    // Imprimimos en la consola
    Serial.println("Click Derecho");
    // Se imprime "Click Derecho" cada vez que apretamos el boton siempre y cuando pasen 500 milisegundos antes
    delay(500);
  } else {
    
  }

  
}

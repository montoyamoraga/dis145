// 2024-03-28
// codigo doble click mouse
// queremos que este código distinga si la accion pertenece o no a un doble click y lo imprima en la consola.
// por josefinasanchezr
// hecho con Arduino IDE 1.8.19
// para Arduino UNO R3

// Definimos el pin del boton
const int pinBoton = 4; 

// Variable para almacenar el tiempo del último click en el boton
unsigned long ultimoClick = 0;

void setup() {
  // Configuramos los pines del boton como entrada
  pinMode(pinBoton, INPUT);
  
  // Inicializamos la comunicación serial para imprimir en la consola "Doble Click"
  Serial.begin(9600);
}

void loop() {
  // Leemos el estado del botón derecho
  int estadoBoton = digitalRead(pinBoton);

  // Si el botón está presionado
  if (estadoBoton == HIGH) {
    unsigned long tiempoActual = millis();

    // Si el tiempo transcurrido desde el último click derecho es menor a 300ms, consideramos que es un doble click
    if (tiempoActual - ultimoClick < 300) {
      Serial.println("Doble Click");
     // Reiniciamos el tiempo del último click derecho
      ultimoClick = 0; 
    } else {
      // Actualizamos el tiempo del último click derecho
      ultimoClick = tiempoActual; 
    }

    // Esperamos un pequeño tiempo para evitar que se detecte seguido
    delay(50);
  }


}

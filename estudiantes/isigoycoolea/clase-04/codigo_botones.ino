// Definición de pines
const int buttonPin = 2;  // Pin donde está conectado el botón

// Variables de estado del botón
int buttonState = HIGH;      // Estado actual del botón
int lastButtonState = HIGH;  // Estado anterior del botón
unsigned long lastDebounceTime = 0;  // Último tiempo de rebote del botón
unsigned long debounceDelay = 50;    // Tiempo de rebote en milisegundos

// Variables para el doble click
boolean doubleClickDetected = false;
unsigned long lastClickTime = 0;
unsigned long doubleClickDelay = 250;

// Variables para el click izquierdo mantenido
boolean longClickDetected = false;
unsigned long longClickStartTime = 0;
unsigned long longClickDelay = 1000; // 1 segundos

// Inicialización del programa
void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
  pinMode(buttonPin, INPUT_PULLUP); // Configura el pin del botón como entrada con pull-up
}

// Función para detectar eventos del botón
void checkButton() {
  int reading = digitalRead(buttonPin); // Lee el estado del botón
  unsigned long currentTime = millis(); // Obtener el tiempo actual

  // Aplica el debounce al botón
  if (reading != lastButtonState) {
    lastDebounceTime = currentTime;
  }

  if ((currentTime - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      // Si se detecta un cambio de estado en el botón
      if (buttonState == LOW) { // Botón presionado
        if ((currentTime - lastClickTime) < doubleClickDelay) { // Si es un doble click
          doubleClickDetected = true;
        }
        lastClickTime = currentTime;

        // Si se detecta un click izquierdo mantenido
        longClickStartTime = currentTime; // Actualiza el tiempo de inicio del click izquierdo mantenido
        longClickDetected = true; // Indica que se está detectando un click izquierdo mantenido
      } else { // Botón liberado
        if (longClickDetected && (currentTime - longClickStartTime) >= longClickDelay) {
          Serial.println("Click izquierdo (mantenido)");
          longClickDetected = false; // Reinicia la detección del click izquierdo mantenido
        } else if (!doubleClickDetected) {
          Serial.println("Click derecho");
        }
      }
    }
  }

  lastButtonState = reading;
}

// Función principal del programa
void loop() {
  checkButton(); // Verifica el estado del botón

  // Envía información a la consola serial según el evento detectado
  if (doubleClickDetected) {
    Serial.println("Doble click detectado");
    doubleClickDetected = false; // Reinicia la detección del doble click
  }

  delay(10); // Pequeña pausa para estabilidad del programa
}

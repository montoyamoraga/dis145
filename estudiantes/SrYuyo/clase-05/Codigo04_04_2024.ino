//Codigo para encencder leds si hay luz
//Creado por Sr.Yuyo
//Placa utilizada Arduino uno R3
//04-04-2024


const int fotoresistenciaPin = A0;
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const unsigned long intervaloVerificacion = 5000; // Intervalo de verificación en milisegundos
const unsigned long tiempoMinimo = 5000; // Tiempo mínimo con luz en milisegundos
unsigned long tiempoUltimaVerificacion = 0;
unsigned long tiempoInicio = 0;

void setup() {
  pinMode(fotoresistenciaPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // Inicialmente, apaga los LEDs
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

void loop() {
  unsigned long tiempoActual = millis();

  // Verifica la existencia de luz cada 5 segundos
  if (tiempoActual - tiempoUltimaVerificacion >= intervaloVerificacion) {
    tiempoUltimaVerificacion = tiempoActual;
    if (detectarLuz()) {
      encenderLeds();
    } else {
      apagarLeds();
    }
  }

  // Mantén los LEDs encendidos si hay luz durante al menos 5 segundos
  if (detectarLuz() && tiempoActual - tiempoInicio >= tiempoMinimo) {
    encenderLeds();
  }
}

bool detectarLuz() {
  int valorLuz = analogRead(fotoresistenciaPin);
  return valorLuz > 100; // Ajustar este valor según la sensibilidad de la fotoresistencia
}

void encenderLeds() {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
}

void apagarLeds() {
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}


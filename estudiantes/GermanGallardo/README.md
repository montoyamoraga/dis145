Clase 3

![materiales](materiales.jpeg)

1. Arduino
1. Cable usb arduino
1. Protoboard
1. Resistencias
1. cables
1. Botones

```cpp
void setup() {
int x=0;
}

//Estoy intentando crear el codigo tengo todos los materiales pero tengo un problema de puerto usb para pasar el codigo arduino

//2024
// primer arduino
// queremos que este codigo prenda y apague la luz
// por GermanGallardo
// hecho por Arduino Ide 1.8.18
// para arduino 1 R3
// Definir el pin del botón
// Definir el pin del botón
const int buttonPin = 2;


// Variables para el estado del botón
int buttonState = 0;
int lastButtonState = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

// Variables contar
int clickCount = 0;
unsigned long clickTime = 0;

void setup() {
  // Inicializar el puerto serial
  Serial.begin(9600);
  // Configurar el pin del botón como entrada
  pinMode(buttonPin, INPUT);

}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
```

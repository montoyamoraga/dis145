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
const int botonPin = 2;  
int estadoBoton;         
int estadoAnterior = LOW; 

void setup() {
  pinMode(botonPin, INPUT);  
  Serial.begin(9600);        

void loop() {

  estadoBoton = digitalRead(botonPin);

  
  if (estadoBoton == HIGH && estadoAnterior == LOW) {
    
    Serial.println("Click");
  }

  
  estadoAnterior = estadoBoton;
}

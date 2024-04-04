// 2024-04-03
// codigo rueda del mouse
// haremos que el ponteciometro funcione como la rudea del mause
// por GermanGallardo
// hecho con Arduino IDE 1.8.19
// para Arduino UNO R3

//Definimos el pin del potenciometro

const int potPin = A0;
int valorAnterior = 0; 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int valorActual = analogRead(potPin); 
  
  // Se lee el valor actual del potenciómetro

  if (valorActual > valorAnterior) {
//si la perilla gira hacia la derecha marca abajo, si la perilla gira hacia la izquierda marca arriba
    Serial.println("Arriba");   } else if (valorActual < valorAnterior) {
    Serial.println("Abajo"); 
  }
 // se guarda el valor actual como valor anterior 
  valorAnterior = valorActual;
  delay(100); // 
}

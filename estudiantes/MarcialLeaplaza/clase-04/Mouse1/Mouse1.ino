//Definicion de pines.
//Potenciometros:
int pinPotIzq = A3;
int pinPotDer = A5;
//Botones para mas adelante:
int pinClickDer = 8;
int pinClickIzq = 7;
//Resolucion de pantalla para el cursor:
int pixelsX = 800;
int pixelsY = 600;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Lectura de señal de potenciometros.
  int potIzq = analogRead(pinPotIzq);
  int potDer = analogRead(pinPotDer);

  //Transformacion de lectura al tamaño de la pantalla.
  int posX = map(potIzq, 0, 1023, 0, pixelsX);
  int posY = map(potDer, 0, 1023, 0, pixelsY);

  //Imprimir en consola la posicion del cursor.
  Serial.print("Posicion del mouse: X: ");
  Serial.print(posX);
  Serial.print(", Y: ");
  Serial.println(posY);

  //Delay para dar tiempo para leer las coordenadas.
  delay(10);
}

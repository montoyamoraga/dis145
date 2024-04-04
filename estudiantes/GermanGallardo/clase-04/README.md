# PROYECTO MOUSE
_clase-04_

_2024-03-28_




## Funcionalidad Extra
![](https://github.com/GermanGallardo/dis145/blob/patch-1/estudiantes/GermanGallardo/clase-04/funcionextra.jpeg)
[rueda](./https://github.com/GermanGallardo/dis145/blob/patch-1/estudiantes/GermanGallardo/clase-04/funcionextra/funcionextra.ino)

//en esta parte del codigo haremos que el ponteciometro funcione como la rudea del mause
//definimos el pin del potenciometro

const int potPin = A0;
int valorAnterior = 0; 

void setup() {
  Serial.begin(9600); 
}

void loop() {
  int valorActual = analogRead(potPin); // Se lee el valor actual del potenciómetro

  if (valorActual > valorAnterior) {
//si la perilla gira hacia la derecha marca abajo, si la perilla gira hacia la izquierda marca arriba
    Serial.println("Arriba");   } else if (valorActual < valorAnterior) {
    Serial.println("Abajo"); 
  }
 // se guarda el valor actual como valor anterior 
  valorAnterior = valorActual;
  delay(100); // 
}



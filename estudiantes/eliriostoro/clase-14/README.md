## Avance final
----> **Expectativas de avance hoy:**
* Identificar el funcionamiento del sensor
* Poder formar el color rojo (Problematica clase anterior)
* Ver si es factible agregar un interruptor
* Comentar codigo
* Comparar calidad de trabajo con compañeros

### Proceso:

####  Identificar el funcionamiento del sensor:
 **recordatorio:**
 
* naranjo, rojo **poder**
* negro, verde, **tierra**
* azul, amarillo **señales**

  **PROBLEMATICA**
  al parecer el sensor esta leyendo mal los datos, lee segun el voltaje que le estoy dando, si le doy 3.3 lee entre 60 y 200, si le doy 5V lee entre 400 y 600, y si uso el comando: analogReference(INTERNAL); // Usar la referencia de voltaje interna lee solo 1023 :(
 **Usare 5V fijos**

* Poder formar el color rojo (Problematica clase anterior)
  **Logrado**

  ##### Codigo:
  const int microfono = A0; // Pin del sensor de micrófono
const int rojo = 9;  // Pin rojo
const int verde = 10; // Pin verde
const int azul = 11;  // Pin azul

const int numMuestras = 10; // Número de muestras para promediar
int muestras[numMuestras];   // Array para almacenar las muestras
int indiceMuestra = 0;       // Índice para las muestras

void setup() {
  pinMode(microfono, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Leer el valor del micrófono
  muestras[indiceMuestra] = analogRead(microfono);
  indiceMuestra = (indiceMuestra + 1) % numMuestras;
  
  // Calcular el promedio de las muestras
  int valorMicrofono = 0;
  for (int i = 0; i < numMuestras; i++) {
    valorMicrofono += muestras[i];
  }
  valorMicrofono /= numMuestras;
  
  // Ajustar los colores según el valor promedio
  if (valorMicrofono < 520) {
    setColor(0, 0, 255); // Verde- ruido bajo
  } else if (valorMicrofono < 550) {
    setColor(0, 255, 0); // Azul - ruido medio
  } else {
    setColor(255, 0, 0); // Rojo - ruido alto
  }
  
  Serial.println(valorMicrofono);
  
  // No usar delay() para no bloquear el loop
}

void setColor(int rojoValor, int verdeValor, int azulValor) {
  analogWrite(rojo, rojoValor);
  analogWrite(verde, verdeValor);
  analogWrite(azul, azulValor);
}




* Ver si es factible agregar un interruptor
* Comentar codigo
* Comparar calidad de trabajo con compañeros
 


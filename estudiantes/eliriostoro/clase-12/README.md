# clase-12 TRABAJO EN CASA (JUSTIFICADO)

Compra de materiales, se carga codigo a arduino pero sale un error en la salida de la consola:

El Sketch usa 2516 bytes (7%) del espacio de almacenamiento de programa. El máximo es 32256 bytes.
Las variables Globales usan 188 bytes (9%) de la memoria dinámica, dejando 1860 bytes para las variables locales. El máximo es 2048 bytes.

lamentablemente no se pueden uszar tinckercad ni wokwi porque no poseen el sensor comprado.


### Para la proxima clase cosas pendientes por hacer:
1-. soldar sensor
2-. resover falla de arduino con el profe
3-. probar codigo 

#### codigo
Lo que busca el codigo es, mediante el ruido ambiente, detectar que tan desaagradable es el ambiente, con un diodo  que tendra colores de semaforo, verde, amarillo y rojo que serian agradable, medianamente desagradable y SAL DE ESE LUGAR respectibamente

```
const int microfono = A0; // Pin del sensor de micrófono
const int rojo = 9;  // Pin rojo
const int verde = 10; // Pin verde
const int azul = 11;  // Pin azul

void setup() {
  pinMode(microfono, INPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int micValue = analogRead(microfono);

  if (micValue < 200) {
    setColor(0, 255, 0); // Verde ruido bajo
  } else if (micValue < 400) {
    setColor(255, 255, 0); // Amarillo ruido medio
  } else {
    setColor(255, 0, 0); // Rojo ruido alto
  }
  
  Serial.println(micValue);
  delay(100); 
}

void setColor(int red, int green, int blue) {
  analogWrite(rojo, red);
  analogWrite(verde, green);
  analogWrite(azul, blue);
}

```

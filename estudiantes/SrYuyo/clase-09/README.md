# clase-09

Heroes-David Bowie

# Filtrado de Datos Obtenidos de Sensores con Arduino

El filtrado de datos obtenidos de sensores conectados a una placa Arduino es un proceso crucial para mejorar la precisión y confiabilidad de las mediciones. Los sensores suelen captar ruido y variaciones indeseadas que pueden afectar la calidad de los datos. Implementar técnicas de filtrado ayuda a mitigar estos problemas y obtener lecturas más precisas.

## Técnicas Comunes de Filtrado de Datos

### Media Móvil
Consiste en promediar un conjunto de valores consecutivos para suavizar las variaciones rápidas. Este método es sencillo y efectivo para eliminar el ruido de alta frecuencia.

**Referencia**: [Arduino Moving Average Filter](https://www.arduino.cc/reference/en/libraries/movingaverage/)

```cpp
// Definición del tamaño del arreglo y variables necesarias
const int numReadings = 10;    // Número de lecturas a promediar
int readings[numReadings];     // Arreglo para almacenar las lecturas
int readIndex = 0;             // Índice para seguir la posición actual en el arreglo
int total = 0;                 // Variable para almacenar la suma total de las lecturas
int average = 0;               // Variable para almacenar el promedio calculado

void setup() {
  // Inicialización del arreglo readings con valores iniciales de 0
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // Resta la lectura más antigua del total
  total = total - readings[readIndex];
  
  // Lee el nuevo valor del sensor y lo guarda en el arreglo en la posición actual
  readings[readIndex] = analogRead(A0);
  
  // Suma el nuevo valor al total
  total = total + readings[readIndex];
  
  // Avanza al siguiente índice en el arreglo circular
  readIndex = readIndex + 1;
  
  // Si se llega al final del arreglo, vuelve al principio (circular)
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  
  // Calcula el promedio dividiendo la suma total entre el número de lecturas
  average = total / numReadings;
  
  // Aquí se utilizaría el valor promedio para realizar alguna acción o proceso adicional
  // Ejemplo: enviar el valor promedio por Serial, tomar una decisión basada en el promedio, etc.
}
```

### Filtro de Kalman
Es un algoritmo recursivo que proporciona estimaciones óptimas del estado de un sistema dinámico a partir de una serie de mediciones imprecisas. Es ideal para aplicaciones donde se requiere un alto grado de precisión.

**Referencia**: [Kalman Filter Library for Arduino](https://github.com/TKJElectronics/KalmanFilter)

```cpp
#include <SimpleKalmanFilter.h>  // Incluye la biblioteca del filtro de Kalman

SimpleKalmanFilter kalmanFilter(2, 2, 0.01);  // Crea un objeto de filtro de Kalman

void setup() {
  // Configuración inicial, no se realiza ninguna configuración en este caso
}

void loop() {
  int sensorValue = analogRead(A0);  // Lee el valor analógico del sensor conectado a A0
  float filteredValue = kalmanFilter.updateEstimate(sensorValue);  // Aplica el filtro de Kalman al valor leído
  
  // Utilizar el valor filtrado para realizar acciones adicionales
  // Por ejemplo, enviar el valor filtrado por Serial, tomar decisiones basadas en este valor, etc.
}
```

### Filtro de Mediana
Selecciona el valor medio de un conjunto de datos, eliminando valores atípicos que puedan distorsionar la lectura. Es útil para datos con picos de ruido.

**Referencia**: [MedianFilter Library](https://playground.arduino.cc/Main/MedianFilter/)

```cpp
#include <MedianFilter.h>  // Incluye la biblioteca del filtro de mediana

MedianFilter medianFilter(5, 0);  // Crea un objeto de filtro de mediana con un tamaño de ventana de 5

void setup() {
  // Configuración inicial, no se realiza ninguna configuración en este caso
}

void loop() {
  int sensorValue = analogRead(A0);  // Lee el valor analógico del sensor conectado a A0
  int filteredValue = medianFilter.AddValue(sensorValue);  // Agrega el valor leído al filtro de mediana
  
  // Utilizar el valor filtrado para realizar acciones adicionales
  // Por ejemplo, enviar el valor filtrado por Serial, tomar decisiones basadas en este valor, etc.
}

```

### Promedio Ponderado Exponencialmente (EWMA)
Asigna más peso a los datos más recientes y menos a los antiguos, proporcionando una respuesta más rápida a los cambios sin sacrificar demasiada suavidad.

**Referencia**: [Exponential Moving Average Filter in Arduino](https://www.robotshop.com/community/forum/t/using-an-exponential-moving-average-to-filter-sensor-data/13063)

```cpp
float alpha = 0.1;  // Factor de suavizado, entre 0 y 1
float filteredValue = 0;  // Valor filtrado inicializado en 0

void setup() {
  // Configuración inicial, no se realiza ninguna configuración en este caso
}

void loop() {
  int sensorValue = analogRead(A0);  // Lee el valor analógico del sensor conectado a A0
  
  // Aplica el filtro EWMA para suavizar el valor leído
  filteredValue = alpha * sensorValue + (1 - alpha) * filteredValue;
  
  // Utilizar el valor filtrado para realizar acciones adicionales
  // Por ejemplo, enviar el valor filtrado por Serial, tomar decisiones basadas en este valor, etc.
}

```

El filtro EWMA es útil cuando se desea una respuesta rápida a cambios en la señal, pero se necesita un cierto nivel de suavizado para reducir el ruido en las mediciones analógicas.

## Componentes Utilizados
Para implementar estos filtros en un proyecto de Arduino, se utilizan los siguientes componentes:

- Placa Arduino Uno R3
- Protoboard
- Cables Dupont
- Sensores específicos (ej. MQ2, DHT11, etc.), obtenidos del fablab para poder experimentar.

### Sensor MQ2 (Sensor de Gas)
```cpp
#include <MovingAverage.h>

const int gasPin = A0;  // Pin analógico donde está conectado el sensor de gas
MovingAverage<int> filter(10);  // Filtro de media móvil con ventana de 10

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios para la salida de datos
}

void loop() {
  int gasValue = analogRead(gasPin);  // Lee el valor analógico del sensor de gas
  int filteredValue = filter.add(gasValue);  // Aplica el filtro de media móvil al valor leído
  Serial.println(filteredValue);  // Imprime el valor filtrado por el puerto serial
  delay(1000);  // Espera 1 segundo antes de la próxima lectura
}

```

### Sensor DHT11 (Sensor de Humedad y Temperatura)
```cpp
#include <DHT.h>
#include <SimpleKalmanFilter.h>

#define DHTPIN 2     // Pin digital donde está conectado el sensor DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT (DHT11 en este caso)
DHT dht(DHTPIN, DHTTYPE);  // Crear instancia del sensor DHT

SimpleKalmanFilter kalmanFilter(2, 2, 0.01); // Crear filtro de Kalman con parámetros Q, R, A

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios
  dht.begin();  // Inicia el sensor DHT
}

void loop() {
  float humidity = dht.readHumidity();  // Lee la humedad desde el sensor DHT
  float temperature = dht.readTemperature();  // Lee la temperatura desde el sensor DHT

  // Aplica el filtro de Kalman a las lecturas de humedad y temperatura
  float filteredHumidity = kalmanFilter.updateEstimate(humidity);
  float filteredTemperature = kalmanFilter.updateEstimate(temperature);
  
  // Imprime las lecturas filtradas por el puerto serial
  Serial.print("Filtered Humidity: ");
  Serial.print(filteredHumidity);
  Serial.print(" %\t");
  Serial.print("Filtered Temperature: ");
  Serial.print(filteredTemperature);
  Serial.println(" *C");
  
  delay(2000);  // Espera 2 segundos antes de realizar la siguiente lectura
}

```

### Sensor Ultrasonico HC-SR04
```cpp
#include <MedianFilter.h>

#define echoPin 7    // Pin digital donde está conectado el pin de eco del sensor ultrasónico
#define trigPin 8    // Pin digital donde está conectado el pin de trigger del sensor ultrasónico

MedianFilter filter(5, 0); // Filtro de mediana con ventana de 5 elementos

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios
  pinMode(trigPin, OUTPUT);  // Configura el pin de trigger como salida
  pinMode(echoPin, INPUT);   // Configura el pin de eco como entrada
}

void loop() {
  long duration, distance;
  
  // Envía un pulso corto al pin de trigger para iniciar la medición
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Mide la duración del eco recibido y calcula la distancia en centímetros
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;  // Calcula la distancia en centímetros
  
  // Aplica el filtro de mediana a las lecturas de distancia
  int filteredDistance = filter.AddValue(distance);
  
  // Imprime la distancia filtrada por el puerto serial
  Serial.print("Filtered Distance: ");
  Serial.print(filteredDistance);
  Serial.println(" cm");
  
  delay(1000);  // Espera 1 segundo antes de realizar la siguiente lectura
}

```

### Sensor de Luz LDR
```cpp
#include <EEPROM.h>

const int ldrPin = A0;    // Pin analógico donde está conectado el LDR
float alpha = 0.5;        // Factor de suavizado para el filtro EWMA
float filteredValue = 0;  // Variable para almacenar el valor filtrado

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial a 9600 baudios
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Lee el valor analógico del sensor LDR
  
  // Aplica el filtro EWMA para suavizar las lecturas
  filteredValue = alpha * ldrValue + (1 - alpha) * filteredValue;
  
  // Imprime el valor filtrado de intensidad de luz por el puerto serial
  Serial.print("Filtered Light Intensity: ");
  Serial.println(filteredValue);
  
  delay(1000);  // Espera 1 segundo antes de realizar la siguiente lectura
}

```

## Conclusión
Implementar estos filtros en proyectos de Arduino ayuda a mejorar significativamente la precisión y fiabilidad de los datos obtenidos de sensores, lo que es crucial para aplicaciones en robótica, monitoreo ambiental, entre muchas otras. Se logra evitar el posible ruido de los datos y el no procesamiento de estos. Con esto es importante también el contexto en el cual se trabaja y para que se quiere lograr, pues si bien al utilizar esto permite que funcione de mejor manera.

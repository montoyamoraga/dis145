# clase-09

# Filtrado de Datos Obtenidos de Sensores con Arduino

El filtrado de datos obtenidos de sensores conectados a una placa Arduino es un proceso crucial para mejorar la precisión y confiabilidad de las mediciones. Los sensores suelen captar ruido y variaciones indeseadas que pueden afectar la calidad de los datos. Implementar técnicas de filtrado ayuda a mitigar estos problemas y obtener lecturas más precisas.

## Técnicas Comunes de Filtrado de Datos

### Media Móvil
Consiste en promediar un conjunto de valores consecutivos para suavizar las variaciones rápidas. Este método es sencillo y efectivo para eliminar el ruido de alta frecuencia.

**Referencia**: [Arduino Moving Average Filter](https://www.arduino.cc/reference/en/libraries/movingaverage/)

```cpp
const int numReadings = 10;
int readings[numReadings];      
int readIndex = 0;              
int total = 0;                  
int average = 0;                

void setup() {
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(A0);
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  
  average = total / numReadings;
  // Utilizar el valor promedio
}
```

### Filtro de Kalman
Es un algoritmo recursivo que proporciona estimaciones óptimas del estado de un sistema dinámico a partir de una serie de mediciones imprecisas. Es ideal para aplicaciones donde se requiere un alto grado de precisión.

**Referencia**: [Kalman Filter Library for Arduino](https://github.com/TKJElectronics/KalmanFilter)

```cpp
#include <SimpleKalmanFilter.h>

SimpleKalmanFilter kalmanFilter(2, 2, 0.01);

void setup() {
  // Configuración inicial
}

void loop() {
  int sensorValue = analogRead(A0);
  float filteredValue = kalmanFilter.updateEstimate(sensorValue);
  // Utilizar el valor filtrado
}
```

### Filtro de Mediana
Selecciona el valor medio de un conjunto de datos, eliminando valores atípicos que puedan distorsionar la lectura. Es útil para datos con picos de ruido.

**Referencia**: [MedianFilter Library](https://playground.arduino.cc/Main/MedianFilter/)

```cpp
#include <MedianFilter.h>

MedianFilter medianFilter(5, 0);

void setup() {
  // Configuración inicial
}

void loop() {
  int sensorValue = analogRead(A0);
  int filteredValue = medianFilter.AddValue(sensorValue);
  // Utilizar el valor filtrado
}
```

### Promedio Ponderado Exponencialmente (EWMA)
Asigna más peso a los datos más recientes y menos a los antiguos, proporcionando una respuesta más rápida a los cambios sin sacrificar demasiada suavidad.

**Referencia**: [Exponential Moving Average Filter in Arduino](https://www.robotshop.com/community/forum/t/using-an-exponential-moving-average-to-filter-sensor-data/13063)

```cpp
float alpha = 0.1;
float filteredValue = 0;

void setup() {
  // Configuración inicial
}

void loop() {
  int sensorValue = analogRead(A0);
  filteredValue = alpha * sensorValue + (1 - alpha) * filteredValue;
  // Utilizar el valor filtrado
}
```

## Componentes Utilizados
Para implementar estos filtros en un proyecto de Arduino, se utilizan los siguientes componentes:

- Placa Arduino Uno R3
- Protoboard
- Cables Dupont
- Sensores específicos (ej. MQ2, DHT11, etc.)

## Conclusión
Implementar estos filtros en proyectos de Arduino ayuda a mejorar significativamente la precisión y fiabilidad de los datos obtenidos de sensores, lo que es crucial para aplicaciones en robótica, monitoreo ambiental, entre muchas otras. Se logra evitar el posible ruido de los datos y el no procesamiento de estos. Con esto es importante también el contexto en el cual se trabaja y para que se quiere lograr, pues si bien al utilizar esto permite que funcione de mejor manera.


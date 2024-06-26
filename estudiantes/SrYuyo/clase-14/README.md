# Clase-14

# Proyecto de Procesamiento de Datos de Sensores con Processing y Arduino

Este proyecto muestra como crear una interfaz gráfica simple utilizando Processing para visualizar los datos de humedad, temperatura y concentración de gas obtenidos de un Arduino.

# Código de Arduino

El siguiente código de Arduino lee datos de un sensor DHT22 para la humedad y temperatura, y de un sensor MQ-2 para la concentración de gas. Los datos son enviados a través del puerto serial.

```cpp
#include <DHT.h>

#define DHTPIN 8 // Pin de datos del sensor.
#define DHTTYPE DHT22 // Tipo de sensor DHT22.

#define MQ1 (0)     // Entrada analógica para el sensor.
#define RL_VALOR (5)     // Valor de la resistencia de carga en kilo ohms.
#define RAL (9.83)  // Resistencia del sensor en el aire limpio / RO, resistencia de sensibilidad.
#define GAS_LP (0)

DHT dht(DHTPIN, DHTTYPE);

String inputstring = ""; // Cadena recibida desde el PC.
float LPCurve[3] = {2.3, 0.21, -0.47};
float Ro = 10;

float humidityArray[5] = {0}; // Arreglo para almacenar las últimas 5 lecturas de humedad.
float temperatureArray[5] = {0}; // Arreglo para almacenar las últimas 5 lecturas de temperatura.
int arrayIndex = 0; // Índice actual del arreglo.

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Iniciando ...");//Se puede quitar o dejar.

  // Configuración del sensor
  Serial.print("Calibrando...\n");
  Ro = Calibracion(MQ1); // Calibrando el sensor. Tenemos una aproximación a encierta forma a como se puede ver, esto se puede quitar
  if (Ro == 0) {
    Serial.println("Error en la calibración del sensor de gas.");
    while (true); // Detener el programa si hay un error crítico,
  }
  Serial.print("Calibración finalizada...\n");
  Serial.print("Ro=");
  Serial.print(Ro);
  Serial.print("kohm");
  Serial.print("\n");
}

void loop() {
  delay(2000);

  // Lectura de humedad y temperatura
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error en la lectura del sensor DHT22.");
    return;
  }

  // Filtrado de datos
  humidityArray[arrayIndex] = humidity;
  temperatureArray[arrayIndex] = temperature;
  arrayIndex = (arrayIndex + 1) % 5;

  float filteredHumidity = getFilteredValue(humidityArray, 5);
  float filteredTemperature = getFilteredValue(temperatureArray, 5);

  Serial.print("Humedad: ");
  Serial.print(filteredHumidity);
  Serial.print("% Temperatura: ");
  Serial.print(filteredTemperature);
  Serial.println("°C");

  // Lectura de gas
  Serial.print("LP:");
  float rs_ro_ratio = lecturaMQ(MQ1) / Ro;
  if (isnan(rs_ro_ratio)) {
    Serial.println("Error en la lectura del sensor de gas MQ-2."); //util en el caso de existir algún fallo
    return;
  }
  Serial.print(porcentaje_gas(rs_ro_ratio, GAS_LP));
  Serial.print(" ppm");
  Serial.print("    ");
  Serial.print("\n");

  delay(200); // Sacar??
}

float calc_res(int raw_adc) {
  return (((float)RL_VALOR * (1023 - raw_adc) / raw_adc));
}

float Calibracion(float mq_pin) {
  int i;
  float val = 0;
  for (i = 0; i < 50; i++) { // Tomar múltiples muestras
    val += calc_res(analogRead(mq_pin));
    delay(500);
  }
  val = val / 50; // Calcular el valor medio
  val = val / RAL;
  return val;
}

float lecturaMQ(int mq_pin) {
  int i;
  float rs = 0;
  for (i = 0; i < 5; i++) {
    rs += calc_res(analogRead(mq_pin));
    delay(50);
  }
  rs = rs / 5;
  return rs;
}

int porcentaje_gas(float rs_ro_ratio, int gas_id) {
  if (gas_id == GAS_LP) {
    return porcentaje_gas(rs_ro_ratio, LPCurve);
  }
  return 0;
}

int porcentaje_gas(float rs_ro_ratio, float *pcurve) {
  return (pow(10, (((log(rs_ro_ratio) - pcurve[1]) / pcurve[2]) + pcurve[0])));
}

float getFilteredValue(float *arr, int length) {
  float sum = 0;
  for (int i = 0; i < length; i++) {
    sum += arr[i];
  }
  return sum / length;
}
```

**Codigo Processing**

El siguiente código de Processing crea una interfaz gráfica para mostrar los datos de humedad, temperatura y concentración de gas enviados desde el Arduino.

```java
import processing.serial.*;

Serial myPort;
String dataString = "";
float humidity = 0;
float temperature = 0;
int gas = 0;

void setup() {
  size(400, 300);
  println(Serial.list()); // Listar los puertos seriales disponibles, en mi caso MQ5
  myPort = new Serial(this, Serial.list()[0], 9600); // Ajustar el índice según el puerto usado
  myPort.bufferUntil('\n'); // Lectura hasta el fin de línea
}

void draw() {
  background(255);
  fill(0);
  textSize(20);
  textAlign(CENTER);

  // Mostrar los valores de los sensores
  text("Lecturas de los Sensores", width/2, 40);
  text("Humedad: " + nf(humidity, 1, 2) + "%", width/2, 100);
  text("Temperatura: " + nf(temperature, 1, 2) + "°C", width/2, 140);
  text("Concentración de Gas: " + gas + " ppm", width/2, 180);
}

void serialEvent(Serial myPort) {
  dataString = myPort.readStringUntil('\n');
  dataString = trim(dataString);

  // Separar la cadena de datos recibidos
  String[] data = split(dataString, ' ');

  if (data.length == 3) {
    humidity = float(data[0]);
    temperature = float(data[1]);
    gas = int(data[2]);
  }
}
```

# **REQUISITOS**

Arduino UNO R3 o superior con sensores DHT22 y MQ-2 conectados.
Entorno de desarrollo de Arduino.
Entorno de desarrollo de Processing.
Cable USB para conectar el Arduino a la computadora.


# **OBSERVACIONES**

Es bueno verificar de que los sensores estén correctamente conectados al Arduino (utilizar cables dupont ideal) y de que el código de Arduino esté funcionando correctamente (analizar en la interfaz de arduino) antes de ejecutar el código de Processing.
El índice del puerto serial en Processing puede variar según el sistema y la configuración.
El código de Processing incluye un filtrado básico de los datos para suavizar las lecturas de los sensores.


# Referencias

1. **Biblioteca DHT para Arduino**:
   - [GitHub - Adafruit DHT library](https://github.com/adafruit/DHT-sensor-library)
   - Documentación de la biblioteca DHT utilizada para leer datos del sensor DHT22.

2. **Sensor MQ-2**:
   - [MQ-2 Gas Sensor Datasheet](https://www.sparkfun.com/datasheets/Sensors/Biometric/MQ-2.pdf)
   - Hoja de datos del sensor MQ-2 para obtener información técnica sobre el sensor de gas.

3. **Processing**:
   - [Processing.org](https://processing.org/)
   - Sitio web oficial de Processing con documentación y tutoriales.

4. **Comunicación Serial entre Arduino y Processing**:
   - [Arduino to Processing Serial Communication](https://processing.org/tutorials/electronics/)
   - Tutorial de Processing sobre cómo establecer la comunicación serial entre Arduino y Processing.

5. **Documentación de Arduino**:
   - [Arduino Reference](https://www.arduino.cc/reference/en/)
   - Referencia oficial de Arduino con ejemplos y documentación sobre las funciones utilizadas en el código.

6. **Filtrado de Datos**:
   - Artículo sobre técnicas de filtrado de datos para sensores:
     - [Simple and Robust Techniques for Sensor Data Filtering](https://www.digikey.com/en/articles/simple-and-robust-techniques-for-sensor-data-filtering)
   - Discusión sobre métodos de filtrado para obtener lecturas más precisas de los sensores.

# Recursos Adicionales

1. **Editor de Arduino**:
   - [Arduino IDE](https://www.arduino.cc/en/software)
   - Editor utilizado para cargar el código en la placa Arduino.

2. **Editor de Processing**:
   - [Processing IDE](https://processing.org/download/)
   - Editor utilizado para desarrollar y ejecutar el código de Processing.

3. **Ejemplos y Proyectos**:
   - [Arduino Project Hub](https://create.arduino.cc/projecthub)
   - Repositorio de proyectos de Arduino que pueden servir como inspiración para proyectos adicionales.

4. **GitHub Documentation - Basic Writing and Formatting Syntax**:
   - [GitHub Docs: Basic Writing and Formatting Syntax](https://docs.github.com/es/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
   - Guía oficial de GitHub sobre cómo empezar a escribir y formatear en GitHub, incluyendo la sintaxis básica de escritura y formateo.


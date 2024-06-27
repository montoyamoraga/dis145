# clase-12

**AC/DC - You Shook Me All Night Long**


Presentación de las iteraciones del código para el proyecto del ramo. Todas los códigos fueron realizados mediante una placa arduino uno R3 V 2.3.2.

Codigo para el sensor dht22
```cpp
#include <DHT.h>
#define DHTPIN 8 // Pin de datos del sensor
#define DHTTYPE DHT22 // Tipo de sensor DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
dht.begin();
}

void loop() {
delay(2000);

float humidity = dht.readHumidity();
float temperature = dht.readTemperature();

if (isnan(humidity) || isnan(temperature)) {
Serial.println("Error");// si hay problemas en la lectura
return;
}

Serial.print("Humedad: ");
Serial.print(humidity);
Serial.print("% Temperatura: ");
Serial.print(temperature);
Serial.println("°C");
}
```

Primera iteración del sensor MQ-2

```cpp
int A;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  A = analogRead(A0);
  Serial.println(A);

}
```

Segunda iteración con un filtrado de los datos
```cpp
#define         MQ1                       (0)     //entrada analogica para el sensor
#define         RL_VALOR             (5)     //valor de la resistencia mde carga en kilo ohms
#define         RAL       (9.83)  //resistencia del sensor en el aire limpio / RO, resistencia de sensibilidad
#define         GAS_LP                      (0)
String inputstring = "";                                                        //Cadena recibida desde el PC
float           LPCurve[3]  =  {2.3,0.21,-0.47};
float           Ro           =  10;
void setup(){
Serial.begin(9600);                                                                  //Inicializa Serial a 9600 y le agregamos suspenso
 Serial.println("Iniciando ...");
   //configuracion del sensor
  Serial.print("Calibrando...\n");
  Ro = Calibracion(MQ1);                        //Calibrando el sensor.
  Serial.print("Calibracion finalizada...\n");
  Serial.print("Ro=");
  Serial.print(Ro);
  Serial.print("kohm");
  Serial.print("\n");
}
 
void loop()
{
   Serial.print("LP:");
   Serial.print(porcentaje_gas(lecturaMQ(MQ1)/Ro,GAS_LP) );
   Serial.print( "ppm" );
   Serial.print("    ");
   Serial.print("\n");
   delay(200); //sacar??
}
 
float calc_res(int raw_adc)
{
  return ( ((float)RL_VALOR*(1023-raw_adc)/raw_adc));
}
 
float Calibracion(float mq_pin){
  int i;
  float val=0;
    for (i=0;i<50;i++) {                                                                               //tomar múltiples muestras
    val += calc_res(analogRead(mq_pin));
    delay(500);
  }
  val = val/50;                                                                                         //calcular el valor medio
  val = val/RAL;
  return val;
}
 
float lecturaMQ(int mq_pin){
  int i;
  float rs=0;
  for (i=0;i<5;i++) {
    rs += calc_res(analogRead(mq_pin));
    delay(50);
  }
rs = rs/5;
return rs;
}
 
int porcentaje_gas(float rs_ro_ratio, int gas_id){
   if ( gas_id == GAS_LP ) {
     return porcentaje_gas(rs_ro_ratio,LPCurve);
   }
  return 0;
}
 
int porcentaje_gas(float rs_ro_ratio, float *pcurve){
  return (pow(10, (((log(rs_ro_ratio)-pcurve[1])/pcurve[2]) + pcurve[0])));
}
```

Combinación entre ambos códigos V1:

```cpp
#include <DHT.h>

#define DHTPIN 8 // Pin de datos del sensor
#define DHTTYPE DHT22 // Tipo de sensor DHT22

#define MQ1 (0)     // Entrada analógica para el sensor
#define RL_VALOR (5)     // Valor de la resistencia de carga en kilo ohms
#define RAL (9.83)  // Resistencia del sensor en el aire limpio / RO, resistencia de sensibilidad
#define GAS_LP (0)

DHT dht(DHTPIN, DHTTYPE);

String inputstring = ""; // Cadena recibida desde el PC
float LPCurve[3] = {2.3, 0.21, -0.47};
float Ro = 10;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Iniciando ...");

  // Configuración del sensor
  Serial.print("Calibrando...\n");
  Ro = Calibracion(MQ1); // Calibrando el sensor.
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
    Serial.println("Error"); // Si hay problemas en la lectura
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(humidity);
  Serial.print("% Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Lectura de gas
  Serial.print("LP:");
  Serial.print(porcentaje_gas(lecturaMQ(MQ1) / Ro, GAS_LP));
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

```

Combinación entre ambos códigos V2:
```cpp
#include <DHT.h>

#define DHTPIN 8 // Pin de datos del sensor
#define DHTTYPE DHT22 // Tipo de sensor DHT22

#define MQ1 (0)     // Entrada analógica para el sensor
#define RL_VALOR (5)     // Valor de la resistencia de carga en kilo ohms
#define RAL (9.83)  // Resistencia del sensor en el aire limpio / RO, resistencia de sensibilidad
#define GAS_LP (0)

DHT dht(DHTPIN, DHTTYPE);

String inputstring = ""; // Cadena recibida desde el PC
float LPCurve[3] = {2.3, 0.21, -0.47};
float Ro = 10;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Iniciando ...");

  // Configuración del sensor
  Serial.print("Calibrando...\n");
  Ro = Calibracion(MQ1); // Calibrando el sensor.
  if (Ro == 0) {
    Serial.println("Error en la calibración del sensor de gas.");
    while (true); // Detener el programa si hay un error crítico
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

  Serial.print("Humedad: ");
  Serial.print(humidity);
  Serial.print("% Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Lectura de gas
  Serial.print("LP:");
  float rs_ro_ratio = lecturaMQ(MQ1) / Ro;
  if (isnan(rs_ro_ratio)) {
    Serial.println("Error en la lectura del sensor de gas MQ-2.");
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

````

En este código, se han agregado verificaciones de errores después de cada lectura de sensor. Si se detecta un error en la lectura del sensor DHT22 o MQ-2, se imprime un mensaje de error en el puerto serie. Si hay un error crítico durante la calibración del sensor MQ-2, el programa se detiene con un bucle infinito while(true).


Combinación entre ambos códigos V3:

```cpp
#include <DHT.h>

#define DHTPIN 8 // Pin de datos del sensor
#define DHTTYPE DHT22 // Tipo de sensor DHT22

#define MQ1 (0)     // Entrada analógica para el sensor
#define RL_VALOR (5)     // Valor de la resistencia de carga en kilo ohms
#define RAL (9.83)  // Resistencia del sensor en el aire limpio / RO, resistencia de sensibilidad
#define GAS_LP (0)

DHT dht(DHTPIN, DHTTYPE);

String inputstring = ""; // Cadena recibida desde el PC
float LPCurve[3] = {2.3, 0.21, -0.47};
float Ro = 10;

float humidityArray[5] = {0}; // Arreglo para almacenar las últimas 5 lecturas de humedad
float temperatureArray[5] = {0}; // Arreglo para almacenar las últimas 5 lecturas de temperatura
int arrayIndex = 0; // Índice actual del arreglo

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Iniciando ...");

  // Configuración del sensor
  Serial.print("Calibrando...\n");
  Ro = Calibracion(MQ1); // Calibrando el sensor.
  if (Ro == 0) {
    Serial.println("Error en la calibración del sensor de gas.");
    while (true); // Detener el programa si hay un error crítico
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
    Serial.println("Error en la lectura del sensor de gas MQ-2.");
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

En este código, se almacenan las últimas 5 lecturas de humedad y temperatura en arreglos y se calcula el promedio de estos valores para obtener el valor filtrado. Este enfoque proporciona una manera simple de suavizar las lecturas y reducir el ruido en los datos.


Referencias:

<https://learn.adafruit.com/dht>
<https://learn.adafruit.com/modern-replacements-for-dht11-dht22-sensors>
<https://learn.adafruit.com/gas-sensor-comparison>
<https://learn.sparkfun.com/tutorials/rht03-dht22-humidity-and-temperature-sensor-hookup-guide>
<https://www.instructables.com/How-to-Detect-Concentration-of-Gas-by-Using-MQ2-Se/>
<https://www.instructables.com/MQ2-Shield-on-pcDuino/>
<https://www.instructables.com/IOT123-I2C-MQ2-BRICK/>
<https://www.instructables.com/How-to-use-MQ2-Gas-Sensor-Arduino-Tutorial/>

![image](https://github.com/SrYuyo/dis145/assets/103392227/9ab00bb2-3d3f-4fff-b4ff-e0c978a3e850)

![image](https://github.com/SrYuyo/dis145/assets/103392227/1514e83d-4066-4162-a398-ec15bc371a05)

![image](https://github.com/SrYuyo/dis145/assets/103392227/07b629ac-d4c6-4adc-ac4f-90a48ab5415c)

![image](https://github.com/SrYuyo/dis145/assets/103392227/f5aa2569-764f-4484-afa2-031bb5b74715)

![image](https://github.com/SrYuyo/dis145/assets/103392227/73da6a6f-71ad-4d74-8dbd-2be888f59c43)







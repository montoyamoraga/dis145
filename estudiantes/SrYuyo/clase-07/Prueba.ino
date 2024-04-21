#include <DHT.h>//biblioteca necesaria sensor de humedad, instalalar drivers

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int red_led = 12;  // Indica gas
int green_led = 13;  // Indica normal
int smokeA0 = A0;  // Sensor conectado a A5
int sensorThres = 300;  // Valor umbral del sensor de gas

//seteo
void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  int gas_value = analogRead(smokeA0);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");//los errores se pueden deber a los cables
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");

//Outputs Arduino
  if (gas_value > sensorThres) {
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, LOW);
    Serial.println("Descompuesto");
  } 
  
  else {
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, HIGH);
    Serial.println("Buen estado");
  }

  delay(100);//tiempo de espera de datos
}


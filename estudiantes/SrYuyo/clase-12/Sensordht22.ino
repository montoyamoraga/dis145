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
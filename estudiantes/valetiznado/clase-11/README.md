<img width="1147" alt="Captura de Pantalla 2024-05-29 a la(s) 15 51 50" src="https://github.com/valetiznado/dis145/assets/164402604/a188232a-dfdc-48a0-aaef-873a1c22d15c">APUNTES: (23/mayo)

Proyecto Arduino - Smart Parking Lot System

Con todos los materiales conseguidos empece a trabajar en como enviar información desde ESP32 via WIFI.

Se debe descargar un controlador para CP2102
https://www.pololu.com/docs/0J7/all#3

En esta clase deje el controlador descargado en el computador, pero no pude actualizarlo en la placa ya que esta no venia con el cable correspondiente por lo que no la pude conectar al computador. Igualmente deje en Arduino IDE el URL correspondiente para gestionar la placa el URL usado es el siguiente: https://espressif.github.io/arduino-esp32/package_esp32_index.json. En el gestor de placas de Arduino también deje instalado el ESP32. Por lo que, en esta clase en conjunto con ayuda del profesor y la ayudante logre visualizar el codigo en arduino. Algunos de los ejemplos que estuve investigando en clases fueron los siguentes; 

- Ejemplos Arduino NANO 33 IOT
- Ejemplo “Send Data from ESP32 to Processing via WIFI”; https://stackoverflow.com/questions/56792427/send-data-from-esp32-to-processing-via-wifi
- Ejemplo Jani; https://github.com/janisepulveda/dis9029/blob/main/solemne02/WiFiWebCliente/WiFiWebCliente.ino

Los siguientes ejemplos son de gran ayuda ya que me permiten tener una guia para saber como configurar mi tarjeta de desarrollo ESP32, si bien en los apuntes de esta clase son un poco breves, es porque la gran mayoria del tiempo estuve trabajando con Arduino y e instalando el controlador para este mismo, considero que fue una de las clases con mas avance para mi proyecto ya que se pudieron concretar varios puntos importantes del proyecto


Codigo ESP32 

#include <WiFi.h>

const char* ssid = "myNetwork";
const char* pass = "myPassword";

void setup()
{
    Serial.begin(115200);
    delay(10);
    WiFi.begin(ssid,pass);

    Serial.print("Connecting.");
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.print("WiFi connected - IP address: ");
    Serial.println(WiFi.localIP());
    delay(500);
}

void loop()
{
    const uint16_t port = 5204;
    const char * host = "10.0.26.xx";

    Serial.print("Connecting to ");
    Serial.println(host);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;

    if (client.connect(host, port)){
      Serial.println("Sending data"); // printed on serial monitor
      client.print("Hello");
    }

    // This will send a request to the server
    client.print("Send this data to the server");

    Serial.println("Closing connection.");
    client.stop();
}

Codigo en Arduino


<img width="1147" alt="Captura de Pantalla 2024-05-29 a la(s) 15 51 50" src="https://github.com/valetiznado/dis145/assets/164402604/a5553628-bd1e-4e21-8a17-52cadaf4c9b8">

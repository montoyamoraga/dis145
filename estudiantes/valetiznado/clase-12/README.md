**APUNTES: (30/mayo)**

Servidor es el que construye la base de datos t el cliente es el que le pregunta a la base de datos, en este caso ESP32 es el servidor que se conecta al Hotspot de mi celular en este caso y al conectarse el WIFI están siempre conectanose y este es el que me dará una dirección IP. Y el cliente tienen la misma dirección IP que es al que me entrega el modulo ESP32 y le pregunta al servidor cuales son los datos del sensor, mientras el servidor esta haciendo lecturas constantemente del sensor.

Codigo trabajado en clases:

/*
 WiFi Web Server LED Blink

 A simple web server that lets you blink an LED via the web.
 This sketch will print the IP address of your WiFi Shield (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to turn on and off the LED on pin 5.

 If the IP address of your shield is yourAddress:
 http://yourAddress/H turns the LED on
 http://yourAddress/L turns it off

 This example is written for a network using WPA2 encryption. For insecure
 WEP or WPA, change the Wifi.begin() call and use Wifi.setMinSecurity() accordingly.

 Circuit:
 * WiFi shield attached
 * LED attached to pin 5

 created for arduino 25 Nov 2012
 by Tom Igoe

ported for sparkfun esp32 
31.01.2017 by Jan Hendrik Berlin
 
 */

#include <WiFi.h>

const char* ssid     = "Valetiznado";
const char* password = "holahola";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    pinMode(5, OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(5, HIGH);               // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(5, LOW);                // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}


￼
Cuando me sale Connecting debo apagar mi Hotspot (wifi) y volver a prenderlo.

Pasos a seguir;

- [x] Sensor conectado a Arduino
- [x] Procesar estos datos
- [x] Y subir estos datos a mi ESP32
- [ ] Demostrar que somos capaces de usar el computador como cliente para leer los datos que están en el servidor
￼

Para cargar esto es importante apretar el Serial Monitor
(Esta dirección IP va a ir cambiando)

172.20.10.12:80

Cuando buscamos la dirección y le agregamos :80 lo que estamos haciendo es que deseamos conectarnos a esta dirección IP mediante el puerto 80, este puerto es un punto de acceso lógico a una maquina la cual me permite que los servicios y aplicaciones se comuniquen mediante una red. Este puerto es estándar para el trafico HTTP, en este caso lo que se esta haciendo es establecer una conexión HTTP con el servidor de esa dirección IP.

Igualmente lo que se hizo despues fue agregar el sensor ultrasónico HC-SR04 al mismo código que estábamos trabajando, para esto trabaje con la información de la siguiente pagina; https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1

**Código HC-SR04 (continuación)**

//Conexión de los pines Trig y Echo

const int trigPin = 33; 
const int echoPin = 32;



//Declaración de duración y distancia

float duration, distance;  

//Declaración del pin Trig como salida y el Echo como entrada

void setup() { 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
} 

void loop() { 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigPin, LOW); 

duration = pulseIn(echoPin, HIGH); 

distance = (duration*.0343)/2; 

Serial.print("Distance: "); 
Serial.println(distance); 
delay(100); 
} 


**Otra de las paginas con las que se trabajo en la clase fue la siguiente:** https://randomnerdtutorials.com/esp32-client-server-wi-fi/
  

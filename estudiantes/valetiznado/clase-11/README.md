APUNTES: (23/mayo)

Proyecto Arduino - Smart Parking Lot System

Con todos los materiales conseguidos empece a trabajar en como enviar información desde ESP32 via WIFI.

Se debe descargar un controlador para CP2102
https://www.pololu.com/docs/0J7/all#3

En esta clase deje el controlador descargado en el computador, pero no pude actualizarlo en la placa ya que esta no venia con el cable correspondiente por lo que no la pude conectar al computador. Igualmente deje en Arduino IDE el URL correspondiente para gestionar la placa el URL usado es el siguiente: https://espressif.github.io/arduino-esp32/package_esp32_index.json. En el gestor de placas de Arduino también deje instalado el ESP32. Por lo que, en esta clase en conjunto con ayuda del profesor y la ayudante logre visualizar el codigo en arduino. Algunos de los ejemplos que estuve investigando en clases fueron los siguentes; 

- Ejemplos Arduino NANO 33 IOT
- Ejemplo “Send Data from ESP32 to Processing via WIFI”; https://stackoverflow.com/questions/56792427/send-data-from-esp32-to-processing-via-wifi
- Ejemplo Jani; https://github.com/janisepulveda/dis9029/blob/main/solemne02/WiFiWebCliente/WiFiWebCliente.ino

Los siguientes ejemplos son de gran ayuda ya que me permiten tener una guia para saber como configurar mi tarjeta de desarrollo ESP32, si bien en los apuntes de esta clase son un poco breves, es porque la gran mayoria del tiempo estuve trabajando con Arduino y e instalando el controlador para este mismo, considero que fue una de las clases con mas avance para mi proyecto ya que se pudieron concretar varios puntos importantes del proyecto

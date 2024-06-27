* Definición de la temática de investigación:

Reducción del tiempo de búsqueda de estacionamiento mediante un sistema inteligente con Arduino. Este sistema recopilará información en tiempo real sobre la disponibilidad de espacios de estacionamiento a través de sensores de movimiento. La información captada se transmitirá a través de un sistema de comunicación que puede ser Wifi o Bluetooth, facilitando a los conductores la localización de espacios libres de manera rápida y eficiente.

Este proyecto lo que hace mediante un código configurar un sistema de estacionamiento inteligente usando un sensor ultrasónico y una conexión WiFi. La conexión WiFi en este sistema de estacionamiento inteligente, permite enviar los datos del sensor ultrasónico a una red, facilitando el monitoreo remoto de los espacios de estacionamiento. 

En este sistema:

* El servidor es el dispositivo con el sensor ultrasónico: Este dispositivo mide la distancia y aloja una página web para mostrar los datos. Actúa como servidor porque ofrece información a otros dispositivos a través de la red WiFi.

* El cliente es cualquier dispositivo que se conecta al servidor para ver los datos: Por ejemplo, un teléfono, una tablet o una computadora que accede a la página web alojada por el servidor. Actúa como cliente porque solicita y recibe información del servidor.



* Linea del tiempo:


Semana 8 (25 de abril)
Se eligió el proyecto "Smart Parking Lot System". Se investigaron y definieron materiales disponibles y viables. Se exploraron posibles sistemas como Raspberry Pi y Arduino Nano 33 IoT. Se establecieron los objetivos del proyecto.

Semana 9 (2 de mayo)
No hubo avances significativos (semana de pausa)

Semana 10 (16 de mayo)
Se compraron una tarjeta de desarrollo ESP32 y dos sensores HC-SR04. Se decidió usar Arduino UNO R4 mínima por su potencia y tolerancia de voltaje.

Semana 11 (23 de mayo)
Se descargaron controladores y se configuró Arduino IDE para ESP32. Se instaló el gestor de placas y se visualizó el código en Arduino.

Semana 12 (30 de mayo)
Se entendió la comunicación servidor-cliente con ESP32. Se avanzó en los códigos para conectar el sensor a Arduino y procesar los datos en ESP32.

Semana 13 (6 de junio)
Se revisaron trabajos de compañeros y se investigó la transmisión inalámbrica al computador. Se finalizó el código del sensor y se cambió ESP32 por Arduino Nano 33 IoT.



* Fuentes y citas:

- https://randomnerdtutorials.com/esp32-client-server-wi-fi/
- https://stackoverflow.com/questions/56792427/send-data-from-esp32-to-processing-via-wifi
- https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
- https://stackoverflow.com/questions/56792427/send-data-from-esp32-to-processing-via-wifi

* Conclusión de la investigación:

A lo largo del desarrollo del proyecto vemos que algunos de los aspectos positivos fueron: la elección y la definición del proyecto en si mismo el cual es un proyecto relevante, enfocado en la optimización del tiempo de búsqueda de estacionamiento, ademas del avance progresivo del proyecto a lo largo de las semanas, en cuanto a los aspectos que se podrían haber hecho de mejor forma fue que en las semanas de pausa  o donde no hubo clases, no se registraron avances significativos, los cuales se podrían haber aprovechado de mejor forma para avanzar en el proyecto, por otro lado el hecho de que inicialmente elegí el ESP32 para la transmisión de los datos que me llevaron a tener que usar el Arduino Nano 33 IoT, lo cual causo retrasos, por lo que en este punto lo que se podria haber hecho es investigar mas y a mas profundidad sobre la transmisión de datos. Actualmente las dudas que tengo son; ¿Cómo se comportará el sistema en términos de fiabilidad y mantenimiento a largo plazo? y ¿Qué tan fácilmente se puede escalar este sistema para grandes estacionamientos o múltiples ubicaciones?. Por ultimo, en cuanto a la influencia de este trabajo en mi practica de diseño son; la importancia de una investigación preliminar exhaustiva y la flexibilidad en la elección de componentes. Aprendí a manejar mejor los tiempos y a adaptarme a los cambios necesarios durante el desarrollo del proyecto. Además, comprendí la importancia de la integración de sistemas de hardware y software, y cómo pueden influir en la experiencia del usuario final. Esta experiencia ha mejorado mis habilidades en el diseño de soluciones tecnológicas prácticas y eficientes.

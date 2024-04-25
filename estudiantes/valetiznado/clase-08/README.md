APUNTES: (25/abril)

**Proyecto Arduino - Smart Parking Lot System**


**Materiales (conseguir):**

- MKR Family Arduino (todos, evaluar)
- Arduino UNO Wifi Rev2
- Arduino UNO R4 Wifi
- Lector RFID: permite identificar objetos mediante ondas de radio
- Ultrasonic Ranger HC-SR04
- Resistencia dependiente de la luz / Fotorresistor (LDR)
- Pantalla LCD (opcional, evaluar)
- Raspbian (evaluar)
- Cable UTP (evaluar)
- Sensor IR (evaluar)
- Lector/sensor RFID (evaluar)
- Tarjeta de Identificación RFID (evaluar)
- Arduino Ethernet Shield (evaluar)

**Materiales Preliminares:**

- Dos monitores (uno de entrada y otro de salida)
- LED
- Cables de puente
- Breadboard

**Softwares preliminares:**

- Raspberry Pi: Para la posible automatización, en este caso de la llegada de información que nos proporciona nuestro sensor. El cual ademas sirve como un sistema básico de escritorio, pudiendo en este caso procesar la información. Después de la evaluación me di cuenta que en este caso no es necesario, ya que para el desarrollo del proyecto seria complejizarlo mucho mas.
- Sistema basado en IOT: La idea de esto es para poder hacer una red colectiva de dispositivos conectados, según mi investigación hay placas de Arduino las cuales tienen este sistema incluido, como por ejemplo el caso de una que esta dentro de las Nano Family que se llama Arduino Nano 33 loT, para este paso es importante en mi caso hacer una investigación mas profunda para poder determinar cual será la polaca mas adecuada para el proyecto. Por otro lado, lo que entendí de el termino loT es que esta conectado a Internet y no a Bluetooth (por favor corregirme si no estoy en lo correcto)

**Objetivo:** Reducir el tiempo que se pierde buscando estacionamiento, mediante el uso de Arduino, el cual captara la información mediante un sensor de movimiento y posteriormente reenviara esta misma mediante un sistema de inteligencia que puede ser Wifi o Bluetooth. Por otro lado quiero evaluar la posibilidad de complementar esto mismo mediante la aplicación de una luz LED, el cual puede ser un sistema de iluminación automatice

**Explicación en una frase:** Optimizar búsqueda de estacionamiento con Arduino mediante un sensor


**Información adicional (investigación):**

Programar el sensor RFID: (buscar información)

- Un punto importante es decidir cual será el sensor mas adecuado para el proyecto, ya que, como se puede ver en l lista de materiales para conseguir hay varios tipos de sensores, por esto mismo es que entre paréntesis les he puesto evaluar, porque todavía no decido cual será el mas indicado para este proyecto
- Según mi investigación si se quiere usar tarjetas RFID se puede hacer mediante el programa de Python, permitiendo así que el programa autentique las tarjetas RF-ID.
  
- Arduino Ethernet Shield, este dispositivo lo que hace es permitir que una placa de Ardino pueda conectarse a internet, esta basado en un chip Ethernet Wiznet W5100, el cual es compatible con Arduino Uno cuando se hacer uso de la librería de Ethernet, lo que me quedo duda de este dispositivo es que al parecer no es inalámbrico, por lo que es necesario que se tenga un cable de Ethernet conectado para que funcione (por favor corregirme si no estoy en lo correcto, o si existe la posibilidad de conectar este dispositivo mediante conexión inalámbrica)


**Hashtags:**

#sensor #smartparkinglot #arduinodiy #parksmartwitharduino #techparkingsolutions 


# Proyecto Final

<sub> Entrega Final

<sub> Diseño y Construcción de Interfaces

<sub> Fecha: Jueves 27/06/2024

### Contenido

 1. Definición de la temática de investigación

 2. Imágenes y dibujos explicativos

 3. Línea temporal sobre bitácora 

 4. Conclusiones de la investigación 

 5. Referentes de la investigación 




   

## 1. Definición de la temática de investigación:
El proyecto consiste en la creación de un mecanismo de alimentación para mascotas que sea controlable por ellos mismos. 

## 1.1 _¿Cómo funcionará?_

El sistema usará un lector RFID de tipo llavero, este se encargará de detectar cuando la mascota se acerque a su plato de comida. Luego se comunicará con un servomotor, el cual girará únicamente cuando detecte la presencia de la tarjeta. Se deberá configurar ángulo de giro y tiempos.

## 1.2 _Motivación del proyecto_

La idea nace pensando en mis gatos (2). Ellos son mañosos y solo toman agua directamente de la llave, no en bebedor ni en su pote. Por esto creí que hacer un sistema en el que ellos activen y regulen lo que consumen sería óptimo. Para efectos de este ejercicio se prueba con alimentos y no bebestibles.


## 2. Imágenes y dibujos explicativos

A continuación se muestra la idea inicial y los bosquejos. Esto es lo que se desea lograr.

![representacion_idea](https://github.com/nicolebech/dis145/assets/164402586/dcf4d5dc-48e6-423c-bf9c-c50aef22cecd)
_Fotomontaje hecho en Adobe Firefly_


### Materiales
- Arduino
- Cables
- Lector RFID
- Servomotor
  
![materialess](https://github.com/nicolebech/dis145/assets/164402586/b85b6444-01fc-4cc0-aa6a-38d4d6ed3dc6)
_Imagénes de: https://mcielectronics.cl/_


### Diagrama
Se presenta el diagrama hecho en tinkercad que incluye todos los componentes necesarios.
![diagrama](https://github.com/nicolebech/dis145/assets/164402586/6cd452dd-6450-4236-b570-c07b9348d507)
Página: https://www.tinkercad.com/

## 3. Línea temporal sobre bitácora





Comencé probando el nuevo lector, ya que nunca había trabajado con él. Aquí noté que cada tarjeta tenía su identificación, por lo que al probar con ejemplos de internet no me iba a funcionar. Logré probarla y que funcionara. Al principio no la detectaba.


Después hice lo mismo con el servomotor, que si bien alguna vez lo había utilizado no recordaba tan bien. Probé que estuviera funcionando y luego jugué con la configuración de tiempos y grados de apertura. Todo iba bien :)

https://github.com/nicolebech/dis145/assets/164402586/d709d485-a771-4d22-bad8-a07dbe16eeb6

Cuando me aseguré de que ambos componentes estaban funcionando los uní. Mi idea era no usar protoboard para que no ocupara tanto espacio en la maqueta física. Después de un par de pruebas logré que el servomotor girara solo para abrirse y se cerrara en 1 segundo, ya que de lo contrario me parecía mucho tiempo y caería demasiada comida.

https://github.com/nicolebech/dis145/assets/164402586/befaf130-cae6-4793-b650-1b70b991c644

Mecanismo unido y funcionado :)



*Código y comentarios*


```cpp

https://github.com/nicolebech/dis145/assets/164402586/0f9a1f7c-f16d-4f7d-9a12-7e188263a536


#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  // Pin de selección del módulo RFID
#define RST_PIN 9  // Pin de reinicio del módulo RFID

MFRC522 mfrc522(SS_PIN, RST_PIN); // Crear instancia del MFRC522
Servo myservo;  // Crear instancia del servomotor

// UID de la tarjeta autorizada 
byte kart[4] = {0xB9, 0xC0, 0xF7, 0xB8};
boolean card = false;  // Variable para almacenar el estado de la tarjeta

void setup() {
  Serial.begin(9600);  // Iniciar comunicación serial a 9600 baudios
  SPI.begin();         
  mfrc522.PCD_Init();  // Iniciar lector MFRC522
  myservo.attach(3);   // Conectar servomotor al pin 3
  myservo.write(100);  // Posición inicial del servo
}

void loop() {
  // Revisar si hay una nueva tarjeta presente
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Seleccionar una tarjeta
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Mostrar UID de la tarjeta en el monitor serial
  Serial.print("Found ID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Comparar UID con la tarjeta autorizada
  card = true;  // Asumir que es correcta inicialmente
  for (byte i = 0; i < 4; i++) {  // Comparar solo los 4 bytes relevantes
    if (mfrc522.uid.uidByte[i] != kart[i]) {
      card = false;  // Si algún byte no coincide, no es la tarjeta correcta
      break;
    }
  }

  if (card) {
    Serial.println("Correct Card");
    myservo.write(180);   // Mover servo a la posición de alimentación (180 grados)
    delay(1000);          // Esperar 1 segundo
    myservo.write(100);   // Volver servo a la posición inicial (100 grados)
    delay(1000);          // Esperar 1 segundo entre detecciones
  } else {
    Serial.println("Wrong Card");
  }

  mfrc522.PICC_HaltA();  // Parar comunicación con la tarjeta
}
```

## 4. Conclusiones de la Investigación

*¿Qué hice bien?*
- Logré programar correctamente el Arduino para que el lector RFID detectara la tarjeta autorizada y enviara la señal al servomotor. La lógica del código funcionó perfectamente, permitiendo que el servomotor se moviera en la dirección y tiempo estipulados. 
- Realicé múltiples pruebas para asegurarme de que el sistema respondiera adecuadamente a la detección de la tarjeta RFID.
- Utilicé comentarios detallados y claros en el código, facilitando su comprensión y mantenimiento.
 Documenté el proceso de desarrollo e incluí esquemas de conexión, explicaciones del código y la lógica detrás de cada paso.

*¿Qué hice mal?*
- No asigné suficiente tiempo para la construcción y ensamblaje de la parte física del alimentador, lo que resultó en la incompletitud de esta etapa del proyecto. Primero quería que fuera en impresión 3D, pero no me convenció el resultado. Finalmente con cartón no pude darle la forma que quería :( 
Subestimé la cantidad de materiales y herramientas necesarias para la construcción física del alimentador

*¿Qué cosas funcionaron?*
- La comunicación entre el lector RFID, el Arduino y el servomotor fue exitosa y sin interrupciones.
El sistema respondía correctamente a la detección de la tarjeta RFID, activando el servomotor como se esperaba.

*¿Qué cosas no funcionaron?*
- No logré completar la construcción física del alimentador, lo que impidió la prueba del sistema en un entorno real.
La falta de una estructura física impidió la integración completa y la validación del proyecto en su totalidad.

*¿Qué dudas tengo ahora?*
- ¿Cómo se comportaría el sistema en condiciones reales de uso continuo, en temas de durabilidad y funcionamiento?
Creo que quizás podría incorporarle un mecanismo extra para cuando la comida se acabara. Una especie de partición en la parte del contenedor que permita almacenar la comida en 2 partes. La parte de abajo es la que se expulsa con el sistema ya hecho, la de arriba podría incluir un sensor y otro servomotor. Permitiendo al humano activar la recarga de forma automática, en vez de servir :O

*¿Cómo este proyecto influye en mi práctica en diseño?*
- Aprendí la importancia de una planificación integral que incluya tanto el desarrollo del software como la construcción física del proyecto. La experiencia me enseñó que debo documentar cada paso del proceso, lo cual es crucial para la replicabilidad y el mantenimiento del proyecto. Este proyecto me ayudó a ver el diseño de interfaces de manera diferente y entretenida, considerando tanto los aspectos técnicos como prácticos para una implementación exitosa. 

En resumen, aunque no pude completar la parte física del alimentador, el proyecto me proporcionó lecciones sobre la integración de componentes electrónicos, la importancia de una planificación adecuada (sobretodo de la anticipación, ya que nunca hay certeza de lo que puede ocurrir a último momento que quizás no te permita continuar adecuadamente o como lo deseabas). Además destaco la relevancia de necesidad de una buena documentación en el diseño y construcción de interfaces, algo que debo mantener y mejorar en el tiempo en mis proyectos personales porque me cuesta mantener una secuencia histórica o documentación.

##5. Referentes de la investigación:
https://blog.adafruit.com/2020/11/30/build-an-automatic-pet-feeder/
https://all3dp.com/2/arduino-pet-feeder-cat-dog/
https://circuitdigest.com/microcontroller-projects/automatic-pet-feeder-using-arduino

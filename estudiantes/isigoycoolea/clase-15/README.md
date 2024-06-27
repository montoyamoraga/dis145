# **Entrega Final** 	:electric_plug:

_Exámen Diseño y construcción de Interfaces_

_Universidad Adolfo Ibañez_

_S1-2024_

_Docente: Aaron Montoya_  

_Ayudante: Janis Sepulveda_

## Elección del tema:
1. Definición de la idea: Me costó demasiado definir la idea y llevarla a cabo.
 - Idea A: chaqueta de tela lisa, pero que mediante arduino y materiales eléctricos se genera textura arrugándose creando una superficie.
 - Idea B: hacer una cámara estenopeica 
 - Idea C: cámara digital
 - Idea D: cámara web
> [!NOTE]
> Terminé desarrollando la cámara web.

# Cámara Web :video_camera:
Decidí hacer una cámara de video que se conecta a una computadora a través de un puerto USB, para transmitir imágenes en tiempo real.
Inicialmente, el proyecto se centró en explorar el funcionamiento de una cámara estenopeica. Sin embargo, debido a las dificultades para implementarlo con conexiones y Arduino, me surgió la necesidad de cambiar de enfoque. La transición hacia la creación de una cámara web utilizando el módulo OV7670 y Arduino Nano 33 BLE implicó resolver varios desafíos técnicos, como configurar correctamente las conexiones físicas y la comunicación entre la cámara y la computadora. Esto incluyó el uso del complemento "ArduImageCapture" de Arduino IDE para capturar imágenes en la computadora desde el módulo de cámara.

El proyecto se propone explorar y desarrollar una cámara web funcional utilizando componentes electrónicos accesibles como Arduino y el módulo OV7670. La elección de cambiar hacia una cámara web se debió a la viabilidad técnica y a la capacidad de integrar la tecnología Arduino para captura y transmisión de imágenes. La cámara web resultante permitirá explorar no solo los aspectos técnicos de la captura de imágenes, sino también la interfaz entre hardware y software.

## Materiales:
![Conexiones en Arduino (1)](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-11/arduino%20nano)
![Conexiones en Arduino (1)](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-11/cables)
![Conexiones en Arduino (1)](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-11/c%C3%A1mara)
![Conexiones en Arduino (1)](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-11/protoboard)
![Conexiones en Arduino (1)](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-11/resistencias)

Imágenes sacadas de la página "https://circuitjournal.com/arduino-OV7670-to-pc"

## Referentes :bulb:
 - https://circuitjournal.com/arduino-OV7670-to-pc
 - https://www.youtube.com/watch?v=pgSvtymcNq4
 - https://github.com/hpssjellis/my-examples-of-edge-impulse/blob/main/OV7670-Camera/default-ov767x/rawbytes.ino

## Proceso 🚶

Comencé con el proceso de diseño, intenté hacer la cámara con corte láser de este tipo:
   
![cámara woodsum](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/c%C3%A1mara%20woodsum.jpg) 


![Proceso en MDF](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/2.jpeg)


Pero me dí cuenta que como no iba a usar una pantalla sino que la imágen se visualizara al computador era más lógico diseñarlo al estilo de cámara web y con impresión 3D

![foto computador impresión 3D](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/5.jpeg) 


Pero no me gustó el diseño porque era el típico de las webcam comerciales. Así que busqué inspiración e hice otro diseño un poco más distitno.


![6](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/6.jpeg) 

![7](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/7.jpeg) 

![4](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/4.jpeg) 


Dejé muy para el final el código porque pensaba lo tenía listo para llegar y usar, pero me dí cuenta que como cambie el arduíno a arduíno nano el código me mando muchos errores que aún sigo sin entender por qué no funciona.

## Código y descripción
### Código:

```markdown

#include <ArduCAM.h>
#include <SPI.h>
#include "memorysaver.h"

// Definiciones de pines para el módulo de la cámara
#define CS_PIN 10
#define XCLK_PIN A0
#define SIOD_PIN A4
#define SIOC_PIN A5
#define VSYNC_PIN 2
#define HREF_PIN 3
#define PCLK_PIN 4

// Crear un objeto ArduCAM
ArduCAM myCAM(OV7670, CS_PIN);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  SPI.begin();
  
  // Configurar los modos de los pines
  pinMode(CS_PIN, OUTPUT);
  pinMode(XCLK_PIN, OUTPUT);
  pinMode(SIOD_PIN, OUTPUT);
  pinMode(SIOC_PIN, OUTPUT);
  pinMode(VSYNC_PIN, INPUT);
  pinMode(HREF_PIN, INPUT);
  pinMode(PCLK_PIN, INPUT);

  // Inicializar el módulo de la cámara
  myCAM.InitCAM();
  myCAM.clear_fifo_flag();

  // Configurar los ajustes de la cámara
  myCAM.write_reg(0x12, 0x80); // Reiniciar la cámara
  delay(100);
  myCAM.write_reg(0x11, 0x01); // Configurar el preescalador de reloj
  myCAM.write_reg(0x6b, 0x0A); // PLL
  myCAM.write_reg(0x0C, 0x00); // Deshabilitar barra de color

  // Establecer la resolución a 640x480
  myCAM.write_reg(0x3A, 0x04); // Establecer bits[3:0] a '0100' para seleccionar VGA
  myCAM.write_reg(0x12, 0x14); // Establecer bits[6:4] a '0010' para seleccionar VGA
  myCAM.set_format(JPEG);
  myCAM.InitCAM();
}

void loop() {
  // Capturar una imagen
  myCAM.clear_fifo_flag();
  myCAM.start_capture();
  while (!myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK));

  // Leer los datos de la imagen desde la cámara
  myCAM.CS_LOW();
  myCAM.set_fifo_burst();
  
  uint8_t temp = 0;
  int i = 0;
  while ((temp != 0xD9) | (temp != 0xFF)) {
    temp = SPI.transfer(0x00);
    Serial.write(temp);
  }
  myCAM.CS_HIGH();

  // Esperar antes de capturar el siguiente fotograma
  delay(1000);
} 

```



### Descripción:

1. **Inclusión de Bibliotecas y Definiciones de Pines**:
   - Incluye las bibliotecas necesarias para la cámara ArduCAM y la comunicación SPI.
   - Define los pines utilizados para la cámara.

2. **Creación del Objeto ArduCAM**:
   - Crea un objeto `myCAM` para manejar la cámara OV7670.

3. **Función `setup()`**:
   - Inicializa la comunicación serie, I2C y SPI.
   - Configura los modos de los pines (entrada/salida).
   - Inicializa la cámara y limpia los flags del FIFO.
   - Configura los registros de la cámara para los ajustes específicos (reinicio, preescalador de reloj, PLL, desactivación de la barra de color y resolución VGA).

4. **Función `loop()`**:
   - Captura una imagen.
   - Espera hasta que la captura esté completa.
   - Lee los datos de la imagen desde el FIFO de la cámara y los envía a través de la comunicación serie.
   - Espera un segundo antes de capturar el siguiente fotograma.
  
 
## Qué errores tuve 🥊
No logré adaptar el código a mis necesidades y tampoco logré crear un código que funcionara como debía.
No aproveché las clases previas para avanzar en lo que realmente era más complejo para mi (adaptar el código).
Dejé todo a última hora y tuve procesos de cosas que ni si quiera usé para el proyecto final. 
Cambié demasiado de idea, me costó demasiado decidirme.


## Como quedo finalmente :scream:
![1](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/1.jpeg) 

![3](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/3.jpeg) 

![8](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/8.jpeg) 

![9](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/9.jpeg) 

![10](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/10.jpeg) 


## Conclusiones de aprendizaje :open_book:
> [!TIP]
> NO DEJAR LO MÁS IMPORTANTE PARA EL FINAL.

## Dudas que aún tengo :monocle_face:
![10](https://github.com/isigoycoolea/dis145/blob/main/estudiantes/isigoycoolea/clase-15/Captura%20de%20pantalla%202024-06-27%20152549.png) 
 - ¿Cómo se usa este tipo de códigos que son múltiples pestañas?


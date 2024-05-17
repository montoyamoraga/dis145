# clase-10
Estaba complicada y bloqueada con la idea anterior :warning: , así que decidí cambiarla completamente. :new: Para mi nuevo proyecto imitaré el sistema de una cámara fotográfica, principalmente del sistema llamado Phinhole Camera. Esto consiste en una cámara estenopeica que es un tipo de cámara fotográfica sin lente. Se forma por una caja cerrada a la luz, que solo tiene un pequeño orificio llamado estenopo. La luz entra por este orificio y proyecta una imagen invertida en el interior de la cámara sobre un material fotosensible, como papel fotográfico o una película. El pequeño tamaño del orificio permite que la luz se enfoque sin necesidad de una lente, creando una imagen nítida aunque con menos brillo. Este tipo de cámara es simple pero efectiva para capturar imágenes.:hearts:

# Cámara Estenopeica :camera:
Mi idea es imitar este sistema de funcionamiento, con 

El funcionamiento de la cámara estenopeica se basa en principios básicos de la óptica. Aquí te explico el paso a paso de cómo funciona:

1. **Estenopo**: La cámara estenopeica tiene un pequeño orificio, llamado estenopo, que permite el paso de la luz. Este orificio es muy pequeño, lo que permite que solo una cantidad limitada de luz entre a la cámara.

2. **Caja estanca a la luz**: La cámara es una caja completamente cerrada a la luz, excepto por el estenopo. Esto asegura que la única luz que entra a la cámara es la que pasa por el pequeño orificio.

3. **Entrada de luz**: Cuando la luz de una escena pasa por el estenopo, los rayos de luz se cruzan y forman una imagen invertida en la superficie opuesta dentro de la caja.

4. **Proyección de la imagen**: La luz que entra por el estenopo proyecta una imagen de la escena exterior en la pared opuesta dentro de la cámara. Esta imagen es real, pero está invertida tanto vertical como horizontalmente.

5. **Material fotosensible**: En la superficie donde se proyecta la imagen (dentro de la cámara), se coloca un material fotosensible, como papel fotográfico o película. Este material reacciona a la luz, registrando la imagen proyectada.

6. **Exposición**: La cantidad de tiempo que se permite que la luz entre por el estenopo se llama tiempo de exposición. Dependiendo de la intensidad de la luz y el tamaño del estenopo, el tiempo de exposición puede variar desde unos pocos segundos hasta varias horas.

7. **Desarrollo de la imagen**: Después de la exposición, el material fotosensible se revela utilizando procesos químicos (en el caso de la película fotográfica) o procesos digitales (en el caso de algunos tipos de papel fotosensible moderno), para producir una imagen visible.

La simplicidad de la cámara estenopeica permite experimentar con los fundamentos de la fotografía y entender cómo la luz puede formar imágenes sin la necesidad de lentes complejas, y esto es lo que me interesa al realizr el proyecto. Como me gusta la fotografía estoy interesada en el proceso de la creación de una imágen, y qué mejor forma de aprenderla que recrearla.

# ¿Cómo haré el funcionamiento de la cámara?
Para imitar el funcionamiento de una cámara estenopeica usando Arduino, combinaré los principios de una cámara estenopeica con un sensor de luz (fotodiodo o LDR) y una pantalla para mostrar la imagen. Aunque no podré capturar imágenes detalladas como una cámara estenopeica tradicional, podré simular la captura de luz y mostrar una representación básica de la intensidad de luz.

### Materiales necesarios
- Arduino (por ejemplo, Arduino Uno)
- Matriz de fotodiodos o LDRs (resistencias dependientes de luz)
- Pantalla LCD o pantalla LED matricial
- Resistencias
- Cables de conexión
- Protoboard

### Pasos para crear la cámara estenopeica simulada :mag_right:

1. **Construcción del sensor de luz**:
   - Crera una matriz de fotodiodos o LDRs en una protoboard. Cada fotodiodo o LDR representará un píxel de la imagen.
   - Conectar cada fotodiodo o LDR a un pin analógico del Arduino usando resistencias para formar un divisor de voltaje.

2. **Conexión de la pantalla**:
   - Conectar una pantalla LCD o una pantalla LED matricial al Arduino para mostrar la intensidad de luz capturada por los sensores.

3. **Escribir el código en Arduino**:
   - Escribir el código para leer los valores de luz de cada sensor y mostrarlos en la pantalla.

### Ejemplo de código :computer:

Este código asume una matriz de 3x3 LDRs conectados a los pines analógicos A0 a A8 del Arduino y una pantalla LCD para mostrar los valores.

```cpp
#include <LiquidCrystal.h>

// Inicializa la librería con los números de los pines de la interfaz
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Número de filas y columnas de la matriz de sensores
const int rows = 3;
const int cols = 3;

// Pines analógicos a los que están conectados los sensores
int sensorPins[rows][cols] = {
  {A0, A1, A2},
  {A3, A4, A5},
  {A6, A7, A8}
};

// Matriz para almacenar los valores de luz leídos
int sensorValues[rows][cols];

void setup() {
  // Configura el número de columnas y filas de la pantalla LCD
  lcd.begin(16, 2);
  lcd.print("Pinhole Camera");
}

void loop() {
  // Leer los valores de los sensores
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sensorValues[i][j] = analogRead(sensorPins[i][j]);
    }
  }

  // Mostrar los valores en la pantalla LCD
  lcd.clear();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      lcd.setCursor(j * 5, i);
      lcd.print(sensorValues[i][j]);
    }
  }

  delay(1000); // Espera un segundo antes de la siguiente lectura
}
```

### Explicación del código :battery:
1. **Inicialización de la pantalla LCD**:
   - Se configura la pantalla LCD usando la librería `LiquidCrystal`.

2. **Configuración de los sensores**:
   - Se define una matriz para los pines analógicos a los que están conectados los LDRs.
   - Se define una matriz para almacenar los valores leídos de los sensores.

3. **Lectura de los valores de luz**:
   - En el bucle `loop()`, se leen los valores de cada sensor utilizando `analogRead()` y se almacenan en la matriz `sensorValues`.

4. **Visualización en la pantalla LCD**:
   - Los valores leídos se muestran en la pantalla LCD. Cada valor representa la intensidad de luz capturada por un LDR.

Este proyecto dará una simulación básica del funcionamiento de una cámara estenopeica utilizando Arduino. Pero intentaré obtener una resolución más alta, aumentando la cantidad de sensores de luz y ajustando el código en consecuencia.

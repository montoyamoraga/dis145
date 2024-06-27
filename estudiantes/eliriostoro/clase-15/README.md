# Proyecto: Calla-0-Lente

### **Definición de la temática de investigación:**
La temática del proyecto consiste en unos lentes de sol que, mediante una luz LED, indican qué tan desagradable es el ambiente. La luz LED, mediante 3 colores: verde (ruido bajo), azul (ruido moderado) y rojo (ruido desagradable), irá cambiando de color según los decibeles que reciba el sensor.

### Imágenes dibujos y videos explicativos:

#### Idea principal:
![image](https://github.com/eliriostoro/dis145/assets/95258783/6127f5a7-b904-481d-be54-dc515a909b71)
#### Proceso:
- Arduino:
 ![image](https://github.com/eliriostoro/dis145/assets/95258783/ecf7a9f0-3b22-4759-8bba-b66759807de3)
- Video de funcionamiento:
  * Sin sonido:

    https://github.com/eliriostoro/dis145/assets/95258783/3ed48bf4-22b7-4ce8-935b-1fac4ed06fbb



  * Con sonido:
    https://github.com/eliriostoro/dis145/assets/95258783/67f399e3-ac8c-4b6f-836b-bbb870c443d9


  
#### Código:
```
// 2024-25-06
// Código que permite detectar, mediante un sensor de sonido, que tan desagradble es el entorno
// por eliriostoro
// hecho con Arduino UNO
// para Arduino UNO 

const int microfono = A0; // Pin del sensor de micrófono
const int rojo = 9;  // Pin rojo
const int verde = 10; // Pin verde
const int azul = 11;  // Pin azul


// Número de muestras para promediar
const int numMuestras = 10; 

// Array para almacenar las muestras
int muestras[numMuestras];  

// Índice para las muestras
int indiceMuestra = 0;       

void setup() {
  // Configura el pin del micrófono como entrada
  pinMode(microfono, INPUT);


// Configura los pines de los LEDs como salida
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  Serial.begin(9600);
}

void loop() {

// Leer el valor del micrófono y lo almacena como muestras
  muestras[indiceMuestra] = analogRead(microfono);
  indiceMuestra = (indiceMuestra + 1) % numMuestras;
  
// Calcular el promedio de las muestras
  int valorMicrofono = 0;
  for (int i = 0; i < numMuestras; i++) {
    valorMicrofono += muestras[i];
  }
  valorMicrofono /= numMuestras;
  
// Ajustar los colores según el valor promedio
  if (valorMicrofono < 530) {

// Cambia el led a color Verde si el ruido es bajo
    setColor(0, 0, 255); 
  } else if (valorMicrofono < 550) {

// Cambia el led a Azul si el ruido es medio
    setColor(0, 255, 0); 
  } else {

// Cambia el led a Rojo si el ruido es alto
    setColor(255, 0, 0); 
  }
  
  Serial.println(valorMicrofono);
  
  // No usar delay() para no bloquear el loop
}

void setColor(int rojoValor, int verdeValor, int azulValor) {

  
  analogWrite(rojo, rojoValor);
  analogWrite(verde, verdeValor);
  analogWrite(azul, azulValor);
}

```




### **Línea temporal:**
  -  Clase 7: Iniciamos pensando qué proyecto podríamos realizar. Personalmente, tenía una idea que no vi factible debido a que requería el uso de datos en tiempo real y sería muy compleja. Además, no me convencía como proyecto.
  -  Clase 11:  Con Jannis, aterrizamos mi idea de los lentes y comenzamos comprando el sensor, Arduino, diodo LED RGB y sensor de sonido analógico. La parte del sensor era crucial, ya que no podía ser digital; debía ser analógico debido a que el proyecto se basa en medir la variabilidad del sonido.
  -  Clase 12: Trabajé desde casa ya que estaba enferma. Logré definir el código y mis pendientes para la próxima clase.
  -  Clase 13: Julio me ayudó a soldar el sensor de sonido. Probé el código y funcionó casi correctamente; por alguna razón, mostraba un color morado.
  -  Clase 14: Investigué mejor el funcionamiento del sensor y surgió un problema extraño: los datos variaban mucho según el voltaje suministrado al sensor. Decidí trabajar con 5V fijos y analizar los datos según diferentes ruidos. Llegué a la conclusión de usar los siguientes valores:
        * Verde si los valores del sensor son < 530.
        * Azul si los valores del sensor estan entre 530 y 550.
        * Rojo mayor que 550.
   

          
    
     
  

          
### **Conclusiones**
  * Hice bien:
    - Adaptarme a las dificultades del sensor.
    - Lectura de datos del sensor.
    - Comentar el codigo.
      
    
  * Cosas funcionaron:
    - El led otorga los colores según el ruido.
    - Código.

    
  * Problemas:
    - No logré soldar el LED para que quedara libre del circuito y posicionarlo en los lentes F.
    - Funcionamiento extraño del sensor,

      
  * Dudas:
    - Todavía no entiendo el por qué los datos del sensor varian tanto según cuantos Voltios se le apliquen al sensor.

    
  * Influencia del proyecto: Más que la influencia del proyecto en sí, quiero resaltar la dinámica en las clases. Llegué muy asustada la primera clase, sin saber nada de electrónica, con conocimientos muy básicos, y con cada clase fui aprendiendo sin sentirme fuera de lugar por no saber. Todo lo contrario, siempre tenía muchas ganas de aprender, de preguntarle cosas al profesor y a mis compañeros.




### **Uso de fuentes y citas:**
- Inspiración:
   * Lentes inteligentes Ray-Ban por la ubicacion de la cámara.
     https://www.meta.com/us/es/smart-glasses/
  * Audifonos con cancelación de ruido:
    https://www.apple.com/cl/shop/product/MTJV3AM/A/airpods-pro?fnode=94c297e8bf1b408c63c6fefff7abee450edb009a2830343812946f298e6781411001363210489592c8eb9c336fa78794d381476b536075303be4bfdcac7079306d72a8a2752d1cac0229dd746bdd0be353386eea661c0de57553c207633a783321de8eefaf72c181e9fa26677c996abe&fs=fh%3D47ce%252B282f


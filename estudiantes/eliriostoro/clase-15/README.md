# Proyecto: Calla-0-Lente

### **definición de la temática de investigación:**
  La tematica del proyecto consiste en unos lentes de sol que mediante una luz led indique que tan desagradable es el ambiente. La luz led mediante 3 colores: verde que indica ruido bajo, azul ruido moderado y rojo ruido desagradable ira cambiando de color segun los decibeles que reciva el sensor.

### **imágenes dibujos y videos explicativos:**

## Idea principal:
![image](https://github.com/eliriostoro/dis145/assets/95258783/6127f5a7-b904-481d-be54-dc515a909b71)
## Proceso:
- Arduino:
 ![image](https://github.com/eliriostoro/dis145/assets/95258783/ecf7a9f0-3b22-4759-8bba-b66759807de3)
- Video de funcionamiento:
  * sin sonido:

    https://github.com/eliriostoro/dis145/assets/95258783/3ed48bf4-22b7-4ce8-935b-1fac4ed06fbb



  * con sonido:
    https://github.com/eliriostoro/dis145/assets/95258783/67f399e3-ac8c-4b6f-836b-bbb870c443d9


  
- Código:
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




### **línea temporal:**
  -  Clase 7: Iniciamos pensando que proyecto podriamos realizar, yo en lo personal tenia una idea que no la vi factible debido a que habia que usar datos en tiempo real y seria de mucha complejidad, a parte no me casaba con la idea de proyecto.
  -  Clase 11: Con jannis aterrizamos mi idea de lentes y comenzamos comprando sensor, arduino, diodo led RGB y sensor de sonido ANALOGO. La parte del sensor era de suma importancia, ya que este no podia ser digital y debia ser analogo ya que la base del proyecto consistia en medir la variabilidad del sonido.
  -  Clase 12: Trabaje desde casa, ya que estaba enferma, logré definir el codigo y definir mis pendientes para la proxima clase.
  -  Clase 13: Julio me ayudó soldando el sensor de sonido, pruebo el codigo y funciona de manera casi correcta, por alguna razon salia un color morado.
  -  Clase 14: Investigo de mejor forma el funcionamiento del sensor, nace un problema muy extraño: mis datos entregados por la consola varian mucho segun cuanto voltaje le entregue al sensor. Decidí que trabajaria con 5V fijos y que analizaría los datos que obtengo segun distrintos ruidos. LLego a la conclusión que usare los siguientes valores
        * Verde si los valores del sensor son < 530
        * Azul si los valores del sensor estan entre 530 y 550
        * Rojo mayor que 550
### **uso de fuentes y citas**
          
### **conclusiones**
  * Que hice bien:
    - Adaptarme a las dificultades del sensor
    - Lectura de datos del sensor
    - Comentar el codigo
      
    
  * Que cosas funcionaron:
    - El led otorga los colores segun el ruido
    - Codigo

    
  * Problemas:
    - No logré soldar el LED para que quedara libre del circuito y posicionarlo en los lentes F
    - Funcionamiento extraño del sensor

      
  * Dudas:
    - Todavia no entiendo el por qué los datos del sensor varian tanto según cuantos Voltios se le apliquen al sensor-

    
  * Influencia del proyecto: Mas que la influencia del proyecto en si quiero rescatar la dinamica en clases en si, llegué muy asustada la primera clase, sin saber nada de electronica, conocimientos muy básicos y con cada clase fui aprendiendo nunca con el sentimiento de sentirme fuera de lugar por no saber, todo lo contrario, con muchas ganas de aprender, de preguntarle cosas al profe y a mis compañeross.
  


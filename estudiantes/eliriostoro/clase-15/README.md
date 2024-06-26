## rúbrica

la nota máxima es 7.0, y evalúa estos aspectos:

- definición de la temática de investigación: qué es el proyecto
- imágenes dibujos y videos explicativos
- línea temporal de baja resolución sobre la bitácora: semana X hice esto, semana Y me dediqué a esto, semana Z hice estos 2 caminos equivocados, último día recién programé todo.
- uso de fuentes y citas
- conclusiones de la investigación: qué hice bien, qué hice mal, qué cosas funcionaron, qué cosas no, qué dudas tengo ahora, cómo este proyecto influye mi práctica en diseño

# Proyecto: Calla-0-Lente

* **definición de la temática de investigación:**
  La tematica del proyecto consiste en unos lentes de sol que mediante una luz led indique que tan desagradable es el ambiente. La luz led mediante 3 colores: verde que indica ruido bajo, azul ruido moderado y rojo ruido desagradable ira cambiando de color segun los decibeles que reciva el sensor.

* **imágenes dibujos y videos explicativos:**
* **línea temporal:**
  -  Clase 7: Iniciamos pensando que proyecto podriamos realizar, yo en lo personal tenia una idea que no la vi factible debido a que habia que usar datos en tiempo real y seria de mucha complejidad, a parte no me casaba con la idea de proyecto.
  -  Clase 11: Con jannis aterrizamos mi idea de lentes y comenzamos comprando sensor, arduino, diodo led RGB y sensor de sonido ANALOGO. La parte del sensor era de suma importancia, ya que este no podia ser digital y debia ser analogo ya que la base del proyecto consistia en medir la variabilidad del sonido.
  -  Clase 12: Trabaje desde casa, ya que estaba enferma, logré definir el codigo y definir mis pendientes para la proxima clase.
  -  Clase 13: Julio me ayudó soldando el sensor de sonido, pruebo el codigo y funciona de manera casi correcta, por alguna razon salia un color morado.
  -  Clase 14: Investigo de mejor forma el funcionamiento del sensor, nace un problema muy extraño: mis datos entregados por la consola varian mucho segun cuanto voltaje le entregue al sensor. Decidí que trabajaria con 5V fijos y que analizaría los datos que obtengo segun distrintos ruidos. LLego a la conclusión que usare los siguientes valores
        * Verde si los valores del sensor son < 530
        * Azul si los valores del sensor estan entre 530 y 550
        * Rojo mayor que 550

          
* **conclusiones**
  * Que hice bien:
  * Que cosas funcionaron:
  * Problemas: No logré soldar el LED para que quedara libre del circuito y posicionarlo en los lentes F
  * Dudas:
  * Influencia del proyecto: 
  


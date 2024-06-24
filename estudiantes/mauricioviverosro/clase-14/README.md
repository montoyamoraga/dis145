# Avance del proyecto

Durante este avance, me encargué de recopilar todo lo el avance de la clase anterior, en donde tenía desarrollado el código pero no podía ejecutarlo físicamente ya que requería de una batería externa que 
alimentara al motor paso a paso.

En primer lugar, aclarar que el motor paso a paso requiere de una batería de 12V y 1.7 Ah. Inicialmente, intenté hacer funcionar el motor conectándo dos pilas AA, esto a modo de testear si es que el motor 
funcionaba, lo cual no sucedió, por lo que me di cuenta que efectivamente lo mejor era conseguir una batería que cumpliera con el requerimiento.

Utilicé una batería de moto la cual cumplia con los 12V que requiere el motor paso a paso, pero sus Ah eran muy superiores - 32Ah - a lo que el motor paso a paso realmente requería, que eran 1.7 Ah. Dado 
que no tenía mucho conocimiento acerca de las consecuencias que esto podía traer, decidí primero averiguar qué podía suceder si utilizaba una batería del voltaje requerido pero que excedía los Ah. Las res-
puestas dadas en lugares donde venden estos componentes es que si respetaba el voltaje no habría problema ya que en cuanto a los Ah, ya que el componente (motor) sólo consumiría lo que requiere y no más.

No me confié en un 100% y a modo de prevención utilicé un computador antiguo en donde conecté los compomentes a la batería, cargué el código y realicé la prueba.

No hubo problemas con la batería ni tampoco con el código ya que cargó sin problemas, pero si con el funcionamiento del motor paso a paso ya que el eje de este no rotaba practicamente nada, sino que por 
el encendido de las bobinas el motor vibraba o bien giraba solo un poco el eje de este. Pensé que podía ser que la batería estuviera descargada así que con un voltímetro corroboré que estuviera en óptimas 
condiciones, lo cual fue así. Luego revisé las conexiones de los cables entre los diferentes componentes, estaba todo perfecto también. Después, revisé el código y la verdad tampoco había algo que solu-
cionar a mi parecer. He estado buscando información al respecto, no es algo que particularmente me haya pasado a mi, sino que es un problema común por lo que investigué en videos como los siguientes: 

### https://www.youtube.com/watch?v=lrC1hSQ1oWM
### https://www.youtube.com/watch?v=WoPYHDA32Zk

Hasta ahora, continúo investigando pero sigo sin saber como resolverlo, he corroborado directamente con el voltímetro cada pin del motor para descartar que haya alguna falla en este pero no hay nada fuera
de lo normal.

En paralelo, utilicé una persiana como referencia para diseñar una pieza en 3D que sirviera de soporte para el motor y por otra parte de tracción para que este haga rotar el eje de dicha persiana y pueda
hacer que suba y baje.


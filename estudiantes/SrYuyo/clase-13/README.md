# Clase-13

Stay With Me - Miki Matsubara


## Tareas para hacer 06/06

1. Bloque 2

  -Hacer un dibujo para tener un aproximado de como sera el objeto.
  
  -Proponer un modelo en cierta forma compacto que contenga el objeto.
  
  -Revisar la impresión de deste modelo 3d.

2. Bloque 3

  -Establecer una primera conexión entre arduino con processing.
  
  -Iterar distintos códigos (simples o ejemplos basicos).
  
  -Establecer una conexión entre el codigo de arduino con uno simple de processing.
  
  -Proponer mejoras en la interfaz de processing o observar errores.

## Bloque 2
No se pudo hacer un modelo en 3d, pues el programa de rhino no es apto para poder 

## Bloque 3

```java 
import processing.serial.*;

Serial myPort;
String dataString = "";
float humidity = 0;
float temperature = 0;
int gas = 0;

void setup() {
  size(400, 300);
  println(Serial.list()); // Listar los puertos seriales disponibles
  myPort = new Serial(this, Serial.list()[0], 9600); // Ajustar el índice según el puerto usado
  myPort.bufferUntil('\n'); // Lectura hasta el fin de línea
}

void draw() {
  background(255);
  fill(0);
  textSize(20);
  textAlign(CENTER);

  // Mostrar los valores de los sensores
  text("Lecturas de los Sensores", width/2, 40);
  text("Humedad: " + nf(humidity, 1, 2) + "%", width/2, 100);
  text("Temperatura: " + nf(temperature, 1, 2) + "°C", width/2, 140);
  text("Concentración de Gas: " + gas + " ppm", width/2, 180);
}

void serialEvent(Serial myPort) {
  dataString = myPort.readStringUntil('\n');
  dataString = trim(dataString);

  // Separar la cadena de datos recibidos
  String[] data = split(dataString, ' ');

  if (data.length == 3) {
    humidity = float(data[0]);
    temperature = float(data[1]);
    gas = int(data[2]);
  }
}

```

# Comentarios y observaciones

En esta clase no tuve un avance muy grande, pues estuve ayudando a otros compañeros (@eliriostoro y @thiangie). Aún así hay algunas cosas importantes que destacar o comentar. Por ejemplo, soldar los pines de un sensor cuando este no los trae por defecto. Como guía utilice un vídeo tutorial y vi el como soldo con estaño @supernave1 y la documentación que este tuvo. Es importante que cada pin quede con no mucha soldadura, pues se genera corto y no debe tener poca soldadura, pues este será endeble o puede que no haga contacto. Por eso es importante dejar los pines como se muestra en la foto y utilizar pasta para soldar en los componentes.

![image](https://github.com/SrYuyo/dis145/assets/103392227/f743a8d2-8130-4109-8138-8c73871fe0bf)

![image](https://github.com/SrYuyo/dis145/assets/103392227/b525464b-2c38-41fe-8a48-50be2b678b4d)

Video tutorial: <https://www.youtube.com/watch?v=dhnkp762hfQ&pp=ygUVc29sZGFyIHBpbmVzIGEgc2Vuc29y>

Página referencia: <https://hacedores.com/13-problemas-de-soldadura-de-pcbs/>

Siguiendo con la ayuda y de las cosas que pude observar es que el código de thiangie está bien hecho y trate de ver el porque un buzzer no estaba funcionando. Lamentablemente iteramos de varias formas para ver si el buzzer podía emitir algún simple sonido con distintos códigos, cosa que sí hacía. Lamentablemente thiangie me comentó que tenía problemas con la misma protoboard y que por eso no había ningún sonido. 

Ahora bien, una sugerencia es tener en cuenta el siguiente video para poder personalizar el sonido y otros links de posible interés.<https://www.youtube.com/watch?v=j1XrXFMtjWQ&ab_channel=FranciscoRamirez>
<https://www.pinguytaz.net/index.php/2021/09/21/musica-con-un-arduinoesp32-y-un-buzzer/>

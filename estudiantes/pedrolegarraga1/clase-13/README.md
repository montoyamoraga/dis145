# planificación

* comprender un codigo mas complicado (añadirle un LED y prenderlo con un grado de angulación)
* documentar el proceso
* subirlo a gitHub

# ejemplos descubrir el funcionamiento de led + mpu6050

https://www.youtube.com/watch?v=-aaj0oVLDpQ

https://www.youtube.com/watch?v=8vJp2e6PRks

https://github.com/Ajay-Embed/MPU6050-ArduinoNano/blob/master/detailed%20description

* ejemplo mas acorde con el proyecto
*https://www.instructables.com/Giroscope-led-controll-with-Arduino/*
https://github.com/danionescu0/arduino/tree/master/projects/giroscope_led_controll

* ejemplo simple 1Led
https://github.com/shveytank/MPU_6050_Guesture_codes/blob/master/MPU6050_XYZacc3.ino

# analisis del ejemplo simple 1Led

En este codigo se implementa apagar y prender una luz Led
integran en el codigo las "gestures" que son basicamente acciones predeterminadas
por ejemplo si el sensor mpu 6050 esta angulado hacia la izquierda y marca más de 145 en el serial monitor (son numeros referenciales)
marcaría gesture 1 y se le asignaría una accion con el comando "if"
con estos comandos se pueden prender y apagar luces 


Monitor Serial:

![MonitorSerialClase13](https://github.com/pedrolegarraga1/dis145/assets/164402475/d62377b1-730d-4362-b157-ccaebff0deae)

Codigo Arduino:
```cpp
#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h"    

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
};

MyData data;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255);  // Y axis data
  //delay(500);
  Serial.print("Axis X = ");
  Serial.print(data.X);
  Serial.print("  ");
  Serial.print("Axis Y = ");
  Serial.println(data.Y);
   if (data.Y < 80) { //gesture : down 
    Serial.print("gesture 1");
    digitalWrite(LED_BUILTIN, LOW);
    }
 if (data.Y > 145) {//gesture : up
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("gesture 2");
    }
 if (data.X > 155) {//gesture : left
  Serial.print("gesture 3");
    }
 if (data.X < 80) {//gesture : right
  Serial.print("gesture 4");
    }
 if (data.X > 100 && data.X < 170 && data.Y > 80 && data.Y < 130) { //gesture : little bit down
    Serial.print("gesture 5");
    }

}
```

# metiendonos dentro del codigo

Luego de conocer el codigo y saber que hace cada linea, nos pusimos a modificarlo un poco.  
Iniciamos cambiandole el numero al Serial.begin dado que era mas facil trabajar con 115200 baud para que así el monitor serial pudiera leer los datos que nos entrega el sensor.  
Luego, nos dimos cuenta de que solo necesitariamos trabajar con un axis (en este caso fue Y) asi que eliminamos las demas gestures que utilizaban los axis X. Esto mismo lo podemos ver en el apartado //AXIS "Y"

Ya con el codigo modificado lo verificamos y subimos al arduino para así ver como funciona.


```cpp

#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
};

MyData data;

void setup() {
//CAMBIO DE BAUD
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  pinMode(13, OUTPUT);
  //codigo hecho por mi
  pinMode(10, OUTPUT);
  //
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  data.X = map(ax, -17000, 17000, 0, 255);  // X axis data
  data.Y = map(ay, -17000, 17000, 0, 255);  // Y axis data
  delay(50);
  Serial.print("Axis X = ");
  Serial.print(data.X);
  Serial.print("  ");
  Serial.print("Axis Y = ");
  Serial.println(data.Y);

//AXIS "Y"
  //led n1
  if (data.Y < 180) {  //gesture : down
    Serial.print("gesture 1");
    digitalWrite(13, LOW);
  }
  if (data.Y > 180) {  //gesture : up
    digitalWrite(13, HIGH);
    Serial.print("gesture 2");

```

https://github.com/pedrolegarraga1/dis145/assets/164402475/c848e963-7ad7-4bde-8546-aa696bdecb42


# más allá de la planificación


Ya teniendo una Led funcionando quizimos probar con dos Led las cuales se prendieran a diferente grado de inclinación.  
Como pueden ver creamos dos gestures más las cuales van al final del codigo anterior.  Estas
se caracterizan por estar programadas con los grados de inclinación a la inversa de las anteriores para que el sensor prenda una luz led hacia un lado y otra hacia el lado contrario.  


```cpp
    //led n2
      if (data.Y > 80 ) {  //gesture : down
    Serial.print("gesture 1");
    digitalWrite(10, LOW);

  }
  if (data.Y < 80) {  //gesture : up
    digitalWrite(10, HIGH);
    Serial.print("gesture 2");

 if (data.Y < 80) {  //gesture : up
    digitalWrite(10, HIGH);
    Serial.print("gesture 2");
  }

```

Lamentablemente por falta de tiempo no logramos hacer que estas funcionen pero dejamos el circuito anvanzado.


![circuito2LedMPU](https://github.com/pedrolegarraga1/dis145/assets/164402475/db46e6a0-391e-4362-a511-4f5caaa052d8)


por lo mismo este será el desafío de la siguiente clase!

Clase n14!

# clase 14

dado el problema que tuvimos la clase n13 retomamos el codigo y comenzamos a analizarlo para poder lograr nuestro objetivo prender dos luces led con diferentes anngulos de inclinación.  

Para esto cambiamos un poco el codigo, lo limpiamos y lo adaptamos a nuestra manera de trabajar por ejemplo, eliminamos todas las lineas que nos sobraban acordes a los ejes X y Z dado que trabajamos con el eje Y. Ya con el codigo limpio le añadimos algunos ajustes como pueden ser el cambio de delay para trabajar mas acorde con el monitor serial y poder configurar el grado de angulacion necesario.  

Ya con esto comenzamos a intervenir aún más, añadimos una led en el puerto 12 para luego asignarle un grado de inclinación y que se encienda hacia el lado contrario de la otra led. Esto tambien lo hicimos la clase n13 y fue donde tuvimos problemas por lo que en esta instancia cambiamos las lineas asociadas a Void Loop que es donde ocurría el problema. Pasamos de tener una dinamica simple (si el grado es x, se enciende la luz) a una dinamica un poco más compleja (si el grado de inclinación es x, luz 1 se enciende y luz 2 se apaga, luego, lo mismo del otro lado y finalizamos con una linea neutral donde las dos luces se apagan).

Aqui podemos ver el codigo de la clase n13 limpio y con los cambios mencionados anteriormente.  
```cpp
#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h"    

MPU6050 mpu;
int16_t ax, ay, az;

struct MyData {
  byte Y;
};

MyData data;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();

  pinMode(13, OUTPUT);
  //añadimos una nueva LED
  pinMode(12, OUTPUT);
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  data.Y = map(ay, -17000, 17000, 0, 255);  // Y axis data
  delay(250);

  Serial.print("Axis Y = ");
  Serial.println(data.Y);

    if (data.Y > 180) {
    // Inclinación hacia la derecha
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);

     } else if (data.Y < 40) {
    // Inclinación hacia la izquierda
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  } else {
    // No hay inclinación significativa
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
  }

```
Con esto listo, conectamos la protoboard, luces led, el sensor y la placa arduino para verificar como estaba funcionando.



https://github.com/pedrolegarraga1/dis145/assets/164402475/7c4e099b-2054-4a5e-8ab3-fcbb60acabcd



Ya con el codigo funcionando le añadimos algunos extras como un delay a las luces para que estas no se apaguen al instante
```cpp
    //delay para que la luz se quede encendida un cierto tiempo
  digitalWrite(12, HIGH);
    delay(2000);
   digitalWrite(13, LOW);
```
y nos pusimos a experimentar añadiendole más luces al circuito para asi poder lograr formar una flecha o algo parecido. Nos dimos cuenta de que no era necesario seguir editando el codigo sino que crear una cadena con columnas de leds y las mismas conectarlas como si fuera una sola.

![FlechaLed](https://github.com/pedrolegarraga1/dis145/assets/164402475/87df5afb-15fd-4c77-bdfc-a1c754a766a1)

Hicimos lo mismo con las luces del otro lado y las diferenciamos entre rojas y verdes. Luego de que solucionamos el problema nos dedicamos a dejar presnetable el sistema y que sea aún mas visible.



https://github.com/pedrolegarraga1/dis145/assets/164402475/c21e17ce-21d9-4548-850b-c30d9301fa85



# conclusión
El corazón del proyecto quedó funcionando dado que logramos crear con un sensor MPU6050 (accelerometro y giroscopio), luces led, una protoboard, cables y una placa arduino un proyecto en donde al girar hacia la derecha varias luces se enciendan por un corto tiempo y luego, al girar hacia la izquierda se enciendan las luces del otro lado.  

Eso tiene como funcion ser un dispositivo señaletico para la gente que no quiera quitar sus manos del manillar al transitar por la calle y que lo puedan hacer con la cabeza.  
por lo tanto, faltaría la creación del producto en sí en base a la interfaz que hemos creado.

aquí adjunto un boceto de lo que podría llegar a ser el susodicho dispositivo.

![LeyendaCasco](https://github.com/pedrolegarraga1/dis145/assets/164402475/3d74bbf1-feb9-4faf-8b43-519071e42a7d)  


![CascoLateral](https://github.com/pedrolegarraga1/dis145/assets/164402475/c41025a1-6e8f-4d3a-9d56-fac47673b490)

![CascoFrontal_V2](https://github.com/pedrolegarraga1/dis145/assets/164402475/73dbe0c3-bb59-4f8a-9a2d-5516f04de63c)

![CascoTrasero](https://github.com/pedrolegarraga1/dis145/assets/164402475/20a51a28-fbb7-462c-a683-64ef791706b5)


Al ser un prototipo puede llegar a tener diferentes formas e interacciones. Por esto mismo los dejo invitados a utilizar esta base e información y así crear un dispositivo señalético práctico y eficiente para ciclistas, mejorando la seguridad y visibilidad en las calles.

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
 ![videoEjMPU1led](videoEjMPU1led.mp4)


Ya teniendo una Led funcionando quizimos probar con dos Led las cuales se prendieran a diferente grado de inclinación.  
Como pueden ver creamos dos gestures más pero que se caracterizan por estar programadas con los grados de inclinación a la inversa de las anteriores.  


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

Lamentablemente por falta de tiempo no logramos hacer que estas funcionen.  
por lo mismo este será el desafío de la siguiente clase...

Clase n14!




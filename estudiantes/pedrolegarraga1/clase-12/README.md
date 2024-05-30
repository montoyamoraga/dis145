# clase-12




```cpp

//este ejemplo lo sacamos del github de Jarzebski

/*
    MPU6050 Triple Axis Gyroscope & Accelerometer. Simple Accelerometer Example.
    Read more: http://www.jarzebski.pl/arduino/czujniki-i-sensory/3-osiowy-zyroskop-i-akcelerometr-mpu6050.html
    GIT: https://github.com/jarzebski/Arduino-MPU6050
    Web: http://www.jarzebski.pl
    (c) 2014 by Korneliusz Jarzebski
*/


//incluimos estas dos librerias de las cuales mpu6050 la tuvimos que instalar mientras que Wire viene con arduino
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() 
{

  //iniciamos el monitor y en cuantos baud se lee (115200)
  Serial.begin(115200);

//iniciamos el sensor mpu6050
  Serial.println("Initialize MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }


//estas lineas se utilizan para orientar el sensor, por ejemplo si lo queremos utilziar vertical u horizontal
//por el momento no necesitamos cambiar el offset, podemos utilizar el predeterminado
  // If you want, you can set accelerometer offsets
  // mpu.setAccelOffsetX();
  // mpu.setAccelOffsetY();
  // mpu.setAccelOffsetZ();
  


//***en el ejemplo recomiendan no tocar este sector***
  checkSettings();
}

void checkSettings()
{
  Serial.println();
  
  Serial.print(" * Sleep Mode:            ");
  Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");
  
  Serial.print(" * Clock Source:          ");
  switch(mpu.getClockSource())
  {
    case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
  }
  
  Serial.print(" * Accelerometer:         ");
  switch(mpu.getRange())
  {
    case MPU6050_RANGE_16G:            Serial.println("+/- 16 g"); break;
    case MPU6050_RANGE_8G:             Serial.println("+/- 8 g"); break;
    case MPU6050_RANGE_4G:             Serial.println("+/- 4 g"); break;
    case MPU6050_RANGE_2G:             Serial.println("+/- 2 g"); break;
  }  

  Serial.print(" * Accelerometer offsets: ");
  Serial.print(mpu.getAccelOffsetX());
  Serial.print(" / ");
  Serial.print(mpu.getAccelOffsetY());
  Serial.print(" / ");
  Serial.println(mpu.getAccelOffsetZ());
  
  Serial.println();
}

//***fin del sector***

void loop()
{

  //en este caso hay dos variables de numeros
  //Raw el cual nos da un numero mas grande y mucho mas preciso
  //normalize el cual nos da un numero de 1 unidad menos preciso pero mas facil de leer
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();

//en estas lineas se le pide al monitor serial que nos de un numero que represente los axis (x, y, z)
  Serial.println(rawAccel.ZAxis);
  Serial.print(" Xnorm = ");
  Serial.print(normAccel.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(normAccel.YAxis);
  Serial.print(" Znorm = ");
  Serial.println(normAccel.ZAxis);
  
  //podemos decidir que tan rapido el monitor serial nos entrega los numeros de axis
  delay(1000);
}

```

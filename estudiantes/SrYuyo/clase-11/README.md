# clase-11
Say Hello 2 Heaven - Temple Of The Dog

Ya hay una idea de como sera el codigo de arduino, los sensores que se utilizara para poder tener un input, el como crear un posible output con procesing. AHora se vera en como tener la conexión correcta entre ambos. 

Para el codigo de arduino tenemos:

```c
//versión para tener una conexión entre arduino y procesing, con tal de encender un led mediante un sketch de procesing, además la conección es
// tanto de arduino hacia processing como de proccesing a arduino
//Codigo origen de Chepecarlos y editado por SrYuyo
//placa arduino uno R3
//versión arduino 2.3.2

int led_1=13;
int boton=8;
bool estadoBoton=false;


Serial.begin(9600);
pinMode(led_1, OUTPUT);
pinMode(boton, INPUT);

}

void loop() {
  if (Serial .available()){
    char letra=Serial.read();
    
    if (letra =='H'){
      digitalWrite(led_1, 1);
    }

    else if (letra == 'L') {
      digitalWrite(led_1, 0); 
    }
  }

  if (digitalRead(boton) == 1 && estadoBoton == false){
    Serial.println('H')
  }
  else if (digitalRead(boton)==0 && estadoBoton == true){
    Serial.println('L');
    estadoBoton=false;
  }
  delay(100);
}
```

Para el codigo de processing:

```java
//coddiog conectado a arduino
//creado por ChepeCarlos y editado por SrYuyo
//processing v4.3

import processing.serial.*;

Serial puerto_1;
color colorcirculo = color(255,0,0)
color fondo = color(0) 

void setup(){
  puerto_1=new Serial(this,"COM3", 9600);
  size(500, 700);
  ellipseMode(CENTER);
}

void draw(){
  background(0);
  fill(255, 0, 0);
  circle(200, 300, 300);
}

void mousePressed(){
  colorcirculo = color(255, 0, 0);
  float distancia= dist(mouseX, mouseY, 200, 300);
  if (distancia < 150) {
    colorcirculo = color(255, 100, 100);
    puerto.write('H'); 
  }
}

void mouseReleased(){
  colorcirculo = (255, 0, 0);
  puerto.write('L');
}

void serialEvent(Serial p){
  while (puerto.availabble() == 1){
    char letra=puerto.readChar();
    print(letra);
    if (letra == 'H'){
      fondo = color(255);
      }
    else if (letra== 'L'){
    fondo = color(0);
    }
  }
}  
```

Teniendo esto en cuenta se pued eapreciar que la conección es sencilla, pero que sse deben tener en cuenta las variables de los sensores a utilizar para el dispositivo. Además las varaibles que captan los datos deben filtrase, para así poder visualizarlos y manipularlos de mejor manera en la interfaz.

Para un siguiente avance se deben de tener la conección de los sensores en el arduino y que estos manden una señal a processing o el computador y que por este mismo se genere una respuesta. Además se debe fijar el como sera la interfaz, es decir si se mantendra la misma idea original presentada o habra alguna variacción según se vaya dando.

Se debe tener un modelo 3d para el dispositivo y tener una posible distribución de los componentes.

Referencias:

<https://www.arduino.cc/education/visualization-with-arduino-and-processing/>
<https://learn.littlebirdelectronics.com.au/guides/connect-arduino-to-processing>
<https://www.arduino.cc/reference/es/language/variables/data-types/boolean/>
<https://www.youtube.com/watch?v=EQugLcDoaOQ&ab_channel=ChepeCarlos>

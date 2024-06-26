# clase-11
Say Hello 2 Heaven - Temple Of The Dog

Ya hay una idea de como será el código de arduino, los sensores que se utilizara para poder tener un input, el como crear un posible output con procesamiento. Ahora se verá como tener la conexión correcta entre ambos. 

Para el código de arduino tenemos:


```c
//Versión para tener una conexión entre arduino y processing, con tal de encender un led mediante un sketch de processing, además la conección es
//Tanto de arduino hacia processing como de processing a arduino
//Codigo origen de Chepecarlos y editado por SrYuyo
//Placa arduino uno R3
//Versión arduino 2.3.2


//Declaramos la variables a utilizar, led, boton y estado de boton.
int led_1=13;
int boton=8;
bool estadoBoton=false;

//definición del larranque y los componentes electronicos
Serial.begin(9600);
pinMode(led_1, OUTPUT);
pinMode(boton, INPUT);

}

//definimos el ciclo de las letras o inputs
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

//definimos los casos del boton
  if (digitalRead(boton) == 1 && estadoBoton == false){
    Serial.println('H')
  }
  else if (digitalRead(boton)==0 && estadoBoton == true){
    Serial.println('L');
    estadoBoton=false;
  }
  delay(100); //cambiar o modificar?
}
```

Para el codigo de processing:

```java
//codigo conectado a arduino
//creado por ChepeCarlos y editado por SrYuyo
//processing v4.3

//conexión con el puerto sereal
import processing.serial.*;

Serial puerto_1;
color colorcirculo = color(255,0,0)
color fondo = color(0) 

//seteo del puerto y el scketch de dibujo
void setup(){
  puerto_1=new Serial(this,"COM3", 9600);
  size(500, 700);
  ellipseMode(CENTER);
}

//dibujo de "boton"
void draw(){
  background(0);
  fill(255, 0, 0);
  circle(200, 300, 300);
}

//limitamos el uso del mouse, para que sea exclusivamente en el mismo círculo, definimos utilizado un radio fijo.
//el radio puede dejarse expresado en una variable, es decir que el radio no se tenga que estará cambiando constantemente.
//además si se hace click se deja 'H' para encender el led

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

//lectura del uerto sereal
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

Teniendo esto en cuenta se puede apreciar que la conexión es sencilla, pero que se deben tener en cuenta las variables de los sensores a utilizar para el dispositivo. Además las variables que captan los datos deben filtrarse, para así poder visualizarlos y manipularlos de mejor manera en la interfaz. Evitar que estos estén en algún bucle o no se puedan visualizar.

Para un siguiente avance se deben de tener la conexión de los sensores en el arduino y que éstos manden una señal a procesamiento o el computador y que por este mismo se genere una respuesta. Además se debe fijar el como será la interfaz, es decir si se mantendrá la misma idea original presentada o habrá alguna variación según se vaya dando.

Se debe tener un modelo 3d para el dispositivo y tener una posible distribución de los componentes.

# Referencias:

<https://www.arduino.cc/education/visualization-with-arduino-and-processing/>
<https://learn.littlebirdelectronics.com.au/guides/connect-arduino-to-processing>
<https://www.arduino.cc/reference/es/language/variables/data-types/boolean/>
<https://www.youtube.com/watch?v=EQugLcDoaOQ&ab_channel=ChepeCarlos>
<https://python-intermedio.readthedocs.io/es/latest/ternary_operators.html>
<https://component.gallery/>

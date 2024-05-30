# Clase-10

Pearl Jam - Even Flow

Trabajo orientado hacia procesing, con tal de tener una comunicación entre el dispositivo y la placa. Tener una idea de que se deberia arojar por pantalla, con esto se tiene una boción.

Un codigo interesante para entender no solo el lenguaje Java en si, si no que procesing es el del siguiente ejemplo sacado de las referencias. En el ejemplo una pelota rebota al llegar al borde del scketch dibujado, pero el rebote toma el centro y cuando el centro llega en algún momento a alguno de los bordes, lo cual esta determinado en los condicionales. Ahora bien el codigo Java sigue una logica similar a otros lenguajes orientados a objetos, los que organizan el diseño de software en torno a objetos o datos, en lugar de usar lógica y funciones.

```java

/*
Session 1 Exercise 4
 */
//Position Variables
int posX=100;
int posY=100;
//Direction Variables
int dirX=1;
int dirY=1;
void setup() {
  size(600, 400);
}
void draw() {
  background(222);
  //X-axis calculation
  posX=posX+dirX;
  if (posX>width) {
    dirX=-1;
  }
  if (posX<0) {
    dirX=1;
  }
  //Y-axis calculation
  posY=posY+dirY;
  if (posY>height) {
    dirY=-1;
  }
  if (posY<0) {
    dirY=1;
  }
  //Draw the primitive shape
  ellipse(posX, posY, 30, 30);
}

```

Ahora bien, si queremos tener otro caso, en el cual sea el borde y no el centro de la elipse o circunferecnia. Una posible solución sería.

```java

//posiciones iniciales
int posX = 100; //genera problemas si tenemos radio 150, bucle infinito
int posY = 100;

//variables de dirección
int dirX = 1;
int dirY = 1;
//radio o diametro
int radio = 150;

void setup() {
  size(600, 400);
}

void draw() {
  background(222);

  posX = posX + dirX;
  if (posX + radio > width || posX - radio < 0) {
    dirX = dirX * -1;
  }

  posY = posY + dirY;
  if (posY + radio > height || posY - radio < 0) {
    dirY = dirY * -1;
  }


  ellipse(posX, posY, radio * 2, radio * 2);

}


```
Para poder ingresar imagenes se debe tener la imagen a utilizar en la misma carpeta en la que está el proyecto, esto también implica que se deba guardar el proyecto para que puedan estar los archivos en la carpeta. Tener en cuenta la logica de dibujo, se dibuja primero lo que primero se corre y luego todo se dibujara sobre el resto. En el ejemplo de as referencias con arreglos tenemos:

```java
//archivos de las imagenes
// 711dhfoqw4L._AC_SL1500_
// 591041

/*
Session 2 exercise 1
*/
//Create the objects for the two images
PImage img1; //PImage define un objeto vacio donde podrás guardar la imagen a utilizar
PImage img2; 

void setup(){
  size(2000,2000);
  //Load the images to the sketch
  img1=loadImage("591041.jpg");
  img2=loadImage("711dhfoqw4L._AC_SL1500_.jpg");
  
}

void draw(){
  //Place the images on the canvas
  image(img1,0,0);
  image(img2,0,0);
}
```
![image](https://github.com/SrYuyo/dis145/assets/103392227/20aa61f5-9598-4b94-a4d4-b14359ae7bef)

![image](https://github.com/SrYuyo/dis145/assets/103392227/371ad0e9-5794-4fa8-86f8-b69f61fbd716)

Ahora biene el definir la interfaz de como se relaciona el usuario con el objeto/producto. Ver si de procesing se puede pasar a pantallas led pequeñas para poder iterar.


Referentes:

<https://happycoding.io/tutorials/processing/>
<https://happycoding.io/tutorials/processing/what-is-programming>
<http://makitpro.com/index.php/aprende/referencia/ejercicios-de-processing/> (link no seguro?)
<http://www.tallertecno.com/recursos/Referencia_Processing_con_Imagenes.pdf> (link no seguro?)
<https://processing.org/reference#control-logical-operators>
<https://cursos.mcielectronics.cl/2019/06/11/conectando-arduino-a-processing/>
<https://www.youtube.com/watch?v=EQugLcDoaOQ&ab_channel=ChepeCarlos>
<https://processing.org/tutorials/gettingstarted>
<https://processing.org/tutorials/>

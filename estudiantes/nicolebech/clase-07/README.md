# clase-07
Fecha: Jueves 18 de abril,2024

## Contenido Clase:
Se trabajó principalmente con la definición de funciones aritmeticas, para esto tuvimos que crear nuestra propia función y explicarla como vimos en clase. Para efectos de este ejercicio definí la división entre dos numeros enteros.

**Ejemplo división (Función aritmetica)**


```
int division2(int x0, int x1) {                  // defino la funcion division entre dos numeros enteros
  int division = x0 / x1;                        // le doy significado a la funcion division2 para que cumpla con su explicacion
  return division;                               // el retorno será el resultado de la división de las variables asignadas
}
```

Además aprendimos a trabajar en distintas carpetas de un mismo archivo para ordenar y facilitar el trabajo. Utilizamos la extensión .h y .cpp que se explican a continuación. Para efectos de este ejercicio se ejemplificó con el funcionamiento de un auto y se definieron variables acorde a esto.


**Explicación archivo Auto.cpp**

```
// Crear clases para despues hacer logica


#include "Auto.h"           // copia todo lo que esta en el archivo .h y lo pega en este

Auto::Auto()         {      // dentro de la clase Auto la funcion Auto, indica las condiciones inciales del constructor
  velocidad = 0;           // el auto parte estacionado
  combustible = 1.0;       // el auto parte con combustible lleno


}

Auto::frenar()       {
velocidad = 0;              // cada vez que frene, este frenara en seco
}

Auto::acelerar() {
  velocidad++;
  if(velocidad > 50) {
    velocidad + 50:
  }
```

**Explicación archivo Auto.h**

```
// Explicacion del tipo de archivo .h
// Este sirve para declarar que las cosas existen o no existen para el cpp

class Auto {                                                   // dice que funciones existen en cada clase
  // varibales
  // atributos

  bool estaEncendido;

  // 0.0 significa vacio
  // 0.1 significa lleno
  float combustible;
  int velocidad;

  // funciones
  // metodos
  
  // constructor                                               // constructor se llama igual que la clase y no tiene tipo, es la plantilla con la que creo 
Auto();


  void acelerar();
  void frenar();
  void encender();                                             // como existe el booleano puede existir un encender o apagar
  void apagar();
  
};                                                             //  termina con ;
```


**Los apuntes de clase y todos los comentarios se encuentran en la carpeta subida.**










## Segunda parte de clase 
En la última parte de la clase tuvimos como tarea analizar una biblioteca a elección. para esto trabajamos en grupo. A continuación se adjunta lo que hicimos:
Reposteado de : @isigoycoolea

# Actividad análisis código :arrow_down:
## Miembros del Grupo:
- ***Josefina Sánchez***
- ***Isidora Goycoolea:***
- ***Nicole Bechan:***
- ***Sebastián Millán:***

![Alt text](1.jpg)


![Alt text](2.jpg)


![Alt text](3.jpg)


![Alt text](4.jpg)


![Alt text](5.jpg)











Finalmente, en cuanto al proyecto personal este se encuentra en proceso de definición. Hasta el momento estuve indagando en sensores y materiales que quiero utilizar y me gustaría trabjar con un módulo lector RFID Rc522. Aun en proceso la idea final.

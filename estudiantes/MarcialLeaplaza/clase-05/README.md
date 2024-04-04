# clase-05
Entender los conceptos basicos de la programacion:

- Float/Int
- Boolean
- Input/Output
- Circuito

Lectura == -1 : No ha recibido una lectura desde la ultima vez que se prendio.

Pines analogos A n° : No se definen en el setup.

Digital : 0 == LOW // 1 == HIGH

Registrar valores maximos y minimos de variables que sea conveniente conocer.

Cuando queremos trackear un valor podemos hacer que los cambios sean menos agresivos eligiendo un rango de valores que se promedioan, y luego ir actualizando progresivamente los valores.

millis() es una herramienta que permite registrar tiempos dentro del codigo. Funciona contando los milisegundos que han pasado desde que se inicia el programa, por lo que se pueden poner marcas de cuando ocurre algun cambio en el circuito.

```Cpp
unsigned long tiempoAhora;
unsigned long tiempoRango;
unsigned long tiempoUltimo;

void setup() {
  tiempoDelta = 1000;
  tiempoAnterior = 0;
}

void loop() {
  tiempoAhora = millis();
  if (tiempoAhora - tiempoUltimo > tiempoDelta){
    tiempoAnterior = tiempoAhora;
  }
}
```

Tambien es posible crear funciones dentro de arduino, las cuales son utiles para acortar codigos que realizan la misma cosa muchas veces.

```Cpp
//Declaracion de variables
unsigned long tiempoAhora;
unsigned long tiempoRango;
unsigned long tiempoUltimo;
int rangoTiempo;

//Funcion
int rangoTiempo(x,y){
  return x-y
}

void setup() {
//Valores para las variables
  tiempoDelta = 1000;
  tiempoAnterior = 0;
  rangoTiempo = 0;
}

void loop() {
//Valor para tiempoAhora son los milisegundos que han pasado desde que se prendio el arduino.
  tiempoAhora = millis();
  rangoTiempo = rangoTiempo(tiempoAhora-tiempoUltimo)
  if (rangoTiempo > tiempoDelta){
    tiempoAnterior = tiempoAhora;
  }
}
```

En este caso la funcion se llama rangoTiempo, y lo que hace es restar dos variables, en este caso el tiempo actual con el tiempo anterior.

MEALEY/MOORE: Maquina de estado.

Sirve para organizar un código.
Por ejemplo para el click:

empezamos con el estado "no hay click" y se desarrollan los distintos caminos que se pueden tomar cuando se interactua con el boton.

![Figura1](./Imagenes/)

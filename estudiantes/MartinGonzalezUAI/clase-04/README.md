# Clase-04

## Codigo Mouse 

Con este codigo podemos apretar un boton y hacer que se mande un mensaje a traves del monitor, en este caso pusimos las palabras "HOLA" y "CHAO" solo para poder comprobar la efectividad del codigo

```cpp

int boton1 = 2; //Definimos el pin del boton 1 
int boton2 = 4; //Definimos el pin del boton 2
int estadoAntBoton1 = LOW; //Almacenamos el estado inicial del boton 1
int estadoAntBoton2 = LOW; //Almacenamos el estado inicial del boton 2

void setup()
{
  pinMode(boton1, INPUT); //Indicamos que el boton 1 es una entrada
  pinMode(boton2, INPUT); //Indicamos que el boton 2 es una entrada
  Serial.begin(9600); //Iniciamos comunicacion serial 
}

void loop()
{
  int estadoBoton1 = digitalRead(boton1); //Leemos el nuevo estado del boton 1
  int estadoBoton2 = digitalRead(boton2); //Leemos el nuevo estado del boton 2
  
  if(estadoBoton1 == HIGH && estadoAntBoton1 == LOW) //Observamos si cambio el estado del boton 1
  {
    Serial.print("HOLA "); //Mostramos mensaje en el monitor 
    delay(100); //Retardo para leer el mensaje bien
  }
  else if(estadoBoton2 == HIGH && estadoAntBoton2 == LOW)//Observamos si cambio el estado del boton 2
  {
    Serial.print("CHAO "); //Mostramos mensaje en el monitor 
    delay(100); //Retardo para leer el mensaje bien
  }
 estadoAntBoton1 = estadoBoton1; //Actualizamos el estado anterior del boton 1 
 estadoAntBoton2 = estadoBoton2; //Actualizamos el estado anterior del boton 1
}

```

## Codigo Mouse con Doble Clic

Con mi compañero Mauricio Viveros hicimos este codigo en la clase para que al apretar el clic izquierdo se mande un mensaje al monitor que diga "CLIC IZQUIERDO", y que al apretar el clic derecho se mande un mensaje al monitor que diga "CLIC DERECHO"
, y que al apretar dos veces el clic izquierdo se mande un mensaje al monitor que diga "DOBLE CLIC IZQUIERDO"

```cpp

int botonIzq = 2; //Definimos el pin del boton Izq
int botonDer = 4; //Definimos el pin del boton Der
int estadoAntBotonIzq = LOW; //Almacenamos el estado inicial del boton Izq
int estadoAntBotonDer = LOW; //Almacenamos el estado inicial del boton Der
unsigned long tiempoClicBotonIzq = 0; // Almacenamos el tiempo del último clic del boton Izq
unsigned long tiempoDobleClic = 1000; // Tiempo máximo entre clics para considerarlo un doble clic

void setup()
{
  pinMode(botonIzq, INPUT); //Indicamos que el boton Izq es una entrada
  pinMode(botonDer, INPUT); //Indicamos que el boton Der es una entrada
  Serial.begin(9600); //Iniciamos comunicacion serial 
}

void loop()
{
  
  int estadoBotonIzq = digitalRead(botonIzq); //Leemos el nuevo estado del boton Izq
  int estadoBotonDer = digitalRead(botonDer); //Leemos el nuevo estado del boton Der
  unsigned long tiempoActual = millis(); // Obtenemos el tiempo actual
  
  
  if(estadoBotonIzq == HIGH && estadoAntBotonIzq == LOW && tiempoActual - tiempoClicBotonIzq > tiempoDobleClic) //Observamos si cambio el estado del boton 1
  {
    Serial.println("CLICK IZQUIERDO"); //Mostramos mensaje en el monitor 
    delay(100); //Retardo para leer el mensaje bien
  }  
  
  if(estadoBotonIzq == HIGH && estadoAntBotonIzq == LOW && tiempoActual - tiempoClicBotonIzq < tiempoDobleClic)
  {
    Serial.println("DOBLE CLICK IZQUIERDO"); //Mostramos mensaje en el monitor 
    delay(100); //Retardo para leer el mensaje bien
    //Serial.println(tiempoActual);
    //Serial.println(tiempoClicBotonIzq);
  }
  
  else if(estadoBotonDer == HIGH && estadoAntBotonDer == LOW)//Observamos si cambio el estado del boton Der
  {
    Serial.println("CLICK DERECHO"); //Mostramos mensaje en el monitor 
    delay(100); //Retardo para leer el mensaje bien
  }
  
  estadoAntBotonIzq = estadoBotonIzq; //Actualizamos el estado anterior del boton Izq
  estadoAntBotonDer = estadoBotonDer; //Actualizamos el estado anterior del boton Izq
 
  if (estadoBotonIzq == HIGH && estadoAntBotonDer == LOW ) 
  {
    tiempoClicBotonIzq = tiempoActual; //Actualizamos el tiempo del boton Izq
  }
}

```

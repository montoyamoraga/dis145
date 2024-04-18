# Clase-07 (18/04/2024)

```cpp

//18-04-2024
//Hecho por Martin Gonzalez

//Funcion para sumar tres numeros

int sumar(int x0, int x1, int x2)
{
  int suma = x0 + x1 + x2;
  return suma;
}

//Funcion para restar cuatro numeros

int restar(int x0, int x1, int x2, int x3)
{
  int x0 - x1 - x2 - x3;
}

//Funcion para sacar valor absoluto 

int valAbs(int x0)
{
  if(x0 < 0)
  {
    return -x0;
  }
  else
  {
    return x0;
  }
}

//Funcion para ver si numero es par o no

int par(x0)
{
  resto = x0 % 2;

  if(resto == 0)
  {
    return string("El numero entero es par");
  }
  else 
  {
    return string("El numero entero no es par")
  }
}

//Funcion para ver si un numero entero es primo o no

int primo(x0)
{
  for i in range(2, x0)
  {
    if(x0 % i) == 0;
    {
      return string("El numero entero no es primo")
    }
    else
    {
      return string("El numero entero si es primo")
    }
  }
}

```

Tambien en esta clase aprendimos a utilizar un archivo .h en donde se crea una clase con sus respectivas variable (atributos) y funciones (metodos)

//Dentro de esta clase hay variables(atributos) y funciones(metodos)

```cpp

class Auto 
{
  //Atributos

  boolean estaEncendido;
  //0.0 esta vacio y 1.0 esta lleno
  float combustible;
  int velocidad;

  //Metodos
  Auto();

  void acelerar();
  void frenar();
  void encender();
  void apagar();
};

```


Sumado a esto aprendimos a utilizar un archivo .cpp doned vamos a ¿controlar? las variables y las funciones

```cpp

#include "Auto.h"

Auto::Auto()
{
  velocidad = 0;
  combustible = 1.0;
}

Auto::frenar()
{
  velocidad = 0;
}

Auto::acelerar()
{
  velocidad++;

  if(velocidad > 50)
  {
    velocidad = 50;
  }
}

```


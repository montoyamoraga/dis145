# clase-07

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

int vAbs(int x0)
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

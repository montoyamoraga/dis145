
// Ejemplos de funciones aritmeticas
// En el siguiente codigo se describen ejemplos de funciones y como se definen para trabajar en arduino


int sumar3(int x0, int x1, int x2)  {            // "void" hace lo que tiene que hacer y no responde con nada adicional
  int suma = x0 + x1 + x2;                       // le doy significado a la variable
  return suma;                                   // expulsa hacia afuera "suma"
}

int restar4(int x0, int x1, int x2, int x3) {    // defino lo que quiero hacer, en este caso restar cuatro numeros enteros
  int resta =  x0 - x1 - x2 -x3;                 // le doy significado a la variable restar4 para que cumpla con lo que quiero hacer
  return resta;                                  // expulsa hacia afuera la "resta"
}

int absoluto(int x0) {                           // defino la variable valor absoluto de un numero entero, tambien podria usar float para decimales
  if (x0 < 0) {                                  // establezco condicion
    return -x0;                                  // dará numero negativo el resultado
  } else {                                       // en cualquier otro caso contrario el retorno será el resultado inverso
    return x0;                                  
  }
}
 
int division2(int x0, int x1) {                  // defino la funcion division entre dos numeros enteros
  int division = x0 / x1;                        // le doy significado a la funcion division2 para que cumpla con su explicacion
  return division;                               // el retorno será el resultado de la división de las variables asignadas
}

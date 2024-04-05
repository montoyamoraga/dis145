# clase-05

Es bueno filtrar los datos, no solo para tener un codigo más pulcro, si no que tambie´n a nivel de software y hardware sera más útil, se pueden evitar los saltos o ruidos, además limitar lo que nos puede ser útil respecto a lo que queramos. Se deben tener variables para almacenar lo que queramos, por lo que tendremos variables de tipo int.

Un fotoresistor tiene un rango entre los 0 y 1023 bits. Podemos agregarle una zona de indiferencia o fallo, la que queramos. Para poder saber si se esta leyendo o seteando de correctamanera, es bueno utilizar datos que no tienen, como por ejemplo -1. Es importante tener la mayor cantidad de variables auxiliares, con tal de que nuestro codigo no sea vulnerable.

Siguiendo el ejemplo del foto resistor es jugar lvon las variables de minimo y maximo, además de plantear los casos de que no son posibles, para así poder verificar la lectura de datos. Es bueno declarar las variables con algún número, para así poder tener un codigo robusto.

No Utilizar el delay para lidiar con el ruido. Es bueno utilizar el promedio, en el cual se va dejando desechado el último valor y luego se va actualizando. 


**buscar ejemplo fotoresistor**

**millis**
Momento de inicio desde que se le dio energia a la placa de arduino. Utilizar Long, para que no utilizar delay. Aún así el long tiene un problema respecto a millis, pues tiene un rango negativo, se debe partir desde 0.
Linl: <https://www.arduino.cc/reference/es/language/functions/time/millis/>

Utilizaremos "unsinged long tiempoAhora". Un unsigned long es un tipo de dato para enteros sin signo de 32 bits, es decir, números sin punto decimal. Los enteros largos pueden ser tan grandes como 4294967295 y tan pequeños como 0. Esta declaraci+on de variable puede ocurrir solo una vez y por ende debe ser al principio. También podemos trabajar con una variable "unsingedlong tiempoDelta".

```arduino
//Tiempo
unsignedlong tiempoAhora;
unsignedlong tiempoDelta;
unsignedlong tiempoAhora;

void setup(){
  tiempoDelta=0;
  tiempoAnterior=0;
}

void loop(){
  tiempoAhora=millis();
  if(tiempoAhora - tiempoAnterior > tiempoDelta){
  tiempoAnterior = tiempoAhora;
  }
prenderLuzyParlante();
}
```

Maquinas de estado
Una máquina de estado es un modelo matemático abstracto que se utiliza para diseñar algoritmos. Es una arquitectura de programación que permite el flujo dinámico a los estados según los valores de los estados anteriores o la información del usuario. Me permiten saber de que estado a que estado puedo ir o en que estado estoy. Otro factor es la utilización de boleanos, con tal de definir estados. 

"Seria bueno que analicen, como por ejemplo un hervidor o algun dispositivo".



Referencias:
<https://www.arduino.cc/reference/es/language/functions/time/millis/>
<https://arduino.cl/introduccion-a-los-tipos-de-dato-con-arduino/#:~:text=unsignedlong%20(32%20bit)%2D%20n%C3%BAmero,%2C%20entre%20%2D2%2C147%2C483%2C648%20y%202%2C147%2C483%2C647.>
<https://www.ni.com/es/support/documentation/supplemental/16/simple-state-machine-template-documentation.html#:~:text=Una%20m%C3%A1quina%20de%20estado%20es%20una%20arquitectura,que%20pueden%20describirse%20como%20una%20combinaci%C3%B3n%20de:.>


# clase-05

## Apuntes a mano

![Apuntes 01](./apuntes_clase5_1.jpg)
![Apuntes 01](./apuntes_clase5_2.jpg)
![Apuntes 01](./apuntes_clase5_3.jpg)

## Ejercicios prácticos

### Ejercicio 01

**Codigo:**

**Simulacion en Tinkercard**

**Observaciones**
* No me funciono al principio porque me faltó poner en le codigo **Serial.print(9600) en el void setup()**
* Cuando le ponemos más luz al fotoresistor, se imprime "oscuridad" porque se imprimen numeros mayores a 600, por lo tanto el codigo debe ser **if (lecturaFR<600){ Serial.printIn("luz");}**
* El cambio de luz a oscuridad no se etsá haciendo justo en la mitad


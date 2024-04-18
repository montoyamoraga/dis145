# clase-07

durante esta clase visualizamos y analizamos la arquitectura del software arduino como por ejemplo trabajar en varias pestañas y en archivos .h y .cpp,

para esto vimos ejemplos de suma y tambien creamos uno

```cpp
// sumar 3 numeros

  void
  sumar3(int x0, int x1, int x2);
int suma = x0 + x1 + x2;
return suma;
```
tabs

en este caso quize crear un ejemplo de regla de 3
```cpp
// regla de 3

int x0
int x1
int x2
int xN

int multip(int x1, int x2){

int resultado = x1 * x2;

return resultado;
}

int div(int x1; int x2; int x0){

int regla3 = (x1*x2)/x0

return regla3

}
```
ya para terminar aprendimos a utilizar y leer librerias de arduino con el proposito de reutilizar codigos que ya estan hechos y ahorrar tiempo pero siempre aprendiendo de ellos

creamos una libreria la cual simula ser un auto 
```cpp
class Auto {

//variables o atributos

//float trabaja con 0 y 1
//aca se dice si el estanque esta lleno 1 y sino 0

float combustible
int color

//funciones o metodos

//constructor
Auto()

void acelerar();
void frenar();
void encender()
void apagar()

};
```

luego de esto logramos utilizarla en otro codigo exportandola y simplificando el siguiente trabajo

ya para finalizar
cada uno indagó por github buscando librerias y analizandolas
en mi caso encontré 3 librerias interesantes las cuales fueron codigos para programar sensores IR como por ejemplo un control remoto, un mouse bluetooth y un joystick


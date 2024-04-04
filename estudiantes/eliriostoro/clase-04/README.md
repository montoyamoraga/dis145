# clase-04

# apuntes

variable, sensor---> int (0 a 1023) 
float tiene capacidad de poner un numero decimal

ejemplo:
cuenta de banco esta en int y no en float porque tiende a tener errores.

### estrategias
int lecturaFR= -1 
para saber si esta leyendo la consola
void loop {
  lecturaFR= analogRead(pin)
  serial.print ln(lecturaFR) ----> me dicta los valores del foto receptor

minimo y maximo historico
se ponen los peores casos
int minFR=1023 ; peor caso en min
int maxFR=0 ; peor caso en max

---->actrualizacion de min y maximo 

----> si la lectura es menor al valor minimo igualalos
if(lecturaFR<minFR){
      minFR=lecturaFR;
  }
----> si la lectura es mayo al valor maximo igualalos
if(lecturaFR>maxFR){
  maxFR=lecturaFR;
  }
-----> para que sea un valor parametrico  y no 600
medioFR= (minFR+maxFR)/2;
if (lecturaFR<medioFR){
}
herramientas de precision
entran datos y el profe recomienda que promediemos los 5 valores y que vayamos borrando uno a medida que entra uno
1-2-3-4-5
x-2-3-4-5-6


funcion millis();
damos energia, corre el set up, el loop y tiene conciencia que resucito, cuando empieza tiene 0 
estrategia:

int momento= millis():
----> en el momento que tiene energia es su cero
----> milisegundos pór eso avanza tan rapido 1s=1000 en consola

long: entero mas largo
para no usar delay se usa *LONG*

para guardar los millis
unsinged long momento =millis ();

momento/1000 son la cantidad de segundos

##Ejemplo de codigo
*fuente:* https://hetpro-store.com/TUTORIALES/arduino-millis/ 

```cpp
unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempoSegundos = 0;

void setup() {
  Serial.begin(9600);
  tiempo1 = millis();

}

void loop() {

  tiempo2 = millis();
  if(tiempo2 > (tiempo1+1000)){  //Si ha pasado 1 segundo ejecuta el IF
    tiempo1 = millis(); //Actualiza el tiempo actual
    tiempoSegundos = tiempo1/1000;
    Serial.print("Ha transcurrido: ");
    Serial.print(tiempoSegundos);
    Serial.println(" desde que se encendio el Arduino");
    
  }
  

}
```























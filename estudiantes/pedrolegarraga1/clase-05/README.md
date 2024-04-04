# clase-05

introduccion a los codigos en arduino y analisis de estos para obtener estrategias que usaremos en un futuro programando

1. variables (para definir un sensor u etc):
1. float,  decimales (aproxima)
1. int,  0-1023 (5V, que tanto puede leer el sensor) numeros enteros "el mas utilizado"
2. bool, se utiliza como un int pero solo lee 0 y 1

----------------------------------------------------------------------------------------------------------------------------------
creamos un codigo para sensor fotovoltaico:
```cpp
//creamos variables
	int pin = A1;
	int lecturaFotoetc = -1;
	
//creamos nuevas variables para los valores del sensor y las vinculamos con los valores que pueden leer los sensores
	int MaxFotoR = 1023;
	int MinFotoR = 0;
	int MedioForoR = -1;
void loop {

//puede variar con "digitalRead o analogRead"
lecturaFotoetc = analogRead(pin);

//para que la consola lea, se crea el Serial.println(pin usado)
Serial.println(lecturaFotoetc);	

//el if se utiliza como pregunta, si ocurre tal suceso(pregunta) se abre corchete y se escribe el resultado/solucion
if(lecturaFotoetc<MinFotoR){
MinFotoR = LecturaFotoetc }

if(lecturaFotoetc>MaxFotoR){
MaxFotoR = LecturaFotoetc }

medioFotoR = (MinFotoR+MaxFotoR)/2;

if (lecturaFotoetc<medioFotoR){


	}
else {
}
```

durante este vimos como dejar un numero 
-------------------------------------------------------------------------------------------------------------------------------------

Creamos un codigo usando millis

```cpp
//creamos variables, en este caso "unsigned long" el cual funciona parecido al "int"
unsigned long tiempoAhora;
unsigned long timepoDelta;
unsigned long timepoAnterior;

void setup {
tiempoDelta = 1000;
timepoAnterior = 0;

}

void loop {
	tiempoAhora = millis();

if(tiempoAhora-tiempoAnterior>tiempoDelta) {
	tiempoAnterior = tiempoAhora;
 //para comparar se utiliza ==, en este caso con solo un =, se transpasa su valor

 } prenderLuzyParlante()
//prenderLezyParlante() tiene que ser una funcion la cual definimos mas arriba pero que no haremos en este codigo (imaginarse que funciona)
 }

```

-------------------------------------------------------------------------------------------------------------------------------------

Maquina de estado

objetivo: 

estado inicial: no tengo café

                         -----------> no ;(
se pregunta: HAY? -------                                        -si---------> compro
                         -----------> si ---------> tengo dinero? 
                                                                 -no---------> no compro


  luego, para programar podemos hacer lo mismo
  ej: hay click? no hay click, se vuelve a preguntar
                 si hay click, se hace lo que uno quiera con el comando if y creando una funcion

```cpp
//bool funciona como un int pero solo puede leer 0 y 1
   bool nohayClickReciente = false;
   bool hayClickReciente = true;

void setup {
   boton = digitalRead
void loop

if  = false

```

   {
   else
   }


sintaxis de if y else en c++

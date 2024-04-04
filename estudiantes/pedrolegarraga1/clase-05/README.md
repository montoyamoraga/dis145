# clase-05

Filtrar


variables (para definir un sensor u etc):
float,  decimales (aproxima)
int,  0-1023 (5V, que tanto puede leer el sensor) numeros enteros "el mas utilizado"

----------------------------------------------------------------------------------------------------------------------------------
codigo para sensor fotovoltaico:
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
-------------------------------------------------------------------------------------------------------------------------------------

//tiempo 

```cpp
//creamos variables
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
 }

```

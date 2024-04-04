# clase-05
Clase5 
aprendimos las diferencias entre float e int (float es un numero decimal int entero)
aprendimos como poder ajustar un foto resistor para que pueda funcionar apesar de estar en distintas condiciones
aprendimos que delay es una mala idea ya que se congela el arduino y puede producir un atraso en general
aprendimos la funcion millies en remplazo de delay


```cpp
Int= entero (0-1023)
Float=  decimales
in pinFr=a1
int lecturafotores = -1
int minFR=1023 peor minimo de fotoresistor
int maxFr=0; peor maximo del foto resitor
int medioFr =-1;
medrioFr=max+min)/2;
void loop 
lecturaFr= analogRead (pin) //es analogico  y lee 
Serial.println (lectura) //verlo en el serial
if(lecturaFR<minFR){min fr=lectura;} 
delay es mala idea ya que congela

//tiempo
unsigned long tiempoAhora; 
unsigned long tiempoDelta;
void setup{
tiempodelta=1000
Void loop{ 
tiempoAhora= millis()

if(tiempoAhora-tiempoAnterior > teimpo delta) ;
tiempo anterior=tiempo ahora); 
prenderluzyparlante();

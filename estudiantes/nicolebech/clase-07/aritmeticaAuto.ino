
// Ejemplos de funciones aritmeticas demostradas
// En el siguiente codigo se ejemplifican las funciones declaradas con valores para entender su funcionamiento


int cantidaddeudas;                                         //defino las variables a utilizar a continuacion
int finanzas;                                               
int sueldo0 = 3;
int otroSueldo = 7;
int deudas = -1000000;

void setup() {                                              // Inicio el programa
  Serial.begin(9600);
}
  
void loop() {
  finanzas = sumar3(sueldo0, otroSueldo, deudas);          // En este caso se ejemplifica como utilizar la funcion de sumar tres variables
  Serial.println(finanzas);                                // El resultado será mostrado en la consola
 
  cantidaddeudas = division2(deudas, sueldo0);             // En este caso se ejemplifica como utilizar la funcion de division de 2 variables
   Serial.println(cantidaddeudas);                         // El resultado sera mostrado en la consola
}



  
  

**APUNTES**: Fotoresistor (4/abril)

**Integrantes**: Martin Gonzalez, Mauricio Viveros y Valentina Tiznado
Codigo que enciende una luz led, dependiendo del valor entregado por nuestro fotoresistor


int pinLedNaranjo = 7; //Indicamos el pin del led naranjo
int pinFR = A3; //Indicamos el pin del fotoresistor
int estadoFR = 0; //Indicamos le estado del fotoresistor
int minFR = 1023; //Indicamos el valor del peor minimo
int maxFR = 0; //Indicamos el valor del peor maximo
int medioFR = (minFR + maxFR)/2; //Indicamos el parametro para la luz 

void setup()
{
  pinMode(pinLedNaranjo, OUTPUT); //Determinamos que el led es una salida
  Serial.begin(9600); //Iniciamos comunicacion serial
}

void loop()
{
  estadoFR = analogRead(pinFR); //Leemos estado del fotoresistor 
  
  if(estadoFR < minFR) //Condicion para buscar el minimo valor del fotoresitor 
  {
    minFR = estadoFR; //Actualizamos minimo valor 
    Serial.print("EL MINIMO ES: "); //Mostramos mensaje en el monitor
    Serial.println(minFR); //Mostramos el valor del minimo valor en el monitor
  }
  
  if(estadoFR > maxFR) //Condicion para buscar el maximo valor del fotoresitor
  {
    maxFR = estadoFR; //Actualizamos maximo valor 
    Serial.print("EL MAXIMO ES: "); //Mostramos mensaje en el monitor
    Serial.println(maxFR); //Mostramos el valor del maximo valor en el monitor
 }
  
  if(estadoFR > medioFR) //Condicion para determinar si se enciende o no el led
  {
    digitalWrite(pinLedNaranjo, HIGH); //Encendemos el led si se cumple la condicion
    Serial.print(estadoFR); //Mostramos el valor del fotoresistor en el monitor
    Serial.print(": "); //Mostramos mensaje en el monitor
    Serial.println("LUZ"); //Mostramos mensaje en el monitor
  }
  else 
  {
    digitalWrite(pinLedNaranjo, LOW); //Apagamos el led si no se cumple la condicion anterior 
    Serial.print(estadoFR); //Mostramos el valor del fotoresistor en el monitor
    Serial.print(": "); //Mostramos mensaje en el monitor
    Serial.println("OSCURIDAD"); //Mostramos mensaje en el monitor
  }
}
[Apuntes clase 5.pdf](https://github.com/valetiznado/dis145/files/14877316/Apuntes.clase.5.pdf)

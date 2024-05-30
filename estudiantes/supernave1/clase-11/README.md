# clase-11

## Investigación

Averiguamos cuanto volts necesita el motor 500TB-12560, que son de 3 a 14. Aguanta una potencia maxima de 2W.
Potencia = Voltage x Corriente, con esta formula llegamos a la conclusion de que ocupando la salida de 5v del arduino UNO, podriamos usar el motor previamente mencionado. La corriente del arduino es de 435 mA.

https://github.com/supernave1/dis145/assets/164402810/cd655e64-b29c-4525-acc5-eec3b2a57dcf

Este motor sera el responsable de lanzar las cartas, para ello voy a tener que programar para que el motor funcione en intervalos lo suficientemente cortos para lanzar una a una las cartas.

## Funcionamiento
Gracias a un blog encontrado en intenet, logre hacer andar el motor, y ser capaz de regularle la velocidad.

Para esto se necesita:
* Motor DC
* Transistor PN2222
* Diodo 1N4001
* Resistencia 270Ω
* ProtoBoard
* Arduino UNO
* 5 cables

Estos materiales se conectan de la siguiente forma para dar vida al circuito

![Circuito_Motor_Velocidades](https://github.com/supernave1/dis145/assets/164402810/17b29b5c-c8f9-4916-8c18-70de89b28d23)

* El Transistr PN2222 cumple la funcion de interrumptor, el cual ocupa poca corriente de la salida digital de Arduino, para asi controlar la corriente del motor, la cual al ser mayor puede dañar el Arduino.

* El Diodo 1N4001, permite que la electricidad fluya en una dirección, lo que protege al Arduino de cualquier corriente inversa que puede generar el motor.

* El pin D3 del Arduino está conectado a la resistencia, la cual limita la corriente que fluye hacia el transistor a través de la base.

En un principio no me estaba funcionando el circuito, el problema era que no estaba usando una resistencia de 270Ω, esto es muy importante ya que los transistores al ser capaces de hacer tantas cosas, son muy sencibles a lo que necesitan para hacer algo.

## Código
El codigo logra darnos la opción de elegir a que velocidad queremos que gire, en un rango de 0 a 255, donde 255 es la velocidad maxima. Para esto en el serial monitor uno pone el valor a gusto.


```cpp
int motorPin = 3; // Motor en pin 3
void setup()
{ 
  pinMode(motorPin, OUTPUT); // Da una variable y la da como salida
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");  // Pone en el serial monitor
}
void loop()  // Inicia el recorrido
{ 
  if (Serial.available()) 
  {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  }
} 
```

## Circuito funcionando

En el video, se puede ver como le damos un valor de 100, para que el motor gire, y despues de un tiempo, le damos valor 0 para que frene.

https://github.com/supernave1/dis145/assets/164402810/c2dbc7b4-4b62-436d-ba90-af15dc861772



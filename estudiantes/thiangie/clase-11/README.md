# clase-11
## Entendimiento de cómo transmitir códigos de Arduino a Processing
### Primer acercamiento: cómo transmitir un mensaje del monitor serial de Arduino a Processing
Se va a transmitir los valores de un potenciómetro conectado a un Arduino Mega
#### Código en Arduino

```
// variable donde se almacenarán los datos del potenciometro
int valor;

// variable de conversion de la variable numerica a un string
String valorString;
 
void setup() {
  //Inicializamos la comunicación serial
  Serial.begin(9600);
  
  //Escribimos por el monitor serie mensaje de inicio
  Serial.println("Valores del potenciometro");
 
}
 
void loop() {
  // leemos del pin A0 valor
  valor = analogRead(A0);

  // conversion de valor numerico a string
  valorString = String(valor);
  Serial.println(valorString);

  // delay de tiempo para no emitir el mensaje muy rapido
  delay(1000);
}
```
#### Código en processing
Se va a hacer que muestre los valores del potenciometro de Arduino
```
import processing.serial.*;

Serial myPort;
String val;

void setup() {
  String portName = Serial.list() [1];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if (myPort.available() > 0) {
    val = myPort.readStringUntil('\n');
  }
  
  println(val);
}
```
### Cosas aprendidas
Partir desde lo más básico y desde ahí llegar a algo más complejo (el proyecto en sí mismo).
Convertir variables numéricas en strings (carácteres).

### Pendientes
Buscar cómo hacer que el processing lea "dos strings en uno".
Desglosar el código del proyecto para averiguar las variables que debe manejar cada potenciómetro.





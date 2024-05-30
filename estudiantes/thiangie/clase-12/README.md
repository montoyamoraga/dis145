# clase-12


Presentación de la iteraciones del codigo para el proyecto del ramo. Todas los codigos fueron realizados mediante una placa arduino unoR3 V 2.3.2. 


Codigo para el sensor dht22
```cpp
#include <DHT.h>
#define DHTPIN 8 // Pin de datos del sensor
#define DHTTYPE DHT22 // Tipo de sensor DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
dht.begin();
}

void loop() {
delay(2000);

float humidity = dht.readHumidity();
float temperature = dht.readTemperature();

if (isnan(humidity) || isnan(temperature)) {
Serial.println("Error");// si hay problemas en la lectura
return;
}

Serial.print("Humedad: ");
Serial.print(humidity);
Serial.print("% Temperatura: ");
Serial.print(temperature);
Serial.println("°C");
}
```

Primera iteración del sensor MQ-2

```cpp
int A;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  A = analogRead(A0);
  Serial.println(A);

}
```

Segunda iteración con un filtrado de los datos
```cpp
#define         MQ1                       (0)     //entrada analogica para el sensor
#define         RL_VALOR             (5)     //valor de la resistencia mde carga en kilo ohms
#define         RAL       (9.83)  //resistencia del sensor en el aire limpio / RO, resistencia de sensibilidad
#define         GAS_LP                      (0)
String inputstring = "";                                                        //Cadena recibida desde el PC
float           LPCurve[3]  =  {2.3,0.21,-0.47};
float           Ro           =  10;
void setup(){
Serial.begin(9600);                                                                  //Inicializa Serial a 9600 y le agregamos suspenso
 Serial.println("Iniciando ...");
   //configuracion del sensor
  Serial.print("Calibrando...\n");
  Ro = Calibracion(MQ1);                        //Calibrando el sensor.
  Serial.print("Calibracion finalizada...\n");
  Serial.print("Ro=");
  Serial.print(Ro);
  Serial.print("kohm");
  Serial.print("\n");
}
 
void loop()
{
   Serial.print("LP:");
   Serial.print(porcentaje_gas(lecturaMQ(MQ1)/Ro,GAS_LP) );
   Serial.print( "ppm" );
   Serial.print("    ");
   Serial.print("\n");
   delay(200); //sacar??
}
 
float calc_res(int raw_adc)
{
  return ( ((float)RL_VALOR*(1023-raw_adc)/raw_adc));
}
 
float Calibracion(float mq_pin){
  int i;
  float val=0;
    for (i=0;i<50;i++) {                                                                               //tomar múltiples muestras
    val += calc_res(analogRead(mq_pin));
    delay(500);
  }
  val = val/50;                                                                                         //calcular el valor medio
  val = val/RAL;
  return val;
}
 
float lecturaMQ(int mq_pin){
  int i;
  float rs=0;
  for (i=0;i<5;i++) {
    rs += calc_res(analogRead(mq_pin));
    delay(50);
  }
rs = rs/5;
return rs;
}
 
int porcentaje_gas(float rs_ro_ratio, int gas_id){
   if ( gas_id == GAS_LP ) {
     return porcentaje_gas(rs_ro_ratio,LPCurve);
   }
  return 0;
}
 
int porcentaje_gas(float rs_ro_ratio, float *pcurve){
  return (pow(10, (((log(rs_ro_ratio)-pcurve[1])/pcurve[2]) + pcurve[0])));
}
```

Combinación entre ambos codigos:

```cpp


```

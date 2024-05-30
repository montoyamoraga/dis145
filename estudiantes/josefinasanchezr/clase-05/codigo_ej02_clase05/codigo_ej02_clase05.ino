// 2024-04-04
// codigo para dejar como variables la lectura de un fotoresistor
// por josefinasanchezr
// hecho con Arduino IDE 1.8.19
// para Arduino UNO R3

// Definimos variables

int pinFR = A1;
int lecturaFR = -1;
//se asigna el peor minimo
int minFR = 1023;
//se asigna el peor maximo
int maxFR = 0;
int medioFR = -1;


void setup() {
  Serial.begin(9600);
}

void loop() {
  lecturaFR = analogRead(pinFR);

  //Imprimimos en la consola con la siguiente estructura para tener de una m anera mas ordenada los numeros y sea mas faciul compararlos
  Serial.print("lectura: ");
  Serial.print(lecturaFR);
  Serial.print(", ");
  Serial.print("min: ");
  Serial.print(minFR);
  Serial.print(", ");
  Serial.print("max: ");
  Serial.println(maxFR);

  if(lecturaFR < minFR){
    minFR = lecturaFR;
    // Serial.print("nuevoMin: ");
    // Serial.println(minFR);
    
  }
  
  if(lecturaFR > maxFR){
    maxFR = lecturaFR;
    // Serial.print("nuevoMax: ");
    // Serial.println(maxFR);
    

  }
    
  else{
    medioFR = (minFR + maxFR)/2;
      
  }
  
}

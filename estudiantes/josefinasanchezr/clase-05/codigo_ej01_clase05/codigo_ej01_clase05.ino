// 2024-04-04
// codigo para dejar como variables la lectura de un fotoresistor
// por josefinasanchezr
// hecho con Arduino IDE 1.8.19
// para Arduino UNO R3

// Definimos variables

int pinFR = A1;
int lecturaFR = -1;

void setup() {
}

void loop() {
  lecturaFR = analogRead(pinFR);
  Serial.println(lecturaFR);

  if(lecturaFR > 600){
    Serial.println("luz");
    
  }

  else{
    Serial.println("oscuridad");
      
  }
  
}

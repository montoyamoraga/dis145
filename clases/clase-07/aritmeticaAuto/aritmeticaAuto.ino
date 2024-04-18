int finanzas;
int sueldo0 = 3;
int otroSueldo = 7;
int deudas = -10000000;


void setup() {
  Serial.begin(9600);
}

void loop() {
 finanzas = sumar3(sueldo0,  otroSueldo, deudas);
 Serial.println(finanzas); 
}

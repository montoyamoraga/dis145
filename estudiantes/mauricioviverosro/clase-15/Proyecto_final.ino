// Pines driver L298N
const int CON1 = 2;
const int CON2 = 3;
const int CON3 = 4;
const int CON4 = 5;

// Pines Joystick
const int direcX = A1;
const int direcY = A2;

// Variables para los valores del Joystick
int varx = 0;
int vary = 0;
int DELAY = 10;

void setup() {
  pinMode(CON1, OUTPUT);
  pinMode(CON2, OUTPUT);
  pinMode(CON3, OUTPUT);
  pinMode(CON4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
 
  varx = analogRead(direcX);
  vary = analogRead(direcY);
 
  if (varx > 550) {
    SetStepForward();
  } else if (varx < 400) {
    SetStepBackward();
  }
  delay(4);
}

void SetStepForward(){
  con1(); delay(DELAY);
  con2(); delay(DELAY);
  con3(); delay(DELAY);
  con4(); delay(DELAY);
}
void SetStepBackward(){
  con1(); delay(DELAY);
  con2(); delay(DELAY);
  con3(); delay(DELAY);
  con4(); delay(DELAY);
}

void con1(){
  digitalWrite(CON1, HIGH);
  digitalWrite(CON2, LOW);
  digitalWrite(CON3, HIGH);
  digitalWrite(CON4, LOW);
}
void con2(){
  digitalWrite(CON1, LOW);
  digitalWrite(CON2, HIGH);
  digitalWrite(CON3, HIGH);
  digitalWrite(CON4, LOW);
}
void con3(){
  digitalWrite(CON1, LOW);
  digitalWrite(CON2, HIGH);
  digitalWrite(CON3, LOW);
  digitalWrite(CON4, HIGH);
}
void con4(){
  digitalWrite(CON1, HIGH);
  digitalWrite(CON2, LOW);
  digitalWrite(CON3, LOW);
  digitalWrite(CON4, HIGH);
}

// 2024-03-21
//primer arduinito 
//prenda y apague luz
//por Spidermaneberl y 
//hecho con Rduino IDE2.3.2
//para arduino UNO R3

const int buttonPin = 4;     
const int ledPin =  12;

int buttonState = 0;    

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } 
  else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(50);
}

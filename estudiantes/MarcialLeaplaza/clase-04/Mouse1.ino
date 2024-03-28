int pinPotIzq = A3;
int pinPotDer = A5;
int clickDer = 8;
int clickIzq = 7;
int pixelsX = 800;
int pixelsY = 600;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:  
  int potIzq = analogRead(pinPotIzq);
  int potDer = analogRead(pinPotDer);
  
  int posX = map(potIzq, 0, 1023, 0, pixelsX);
  int posY = map(potDer, 0, 1023, 0, pixelsY);

  Serial.print("Posicion del mouse: X: ");
  Serial.print(posX);
  Serial.print(", Y: ");
  Serial.println(posY);

  delay(10);

}

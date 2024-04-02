// Primero declaramos dos variables enteras d7 y d8 y le asignamos los valores 7 y 8 respectivamente
int d7 = 7;
int d8 = 8;

// Se ejecuta la funcion setup, la cual se hace una sola vez al iniciar el Arduino
void setup() {

  // Se configura el pin d7 como entrada con pull-up, lo que significa que se activa una resistencia interna para asegurarse de que el pin esté en estado alto (HIGH) cuando no esté conectado a nada
  pinMode(d7, INPUT_PULLUP);

  // Luego configuramos el pin d8 como entrada con pull-up
  pinMode(d8, INPUT_PULLUP);

  // Se inicia la comunicación serial a 9600 baudios, lo que permite enviar y recibir datos desde y hacia el Arduino
  Serial.begin(9600);
}

// Se ejecuta la funcion loop, la cual permite crear un bucle después de completar la función setup
void loop() {

  // Se leen valores analógicos de dos pines: A1 y A0. La función analogRead convierte una señal analógica en un valor digital de 0 a 1023
  int lecturaX = analogRead(A1);
  int lecturaY = analogRead(A0);

  // Se mapean los valores leídos de los pines A1 y A0 a nuevos rangos y se guardan en las variables x e y respectivamente
// La función map transforma un valor de un rango a otro, por ejemplo, de 0 a 1023 a 1917 a 2 para x
  int x = map(lecturaX, 0, 1023, 1917, 2);
  int y = map(lecturaY, 0, 1023, 2, 1077);

  // Se verifica el estado del pin d8, si está conectado a tierra (LOW), se ejecuta el código dentro de este bloque
  if (digitalRead(d8) == LOW) {
   
 // Se envía la letra 'c' por la comunicación serial si d8 está en LOW
    Serial.print("c");
  } else { // Si d8 está en HIGH (no conectado a tierra)
   
 // Se envía la letra 'z' por la comunicación serial
    Serial.print("z");
  }

  // Se envían espacios y valores de x e y por la comunicación serial para visualizar la información
  Serial.print(" "); // Se envía un espacio
  Serial.print(x); // Se envía el valor de x
  Serial.print(" "); // Se envía otro espacio
  Serial.print(y); // Se envía el valor de y
  Serial.print(" "); // Se envía otro espacio
  Serial.println("m"); // Se envía la letra 'm' seguida de un salto de línea

  // Se esperará 100 milisegundos antes de repetir el bucle anterior
  delay(100);
}

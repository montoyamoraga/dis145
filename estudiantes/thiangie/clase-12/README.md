# clase-12
Objetivo de la clase: hacer que se pueda leer los valores de lectura de un potenciómetro en arduino para que se prenda un led RGB según los valores entregados.

Para esto se va a considerar lo siguiente:
1. Color Rojo: 1-171
2. Color amarillo: 172-342
3. Color verde: 343-513
4. Color cyan: 514-684
5. Color azul: 685-855
6. Color magenta: 856-1023

## Conexión de un led RGB a Arduino
Importante tener en cuenta que cada led RGB está conectado a un pin analógico de arduino
```
/* 30 de mayo, 2024
clase 12
thiare gonzalez
versión 1
conectar led rgb a un arduino uno
*/

// definir los leds asociado a cada pin en el arduino
#define ledRojo 11
#define ledVerde 10
#define ledAzul 9

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop() {
  // color rojo
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, LOW);
  delay(1000);

  // color amarillo 
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAzul, LOW);
  delay(1000);

  // color verde
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAzul, LOW);
  delay(1000);

  // color azul
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, HIGH);
  delay(1000);

  // color blanco
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAzul, HIGH);
  delay(1000);

  // color magenta
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, HIGH);
  delay(1000);

  // color cyan
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAzul, HIGH);
  delay(1000);

}

```

## Controlar un led RGB con un potenciómetro
```
/* 30 de mayo, 2024
clase 12
thiare gonzalez
versión 1
conectar led rgb a un arduino uno
*/

// definir los leds asociado a cada pin en el arduino
#define ledRojo 11
#define ledVerde 10
#define ledAzul 9

// valor que tomará el potenciómetro
long valor;

//ingresar el potenciometro
int pot = A0;

void setup() {
  // registrar los leds del led rgb como salida
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  // registrar el potenciómetor como entrada
  pinMode(pot, INPUT);
}

void loop() {

  valor = analogRead(A0);

  if(valor >= 1 && valor <= 171) {
    // color rojo
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
    delay(1000);
  }

  if(valor >= 172 && valor <= 342) {
    // color amarillo 
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
    delay(1000);
  }

  if(valor >= 343 && valor <= 513) {
    // color verde
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
    delay(1000);
  }

  if(valor >= 514 && valor <= 684) {
    // color verde
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, HIGH);
    delay(1000);
  }

  if(valor >= 685 && valor <= 855) {
    // color azul
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
    delay(1000);
  }

  if(valor >= 856 && valor <= 1023) {
    // color magenta
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
    delay(1000);
  } 

/*
  // color blanco
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAzul, HIGH);
  delay(1000);

*/

}
```


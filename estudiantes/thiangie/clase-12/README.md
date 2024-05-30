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
``` C++
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

### Video de cómo funciona el código físicamente


https://github.com/thiangie/dis145/assets/100184098/c0d1d4d2-7643-4120-aa21-fa6d8bbe3eaf



## Controlar un led RGB con un potenciómetro
``` C++
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
    // color cyan
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

}
```
### Video de cómo funciona físicamente

https://github.com/thiangie/dis145/assets/100184098/35074195-5898-4d95-8c18-4512b9b27ddb

## Añadir un segundo potenciómetro
El segundo potenciómetro tiene como finalidad hacer que cambiar los Hz de un buzzer, que según color ya tiene asignado ciertos valores.

1. Color Rojo: 400 - 484
2. Color amarillo: 508 - 526
3. Color verde: 527 - 606
4. Color cyan: 607 - 630
5. Color azul: 631 - 668
6. Color magenta: 669 - 789


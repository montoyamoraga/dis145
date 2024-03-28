<<<<<<< main
HOLA EN TITULO
==
HOLA EN SUBTITULO
--

LINK DE COMANDOS: https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet

![material1](material1.jpg)
![material2](material2.jpg)
![material3](material3.jpg)
![material4](material4.jpg)
![material5](material5.jpg)
![material6](material6.jpg)
![material7](material7.jpg)

- Arduino UNO R3
- Protoborad
- Cable USB
- Cables Dupont
- Resistencias
- Sensor de color
- Botones y potenciometro

```cpp
// Para encontrar el acento al reves
// Buscar backtick
void setup()
{
int x = 0;
}
```

=======

# índice

- [clase-01](./clase-01)
- [clase-02](./clase-02)
- [clase-03](./clase-03)
- [clase-04](./clase-04)
- [clase-05](./clase-05)
- [clase-06](./clase-06)
- [clase-07](./clase-07)
- [clase-08](./clase-08)
- [clase-09](./clase-09)
- [clase-10](./clase-10)
- [clase-11](./clase-11)
- [clase-12](./clase-12)
  > > > > > > > main


Con el grupo (Tiznado, Viveros y Gonzalez) intentamos de correr el codigo pero no funciono. 

Codigo: 
```cpp
int boton_pin = 2;

int estadoAnterior = LOW;

void setup() 
{
  Serial.begin(9600);

  pinMode(boton_pin, INPUT);
}

void loop() {
  int estadoActual = digitalRead(boton_pin);
  
  if (estadoActual == HIGH && estadoAnterior == LOW) 
  {
    Serial.println("HOLA");
    delay(100);
  }
  estadoAnterior = estadoActual;
}
```
![errorArduino](errorArduino.png)


# clase-06
apuntes clase 06 DyCdI

durante la clasee de hoy trabajamos con codigos "Serial" los cuales mandan señales en serie.
ej:
```cpp
Serial.begin(9600)


Serial.println(mensaje que uno quiera escribir)

Serial.write
```

Luego trabajamos con el software "Processing" con el que hicimos dos ejercicios en este caso el primero se basaba en dibujar y en el segundo enviamos notas de piano desde un codigo a otro y en este hicimos enfasis en que trabajamos con MIDI's

Midi es un lenguaje con el que se programa la mayoria de los instrumentos melodicos digitales y que los hace compatibles

PROCESSING
```cpp
//este proyecto esta hecho para "prosessing 4.3"
//durante este dibujamos con el cursor

void setup() {
  size(400, 300);
background(6595, 0, 0);
}

void draw() {
ellipse(mouseX, mouseY, 10, 10);
}
```
para finalizar dimos enfasis en como deberian quedar 
Siempre nuestro proyectos tienen que estar con una estructura así:

```cpp
// ej_34_midi_enviar
// por montoyamoraga
// para Academia Sinestesia
// Programa de Medios Interactivos 2023
// v0.0.2 mayo 2023
// hecho con Processing 4.2.0
// ejemplo traducido y basado
// de The MidiBus => Basic
```

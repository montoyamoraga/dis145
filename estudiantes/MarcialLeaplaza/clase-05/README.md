# clase-05
Entender los conceptos basicos de la programacion:

- Float/Int
- Boolean
- Input/Output
- Circuito

Lectura == -1 : No ha recibido una lectura desde la ultima vez que se prendio.

Pines analogos A n° : No se definen en el setup.

Digital : 0 == LOW // 1 == HIGH

Registrar valores maximos y minimos de variables que sea conveniente conocer.

Cuando queremos trackear un valor podemos hacer que los cambios sean menos agresivos eligiendo un rango de valores que se promedioan, y luego ir actualizando progresivamente los valores.
'''C++
unsigned long tiempoAhora;
unsigned long tiempoRango;
unsigned long tiempoUltimo;

void setup() {
  tiempoDelta = 1000;
  tiempoAnterior = 0;
}

void loop() {
  tiempoAhora = millis();
  if (tiempoAhora - tiempoUltimo > tiempoDelta){
    tiempoAnterior = tiempoAhora;
  }
}
'''

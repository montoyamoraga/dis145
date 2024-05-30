
// Explicacion del tipo de archivo .h
// Este sirve para declarar que las cosas existen o no existen para el cpp

class Auto {                                                   // dice que funciones existen en cada clase
  // varibales
  // atributos

  bool estaEncendido;

  // 0.0 significa vacio
  // 0.1 significa lleno
  float combustible;
  int velocidad;

  // funciones
  // metodos
  
  // constructor                                               // constructor se llama igual que la clase y no tiene tipo, es la plantilla con la que creo 
Auto();


  void acelerar();
  void frenar();
  void encender();                                             // como existe el booleano puede existir un encender o apagar
  void apagar();
  
};                                                             //  termina con ; 
